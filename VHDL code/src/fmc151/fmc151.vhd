-- FMC151 Module
-- Overview: wrapper for FMC151 control modules & setup iDelay
-- Written by P. Antonik, 2015
-- Written for Michiel's BPT project

-- NOTES:
-- * iDelay (15b) : 14.. iDelay CLK + iDelay CHB + iDelay CHA ..0


library ieee;
    use ieee.std_logic_1164.all;
library work;
    use work.types_pkg.all;


entity fmc151 is
    port (
        -- Clock from ML605 (sysclk)
        clk_100MHz      : in  std_logic;
        clk_200MHz      : in  std_logic;
        mmcm_locked     : in  std_logic;

        -- CPU Reset
        cpu_reset       : in  std_logic;
        
        --Clock/Data connection to ADC on FMC150 (ADS62P49)
        clk_ab_p         : in    std_logic;
        clk_ab_n         : in    std_logic;
        cha_p            : in    std_logic_vector(6 downto 0);
        cha_n            : in    std_logic_vector(6 downto 0);
        chb_p            : in    std_logic_vector(6 downto 0);
        chb_n            : in    std_logic_vector(6 downto 0);

        --Clock/Data connection to DAC on FMC150 (DAC3283)
        dac_dclk_p       : out   std_logic;
        dac_dclk_n       : out   std_logic;
        dac_data_p       : out   std_logic_vector(7 downto 0);
        dac_data_n       : out   std_logic_vector(7 downto 0);
        dac_frame_p      : out   std_logic;
        dac_frame_n      : out   std_logic;
        txenable         : out   std_logic;

        --Clock/Trigger connection to FMC150
        clk_to_fpga_p    : in    std_logic;
        clk_to_fpga_n    : in    std_logic;
        ext_trigger_p    : in    std_logic;
        ext_trigger_n    : in    std_logic;

        --Serial Peripheral Interface (SPI)
        spi_sclk         : out   std_logic; -- Shared SPI clock line
        spi_sdata        : out   std_logic; -- Shared SPI sata line

        -- ADC specific signals
        adc_n_en         : out   std_logic; -- SPI chip select
        adc_sdo          : in    std_logic; -- SPI data out
        adc_reset        : out   std_logic; -- SPI reset
        clk_adc          : out   std_logic;

        -- CDCE specific signals
        cdce_n_en        : out   std_logic; -- SPI chip select
        cdce_sdo         : in    std_logic; -- SPI data out
        cdce_n_reset     : out   std_logic;
        cdce_n_pd        : out   std_logic;
        ref_en           : out   std_logic;
        pll_status       : in    std_logic;

        -- DAC specific signals
        dac_n_en         : out   std_logic; -- SPI chip select
        dac_sdo          : in    std_logic; -- SPI data out

        -- Monitoring specific signals
        mon_n_en         : out   std_logic; -- SPI chip select
        mon_sdo          : in    std_logic; -- SPI data out
        mon_n_reset      : out   std_logic;
        mon_n_int        : in    std_logic;

        --FMC Present status
        prsnt_m2c_l      : in    std_logic;

        -- Actual data
        dac_din_i       : in  std_logic_vector(15 downto 0);
        dac_din_q       : in  std_logic_vector(15 downto 0);
        adc_dout_i      : out std_logic_vector(13 downto 0);
        adc_dout_q      : out std_logic_vector(13 downto 0);

        -- iDelay setup
        state           : in  stateType;
        setTarget       : in  targetType;
        inWord          : in  std_logic_vector(15 downto 0);
        inWordTrig      : in  std_logic;
        d_idelay        : out std_logic_vector(14 downto 0)
);
end entity;

