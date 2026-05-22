-- todo: comments
-- Piotr Antonik, 2014


library ieee;
    use ieee.std_logic_1164.all;
library unisim;
    use unisim.vcomponents.all;


entity dac_phy_old is
--  generic
--  (
--    CLK_IDELAY   : integer := 0;
--    CHA_IDELAY   : integer := 0;
--    CHB_IDELAY   : integer := 0
--  );
    port (
        -- input clock & reset signals
        clk_to_fpga_p : in  std_logic;
        clk_to_fpga_n : in  std_logic;
        cpu_reset     : in  std_logic;

        -- data to DAC
        dac_din_i    : in  std_logic_vector(15 downto 0);
        dac_din_q    : in  std_logic_vector(15 downto 0);

        -- output signals to DAC chip
        txenable      : out std_logic;
        
        dac_dclk_p    : out std_logic;
        dac_dclk_n    : out std_logic;
        
        dac_data_p    : out std_logic_vector(7 downto 0);
        dac_data_n    : out std_logic_vector(7 downto 0);
        
        dac_frame_p   : out std_logic;
        dac_frame_n   : out std_logic;

        -- output clock
        clk_dac_o     : out std_logic
    );
end entity;

architecture Behavioral of dac_phy_old is

    signal frame             : std_logic;
    signal io_rst            : std_logic;
    signal rst               : std_logic;

    signal dac_dclk_prebuf   : std_logic;
    signal dac_data_prebuf   : std_logic_vector(7 downto 0);
    signal dac_frame_prebuf  : std_logic;

    signal clk_dac           : std_logic;
    signal clk_dac2x         : std_logic;
    signal clk_to_fpga       : std_logic;
    --signal clk_368_64MHz     : std_logic;
    signal mmcm_adac_locked  : std_logic;

