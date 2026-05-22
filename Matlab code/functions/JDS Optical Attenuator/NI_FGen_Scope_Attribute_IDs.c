
/*****************************************************************************/
/*= Base values for attribute contants.                             ======== */
/*= A private attribute is one that is defined for use within       ======== */
/*= that module and is not exported via an include file.            ======== */
/*****************************************************************************/
#define IVI_ATTR_BASE                   1000000
#define IVI_ENGINE_PRIVATE_ATTR_BASE    (IVI_ATTR_BASE +  00000)   /* base for private attributes of the IVI engine */
#define IVI_ENGINE_PUBLIC_ATTR_BASE     (IVI_ATTR_BASE +  50000)   /* base for public attributes of the IVI engine */
#define IVI_SPECIFIC_PRIVATE_ATTR_BASE  (IVI_ATTR_BASE + 100000)   /* base for private attributes of specific drivers */
#define IVI_SPECIFIC_PUBLIC_ATTR_BASE   (IVI_ATTR_BASE + 150000)   /* base for public attributes of specific drivers */
#define IVI_CLASS_PRIVATE_ATTR_BASE     (IVI_ATTR_BASE + 200000)   /* base for private attributes of class drivers */
#define IVI_CLASS_PUBLIC_ATTR_BASE      (IVI_ATTR_BASE + 250000)   /* base for public attributes of class drivers */

/*****************************************************************************/
/*= Public IVI engine attributes                                    ======== */
/*= The data type of each attribute is listed, followed by the      ======== */
/*= default value or a remark.                                      ======== */
/*= Note:  "hidden" means not readable or writable by the end-user. ======== */
/*****************************************************************************/
#define IVI_ATTR_NONE                   /* no attribute */              0xFFFFFFFF

#define IVI_ATTR_RANGE_CHECK            /* ViBoolean, VI_TRUE */        (IVI_ENGINE_PUBLIC_ATTR_BASE + 2)     
#define IVI_ATTR_QUERY_INSTRUMENT_STATUS /* ViBoolean, VI_FALSE */      (IVI_ENGINE_PUBLIC_ATTR_BASE + 3)   /* If VI_TRUE, the specific driver is allowed to query the instrument error status after each operation */
#define IVI_ATTR_CACHE                  /* ViBoolean, VI_TRUE */        (IVI_ENGINE_PUBLIC_ATTR_BASE + 4)     
#define IVI_ATTR_SIMULATE               /* ViBoolean, VI_FALSE */       (IVI_ENGINE_PUBLIC_ATTR_BASE + 5)    
#define IVI_ATTR_RECORD_COERCIONS       /* ViBoolean, VI_FALSE */       (IVI_ENGINE_PUBLIC_ATTR_BASE + 6)
#define IVI_ATTR_DRIVER_SETUP           /* ViString,  "" */             (IVI_ENGINE_PUBLIC_ATTR_BASE + 7)

#define IVI_ATTR_INTERCHANGE_CHECK      /* ViBoolean, VI_TRUE */        (IVI_ENGINE_PUBLIC_ATTR_BASE + 21)
#define IVI_ATTR_SPY                    /* ViBoolean, VI_FALSE */       (IVI_ENGINE_PUBLIC_ATTR_BASE + 22)     
#define IVI_ATTR_USE_SPECIFIC_SIMULATION  /* ViBoolean */               (IVI_ENGINE_PUBLIC_ATTR_BASE + 23)  /* simulate values in specific rather than class driver;  default is VI_TRUE if session opened through class driver, VI_FALSE otherwise */

#define IVI_ATTR_PRIMARY_ERROR          /* ViInt32  */                  (IVI_ENGINE_PUBLIC_ATTR_BASE + 101)     
#define IVI_ATTR_SECONDARY_ERROR        /* VIInt32  */                  (IVI_ENGINE_PUBLIC_ATTR_BASE + 102)     
#define IVI_ATTR_ERROR_ELABORATION      /* ViString */                  (IVI_ENGINE_PUBLIC_ATTR_BASE + 103)    

#define IVI_ATTR_CHANNEL_COUNT          /* ViInt32,  not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 203)   /* set by the specific-driver;  default: 1 */

#define IVI_ATTR_CLASS_DRIVER_PREFIX    /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 301)  /* instrument prefix for the class driver;  empty string if not using class driver */
#define IVI_ATTR_SPECIFIC_DRIVER_PREFIX /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 302)  /* instrument prefix for the specific driver */ 
#define IVI_ATTR_SPECIFIC_DRIVER_LOCATOR/* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 303)  /* the pathnname of the specific driver code module; from the configuration file */
#define IVI_ATTR_IO_RESOURCE_DESCRIPTOR /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 304)  /* the string that describes how to find the physical instrument; from the configuration file */
#define IVI_ATTR_LOGICAL_NAME           /* ViString, not writable*/     (IVI_ENGINE_PUBLIC_ATTR_BASE + 305)  /* for class drivers, the logical name used in the Init call to identify the specific instrument */
#define IVI_ATTR_VISA_RM_SESSION        /* ViSession,hidden      */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 321)   
#define IVI_ATTR_IO_SESSION             /* ViSession,not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 322)     
#define IVI_ATTR_IO_SESSION_TYPE        /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 324)
#define IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS   /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 327)

#define IVI_ATTR_GROUP_CAPABILITIES     /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 401)    
#define IVI_ATTR_FUNCTION_CAPABILITIES  /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 402)    
    
#define IVI_ATTR_ENGINE_MAJOR_VERSION       /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 501)   
#define IVI_ATTR_ENGINE_MINOR_VERSION       /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 502)   
#define IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 503)   
#define IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 504)   
#define IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 505)   
#define IVI_ATTR_CLASS_DRIVER_MINOR_VERSION /* ViInt32,  not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 506)   

#define IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 510)
#define IVI_ATTR_INSTRUMENT_MANUFACTURER    /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 511)
#define IVI_ATTR_INSTRUMENT_MODEL           /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 512)
#define IVI_ATTR_SPECIFIC_DRIVER_VENDOR     /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 513)
#define IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION/* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 514)
#define IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 515)
#define IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 516)
#define IVI_ATTR_CLASS_DRIVER_VENDOR        /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 517)
#define IVI_ATTR_CLASS_DRIVER_DESCRIPTION   /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 518)
#define IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 519)
#define IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 520)

#define IVI_ATTR_SPECIFIC_DRIVER_REVISION   /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 551)    
#define IVI_ATTR_CLASS_DRIVER_REVISION      /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 552)   
#define IVI_ATTR_ENGINE_REVISION            /* ViString, not user-writable*/(IVI_ENGINE_PUBLIC_ATTR_BASE + 553)    

#define IVI_ATTR_OPC_CALLBACK               /* ViAddr,    hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 602)  /* see Ivi_OPCCallbackPtr  typedef */
#define IVI_ATTR_CHECK_STATUS_CALLBACK      /* ViAddr,    hidden */     (IVI_ENGINE_PUBLIC_ATTR_BASE + 603)  /* see Ivi_CheckStatusCallbackPtr  typedef */  

#define IVI_ATTR_USER_INTERCHANGE_CHECK_CALLBACK /* ViAddr, hidden */   (IVI_ENGINE_PUBLIC_ATTR_BASE + 801)  /* see Ivi_InterchangeCheckCallbackPtr typedef */










/******************************************************************************
 *---------------------- IviFgen Class Attribute Defines ---------------------*
 ******************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVIFGEN_ATTR_CACHE                     IVI_ATTR_CACHE                       /* ViBoolean */
#define IVIFGEN_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVIFGEN_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS		/* ViBoolean */
#define IVIFGEN_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVIFGEN_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVIFGEN_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVIFGEN_ATTR_SPY                       IVI_ATTR_SPY                         /* ViBoolean */
#define IVIFGEN_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIFGEN_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVIFGEN_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/
#define IVIFGEN_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX         /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR         /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION    /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     /* ViString, read-only */
#define IVIFGEN_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      /* ViString, read-only */
#define IVIFGEN_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIFGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVIFGEN_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVIFGEN_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVIFGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

        /*- Version Information -*/
#define IVIFGEN_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION              /* ViString, read-only */

#define IVIFGEN_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION             /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVIFGEN_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                /* ViString */

    /*- IviFgen Fundamental Attributes -*/
#define IVIFGEN_ATTR_CHANNEL_COUNT              IVI_ATTR_CHANNEL_COUNT              /* (ViInt32), read-only */
#define IVIFGEN_ATTR_OUTPUT_MODE                (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)   /* (ViInt32) */
#define IVIFGEN_ATTR_REF_CLOCK_SOURCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)   /* (ViInt32) */
#define IVIFGEN_ATTR_OUTPUT_ENABLED             (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)   /* (ViBoolean,  Multi-Channel) */
#define IVIFGEN_ATTR_OUTPUT_IMPEDANCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)   /* (ViReal64,   Multi-Channel) */
#define IVIFGEN_ATTR_OPERATION_MODE             (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)   /* (ViInt32,    Multi-Channel) */

    /*- IviFgenStdFunc Extended Attributes -*/
#define IVIFGEN_ATTR_FUNC_WAVEFORM              (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)  /* (ViInt32,  Multi-Channel)   */
#define IVIFGEN_ATTR_FUNC_AMPLITUDE             (IVI_CLASS_PUBLIC_ATTR_BASE + 102L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_DC_OFFSET             (IVI_CLASS_PUBLIC_ATTR_BASE + 103L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_FREQUENCY             (IVI_CLASS_PUBLIC_ATTR_BASE + 104L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_START_PHASE           (IVI_CLASS_PUBLIC_ATTR_BASE + 105L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH       (IVI_CLASS_PUBLIC_ATTR_BASE + 106L)  /* (ViReal64,  Multi-Channel)  */

    /*- IviFgenArbWfm Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_WAVEFORM_HANDLE        (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* (ViInt32,  Multi-Channel)   */
#define IVIFGEN_ATTR_ARB_GAIN                   (IVI_CLASS_PUBLIC_ATTR_BASE + 202L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ARB_OFFSET                 (IVI_CLASS_PUBLIC_ATTR_BASE + 203L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ARB_SAMPLE_RATE            (IVI_CLASS_PUBLIC_ATTR_BASE + 204L)  /* (ViReal64)  */

#define IVIFGEN_ATTR_MAX_NUM_WAVEFORMS          (IVI_CLASS_PUBLIC_ATTR_BASE + 205L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_WAVEFORM_QUANTUM           (IVI_CLASS_PUBLIC_ATTR_BASE + 206L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MIN_WAVEFORM_SIZE          (IVI_CLASS_PUBLIC_ATTR_BASE + 207L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_WAVEFORM_SIZE          (IVI_CLASS_PUBLIC_ATTR_BASE + 208L)  /* (ViInt32, Read-only)   */

    /*- IviFgenArbFrequency Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_FREQUENCY              (IVI_CLASS_PUBLIC_ATTR_BASE + 209L)  /* (ViReal64, Multi-Channel)  */    

    /*- IviFgenArbSeq Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_SEQUENCE_HANDLE        (IVI_CLASS_PUBLIC_ATTR_BASE + 211L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_MAX_NUM_SEQUENCES          (IVI_CLASS_PUBLIC_ATTR_BASE + 212L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MIN_SEQUENCE_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE + 213L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_SEQUENCE_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE + 214L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_LOOP_COUNT             (IVI_CLASS_PUBLIC_ATTR_BASE + 215L)  /* (ViInt32, Read-only)   */

    /*- IviFgenTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_TRIGGER_SOURCE             (IVI_CLASS_PUBLIC_ATTR_BASE + 302L)  /* (ViInt32, Multi-Channel)   */

    /*- IviFgenInternalTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_INTERNAL_TRIGGER_RATE      (IVI_CLASS_PUBLIC_ATTR_BASE + 310L)  /* (ViReal64)   */  

    /*- IviFgenBurst Extended Attributes -*/