architecture Behavioral of fmc151 is
    
    signal idelay_cntvalues : std_logic_vector(14 downto 0) := (others => '0');
    signal arst             : std_logic;
    signal rd_n_wr          : std_logic;
    signal addr             : std_logic_vector(15 downto 0);
    signal idata            : std_logic_vector(31 downto 0);
    signal odata            : std_logic_vector(31 downto 0);
    signal busy             : std_logic;
    signal cdce72010_valid  : std_logic;
    signal ads62p49_valid   : std_logic;
    signal dac3283_valid    : std_logic;
    signal amc7823_valid    : std_logic;
    signal clk_dac          : std_logic;
	
	--ATTRIBUTE MARK_DEBUG : STRING;
    --ATTRIBUTE MARK_DEBUG OF setTarget : SIGNAL IS "true";
	--ATTRIBUTE MARK_DEBUG OF inWord : SIGNAL IS "true";

begin

    setidelay : process (clk_200MHz)
    begin
        if rising_edge(clk_200MHz) then
            if state=setup AND setTarget=idelay AND inWordTrig='1' then
                idelay_cntvalues <= inWord(14 downto 0);
            end if;
        end if;
    end process;
    d_idelay <= idelay_cntvalues;

    
    arst <= not mmcm_locked;

    -----------------------------------
    --- Interface with the ADC chip ---
    -----------------------------------
    adc_phy : entity work.adc_phy
    port map (
        -- input
        clk_ab_p        => clk_ab_p,
        clk_ab_n        => clk_ab_n,
        cha_p           => cha_p,
        cha_n           => cha_n,
        chb_p           => chb_p,
        chb_n           => chb_n,
        clk100mhz       => clk_100MHz,
        clk200mhz       => clk_200MHz,
        arst            => arst,
        cntvalues       => idelay_cntvalues,
        -- output
        clk_from_adc    => clk_adc,
        adc_dout_i      => adc_dout_i,
        adc_dout_q      => adc_dout_q
    );


    -----------------------------------
    --- Interface with the DAC chip ---
    -----------------------------------
    dac_phy : entity work.dac_phy_old
    port map (
        -- input
        clk_to_fpga_p   => clk_to_fpga_p,
        clk_to_fpga_n   => clk_to_fpga_n,
        cpu_reset       => cpu_reset,
        dac_din_i       => dac_din_i,
        dac_din_q       => dac_din_q,
        -- output
        txenable        => txenable,
        dac_dclk_p      => dac_dclk_p,
        dac_dclk_n      => dac_dclk_n,
        dac_data_p      => dac_data_p,
        dac_data_n      => dac_data_n,
        dac_frame_p     => dac_frame_p,
        dac_frame_n     => dac_frame_n,
        clk_dac_o       => clk_dac
    );
  
  
    -----------------------------------
    --- Configuring the FMC150 card ---
    -----------------------------------
    -- the fmc150_spi_ctrl component configures the devices on the FMC150 card through the Serial
    -- Peripheral Interfaces (SPI) and some additional direct control signals.
   fmc150_spi_ctrl_inst : entity work.fmc150_spi_ctrl
   port map (
     addr            => addr,
     idata           => idata,
     rd_n_wr         => rd_n_wr,
     cdce72010_valid => cdce72010_valid,
     ads62p49_valid  => ads62p49_valid,
     dac3283_valid   => dac3283_valid,
     amc7823_valid   => amc7823_valid,
   
     odata           => odata,
     busy            => busy,
   
     external_clock  => '0',
   
     rst             => arst,
     clk             => clk_100MHz,
     spi_sclk        => spi_sclk,
     spi_sdata       => spi_sdata,
     adc_n_en        => adc_n_en,
     adc_sdo         => adc_sdo,
     adc_reset       => adc_reset,
     cdce_n_en       => cdce_n_en,
     cdce_sdo        => cdce_sdo,
     cdce_n_reset    => cdce_n_reset,
     cdce_n_pd       => cdce_n_pd,
     ref_en          => ref_en,
     pll_status      => pll_status,
     dac_n_en        => dac_n_en,
     dac_sdo         => dac_sdo,
     mon_n_en        => mon_n_en,
     mon_sdo         => mon_sdo,
     mon_n_reset     => mon_n_reset,
     mon_n_int       => mon_n_int,
     prsnt_m2c_l     => prsnt_m2c_l
   );

end Behavioral;