begin

    -- Dedicated 61.44 MHz clock from the CDCE, independant from the ADC clock
    ibufds_ref_clk : ibufds
    generic map (
        IOSTANDARD => "LVDS_25",
        DIFF_TERM => TRUE
    )
    port map (
        i  => clk_to_fpga_p,
        ib => clk_to_fpga_n,
        o  => clk_to_fpga
    );

    clk_dac_o <= clk_dac;

    -- DAC Clock Wizard
    -- * clk_to_fpga is a clock signal coming from the 4th port of the CDCE; if
    -- an external clock is used, and it's divider is set to 4 (right now), this
    -- is extclk/4.
    -- This clkwiz outputs 1x and 2x its input clock.
    mmcm_adac_inst : entity work.clkwiz_dac2
    port map (
        clk_in1   => clk_to_fpga,
        clk_out1  => clk_dac,
        clk_out2  => clk_dac2x,
        reset     => cpu_reset,
        locked    => mmcm_adac_locked
    );
 

    ----------------------
    --- Reset sequence ---
    ----------------------
    process (mmcm_adac_locked, clk_dac)
        variable cnt : integer range 0 to 1023 := 0;
    begin
     if (mmcm_adac_locked = '0') then
   
       cnt := 0;
       rst <= '1';
       io_rst <= '0';
       frame <= '0';
       txenable <= '0';
   
     elsif (rising_edge(clk_dac)) then
   
       -- DDC and DUC are kept in reset state for a while...
       if (cnt < 1023) then
         cnt := cnt + 1;
         rst <= '1';
       else
         cnt := cnt;
         rst <= '0';
       end if;
   
       -- The OSERDES blocks are synchronously reset for one clock cycle...
       if (cnt = 255) then
         io_rst <= '1';
       else
         io_rst <= '0';
       end if;
   
       -- Then a frame pulse is transmitted to the DAC...
       if (cnt = 511) then
         frame <= '1';
       else
         frame <= '0';
       end if;
   
       -- Finally the TX enable for the DAC can by pulled high.
       if (cnt = 1023) then
         txenable <= '1';
       end if;
   
     end if;
   end process;
  

    ---------------------------------------------------
    --- Output serdes and LVDS buffer for DAC clock ---
    ---------------------------------------------------
   oserdes_clock : oserdes
   generic map (
     DATA_RATE_OQ => "DDR",
     DATA_RATE_TQ => "DDR",
     DATA_WIDTH => 4,
     INIT_OQ => '0',
     INIT_TQ => '0',
     SERDES_MODE => "MASTER",
     SRVAL_OQ => '0',
     SRVAL_TQ => '0',
     TRISTATE_WIDTH => 1
   )
   port map (
     oq        => dac_dclk_prebuf,
     shiftout1 => open,
     shiftout2 => open,
     tq        => open,
     clk       => clk_dac2x,
     clkdiv    => clk_dac,
     d1        => '1',
     d2        => '0',
     d3        => '1',
     d4        => '0',
     d5        => '0',
     d6        => '0',
     oce       => '1',
     rev       => '0',
     shiftin1  => '0',
     shiftin2  => '0',
     sr        => io_rst,
     t1        => '0',
     t2        => '0',
     t3        => '0',
     t4        => '0',
     tce       => '0'
   );
   
   --output buffer
   obufds_clock : obufds_lvdsext_25
   port map (
     i  => dac_dclk_prebuf,
     o  => dac_dclk_p,
     ob => dac_dclk_n
   );
   
    ---------------------------------------------------
    --- Output serdes and LVDS buffers for DAC data ---
    ---------------------------------------------------
   dac_data: for i in 0 to 7 generate
   
     --oserdes in data path
     oserdes_data : oserdes
     generic map (
       DATA_RATE_OQ => "DDR",
       DATA_RATE_TQ => "DDR",
       DATA_WIDTH => 4,
       INIT_OQ => '0',
       INIT_TQ => '0',
       SERDES_MODE => "MASTER",
       SRVAL_OQ => '0',
       SRVAL_TQ => '0',
       TRISTATE_WIDTH => 1
     )
     port map (
       oq        => dac_data_prebuf(i),
       shiftout1 => open,
       shiftout2 => open,
       tq        => open,
       clk       => clk_dac2x,
       clkdiv    => clk_dac,
       d1        => dac_din_i(i + 8),
       d2        => dac_din_i(i),
       d3        => dac_din_q(i + 8),
       d4        => dac_din_q(i),
       d5        => '0',
       d6        => '0',
       oce       => '1',
       rev       => '0',
       shiftin1  => '0',
       shiftin2  => '0',
       sr        => io_rst,
       t1        => '0',
       t2        => '0',
       t3        => '0',
       t4        => '0',
       tce       => '0'
     );
   
     --output buffers
     obufds_data : obufds_lvdsext_25
     port map (
       i  => dac_data_prebuf(i),
       o  => dac_data_p(i),
       ob => dac_data_n(i)
     );
   
   end generate;
   
    ---------------------------------------------------
    --- Output serdes and LVDS buffer for DAC frame ---
    ---------------------------------------------------
   oserdes_frame : oserdes
   generic map (
     DATA_RATE_OQ => "DDR",
     DATA_RATE_TQ => "DDR",
     DATA_WIDTH => 4,
     INIT_OQ => '0',
     INIT_TQ => '0',
     SERDES_MODE => "MASTER",
     SRVAL_OQ => '0',
     SRVAL_TQ => '0',
     TRISTATE_WIDTH => 1
   )
   port map (
     oq        => dac_frame_prebuf,
     shiftout1 => open,
     shiftout2 => open,
     tq        => open,
     clk       => clk_dac2x,
     clkdiv    => clk_dac,
     d1        => frame,
     d2        => frame,
     d3        => frame,
     d4        => frame,
     d5        => '0',
     d6        => '0',
     oce       => '1',
     rev       => '0',
     shiftin1  => '0',
     shiftin2  => '0',
     sr        => io_rst,
     t1        => '0',
     t2        => '0',
     t3        => '0',
     t4        => '0',
     tce       => '0'
   );
   
   --output buffer
   obufds_frame : obufds_lvdsext_25
   port map (
     i  => dac_frame_prebuf,
     o  => dac_frame_p,
     ob => dac_frame_n
   );


end Behavioral;