#define IVIFGEN_ATTR_BURST_COUNT                (IVI_CLASS_PUBLIC_ATTR_BASE + 350L)  /* (ViInt32, Multi-Channel)   */  

    /*- IviFgenModulateAM Extended Attributes -*/
#define IVIFGEN_ATTR_AM_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 401L)  /* (ViBoolean, Multi-Channel) */
#define IVIFGEN_ATTR_AM_SOURCE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 402L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_AM_INTERNAL_DEPTH          (IVI_CLASS_PUBLIC_ATTR_BASE + 403L)  /* (ViReal64)  */
#define IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM       (IVI_CLASS_PUBLIC_ATTR_BASE + 404L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_AM_INTERNAL_FREQUENCY      (IVI_CLASS_PUBLIC_ATTR_BASE + 405L)  /* (ViReal64)  */

    /*- IviFgenModulateFM Extended Attributes -*/
#define IVIFGEN_ATTR_FM_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 501L)  /* (ViBoolean, Multi-Channel) */
#define IVIFGEN_ATTR_FM_SOURCE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 502L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_FM_INTERNAL_DEVIATION      (IVI_CLASS_PUBLIC_ATTR_BASE + 503L)  /* (ViReal64)  */
#define IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM       (IVI_CLASS_PUBLIC_ATTR_BASE + 504L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_FM_INTERNAL_FREQUENCY      (IVI_CLASS_PUBLIC_ATTR_BASE + 505L)  /* (ViReal64)  */
      
/******************************************************************************
 *------------------- IviFgen Class Attribute Value Defines ------------------*
 ******************************************************************************/

   /*- Defined valued for attribute IVIFGEN_ATTR_OUTPUT_MODE -*/
#define IVIFGEN_VAL_OUTPUT_FUNC                         (0L)
#define IVIFGEN_VAL_OUTPUT_ARB                          (1L)
#define IVIFGEN_VAL_OUTPUT_SEQ                          (2L)

#define IVIFGEN_VAL_OUT_MODE_CLASS_EXT_BASE             (500L)
#define IVIFGEN_VAL_OUT_MODE_SPECIFIC_EXT_BASE          (1000L)

   /*- Defined valued for attribute IVIFGEN_ATTR_OPERATION_MODE -*/
#define IVIFGEN_VAL_OPERATE_CONTINUOUS                  (0L)
#define IVIFGEN_VAL_OPERATE_BURST                       (1L)

#define IVIFGEN_VAL_OP_MODE_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_OP_MODE_SPECIFIC_EXT_BASE           (1000L)

   /*- Defined values for attribute IVIFGEN_ATTR_REF_CLOCK_SOURCE -*/
#define IVIFGEN_VAL_REF_CLOCK_INTERNAL                  (0L)
#define IVIFGEN_VAL_REF_CLOCK_EXTERNAL                  (1L)
#define IVIFGEN_VAL_REF_CLOCK_RTSI_CLOCK                (101L)

#define IVIFGEN_VAL_CLK_SRC_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_CLK_SRC_SPECIFIC_EXT_BASE           (1000L)

   /*- Defined values for attribute IVIFGEN_ATTR_FUNC_WAVEFORM -*/
#define IVIFGEN_VAL_WFM_SINE                            (1L)
#define IVIFGEN_VAL_WFM_SQUARE                          (2L)
#define IVIFGEN_VAL_WFM_TRIANGLE                        (3L)
#define IVIFGEN_VAL_WFM_RAMP_UP                         (4L)
#define IVIFGEN_VAL_WFM_RAMP_DOWN                       (5L)
#define IVIFGEN_VAL_WFM_DC                              (6L)

#define IVIFGEN_VAL_WFM_CLASS_EXT_BASE                  (500L)
#define IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE               (1000L)

    /*- Defined values for attribute IVIFGEN_ATTR_TRIGGER_SOURCE -*/
#define IVIFGEN_VAL_EXTERNAL                            (1L)
#define IVIFGEN_VAL_SOFTWARE_TRIG                       (2L)
#define IVIFGEN_VAL_INTERNAL_TRIGGER                    (3L) 
#define IVIFGEN_VAL_TTL0                                (111L)
#define IVIFGEN_VAL_TTL1                                (112L)
#define IVIFGEN_VAL_TTL2                                (113L)
#define IVIFGEN_VAL_TTL3                                (114L)
#define IVIFGEN_VAL_TTL4                                (115L)
#define IVIFGEN_VAL_TTL5                                (116L)
#define IVIFGEN_VAL_TTL6                                (117L)
#define IVIFGEN_VAL_TTL7                                (118L)
#define IVIFGEN_VAL_ECL0                                (119L)
#define IVIFGEN_VAL_ECL1                                (120L)
#define IVIFGEN_VAL_PXI_STAR                            (131L)
#define IVIFGEN_VAL_RTSI_0                              (141L)
#define IVIFGEN_VAL_RTSI_1                              (142L)
#define IVIFGEN_VAL_RTSI_2                              (143L)
#define IVIFGEN_VAL_RTSI_3                              (144L)
#define IVIFGEN_VAL_RTSI_4                              (145L)
#define IVIFGEN_VAL_RTSI_5                              (146L)
#define IVIFGEN_VAL_RTSI_6                              (147L)

#define IVIFGEN_VAL_TRIG_SRC_CLASS_EXT_BASE             (500L)
#define IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE          (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_AM_SOURCE -*/
#define IVIFGEN_VAL_AM_INTERNAL                         (0L)
#define IVIFGEN_VAL_AM_EXTERNAL                         (1L)

#define IVIFGEN_VAL_AM_SOURCE_CLASS_EXT_BASE            (500L)
#define IVIFGEN_VAL_AM_SOURCE_SPECIFIC_EXT_BASE         (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_AM_INTERNAL_SINE                    (1L)
#define IVIFGEN_VAL_AM_INTERNAL_SQUARE                  (2L)
#define IVIFGEN_VAL_AM_INTERNAL_TRIANGLE                (3L)
#define IVIFGEN_VAL_AM_INTERNAL_RAMP_UP                 (4L)
#define IVIFGEN_VAL_AM_INTERNAL_RAMP_DOWN               (5L)

#define IVIFGEN_VAL_AM_INTERNAL_WFM_CLASS_EXT_BASE      (500L)
#define IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE   (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_FM_SOURCE -*/
#define IVIFGEN_VAL_FM_INTERNAL                         (0L)
#define IVIFGEN_VAL_FM_EXTERNAL                         (1L)

#define IVIFGEN_VAL_FM_SOURCE_CLASS_EXT_BASE            (500L)
#define IVIFGEN_VAL_FM_SOURCE_SPECIFIC_EXT_BASE         (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_FM_INTERNAL_SINE                    (1L)
#define IVIFGEN_VAL_FM_INTERNAL_SQUARE                  (2L)
#define IVIFGEN_VAL_FM_INTERNAL_TRIANGLE                (3L)
#define IVIFGEN_VAL_FM_INTERNAL_RAMP_UP                 (4L)
#define IVIFGEN_VAL_FM_INTERNAL_RAMP_DOWN               (5L)

#define IVIFGEN_VAL_FM_INTERNAL_WFM_CLASS_EXT_BASE      (500L)
#define IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE   (1000L)

   /*- Defined values for waveformHandle parameter for function IviFgen_ClearArbWaveform -*/
#define IVIFGEN_VAL_ALL_WAVEFORMS                       (-1L)

   /*- Defined values for sequenceHandle parameter for function IviFgen_ClearArbSequence -*/
#define IVIFGEN_VAL_ALL_SEQUENCES                       (-1L)









/**************************************************************************** 
 *---------------------------- Attribute Defines ---------------------------* 
 ****************************************************************************/

/*--------------- Output Attributes ----------------------------------------*/

#define NIFGEN_ATTR_OUTPUT_MODE                              IVIFGEN_ATTR_OUTPUT_MODE              /* ViInt32   */              
#define NIFGEN_ATTR_OUTPUT_ENABLED                           IVIFGEN_ATTR_OUTPUT_ENABLED           /* ViBoolean, multi-channel */  
#define NIFGEN_ATTR_DIGITAL_GAIN                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 254L) /* ViReal64  */ 
#define NIFGEN_ATTR_ANALOG_PATH                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 222L) /* ViInt32   */ 
#define NIFGEN_ATTR_LOAD_IMPEDANCE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 220L) /* ViReal64  */ 
#define NIFGEN_ATTR_OUTPUT_IMPEDANCE                         IVIFGEN_ATTR_OUTPUT_IMPEDANCE         /* ViReal64,  multi-channel, ohms */  
#define NIFGEN_ATTR_TERMINAL_CONFIGURATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 365L) /* ViInt32   */ 
#define NIFGEN_ATTR_COMMON_MODE_OFFSET                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 366L) /* ViReal64  */ 
#define NIFGEN_ATTR_CHANNEL_DELAY                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 369L) /* ViReal64  */ 

/*- Filter -----------------------------------------------------------------*/
#define NIFGEN_ATTR_ANALOG_FILTER_ENABLED                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103L) /* ViBoolean */ 
#define NIFGEN_ATTR_DIGITAL_FILTER_ENABLED                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102L) /* ViBoolean */ 
#define NIFGEN_ATTR_DIGITAL_FILTER_INTERPOLATION_FACTOR     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 218L) /* ViReal64  */ 
#define NIFGEN_ATTR_FLATNESS_CORRECTION_ENABLED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 323L) /* ViBoolean */ 

/*- Data Mask --------------------------------------------------------------*/
#define NIFGEN_ATTR_ANALOG_DATA_MASK                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 234L) /* ViInt32 */ 
#define NIFGEN_ATTR_ANALOG_STATIC_VALUE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 235L) /* ViInt32 */ 
#define NIFGEN_ATTR_DIGITAL_DATA_MASK                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 236L) /* ViInt32 */ 
#define NIFGEN_ATTR_DIGITAL_STATIC_VALUE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 237L) /* ViInt32 */ 

/*- Advanced Output Attributes ---------------------------------------------*/
#define NIFGEN_ATTR_DIGITAL_PATTERN_ENABLED                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L) /* ViBoolean */ 
#define NIFGEN_ATTR_IDLE_BEHAVIOR                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 377L) /* ViInt32 */ 
#define NIFGEN_ATTR_IDLE_VALUE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 378L) /* ViInt32 */ 
#define NIFGEN_ATTR_WAIT_BEHAVIOR                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 379L) /* ViInt32 */ 
#define NIFGEN_ATTR_WAIT_VALUE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 380L) /* ViInt32 */ 


/*----------------------------- Arbitrary Waveform -------------------------*/

#define NIFGEN_ATTR_ARB_GAIN                                 IVIFGEN_ATTR_ARB_GAIN                 /* ViReal64, multi-channel        */ 
#define NIFGEN_ATTR_ARB_OFFSET                               IVIFGEN_ATTR_ARB_OFFSET               /* ViReal64, multi-channel, volts */ 
#define NIFGEN_ATTR_WAVEFORM_QUANTUM                         IVIFGEN_ATTR_WAVEFORM_QUANTUM         /* ViInt32,  read-only, samples   */ 
#define NIFGEN_ATTR_MAX_NUM_WAVEFORMS                        IVIFGEN_ATTR_MAX_NUM_WAVEFORMS        /* ViInt32,  read-only            */ 
#define NIFGEN_ATTR_MIN_WAVEFORM_SIZE                        IVIFGEN_ATTR_MIN_WAVEFORM_SIZE        /* ViInt32,  read-only, samples   */ 
#define NIFGEN_ATTR_MAX_WAVEFORM_SIZE                        IVIFGEN_ATTR_MAX_WAVEFORM_SIZE        /* ViInt32,  read-only, samples   */ 

