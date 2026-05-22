-- todo: comments
-- Piotr Antonik, 2014


library ieee;
    use ieee.std_logic_1164.all;
    use ieee.numeric_std.all;
library unisim;
    use unisim.vcomponents.all;


entity adc_phy is
  generic
  (
    CLK_IDELAY   : integer := 0;
    CHA_IDELAY   : integer := 5;
    CHB_IDELAY   : integer := 5
  );
    port (
        -- ADC sampling clock from the ADS 62p49 chip (LVDS)
        clk_ab_p     : in  std_logic;
        clk_ab_n     : in  std_logic;

        -- Data channels A & B (LVDS)
        cha_p         : in std_logic_vector(6 downto 0);
        cha_n         : in std_logic_vector(6 downto 0);
        chb_p         : in std_logic_vector(6 downto 0);
        chb_n         : in std_logic_vector(6 downto 0);

        -- Delay clocks & reset signal
        clk100mhz     : in  std_logic;
        clk200mhz     : in  std_logic;
        arst          : in  std_logic;

        -- iDelay counter values
        cntvalues     : in  std_logic_vector(14 downto 0);

        -- Output clock from ADC
        clk_from_adc  : out std_logic;

        -- Output data
        --adc_dout_i    : out std_logic_vector(15 downto 0);
        --adc_dout_q    : out std_logic_vector(15 downto 0) 
        adc_dout_i    : out std_logic_vector(13 downto 0);
        adc_dout_q    : out std_logic_vector(13 downto 0) 
    );
end adc_phy;

