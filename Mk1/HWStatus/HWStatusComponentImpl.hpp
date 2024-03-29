// ======================================================================
// \title  HWStatusComponentImpl.hpp
// \author rpk
// \brief  hpp file for HWStatus component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef HWStatus_HPP
#define HWStatus_HPP

#include "Mk1/HWStatus/HWStatusComponentAc.hpp"
#define SYSFS_Temp_DIR "/sys/class/thermal/thermal_zone0/temp"
#define SYSFS_Clockspeed_DIR "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"
namespace Mk1 {

  class HWStatusComponentImpl :
    public HWStatusComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object HWStatus
      //!
      HWStatusComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object HWStatus
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object HWStatus
      //!
      ~HWStatusComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );


    };

} // end namespace Mk1

#endif