/*- Arbitrary Waveform Generation ------------------------------------------*/
#define NIFGEN_ATTR_ARB_WAVEFORM_HANDLE                      IVIFGEN_ATTR_ARB_WAVEFORM_HANDLE  /* ViInt32,  multi-channel        */ 
#define NIFGEN_ATTR_ARB_MARKER_POSITION                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 327L) /* ViInt32,  readwrite, samples   */ 
#define NIFGEN_ATTR_ARB_REPEAT_COUNT                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 328L) /* ViInt32,  readwrite            */ 

/*- Arbitrary Sequence Generation ------------------------------------------*/
#define NIFGEN_ATTR_ARB_SEQUENCE_HANDLE                      IVIFGEN_ATTR_ARB_SEQUENCE_HANDLE /* ViInt32,  multi-channel        */
#define NIFGEN_ATTR_MAX_NUM_SEQUENCES                        IVIFGEN_ATTR_MAX_NUM_SEQUENCES   /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MIN_SEQUENCE_LENGTH                      IVIFGEN_ATTR_MIN_SEQUENCE_LENGTH /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MAX_SEQUENCE_LENGTH                      IVIFGEN_ATTR_MAX_SEQUENCE_LENGTH /* ViInt32,  read-only            */
#define NIFGEN_ATTR_MAX_LOOP_COUNT                           IVIFGEN_ATTR_MAX_LOOP_COUNT      /* ViInt32,  read-only            */

/*- Script Generation ------------------------------------------------------*/
#define NIFGEN_ATTR_SCRIPT_TO_GENERATE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 270L)  /* ViString */   

/*- Data Transfer ----------------------------------------------------------*/
#define NIFGEN_ATTR_FILE_TRANSFER_BLOCK_SIZE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 240L)  /* ViInt32, samples */ 
#define NIFGEN_ATTR_DATA_TRANSFER_BLOCK_SIZE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 241L)  /* ViInt32, samples */ 
#define NIFGEN_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 373L)  /* ViReal64 */ 
/*- Direct DMA -------------------------------------------------------------*/
#define NIFGEN_ATTR_DIRECT_DMA_ENABLED                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 244L)  /* ViBoolean */ 
#define NIFGEN_ATTR_DIRECT_DMA_WINDOW_SIZE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 245L)  /* ViInt32, bytes */ 
#define NIFGEN_ATTR_DIRECT_DMA_WINDOW_ADDRESS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 274L)  /* ViInt32 */ 
/*- Streaming --------------------------------------------------------------*/
#define NIFGEN_ATTR_STREAMING_WAVEFORM_NAME                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 326L)  /* ViString */                 
#define NIFGEN_ATTR_STREAMING_WAVEFORM_HANDLE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 324L)  /* ViInt32  */ 
#define NIFGEN_ATTR_STREAMING_SPACE_AVAILABLE_IN_WAVEFORM   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 325L)  /* ViInt32  */ 
/*- Advanced Data Transfer -------------------------------------------------*/
#define NIFGEN_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 374L)  /* ViInt32  */ 
#define NIFGEN_ATTR_DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 375L)  /* ViInt32  */ 
#define NIFGEN_ATTR_PCI_DMA_OPTIMIZATIONS_ENABLED           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 362L)  /* ViBoolean */  

/*- Onboard Signal Processing-------------------------------------------*/
#define NIFGEN_ATTR_OSP_ENABLED                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 246L) /* ViBoolean */  
#define NIFGEN_ATTR_OSP_IQ_RATE                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 248L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_DATA_PROCESSING_MODE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 247L) /* ViInt32   */  
#define NIFGEN_ATTR_OSP_MODE                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 370L) /* ViInt32   */  
#define NIFGEN_ATTR_OSP_FREQUENCY_SHIFT                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 371L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_CARRIER_ENABLED                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 249L) /* ViBoolean */  
#define NIFGEN_ATTR_OSP_CARRIER_FREQUENCY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 250L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_CARRIER_PHASE_I                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 251L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_CARRIER_PHASE_Q                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 252L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_COMPENSATE_FOR_FILTER_GROUP_DELAY   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 389L) /* ViBoolean  */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_TYPE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 253L) /* ViInt32   */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_ENABLED                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 255L) /* ViBoolean */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_INTERPOLATION            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 256L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_CIC_FILTER_ENABLED                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 257L) /* ViBoolean */  
#define NIFGEN_ATTR_OSP_CIC_FILTER_INTERPOLATION            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 258L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_ROOT_RAISED_COSINE_ALPHA (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 259L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_RAISED_COSINE_ALPHA      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 260L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_FLAT_PASSBAND            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 261L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_FIR_FILTER_GAUSSIAN_BT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 262L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_CIC_FILTER_GAIN                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 263L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_PRE_FILTER_GAIN_I                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 264L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_PRE_FILTER_GAIN_Q                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 265L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_PRE_FILTER_OFFSET_I                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 266L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_PRE_FILTER_OFFSET_Q                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 267L) /* ViReal64  */  
#define NIFGEN_ATTR_OSP_OVERFLOW_ERROR_REPORTING            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 268L) /* ViInt32   */  
#define NIFGEN_ATTR_OSP_OVERFLOW_STATUS                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 269L) /* ViInt32   */  


/*---------------------------- Standard Function --------------------------*/

#define NIFGEN_ATTR_FUNC_WAVEFORM                            IVIFGEN_ATTR_FUNC_WAVEFORM            /* ViInt32,  multi-channel        */ 
#define NIFGEN_ATTR_FUNC_AMPLITUDE                           IVIFGEN_ATTR_FUNC_AMPLITUDE           /* ViReal64, multi-channel, volts */ 
#define NIFGEN_ATTR_FUNC_DC_OFFSET                           IVIFGEN_ATTR_FUNC_DC_OFFSET           /* ViReal64, multi-channel, volts */ 
#define NIFGEN_ATTR_FUNC_START_PHASE                         IVIFGEN_ATTR_FUNC_START_PHASE         /* ViReal64, multi-channel, deg   */ 
#define NIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH                     IVIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH     /* ViReal64, multi-channel, pct   */ 
#define NIFGEN_ATTR_SYNC_DUTY_CYCLE_HIGH                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105L) /* ViReal64 */ 
#define NIFGEN_ATTR_SYNC_OUT_OUTPUT_TERMINAL                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 330L) /* ViString */                 

/*- Standard Waveform Generation -------------------------------------------*/
#define NIFGEN_ATTR_FUNC_FREQUENCY                           IVIFGEN_ATTR_FUNC_FREQUENCY           /* ViReal64, multi-channel, hertz */ 
#define NIFGEN_ATTR_FUNC_BUFFER_SIZE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 238L) /* ViInt32,  read-only, samples   */ 
#define NIFGEN_ATTR_FUNC_MAX_BUFFER_SIZE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 239L) /* ViInt32,  multi-channel        */ 

/*- Frequency List Generation ------------------------------------------*/
#define NIFGEN_ATTR_FREQ_LIST_HANDLE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 208L) /* ViInt32,  multi-channel */ 
#define NIFGEN_ATTR_MAX_NUM_FREQ_LISTS                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 209L) /* ViInt32,  read-only     */ 
#define NIFGEN_ATTR_MIN_FREQ_LIST_LENGTH                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 210L) /* ViInt32,  read-only     */ 
#define NIFGEN_ATTR_MAX_FREQ_LIST_LENGTH                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 211L) /* ViInt32,  read-only     */ 
#define NIFGEN_ATTR_MIN_FREQ_LIST_DURATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 212L) /* ViReal64, read-only     */ 
#define NIFGEN_ATTR_MAX_FREQ_LIST_DURATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 213L) /* ViReal64, read-only     */ 
#define NIFGEN_ATTR_FREQ_LIST_DURATION_QUANTUM              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 214L) /* ViReal64, read-only     */ 


/*-------------------------------- Clocks ----------------------------------*/

/*- Reference Clock --------------------------------------------------------*/
#define NIFGEN_ATTR_REFERENCE_CLOCK_SOURCE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 113L) /* ViString */ 
#define NIFGEN_ATTR_REF_CLOCK_FREQUENCY                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L) /* ViReal64 */
#define NIFGEN_ATTR_EXPORTED_REFERENCE_CLOCK_OUTPUT_TERMINAL         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_ONBOARD_REFERENCE_CLOCK_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L) /* ViString */

/*- Sample Clock -----------------------------------------------------------*/
#define NIFGEN_ATTR_ARB_SAMPLE_RATE                                 IVIFGEN_ATTR_ARB_SAMPLE_RATE          /* ViReal64, samples-per-second */
#define NIFGEN_ATTR_CLOCK_MODE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110L) /* ViInt32 */
#define NIFGEN_ATTR_SAMPLE_CLOCK_SOURCE                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 320L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_DIVISOR                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 219L) /* ViInt32  */

/*- Sample Clock Timebase --------------------------------------------------*/
#define NIFGEN_ATTR_SAMPLE_CLOCK_TIMEBASE_SOURCE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 367L) /* ViString */
#define NIFGEN_ATTR_SAMPLE_CLOCK_TIMEBASE_RATE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 368L) /* ViReal64 */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_TIMEBASE_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 329L) /* ViString */
#define NIFGEN_ATTR_EXPORTED_SAMPLE_CLOCK_TIMEBASE_DIVISOR         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 230L) /* ViInt32  */

/*- Advanced Clock Attributes ----------------------------------------------*/
#define NIFGEN_ATTR_EXTERNAL_SAMPLE_CLOCK_MULTIPLIER           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 376L)   /* ViReal64 */
#define NIFGEN_ATTR_SAMPLE_CLOCK_ABSOLUTE_DELAY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 231L)   /* ViReal64 */
#define NIFGEN_ATTR_OSCILLATOR_PHASE_DAC_VALUE                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 232L) /* ViInt32  */
#define NIFGEN_ATTR_EXTERNAL_CLOCK_DELAY_BINARY_VALUE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 233L) /* ViInt32  */


/*--------------------------  Events  --------------------------------------*/

/*- Marker Event -------------------------------------------------------*/
#define NIFGEN_ATTR_MARKER_EVENT_OUTPUT_TERMINAL               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 312L)   /* ViString  */
#define NIFGEN_ATTR_MARKER_EVENT_OUTPUT_BEHAVIOR               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 342L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_PULSE_POLARITY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 313L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_PULSE_WIDTH                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 340L)   /* ViReal64  */
#define NIFGEN_ATTR_MARKER_EVENT_PULSE_WIDTH_UNITS             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 341L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_TOGGLE_INITIAL_STATE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 343L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_DELAY                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 354L)   /* ViReal64  */
#define NIFGEN_ATTR_MARKER_EVENT_DELAY_UNITS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 355L)   /* ViInt32   */
#define NIFGEN_ATTR_ALL_MARKER_EVENTS_LIVE_STATUS              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 344L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_LIVE_STATUS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 345L)   /* ViBoolean */
#define NIFGEN_ATTR_ALL_MARKER_EVENTS_LATCHED_STATUS           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 349L)   /* ViInt32   */
#define NIFGEN_ATTR_MARKER_EVENT_LATCHED_STATUS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 350L)   /* ViBoolean */

/*- Data Marker Event --------------------------------------------------*/
#define NIFGEN_ATTR_DATA_MARKER_EVENT_DATA_BIT_NUMBER          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 337L)   /* ViInt32  */
#define NIFGEN_ATTR_DATA_MARKER_EVENT_LEVEL_POLARITY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 338L)   /* ViInt32  */
#define NIFGEN_ATTR_DATA_MARKER_EVENT_OUTPUT_TERMINAL          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 339L)   /* ViString */