architecture Behavioral of adc_phy is

    signal clk_ab_l          : std_logic;
    signal clk_ab_dly        : std_logic;
    signal clk_ab_i          : std_logic;

    signal cha_ddr           : std_logic_vector(6 downto 0);  -- Double Data Rate
    signal cha_ddr_dly       : std_logic_vector(6 downto 0);  -- Double Data Rate, Delayed
    signal cha_sdr           : std_logic_vector(13 downto 0); -- Single Data Rate

    signal chb_ddr           : std_logic_vector(6 downto 0);  -- Double Data Rate
    signal chb_ddr_dly       : std_logic_vector(6 downto 0);  -- Double Data Rate, Delayed
    signal chb_sdr           : std_logic_vector(13 downto 0); -- Single Data Rate

    signal delay_update      : std_logic;
    signal clk_cntvaluein    : std_logic_vector(4 downto 0);
    signal cha_cntvaluein    : std_logic_vector(4 downto 0);
    signal chb_cntvaluein    : std_logic_vector(4 downto 0);

    --signal clk_cntvalueout   : std_logic_vector(4 downto 0);
    --type cha_cntvalueout_array is array(cha_p'length-1 downto 0) of std_logic_vector(4 downto 0);
    --signal cha_cntvalueout   : cha_cntvalueout_array;
    --type chb_cntvalueout_array is array(chb_p'length-1 downto 0) of std_logic_vector(4 downto 0);
    --signal chb_cntvalueout   : chb_cntvalueout_array;



begin

    ----------------------------------------------------
    --- Clock from ADC on FMC150 for channel A and B ---
    ----------------------------------------------------
   
    -- Differential input buffer
    ibufds_inst : ibufds
    generic map (
     IOSTANDARD => "LVDS_25",
     DIFF_TERM  => TRUE
    )
    port map (
     i  => clk_ab_p,
     ib => clk_ab_n,
     o  => clk_ab_l
    );

    -- Input delay
    iodelay_inst : iodelaye1
    generic map (
     IDELAY_TYPE    => "VAR_LOADABLE",
     IDELAY_VALUE   => CLK_IDELAY,
     SIGNAL_PATTERN => "CLOCK",
     DELAY_SRC      => "I"
    )
    port map (
     idatain     => clk_ab_l,
     dataout     => clk_ab_dly,
     c           => clk100mhz,
     ce          => '0',
     inc         => '0',
     datain      => '0',
     odatain     => '0',
     clkin       => '0',
     rst         => delay_update,
     cntvaluein  => clk_cntvaluein,
     cntvalueout => open, --clk_cntvalueout,
     cinvctrl    => '0',
     t           => '1'
    );

    -- Make sure the clock is routed on a global net
    bufg_inst : bufg
    port map (
     i  => clk_ab_dly,
     o  => clk_ab_i
    );

    clk_from_adc <= clk_ab_i;

    -------------------------------
    --- Channel A data from ADC ---
    -------------------------------
   
    adc_data_a: for i in 0 to 6 generate
   
        -- Differantial input buffer with termination (LVDS)
        ibufds_inst : ibufds
        generic map (
        IOSTANDARD => "LVDS_25",
        DIFF_TERM  => TRUE
        )
        port map (
        i  => cha_p(i),
        ib => cha_n(i),
        o  => cha_ddr(i)
        );

        -- Input delay
        iodelay_inst : iodelaye1
        generic map (
        IDELAY_TYPE    => "VAR_LOADABLE",
        IDELAY_VALUE   => CHA_IDELAY,
        SIGNAL_PATTERN => "DATA",
        DELAY_SRC      => "I"
        )
        port map (
        idatain     => cha_ddr(i),
        dataout     => cha_ddr_dly(i),
        c           => clk100mhz,
        ce          => '0',
        inc         => '0',
        datain      => '0',
        odatain     => '0',
        clkin       => '0',
        rst         => delay_update,
        cntvaluein  => cha_cntvaluein,
        cntvalueout => open, --cha_cntvalueout(i),
        cinvctrl    => '0',
        t           => '1'
        );

        -- DDR to SDR
        iddr_inst : iddr
        generic map (
        DDR_CLK_EDGE => "SAME_EDGE_PIPELINED"
        )
        port map (
        q1 => cha_sdr(2*i),
        q2 => cha_sdr(2*i+1),
        c  => clk_ab_i,
        ce => '1',
        d  => cha_ddr_dly(i),
        r  => '0',
        s  => '0'
        );

   end generate;
   
   -------------------------------
   --- Channel B data from ADC ---
   -------------------------------
   adc_data_b: for i in 0 to 6 generate
   
     -- Differantial input buffer with termination (LVDS)
     ibufds_inst : ibufds
     generic map (
       IOSTANDARD => "LVDS_25",
       DIFF_TERM  => TRUE
     )
     port map (
       i  => chb_p(i),
       ib => chb_n(i),
       o  => chb_ddr(i)
     );
   
     -- Input delay
     iodelay_inst : iodelaye1
     generic map (
       IDELAY_TYPE    => "VAR_LOADABLE",
       IDELAY_VALUE   => CHB_IDELAY,
       SIGNAL_PATTERN => "DATA",
       DELAY_SRC      => "I"
     )
     port map (
       idatain     => chb_ddr(i),
       dataout     => chb_ddr_dly(i),
       c           => clk100mhz,
       ce          => '0',
       inc         => '0',
       datain      => '0',
       odatain     => '0',
       clkin       => '0',
       rst         => delay_update,
       cntvaluein  => chb_cntvaluein,
       cntvalueout => open, --chb_cntvalueout(i),
       cinvctrl    => '0',
       t           => '1'
     );

     -- DDR to SDR
     iddr_inst : iddr
     generic map (
       DDR_CLK_EDGE => "SAME_EDGE_PIPELINED"
     )
     port map (
       q1 => chb_sdr(2*i),
       q2 => chb_sdr(2*i+1),
       c  => clk_ab_i,
       ce => '1',
       d  => chb_ddr_dly(i),
       r  => '0',
       s  => '0'
     );
   
   end generate;
   
    ------------------------
    --- Extend to 16-bit ---
    ------------------------
    process (clk_ab_i)
    begin
     if (rising_edge(clk_ab_i)) then

       -- Left justify the data of both channels on 16-bits
       --adc_dout_i <= cha_sdr & "00";
       --adc_dout_q <= chb_sdr & "00";
       adc_dout_i <= cha_sdr;
       adc_dout_q <= chb_sdr;

     end if;
    end process;


    ------------------
    --- IDELAYCTRL ---
    ------------------
    idelayctrl_inst : idelayctrl
    port map (
      rst    => arst,
      refclk => clk200mhz,
      rdy    => open
    );


    ---------------------------------
    --- Set iDelay counter values ---
    ---------------------------------
    process (arst, clk100Mhz)
        variable cntvalues_prev : std_logic_vector(14 downto 0);
    begin
        if (arst = '1') then
            delay_update   <= '1';
            clk_cntvaluein <= std_logic_vector(to_unsigned(CLK_IDELAY, 5));
            cha_cntvaluein <= std_logic_vector(to_unsigned(CHA_IDELAY, 5));
            chb_cntvaluein <= std_logic_vector(to_unsigned(CHB_IDELAY, 5));
            cntvalues_prev := (others => '0');
        elsif (rising_edge(clk100Mhz)) then
            -- Generate an delay_update pulse in case one of the cntvaluein values has changed
            if (cntvalues(4 downto 0) /= cntvalues_prev(4 downto 0)) then
                delay_update   <= '1';
                clk_cntvaluein <= clk_cntvaluein;
                chb_cntvaluein <= chb_cntvaluein;
                cha_cntvaluein <= cntvalues(4 downto 0);
            elsif (cntvalues(9 downto 5) /= cntvalues_prev(9 downto 5)) then
                delay_update   <= '1';
                clk_cntvaluein <= clk_cntvaluein;
                chb_cntvaluein <= cntvalues(9 downto 5);
                cha_cntvaluein <= cha_cntvaluein;
            elsif (cntvalues(14 downto 10) /= cntvalues_prev(14 downto 10)) then
                delay_update   <= '1';
                clk_cntvaluein <= cntvalues(14 downto 10);
                chb_cntvaluein <= chb_cntvaluein;
                cha_cntvaluein <= cha_cntvaluein;
            else
                delay_update   <= '0';
                clk_cntvaluein <= clk_cntvaluein;
                chb_cntvaluein <= chb_cntvaluein;
                cha_cntvaluein <= cha_cntvaluein;
            end if;

            -- Register the VIO output in order to detect changes
            cntvalues_prev := cntvalues;
      end if;
    end process;

end Behavioral;