/*- Ready For Start Event ----------------------------------------------*/
#define NIFGEN_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 310L)   /* ViString  */
#define NIFGEN_ATTR_READY_FOR_START_EVENT_LEVEL_ACTIVE_LEVEL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 311L)   /* ViInt32   */
#define NIFGEN_ATTR_READY_FOR_START_EVENT_LIVE_STATUS          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 348L)   /* ViBoolean */

/*- Started Event ------------------------------------------------------*/
#define NIFGEN_ATTR_STARTED_EVENT_OUTPUT_TERMINAL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 314L) /* ViString */
#define NIFGEN_ATTR_STARTED_EVENT_OUTPUT_BEHAVIOR              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 331L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_LEVEL_ACTIVE_LEVEL           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 316L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_PULSE_POLARITY               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 318L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_PULSE_WIDTH_UNITS            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 333L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_PULSE_WIDTH                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 335L) /* ViReal64 */
#define NIFGEN_ATTR_STARTED_EVENT_DELAY                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 356L) /* ViReal64 */
#define NIFGEN_ATTR_STARTED_EVENT_DELAY_UNITS                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 357L) /* ViInt32  */
#define NIFGEN_ATTR_STARTED_EVENT_LATCHED_STATUS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 352L) /* ViBoolean */

/*- Done Event ---------------------------------------------------------*/
#define NIFGEN_ATTR_DONE_EVENT_OUTPUT_TERMINAL                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 315L) /* ViString */
#define NIFGEN_ATTR_DONE_EVENT_OUTPUT_BEHAVIOR                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 332L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_LEVEL_ACTIVE_LEVEL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 317L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_PULSE_POLARITY                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 319L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_PULSE_WIDTH_UNITS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 334L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_PULSE_WIDTH                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 336L) /* ViReal64 */
#define NIFGEN_ATTR_DONE_EVENT_DELAY                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 358L) /* ViReal64 */
#define NIFGEN_ATTR_DONE_EVENT_DELAY_UNITS                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 359L) /* ViInt32  */
#define NIFGEN_ATTR_DONE_EVENT_LATCHED_STATUS                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 351L) /* ViBoolean */


/*----------------------- Triggers -------------------------------------*/

#define NIFGEN_ATTR_TRIGGER_MODE                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 108L) /* ViInt32 */
#define NIFGEN_ATTR_BURST_COUNT                                 IVIFGEN_ATTR_BURST_COUNT              /* ViInt32, multi-channel */

/*- Start Trigger ------------------------------------------------------*/
#define NIFGEN_ATTR_START_TRIGGER_TYPE                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 280L) /* ViInt32  */
#define NIFGEN_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 281L) /* ViString */
#define NIFGEN_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 282L) /* ViInt32  */
#define NIFGEN_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 283L) /* ViString */

/*- Script Trigger -----------------------------------------------------*/
#define NIFGEN_ATTR_SCRIPT_TRIGGER_TYPE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 290L) /* ViInt32  */
#define NIFGEN_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 291L) /* ViString */
#define NIFGEN_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 292L) /* ViInt32  */
#define NIFGEN_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 293L) /* ViString */
#define NIFGEN_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_ACTIVE_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 294L) /* ViInt32  */
#define NIFGEN_ATTR_EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 295L) /* ViString */

/*------------------ Instrument Specific Attributes --------------------*/

#define NIFGEN_ATTR_BUS_TYPE                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 215L) /* ViInt32,  read-only */
#define NIFGEN_ATTR_MEMORY_SIZE                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 242L) /* ViInt32,  read-only, bytes */
#define NIFGEN_ATTR_SERIAL_NUMBER                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 243L) /* ViString, read-only */
#define NIFGEN_ATTR_MARKER_EVENTS_COUNT                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 271L) /* ViInt32,  Read-only */
#define NIFGEN_ATTR_DATA_MARKER_EVENTS_COUNT                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 273L) /* ViInt32,  Read-only */
#define NIFGEN_ATTR_SCRIPT_TRIGGERS_COUNT                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 272L) /* ViInt32,  Read-only */
#define NIFGEN_ATTR_VIDEO_WAVEFORM_TYPE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 216L) /* ViInt32             */

/*- 5401/5411/5431 Attributes -------------------------------------------*/
#define NIFGEN_ATTR_FILTER_CORRECTION_FREQUENCY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104L) /* ViReal64                */
#define NIFGEN_ATTR_TRIGGER_SOURCE                              IVIFGEN_ATTR_TRIGGER_SOURCE           /* ViInt32, multi-channel */
#define NIFGEN_ATTR_SYNCHRONIZATION                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111L) /* ViInt32,  multi-channel */
#define NIFGEN_ATTR_ID_QUERY_RESPONSE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)   /* ViString, read-only     */

/*-------------------- Calibration --------------------------------------*/
#define NIFGEN_ATTR_GAIN_DAC_VALUE                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 223L) /* ViInt32  */
#define NIFGEN_ATTR_OFFSET_DAC_VALUE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 224L) /* ViInt32  */
#define NIFGEN_ATTR_OSCILLATOR_FREQ_DAC_VALUE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 225L) /* ViInt32  */
#define NIFGEN_ATTR_CAL_ADC_INPUT                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 227L) /* ViInt32  */
#define NIFGEN_ATTR_PRE_AMPLIFIER_ATTENUATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 228L) /* ViReal64 */ 
#define NIFGEN_ATTR_POST_AMPLIFIER_ATTENUATION                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 229L) /* ViReal64 */

/*-------------- IVI Inherent Attributes -----------------------------------*/    
/*- User Options */
#define NIFGEN_ATTR_CACHE                                     IVI_ATTR_CACHE                   /* ViBoolean */                   
#define NIFGEN_ATTR_RANGE_CHECK                               IVI_ATTR_RANGE_CHECK             /* ViBoolean */ 
#define NIFGEN_ATTR_QUERY_INSTRUMENT_STATUS                   IVI_ATTR_QUERY_INSTRUMENT_STATUS /* ViBoolean */     
#define NIFGEN_ATTR_RECORD_COERCIONS                          IVI_ATTR_RECORD_COERCIONS        /* ViBoolean */ 
#define NIFGEN_ATTR_SIMULATE                                  IVI_ATTR_SIMULATE                /* ViBoolean */ 
#define NIFGEN_ATTR_INTERCHANGE_CHECK                         IVI_ATTR_INTERCHANGE_CHECK       /* ViBoolean */ 
/*- Driver Information, Read-only ------------------------------------------*/
#define NIFGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION               IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString */ 
#define NIFGEN_ATTR_SPECIFIC_DRIVER_PREFIX                    IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString */ 
#define NIFGEN_ATTR_SPECIFIC_DRIVER_VENDOR                    IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString */ 
#define NIFGEN_ATTR_SPECIFIC_DRIVER_REVISION                  IVI_ATTR_SPECIFIC_DRIVER_REVISION                 /* ViString */ 
#define NIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32  */ 
#define NIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32  */ 
/*- Driver Capabilities, Read-only -----------------------------------------*/
#define NIFGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS              IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS /* ViString */
#define NIFGEN_ATTR_GROUP_CAPABILITIES                       IVI_ATTR_GROUP_CAPABILITIES          /* ViString */
#define NIFGEN_ATTR_CHANNEL_COUNT				                IVI_ATTR_CHANNEL_COUNT               /* ViInt32,  Read-only  */
/*- Instrument Information, Read-only --------------------------------------*/
#define NIFGEN_ATTR_INSTRUMENT_MANUFACTURER                  IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString */ 
#define NIFGEN_ATTR_INSTRUMENT_MODEL                         IVI_ATTR_INSTRUMENT_MODEL             /* ViString */ 
#define NIFGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION             IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString */ 
#define NIFGEN_ATTR_MODULE_REVISION                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 390L)/* ViString */ 
/*- Advanced Session Information, read-only --------------------------------*/                                     
#define NIFGEN_ATTR_IO_RESOURCE_DESCRIPTOR                   IVI_ATTR_IO_RESOURCE_DESCRIPTOR /* ViString */ 
#define NIFGEN_ATTR_LOGICAL_NAME                             IVI_ATTR_LOGICAL_NAME           /* ViString */ 
#define NIFGEN_ATTR_DRIVER_SETUP                             IVI_ATTR_DRIVER_SETUP           /* ViString */ 


/**************************************************************************** 
 *------------------------ Attribute Value Defines -------------------------* 
 ****************************************************************************/

#define NIFGEN_VAL_TRIG_SRC_RANGE               (200L)
#define NIFGEN_VAL_CLK_SRC_BASE                 (IVIFGEN_VAL_CLK_SRC_SPECIFIC_EXT_BASE + NIFGEN_VAL_TRIG_SRC_RANGE)

/*- Defined value for NIFGEN_ATTR_OPERATION_MODE -----------------------*/
#define NIFGEN_VAL_OPERATE_CONTINUOUS           IVIFGEN_VAL_OPERATE_CONTINUOUS

/*- Defined values for attribute NIFGEN_ATTR_OUTPUT_MODE ---------------*/
#define NIFGEN_VAL_OUTPUT_FUNC                  IVIFGEN_VAL_OUTPUT_FUNC
#define NIFGEN_VAL_OUTPUT_ARB                   IVIFGEN_VAL_OUTPUT_ARB
#define NIFGEN_VAL_OUTPUT_SEQ                   IVIFGEN_VAL_OUTPUT_SEQ
#define NIFGEN_VAL_OUTPUT_FREQ_LIST             (101L)
#define NIFGEN_VAL_OUTPUT_SCRIPT                (102L)
    
/*- Defined values for attribute NIFGEN_ATTR_OUTPUT_IMPEDANCE ----------*/
#define NIFGEN_VAL_50_OHMS                      50.0
#define NIFGEN_VAL_75_OHMS                      75.0

/*- Defined values for attribute NIFGEN_ATTR_LOAD_IMPEDANCE ----------*/
#define NIFGEN_VAL_MATCHED_LOAD_IMPEDANCE       -1.0

/*- Defined values for attribute NIFGEN_ATTR_FUNC_WAVEFORM -------------*/
#define NIFGEN_VAL_WFM_SINE                     IVIFGEN_VAL_WFM_SINE     
#define NIFGEN_VAL_WFM_SQUARE                   IVIFGEN_VAL_WFM_SQUARE   
#define NIFGEN_VAL_WFM_TRIANGLE                 IVIFGEN_VAL_WFM_TRIANGLE 
#define NIFGEN_VAL_WFM_RAMP_UP                  IVIFGEN_VAL_WFM_RAMP_UP  
#define NIFGEN_VAL_WFM_RAMP_DOWN                IVIFGEN_VAL_WFM_RAMP_DOWN
#define NIFGEN_VAL_WFM_DC                       IVIFGEN_VAL_WFM_DC 
#define NIFGEN_VAL_WFM_NOISE                    (101L)
#define NIFGEN_VAL_WFM_USER                     (102L)
 
/*- Defined values for attribute NIFGEN_ATTR_ARB_WAVEFORM_HANDLE ---------*/
#define NIFGEN_VAL_FIRST_WAVEFORM_HANDLE        (10000L)
#define NIFGEN_VAL_LAST_WAVEFORM_HANDLE         (NIFGEN_VAL_FIRST_WAVEFORM_HANDLE + 999L)
#define NIFGEN_VAL_NO_WAVEFORM                  (-1L)

/*- Defined values for attribute NIFGEN_ATTR_ARB_SEQUENCE_HANDLE --------*/  
#define NIFGEN_VAL_FIRST_SEQUENCE_HANDLE        (100000L)
#define NIFGEN_VAL_LAST_SEQUENCE_HANDLE         (NIFGEN_VAL_FIRST_SEQUENCE_HANDLE + 9999L)
#define NIFGEN_VAL_NO_SEQUENCE                  (-1L)
 
/*- Defined values for attribute NIFGEN_ATTR_FREQ_LIST_HANDLE --------*/
#define NIFGEN_VAL_FIRST_FREQ_LIST_HANDLE       (200000L)
#define NIFGEN_VAL_LAST_FREQ_LIST_HANDLE        (NIFGEN_VAL_FIRST_FREQ_LIST_HANDLE + 9999L)
#define NIFGEN_VAL_NO_FREQ_LIST                 (-1L)

/*- Defined values for Arbitrary Waveform Handles ----------------------*/
#define NIFGEN_VAL_ALL_WAVEFORMS                IVIFGEN_VAL_ALL_WAVEFORMS
#define NIFGEN_VAL_ALL_SEQUENCES                IVIFGEN_VAL_ALL_SEQUENCES
#define NIFGEN_VAL_ALL_FLISTS                   (-1L)

/*- Defined values for atttribute NIFGEN_ATTR_BURST_COUNT ---------------*/
#define NIFGEN_VAL_GENERATE_CONTINUOUS          (-1L)

/*- Defined values for attribute NIFGEN_ATTR_TERMINAL_CONFIGURATION -----*/
#define NIFGEN_VAL_SINGLE_ENDED                 (300L)
#define NIFGEN_VAL_DIFFERENTIAL                 (301L)

/*- Defined values for Signal Values ---------------------------------*/
#define NIFGEN_VAL_MARKER_EVENT                                (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 1L)  /* ViInt32 */
#define NIFGEN_VAL_SYNC_OUT                                    (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 2L)  /* ViInt32 */
#define NIFGEN_VAL_ONBOARD_REFERENCE_CLOCK                     (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 19L) /* ViInt32 */
#define NIFGEN_VAL_START_TRIGGER                               (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 4L)  /* ViInt32 */
#define NIFGEN_VAL_SAMPLE_CLOCK_TIMEBASE                       (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 6L)
#define NIFGEN_VAL_SYNCHRONIZATION                             (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 7L)  /* ViInt32 */
#define NIFGEN_VAL_SAMPLE_CLOCK                                (101L)
#define NIFGEN_VAL_REFERENCE_CLOCK                             (102L)
#define NIFGEN_VAL_SCRIPT_TRIGGER                              (103L)
#define NIFGEN_VAL_READY_FOR_START_EVENT                       (105L)
#define NIFGEN_VAL_STARTED_EVENT                               (106L)
#define NIFGEN_VAL_DONE_EVENT                                  (107L)
#define NIFGEN_VAL_DATA_MARKER_EVENT                           (108L)

/*- Additional defined values for 5404 signal routing ----------------*/
#define NIFGEN_VAL_NONE                         (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 0L)
#define NIFGEN_VAL_MARKER                       (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 1L)
#define NIFGEN_VAL_OUT_START_TRIGGER            (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 4L)  
#define NIFGEN_VAL_BOARD_CLOCK                  (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 6L)  
#define NIFGEN_VAL_REF_OUT                      (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 8L)
#define NIFGEN_VAL_CLOCK_OUT                    (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 9L)
#define NIFGEN_VAL_RTSI_7                       (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 10L)
#define NIFGEN_VAL_PFI_0                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 11L)

/*- Defined values for Digital Edge ----------------------------------*/
#define NIFGEN_VAL_RISING_EDGE                                 (101L)
#define NIFGEN_VAL_FALLING_EDGE                                (102L)

/*- Defined values for Toggle ----------------------------------------*/
#define NIFGEN_VAL_HIGH                                        (101L)
#define NIFGEN_VAL_LOW                                         (102L)

/*- Defined values for Event polarity --------------------------------*/
#define NIFGEN_VAL_ACTIVE_HIGH                                 (101L)
#define NIFGEN_VAL_ACTIVE_LOW                                  (102L)

/*- Defined values for Output Behavior -------------------------------*/
#define NIFGEN_VAL_PULSE                                       (101L)
#define NIFGEN_VAL_LEVEL                                       (102L)
#define NIFGEN_VAL_TOGGLE                                      (103L)

/*- Defined values for Pulse Width & Delay ---------------------------*/
#define NIFGEN_VAL_SAMPLE_CLOCK_PERIODS                        (101L)
#define NIFGEN_VAL_SECONDS                                     (102L)

/*- Defined values for Triggers types --------------------------------*/
#define NIFGEN_VAL_TRIG_NONE                                   (101L)                                   /* ViInt32 */     
#define NIFGEN_VAL_DIGITAL_EDGE                                (102L)                                   /* ViInt32 */     
#define NIFGEN_VAL_DIGITAL_LEVEL                               (103L)                                   /* ViInt32 */     
#define NIFGEN_VAL_SOFTWARE_EDGE                               (104L)                                   /* ViInt32 */
#define NIFGEN_VAL_SOFTWARE_LEVEL                              (105L)                                   /* ViInt32 */

/*- Defined values for attribute NIFGEN_ATTR_TRIGGER_MODE ------------*/
#define NIFGEN_VAL_SINGLE                       1L
#define NIFGEN_VAL_CONTINUOUS                   2L
#define NIFGEN_VAL_STEPPED                      3L
#define NIFGEN_VAL_BURST                        4L 

/*- Defined values for attribute NIFGEN_ATTR_ARB_SAMPLE_RATE ---------*/
#define NIFGEN_VAL_EXTERNAL_SAMPLE_RATE         -1.0

/*- Defined values for attribute NIFGEN_ATTR_CLOCK_MODE --------------*/
#define NIFGEN_VAL_HIGH_RESOLUTION               0L
#define NIFGEN_VAL_DIVIDE_DOWN                   1L
#define NIFGEN_VAL_AUTOMATIC                     2L

/*- Defined values for attribute NIFGEN_ATTR_IDLE_BEHAVIOR and NIFGEN_ATTR_WAIT_BEHAVIOR ---*/
#define NIFGEN_VAL_HOLD_LAST_VALUE               400L
#define NIFGEN_VAL_JUMP_TO_VALUE                 401L

/*- Defined values for Arbitrary Sequence Creation -------------------*/
#define NIFGEN_VAL_INFINITE_LOOP                 0L
#define NIFGEN_VAL_WHOLE_BUFFER                  0L
#define NIFGEN_VAL_NO_MARKER                    -1L
#define NIFGEN_VAL_MARKER_QUANTUM                8L

/*- Defined Values for Bus Type --------------------------------------*/
#define NIFGEN_VAL_BUS_INVALID                   0L
#define NIFGEN_VAL_BUS_AT                        1L
#define NIFGEN_VAL_BUS_PCI                       2L
#define NIFGEN_VAL_BUS_PXI                       3L
#define NIFGEN_VAL_BUS_VXI                       4L
#define NIFGEN_VAL_BUS_PCMCIA                    5L
#define NIFGEN_VAL_BUS_PXIE                      6L

/*- Defined Values for Video Waveform Type ---------------------------*/
#define NIFGEN_VAL_PAL_B                         0L
#define NIFGEN_VAL_PAL_D                         1L
#define NIFGEN_VAL_PAL_G                         2L
#define NIFGEN_VAL_PAL_H                         3L
#define NIFGEN_VAL_PAL_I                         4L
#define NIFGEN_VAL_PAL_M                         5L
#define NIFGEN_VAL_PAL_N                         6L
#define NIFGEN_VAL_NTSC_M                        7L

/*- Defined Values for Next Waveform Write Position ------------------*/
#define NIFGEN_VAL_WAVEFORM_POSITION_START       0L
#define NIFGEN_VAL_WAVEFORM_POSITION_CURRENT     1L

/*- Defined values for attribute NIFGEN_ATTR_ANALOG_PATH -------------*/  
#define NIFGEN_VAL_MAIN_ANALOG_PATH              0L
#define NIFGEN_VAL_DIRECT_ANALOG_PATH            1L
#define NIFGEN_VAL_FIXED_LOW_GAIN_ANALOG_PATH    2L
#define NIFGEN_VAL_FIXED_HIGH_GAIN_ANALOG_PATH   3L

/*- Defined values for attribute NIFGEN_ATTR_CAL_ADC_INPUT -----------*/  
#define NIFGEN_VAL_ANALOG_OUTPUT                 0L
#define NIFGEN_VAL_INTERNAL_VOLTAGE_REFERENCE    1L
#define NIFGEN_VAL_GROUND                        2L
#define NIFGEN_VAL_ANALOG_OUTPUT_DIFFERENTIAL    3L
#define NIFGEN_VAL_ANALOG_OUTPUT_PLUS            4L
#define NIFGEN_VAL_ANALOG_OUTPUT_MINUS           5L

/*- Defined values for action in niFgen_CloseExtCal()  ---------------*/  
#define NIFGEN_VAL_EXT_CAL_ABORT                 0L
#define NIFGEN_VAL_EXT_CAL_COMMIT                1L

/*- Defined values for state in niFgen_GetHardwareState ()  ----------*/  
#define NIFGEN_VAL_IDLE                          0L
#define NIFGEN_VAL_WAITING_FOR_START_TRIGGER     100L
#define NIFGEN_VAL_RUNNING                       200L
#define NIFGEN_VAL_DONE                          600L  
#define NIFGEN_VAL_HARDWARE_ERROR                1000L

/*- Defined values for byte order in From File functions -------------*/  
#define NIFGEN_VAL_LITTLE_ENDIAN                 0L
#define NIFGEN_VAL_BIG_ENDIAN                    1L

/*- Defined values for configuration in niFgen_CalAdjustMainPathPreAmpOffset ()
    and niFgen_CalAdjustMainPathPreAmpGain ()  -*/  
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_0DB         0L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_3DB         1L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_6DB         2L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_9DB         3L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_OFF_12DB        4L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_0DB          5L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_3DB          6L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_6DB          7L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_9DB          8L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_FILTER_ON_12DB         9L

/*- Defined values for configuration in niFgen_CalAdjustMainPathPostAmpGainAndOffset ()  -*/  
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_0DB           0L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_12DB          1L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_24DB          2L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_36DB          3L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_0DB          4L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_12DB         5L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_24DB         6L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_36DB         7L

/*- Defined values for configuration in niFgen_CalAdjustMainPathOutputImpedance ()  -*/  
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_0DB_50OHMS    0L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_0DB_75OHMS    1L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_12DB_50OHMS   2L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_12DB_75OHMS   3L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_24DB_50OHMS   4L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_24DB_75OHMS   5L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_36DB_50OHMS   6L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_LOW_GAIN_36DB_75OHMS   7L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_0DB_50OHMS   8L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_0DB_75OHMS   9L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_12DB_50OHMS  10L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_12DB_75OHMS  11L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_24DB_50OHMS  12L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_24DB_75OHMS  13L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_36DB_50OHMS  14L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_HIGH_GAIN_36DB_75OHMS  15L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_DIFFERENTIAL           16L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_RSE                    17L

/*- Defined values for configuration in niFgen_CalAdjustDirectPathOutputImpedance ()  -*/  
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH_50OHMS               0L
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH_75OHMS               1L
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH_DIFFERENTIAL         2L


/*- Defined values for configuration in niFgen_CalAdjustFlatness and niFgen_CalAdjustCalADC ()  -*/  
#define NIFGEN_VAL_CAL_CONFIG_GLOBAL                          -1L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_0DB        0L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_3DB        1L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_6DB        2L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_9DB        3L
#define NIFGEN_VAL_CAL_CONFIG_LOW_GAIN_PATH_PRE_AMP_12DB       4L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_0DB       5L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_3DB       6L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_6DB       7L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_9DB       8L
#define NIFGEN_VAL_CAL_CONFIG_HIGH_GAIN_PATH_PRE_AMP_12DB      9L
#define NIFGEN_VAL_CAL_CONFIG_DIRECT_PATH                     10L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH                       11L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_0DB                   12L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_9DB                   13L
#define NIFGEN_VAL_CAL_CONFIG_MAIN_PATH_33DB                  14L

/*- Defined values for NIFGEN_ATTR_OSP_DATA_PROCESSING_MODE -*/  
#define NIFGEN_VAL_OSP_REAL                                    0L
#define NIFGEN_VAL_OSP_COMPLEX                                 1L

/*- Defined values for NIFGEN_ATTR_OSP_MODE -*/  
#define NIFGEN_VAL_OSP_IF                                      0L
#define NIFGEN_VAL_OSP_BASEBAND                                1L

/*- Defined values for NIFGEN_ATTR_OSP_FIR_FILTER_TYPE -*/  
#define NIFGEN_VAL_OSP_FLAT                                    0L
#define NIFGEN_VAL_OSP_RAISED_COSINE                           1L
#define NIFGEN_VAL_OSP_ROOT_RAISED_COSINE                      2L
#define NIFGEN_VAL_OSP_GAUSSIAN                                3L
#define NIFGEN_VAL_OSP_CUSTOM                                  4L

/*- Defined bit mask values for NIFGEN_ATTR_OSP_OVERFLOW_ERROR_REPORTING -*/  
#define NIFGEN_VAL_ERROR_REPORTING_ERROR                       0L
#define NIFGEN_VAL_ERROR_REPORTING_DISABLED                    2L

/*- Defined bit mask values for NIFGEN_ATTR_OSP_OVERFLOW_STATUS -*/  
#define NIFGEN_VAL_OSP_OVERFLOW_NONE                           0L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_I              1L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_GAIN_Q              2L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_I            4L
#define NIFGEN_VAL_OSP_OVERFLOW_PRE_FILTER_OFFSET_Q            8L
#define NIFGEN_VAL_OSP_OVERFLOW_FIR_FILTER_I                   16L
#define NIFGEN_VAL_OSP_OVERFLOW_PFIR_FILTER_I                  16L
#define NIFGEN_VAL_OSP_OVERFLOW_FIR_FILTER_Q                   32L
#define NIFGEN_VAL_OSP_OVERFLOW_PFIR_FILTER_Q                  32L
#define NIFGEN_VAL_OSP_OVERFLOW_CIC_FILTER_I                   64L
#define NIFGEN_VAL_OSP_OVERFLOW_CIC_FILTER_Q                   128L
#define NIFGEN_VAL_OSP_OVERFLOW_COMPLEX_DATA                   256L
#define NIFGEN_VAL_OSP_OVERFLOW_CFIR_FILTER_I                  512L
#define NIFGEN_VAL_OSP_OVERFLOW_CFIR_FILTER_Q                  1024L
#define NIFGEN_VAL_OSP_OVERFLOW_EQUALIZER                      2048L










/****************************************************************************
 *-------------------- IviScope Class Attribute Defines --------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVISCOPE_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVISCOPE_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVISCOPE_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVISCOPE_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVISCOPE_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVISCOPE_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVISCOPE_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVISCOPE_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVISCOPE_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVISCOPE_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVISCOPE_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVISCOPE_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                       /* ViString, read-only */
#define IVISCOPE_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVISCOPE_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVISCOPE_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVISCOPE_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVISCOPE_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

	/*- Version Information -*/
#define IVISCOPE_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVISCOPE_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviScope Fundamental Attributes -*/
        /*- Channel Subsystem -*/
#define IVISCOPE_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT               /* ViInt32,  read-only */
#define IVISCOPE_ATTR_VERTICAL_RANGE            (IVI_CLASS_PUBLIC_ATTR_BASE  + 1L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_VERTICAL_OFFSET           (IVI_CLASS_PUBLIC_ATTR_BASE  + 2L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_VERTICAL_COUPLING         (IVI_CLASS_PUBLIC_ATTR_BASE  + 3L)   /* ViInt32,   Multi-Channel */
#define IVISCOPE_ATTR_PROBE_ATTENUATION         (IVI_CLASS_PUBLIC_ATTR_BASE  + 4L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_CHANNEL_ENABLED           (IVI_CLASS_PUBLIC_ATTR_BASE  + 5L)   /* ViBoolean, Multi-Channel */
#define IVISCOPE_ATTR_MAX_INPUT_FREQUENCY       (IVI_CLASS_PUBLIC_ATTR_BASE  + 6L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_INPUT_IMPEDANCE           (IVI_CLASS_PUBLIC_ATTR_BASE  + 103L) /* ViReal64,  Multi-Channel */
    
        /*- Acquisition Subsystem -*/
#define IVISCOPE_ATTR_ACQUISITION_TYPE          (IVI_CLASS_PUBLIC_ATTR_BASE  + 101L) /* ViInt32    */
#define IVISCOPE_ATTR_ACQUISITION_START_TIME    (IVI_CLASS_PUBLIC_ATTR_BASE  + 109L) /* ViReal64  */
#define IVISCOPE_ATTR_HORZ_TIME_PER_RECORD      (IVI_CLASS_PUBLIC_ATTR_BASE  + 7L)   /* ViReal64  */
#define IVISCOPE_ATTR_HORZ_RECORD_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE  + 8L)   /* ViInt32, Read-only  */
#define IVISCOPE_ATTR_HORZ_MIN_NUM_PTS          (IVI_CLASS_PUBLIC_ATTR_BASE  + 9L)   /* ViInt32   */
#define IVISCOPE_ATTR_HORZ_SAMPLE_RATE          (IVI_CLASS_PUBLIC_ATTR_BASE  + 10L)  /* ViReal64, Read-only */

        /*- Triggering Subsystem -*/
#define IVISCOPE_ATTR_TRIGGER_TYPE              (IVI_CLASS_PUBLIC_ATTR_BASE  + 12L)  /* ViInt32   */
#define IVISCOPE_ATTR_TRIGGER_SOURCE            (IVI_CLASS_PUBLIC_ATTR_BASE  + 13L)  /* ViString  */
#define IVISCOPE_ATTR_TRIGGER_COUPLING          (IVI_CLASS_PUBLIC_ATTR_BASE  + 14L)  /* ViInt32   */
#define IVISCOPE_ATTR_TRIGGER_HOLDOFF           (IVI_CLASS_PUBLIC_ATTR_BASE  + 16L)  /* ViReal64  */

        /*- Edge Triggering Attributes -*/
#define IVISCOPE_ATTR_TRIGGER_LEVEL             (IVI_CLASS_PUBLIC_ATTR_BASE  + 17L)  /* ViReal64  */
#define IVISCOPE_ATTR_TRIGGER_SLOPE             (IVI_CLASS_PUBLIC_ATTR_BASE  + 18L)  /* ViInt32   */
    
    /*- IviScope Extended Attributes -*/
        /*- IviScopeTVTrigger Extension Group -*/
#define IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT  (IVI_CLASS_PUBLIC_ATTR_BASE + 201L) /* ViInt32   */
#define IVISCOPE_ATTR_TV_TRIGGER_EVENT          (IVI_CLASS_PUBLIC_ATTR_BASE + 205L) /* ViInt32   */
#define IVISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER    (IVI_CLASS_PUBLIC_ATTR_BASE + 206L) /* ViInt32   */
#define IVISCOPE_ATTR_TV_TRIGGER_POLARITY       (IVI_CLASS_PUBLIC_ATTR_BASE + 204L) /* ViInt32   */

        /*- IviScopeRuntTrigger Extension Group -*/
#define IVISCOPE_ATTR_RUNT_HIGH_THRESHOLD       (IVI_CLASS_PUBLIC_ATTR_BASE + 301L) /* ViReal64  */
#define IVISCOPE_ATTR_RUNT_LOW_THRESHOLD        (IVI_CLASS_PUBLIC_ATTR_BASE + 302L) /* ViReal64  */
#define IVISCOPE_ATTR_RUNT_POLARITY             (IVI_CLASS_PUBLIC_ATTR_BASE + 303L) /* ViInt32   */

        /*- IviScopeGlitchTrigger Extension Group -*/
#define IVISCOPE_ATTR_GLITCH_WIDTH              (IVI_CLASS_PUBLIC_ATTR_BASE + 401L) /* ViReal64  */
#define IVISCOPE_ATTR_GLITCH_POLARITY           (IVI_CLASS_PUBLIC_ATTR_BASE + 402L) /* ViInt32   */
#define IVISCOPE_ATTR_GLITCH_CONDITION          (IVI_CLASS_PUBLIC_ATTR_BASE + 403L) /* ViInt32   */

        /*- IviScopeWidthTrigger Extension Group -*/
#define IVISCOPE_ATTR_WIDTH_LOW_THRESHOLD       (IVI_CLASS_PUBLIC_ATTR_BASE + 501L) /* ViReal64  */
#define IVISCOPE_ATTR_WIDTH_HIGH_THRESHOLD      (IVI_CLASS_PUBLIC_ATTR_BASE + 502L) /* ViReal64  */
#define IVISCOPE_ATTR_WIDTH_POLARITY            (IVI_CLASS_PUBLIC_ATTR_BASE + 503L) /* ViInt32   */
#define IVISCOPE_ATTR_WIDTH_CONDITION           (IVI_CLASS_PUBLIC_ATTR_BASE + 504L) /* ViInt32   */

        /*- IviScopeAcLineTrigger Extension Group -*/
#define IVISCOPE_ATTR_AC_LINE_TRIGGER_SLOPE     (IVI_CLASS_PUBLIC_ATTR_BASE + 701L) /* ViInt32   */

        /*- IviScopeMinMaxWaveform Extension Group -*/
#define IVISCOPE_ATTR_NUM_ENVELOPES             (IVI_CLASS_PUBLIC_ATTR_BASE + 105L) /* ViInt32   */
    
        /*- IviScopeWaveformMeas Extension Group -*/
#define IVISCOPE_ATTR_MEAS_HIGH_REF             (IVI_CLASS_PUBLIC_ATTR_BASE + 607L) /* ViReal64, Percentage */
#define IVISCOPE_ATTR_MEAS_LOW_REF              (IVI_CLASS_PUBLIC_ATTR_BASE + 608L) /* ViReal64, Percentage */
#define IVISCOPE_ATTR_MEAS_MID_REF              (IVI_CLASS_PUBLIC_ATTR_BASE + 609L) /* ViReal64, Percentage */

        /*- IviScope Trigger Modifier Extension Group -*/
#define IVISCOPE_ATTR_TRIGGER_MODIFIER          (IVI_CLASS_PUBLIC_ATTR_BASE + 102L) /* ViInt32   */

        /*- IviScope Average Acquisition Extension Group -*/
#define IVISCOPE_ATTR_NUM_AVERAGES              (IVI_CLASS_PUBLIC_ATTR_BASE + 104L) /* ViInt32   */

        /*- IviScope Sample Mode Extension Group -*/
#define IVISCOPE_ATTR_SAMPLE_MODE               (IVI_CLASS_PUBLIC_ATTR_BASE + 106L) /* ViInt32, R/O  */

        /*- IviScope Continuous Acquisition Extension Group -*/
#define IVISCOPE_ATTR_INITIATE_CONTINUOUS       (IVI_CLASS_PUBLIC_ATTR_BASE + 107L) /* ViBoolean */

        /*- IviScope Probe Auto Sense Extension Group -*/
#define IVISCOPE_ATTR_PROBE_SENSE_VALUE         (IVI_CLASS_PUBLIC_ATTR_BASE + 108L) /* ViReal64, R/O */

        /*- IviScope Interpolation Extension Group -*/
#define IVISCOPE_ATTR_INTERPOLATION             (IVI_CLASS_PUBLIC_ATTR_BASE  + 19L) /* ViInt32   */







/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/
/*- NOTE: multi channel denotes an attribute specified on a per channel basis -*/

/*--- IVI Inherent Instrument Attributes --------------------------------------*/

      /* User Options ---------------------------------------------------------*/
#define NISCOPE_ATTR_CACHE                                        /* ViBoolean */   IVI_ATTR_CACHE
#define NISCOPE_ATTR_RANGE_CHECK                                  /* ViBoolean */   IVI_ATTR_RANGE_CHECK
#define NISCOPE_ATTR_QUERY_INSTRUMENT_STATUS                      /* ViBoolean */   IVI_ATTR_QUERY_INSTRUMENT_STATUS
#define NISCOPE_ATTR_RECORD_COERCIONS                             /* ViBoolean */   IVI_ATTR_RECORD_COERCIONS
#define NISCOPE_ATTR_SIMULATE                                     /* ViBoolean */   IVI_ATTR_SIMULATE
#define NISCOPE_ATTR_INTERCHANGE_CHECK                            /* ViBoolean */   IVI_ATTR_INTERCHANGE_CHECK

      /*- Instrument Capabilities, Read Only ----------------------------------*/
#define NISCOPE_ATTR_CHANNEL_COUNT                                /* ViInt32   */   IVI_ATTR_CHANNEL_COUNT
#define NISCOPE_ATTR_SUPPORTED_INSTRUMENT_MODELS                  /* ViString  */   IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS
#define NISCOPE_ATTR_GROUP_CAPABILITIES                           /* ViString  */   IVI_ATTR_GROUP_CAPABILITIES

      /*- Instrument Version and Identification, Read-only --------------------*/
#define NISCOPE_ATTR_SPECIFIC_DRIVER_DESCRIPTION                  /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION
#define NISCOPE_ATTR_SPECIFIC_DRIVER_PREFIX                       /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_PREFIX
#define NISCOPE_ATTR_SPECIFIC_DRIVER_VENDOR                       /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_VENDOR
#define NISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32   */   IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
#define NISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32   */   IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION
#define NISCOPE_ATTR_SPECIFIC_DRIVER_REVISION                     /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_REVISION
#define NISCOPE_ATTR_INSTRUMENT_MANUFACTURER                      /* ViString  */   IVI_ATTR_INSTRUMENT_MANUFACTURER
#define NISCOPE_ATTR_INSTRUMENT_MODEL                             /* ViString  */   IVI_ATTR_INSTRUMENT_MODEL
#define NISCOPE_ATTR_INSTRUMENT_FIRMWARE_REVISION                 /* ViString  */   IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION

      /*- Advanced Session Information, read-only -----------------------------*/
#define NISCOPE_ATTR_IO_RESOURCE_DESCRIPTOR                       /* ViString  */   IVI_ATTR_IO_RESOURCE_DESCRIPTOR
#define NISCOPE_ATTR_LOGICAL_NAME                                 /* ViString  */   IVI_ATTR_LOGICAL_NAME
#define NISCOPE_ATTR_DRIVER_SETUP                                 /* ViString  */   IVI_ATTR_DRIVER_SETUP


/*--- IVI Instrument-Specific Attributes --------------------------------*/

      /*- Acquisition Subsystem -*/
#define NISCOPE_ATTR_ACQUISITION_TYPE         IVISCOPE_ATTR_ACQUISITION_TYPE         /* ViInt32              */
#define NISCOPE_ATTR_SAMPLE_MODE              IVISCOPE_ATTR_SAMPLE_MODE              /* ViInt32,   read-only */

      /*- Vertical Subsystem -*/
#define NISCOPE_ATTR_CHANNEL_ENABLED          IVISCOPE_ATTR_CHANNEL_ENABLED          /* ViBoolean, multi channel        */
#define NISCOPE_ATTR_PROBE_ATTENUATION        IVISCOPE_ATTR_PROBE_ATTENUATION        /* ViReal64,  multi channel        */
#define NISCOPE_ATTR_VERTICAL_RANGE           IVISCOPE_ATTR_VERTICAL_RANGE           /* ViReal64,  multi channel, volts */
#define NISCOPE_ATTR_VERTICAL_OFFSET          IVISCOPE_ATTR_VERTICAL_OFFSET          /* ViReal64,  multi channel, volts */
#define NISCOPE_ATTR_VERTICAL_COUPLING        IVISCOPE_ATTR_VERTICAL_COUPLING        /* ViInt32,   multi channel        */
#define NISCOPE_ATTR_MAX_INPUT_FREQUENCY      IVISCOPE_ATTR_MAX_INPUT_FREQUENCY      /* ViReal64,  multi channel, hertz */
#define NISCOPE_ATTR_INPUT_IMPEDANCE          IVISCOPE_ATTR_INPUT_IMPEDANCE          /* ViReal64,  multi channel, ohms  */

      /*- Horizontal Subsystem -*/
#define NISCOPE_ATTR_HORZ_TIME_PER_RECORD     IVISCOPE_ATTR_HORZ_TIME_PER_RECORD     /* ViReal64,  seconds                         */
#define NISCOPE_ATTR_ACQUISITION_START_TIME   IVISCOPE_ATTR_ACQUISITION_START_TIME   /* ViReal64,  seconds                         */
#define NISCOPE_ATTR_HORZ_MIN_NUM_PTS         IVISCOPE_ATTR_HORZ_MIN_NUM_PTS         /* ViInt32                                    */
#define NISCOPE_ATTR_HORZ_RECORD_LENGTH       IVISCOPE_ATTR_HORZ_RECORD_LENGTH       /* ViInt32,   read-only, actual record length */
#define NISCOPE_ATTR_HORZ_RECORD_REF_POSITION (IVI_CLASS_PUBLIC_ATTR_BASE  + 11L)    /* ViReal64,  percentage of record length     */
#define NISCOPE_ATTR_HORZ_SAMPLE_RATE         IVISCOPE_ATTR_HORZ_SAMPLE_RATE         /* ViReal64,  read-only, actual sample rate   */

      /*- Trigger Subsystem -*/
#define NISCOPE_ATTR_TRIGGER_TYPE             IVISCOPE_ATTR_TRIGGER_TYPE             /* ViInt32            */
#define NISCOPE_ATTR_TRIGGER_SOURCE           IVISCOPE_ATTR_TRIGGER_SOURCE           /* ViString           */
#define NISCOPE_ATTR_TRIGGER_LEVEL            IVISCOPE_ATTR_TRIGGER_LEVEL            /* ViReal64,  volts   */
#define NISCOPE_ATTR_TRIGGER_DELAY_TIME       (IVI_CLASS_PUBLIC_ATTR_BASE  + 15L)    /* ViReal64,  seconds */
#define NISCOPE_ATTR_TRIGGER_HOLDOFF          IVISCOPE_ATTR_TRIGGER_HOLDOFF          /* ViReal64,  seconds */
#define NISCOPE_ATTR_TRIGGER_COUPLING         IVISCOPE_ATTR_TRIGGER_COUPLING         /* ViInt32            */
#define NISCOPE_ATTR_TRIGGER_SLOPE            IVISCOPE_ATTR_TRIGGER_SLOPE            /* ViInt32            */

      /*- TVTrigger Extension -*/
#define NISCOPE_ATTR_TV_TRIGGER_EVENT         IVISCOPE_ATTR_TV_TRIGGER_EVENT         /* ViInt32            */
#define NISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER   IVISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER   /* ViInt32            */
#define NISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT /* ViInt32            */
#define NISCOPE_ATTR_TV_TRIGGER_POLARITY      IVISCOPE_ATTR_TV_TRIGGER_POLARITY      /* ViInt32            */

      /*- Measurement Functions -*/
#define NISCOPE_ATTR_MEAS_HIGH_REF            IVISCOPE_ATTR_MEAS_HIGH_REF            /* ViReal64           */
#define NISCOPE_ATTR_MEAS_LOW_REF             IVISCOPE_ATTR_MEAS_LOW_REF             /* ViReal64           */
#define NISCOPE_ATTR_MEAS_MID_REF             IVISCOPE_ATTR_MEAS_MID_REF             /* ViReal64           */

      /*--- Additional Instrument-Specific Attributes ----------------------------*/
#define NISCOPE_ATTR_HORZ_NUM_RECORDS          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)   /* ViInt32              */
#define NISCOPE_ATTR_INPUT_CLOCK_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)   /* ViString             */
#define NISCOPE_ATTR_OUTPUT_CLOCK_SOURCE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)   /* ViString             */
#define NISCOPE_ATTR_HORZ_ENFORCE_REALTIME     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)   /* ViBoolean            */
#define NISCOPE_ATTR_BINARY_SAMPLE_WIDTH       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)   /* ViInt32              */
#define NISCOPE_ATTR_TRIGGER_HYSTERESIS        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)   /* ViReal64,  volts     */
#define NISCOPE_ATTR_CLOCK_SYNC_PULSE_SOURCE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)   /* ViString             */
#define NISCOPE_ATTR_MASTER_ENABLE             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)   /* ViBoolean            */
#define NISCOPE_ATTR_MIN_SAMPLE_RATE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)   /* ViReal64             */
#define NISCOPE_ATTR_TRIGGER_WINDOW_MODE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)  /* ViInt32              */
#define NISCOPE_ATTR_TRIGGER_WINDOW_LOW_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)  /* ViReal64             */
#define NISCOPE_ATTR_TRIGGER_WINDOW_HIGH_LEVEL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)  /* ViReal64             */
#define NISCOPE_ATTR_MEAS_REF_LEVEL_UNITS      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)  /* ViInt32              */
#define NISCOPE_ATTR_MEAS_OTHER_CHANNEL        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 18L)  /* ViString             */
#define NISCOPE_ATTR_MEAS_HYSTERESIS_PERCENT   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)  /* ViReal64             */
#define NISCOPE_ATTR_MEAS_LAST_ACQ_HISTOGRAM_SIZE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)    /* ViInt32    */
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_SIZE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)    /* ViInt32    */
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_LOW_VOLTS  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_HIGH_VOLTS (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_SIZE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 24L)    /* ViInt32    */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_LOW_VOLTS     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_HIGH_VOLTS    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_LOW_TIME      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_HIGH_TIME     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_POLYNOMIAL_INTERPOLATION_ORDER (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)  /* ViInt32    */
#define NISCOPE_ATTR_MEAS_INTERPOLATION_SAMPLING_FACTOR  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_CUTOFF_FREQ             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 31L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_CENTER_FREQ             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_RIPPLE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_TRANSIENT_WAVEFORM_PERCENT (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L) /* ViReal64 */
#define NISCOPE_ATTR_MEAS_FILTER_TYPE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_FILTER_ORDER         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_FILTER_TAPS          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_CHAN_LOW_REF_LEVEL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_CHAN_MID_REF_LEVEL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_CHAN_HIGH_REF_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_FILTER_WIDTH         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_FIR_FILTER_WINDOW    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_ARRAY_GAIN           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_ARRAY_OFFSET         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_PERCENTAGE_METHOD    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)  /* ViInt32  */

   /*- Advanced synchronization attributes -*/
#define NISCOPE_ATTR_SLAVE_TRIGGER_DELAY              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_TO_STAR_DELAY            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_TO_RTSI_DELAY            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_TO_PFI_DELAY             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 49L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_FROM_STAR_DELAY          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 50L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_FROM_RTSI_DELAY          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_FROM_PFI_DELAY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L) /* ViReal64 */
#define NISCOPE_ATTR_ACQ_ARM_SOURCE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L) /* ViString */
#define NISCOPE_ATTR_RECORD_ARM_SOURCE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 65L) /* ViString */
#define NISCOPE_ATTR_IS_PROBE_COMP_ON                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 66L)  /* ViBoolean */
#define NISCOPE_ATTR_USE_SPEC_INITIAL_X               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 67L)  /* ViBoolean */
#define NISCOPE_ATTR_ALLOW_MORE_RECORDS_THAN_MEMORY   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 68L)  /* ViBoolean */
#define NISCOPE_ATTR_ONBOARD_MEMORY_SIZE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)  /* ViInt32   */
#define NISCOPE_ATTR_RIS_NUM_AVERAGES                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 70L)  /* ViInt32   */
#define NISCOPE_ATTR_RIS_METHOD                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_INTERLEAVED_DATA           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)  /* ViBoolean */
#define NISCOPE_ATTR_MAX_REAL_TIME_SAMPLING_RATE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)  /* ViReal64  */
#define NISCOPE_ATTR_MAX_RIS_RATE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)  /* ViInt32   */
#define NISCOPE_ATTR_TRIGGER_IMPEDANCE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)  /* ViReal64  */
#define NISCOPE_ATTR_DEVICE_NUMBER                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 76L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_RELATIVE_TO                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_OFFSET                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 78L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_RECORD_NUMBER              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_NUM_RECORDS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 80L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_MEAS_NUM_SAMPLES           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)  /* ViInt32   */
#define NISCOPE_ATTR_POINTS_DONE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 82L)  /* ViReal64  */
#define NISCOPE_ATTR_RECORDS_DONE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 83L)  /* ViInt32   */
#define NISCOPE_ATTR_BACKLOG                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 84L)  /* ViReal64  */
#define NISCOPE_ATTR_5102_ADJUST_PRETRIGGER_SAMPLES   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 85L)  /* ViBoolean */
#define NISCOPE_ATTR_POLL_INTERVAL                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 100L) /* ViInt32   */

   /*- Attributes for the 5620 Digital Down Converter -*/
#define NISCOPE_ATTR_DDC_NCO_FREQUENCY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1000)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_NCO_PHASE                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1001)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_ENABLE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1003)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_CIC_DECIMATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1010)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_CIC_SHIFT_GAIN                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1011)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_ENABLED           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1020)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_DECIMATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1021)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_SYMMETRY      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1022)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_SYMMETRY_TYPE (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1023)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_NUM_TAPS      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1024)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_DELAY             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1025)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_INPUT_SOURCE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1026)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_PHASE_MULTIPLIER  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1027)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_DECIMATION                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1030)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_SYMMETRY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1031)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_SYMMETRY_TYPE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1032)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_NUM_TAPS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1033)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_REAL_OR_COMPLEX            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1034)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_UPPER_GAIN_LIMIT            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1040)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_AGC_LOWER_GAIN_LIMIT            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1041)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_0_EXPONENT        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1042)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_0_MANTISSA        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1043)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_1_EXPONENT        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1044)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_1_MANTISSA        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1045)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_THRESHOLD                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1046)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_AVERAGE_CONTROL             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1047)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_HALFBAND_BYPASSED               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1050)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_1_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1051)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_2_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1052)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_3_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1053)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_4_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1054)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_5_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1055)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_AOUT_PARALLEL_OUTPUT_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1070) /* ViInt32   */
#define NISCOPE_ATTR_DDC_BOUT_PARALLEL_OUTPUT_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1071) /* ViInt32   */
#define NISCOPE_ATTR_DDC_TEST_SINE_COSINE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1072) /* ViBoolean */
#define NISCOPE_ATTR_DDC_COORDINATE_CONVERTER_INPUT         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1073) /* ViInt32   */
#define NISCOPE_ATTR_DDC_Q_INPUT_TO_COORD_CONVERTER_INPUT   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1074) /* ViInt32   */
#define NISCOPE_ATTR_DDC_SYNCOUT_CLK_SELECT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1080)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_TIMING_NCO_PHASE_ACCUM_LOAD     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1120)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_TIMING_NCO_CLEAR_PHASE_ACCUM    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1121)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_TIMING_NCO_ENABLE_OFFSET_FREQ   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1122)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_TIMING_NCO_NUM_OFFSET_FREQ_BITS (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1123)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_TIMING_NCO_CENTER_FREQUENCY     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1124)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_TIMING_NCO_PHASE_OFFSET         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1125)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_RESAMPLER_FILTER_MODE_SELECT    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1126)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_RESAMPLER_BYPASS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1127)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_RESAMPLER_OUTPUT_PULSE_DELAY    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1128)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_NCO_DIVIDE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1129)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_REFERENCE_DIVIDE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1130)    /* ViInt32   */
#define NISCOPE_ATTR_ENABLE_DITHER                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1300)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_COMBINED_DECIMATION             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1301)    /* ViInt32   */
#define NISCOPE_ATTR_SERIAL_DAC_CAL_VOLTAGE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1302)    /* ViReal64  */
#define NISCOPE_ATTR_PLL_LOCK_STATUS                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1303)    /* ViBoolean */
#define NISCOPE_ATTR_DELAY_BEFORE_INITIATE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1304)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_DIRECT_REGISTER_ADDRESS         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1305)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DIRECT_REGISTER_DATA            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1306)    /* ViInt32   */

   /* New attributes for NI-SCOPE 2.5 */
#define NISCOPE_ATTR_DEVICE_TEMPERATURE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 86)   /* ViReal64   */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_SRC               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87)   /* ViString   */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_RATE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 88)   /* ViReal64   */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_DIV               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 89)   /* ViInt32    */
#define NISCOPE_ATTR_REF_CLK_RATE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 90)   /* ViReal64   */
#define NISCOPE_ATTR_EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 91)   /* ViString   */
#define NISCOPE_ATTR_DAQMX_TASK                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 92)   /* ViInt32    */
#define NISCOPE_ATTR_ENABLE_DC_RESTORE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93)   /* ViBoolean  */
#define NISCOPE_ATTR_ADV_TRIG_SRC                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 94)   /* ViString   */
#define NISCOPE_ATTR_ARM_REF_TRIG_SRC                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95)   /* ViString   */
#define NISCOPE_ATTR_REF_TRIG_TDC_ENABLE                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 96)   /* ViBoolean  */
#define NISCOPE_ATTR_RESOLUTION                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102)  /* ViInt32,   read-only */

   /* New attributes for NI-SCOPE 2.6 */
#define NISCOPE_ATTR_START_TO_REF_TRIGGER_HOLDOFF        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103)  /* ViReal64,  seconds */

   /* New attributes for NI-SCOPE 2.7 */
#define NISCOPE_ATTR_SERIAL_NUMBER                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104)  /* ViString   */
#define NISCOPE_ATTR_OSCILLATOR_PHASE_DAC_VALUE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105)  /* ViInt32    */

   /* New attributes for NI-SCOPE 2.8 */
#define NISCOPE_ATTR_RIS_IN_AUTO_SETUP_ENABLE                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106)  /* ViBoolean  */
#define NISCOPE_ATTR_CHANNEL_TERMINAL_CONFIGURATION           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107)  /* ViInt32, multi channel */
#define NISCOPE_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109)  /* ViString */
#define NISCOPE_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110)  /* ViString */
#define NISCOPE_ATTR_READY_FOR_REF_EVENT_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111)  /* ViString */
#define NISCOPE_ATTR_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112)  /* ViString */

   /* New attributes for NI-SCOPE 2.9.1 */
#define NISCOPE_ATTR_FLEX_FIR_ANTIALIAS_FILTER_TYPE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 271)  /* ViInt32, multi channel */

   /* New attributes for NI-SCOPE 3.0. Attributes for the NI 5142 & 5622 OSP functionality. */
#define NISCOPE_ATTR_DDC_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 300)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_ENABLED   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 302)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_DDC_CENTER_FREQUENCY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 303)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DDC_DATA_PROCESSING_MODE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 304)  /* ViInt32 */
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_PHASE_I   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 305)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_PHASE_Q   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 306)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DIGITAL_GAIN                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 307)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DIGITAL_OFFSET                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 308)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_OVERFLOW_ERROR_REPORTING            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 309)  /* ViInt32 */
#define NISCOPE_ATTR_DDC_Q_SOURCE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 310)  /* ViInt32, multi channel  */
#define NISCOPE_ATTR_FETCH_INTERLEAVED_IQ_DATA           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 311) // ViBoolean //

   /* New attributes for NI-SCOPE 3.1. */
#define NISCOPE_ATTR_EQUALIZATION_NUM_COEFFICIENTS       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 312)  /* ViInt32, multi channel */
#define NISCOPE_ATTR_EQUALIZATION_FILTER_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 313)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_REF_TRIGGER_DETECTOR_LOCATION       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 314)  /* ViInt32 */
#define NISCOPE_ATTR_REF_TRIGGER_MINIMUM_QUIET_TIME      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 315)  /* ViReal64 */

   /* New attributes for NI-SCOPE 3.2 */
#define NISCOPE_ATTR_ENABLE_TIME_INTERLEAVED_SAMPLING    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 128L)  // ViBoolean

   /* New attributes for NI-SCOPE 3.3 */
#define NISCOPE_ATTR_DATA_TRANSFER_BLOCK_SIZE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 316)  /* ViInt32 */

   /* New attributes for NI-SCOPE 3.4 */
#define NISCOPE_ATTR_TRIGGER_MODIFIER                          IVISCOPE_ATTR_TRIGGER_MODIFIER         /* ViInt32 */
#define NISCOPE_ATTR_TRIGGER_AUTO_TRIGGERED                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 278L) /* ViBoolean */
#define NISCOPE_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 97L)  /* ViString  */
#define NISCOPE_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 98L)  /* ViString  */
#define NISCOPE_ATTR_END_OF_RECORD_EVENT_OUTPUT_TERMINAL       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 99L)  /* ViString  */
#define NISCOPE_ATTR_END_OF_ACQUISITION_EVENT_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L) /* ViString  */
#define NISCOPE_ATTR_5V_OUT_OUTPUT_TERMINAL                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 129L) /* ViString  */

   /* New attributes for NI-SCOPE 3.5 */
#define NISCOPE_ATTR_BANDPASS_FILTER_ENABLED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 318)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_DITHER_ENABLED                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 319)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_FRACTIONAL_RESAMPLE_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 320)  /* ViBoolean */
#define NISCOPE_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L)  /* ViReal64 */
#define NISCOPE_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L)  /* ViInt32 */

// NI-5900 specific definitions
#define NISCOPE_ATTR_SIGNAL_COND_GAIN                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 279L) // ViReal64 //
#define NISCOPE_ATTR_SIGNAL_COND_OFFSET                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 280L) // ViReal64 //

   /* New attributes for NI-SCOPE 3.7 */

//Peer-to-Peer
#define NISCOPE_ATTR_P2P_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 338L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_CHANNELS_TO_STREAM              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 339L) /* ViString  */
#define NISCOPE_ATTR_P2P_ENDPOINT_SIZE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 342L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_SAMPLES_AVAIL_IN_ENDPOINT       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 328L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_MOST_SAMPLES_AVAIL_IN_ENDPOINT  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 341L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_SAMPLES_TRANSFERRED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 340L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_ENDPOINT_OVERFLOW               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 344L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_FIFO_ENDPOINT_COUNT             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 345L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_ONBOARD_MEMORY_ENABLED          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 354L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_ADVANCED_ATTRIBUTES_ENABLED     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 343L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 329L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR_TYPE (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 330L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 331L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR_TYPE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 332L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_SIZE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 333L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_NOTIFY_PUSH_MESSAGE_ON          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 334L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 335L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 336L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_VALUE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 337L) /* ViInt64 */

// int main(){
// return 0;
// }