// ======================================================================
// \title  HWStatusComponentImpl.cpp
// \author rpk
// \brief  cpp file for HWStatus component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ==============================================8========================


#include <Mk1/HWStatus/HWStatusComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#define SYSFS_Temp_DIR "/sys/class/thermal/thermal_zone0/temp"
#define SYSFS_Clockspeed_DIR "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq"
namespace Mk1 {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  HWStatusComponentImpl ::
    HWStatusComponentImpl(
        const char *const compName
    ) : HWStatusComponentBase(compName)
  {

  }

  void HWStatusComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
        
    )
  {
    HWStatusComponentBase::init(instance);
    float systemp, sysclockspeed, millideg, hz;
    int n, m;
    FILE *thermal, *clock;
    thermal = fopen(SYSFS_Temp_DIR,"r");
    n = fscanf(thermal,"%f",&millideg);
    fclose(thermal);
    clock = fopen(SYSFS_Clockspeed_DIR,"r");
    m = fscanf(clock,"%f",&hz);
    fclose(clock);
    systemp = millideg / 1000;
    sysclockspeed = hz/1000000;
    tlmWrite_tempC(systemp);
    tlmWrite_clockspeed(sysclockspeed);

  }

  HWStatusComponentImpl ::
    ~HWStatusComponentImpl(void)
  {

  }

} // end namespace Mk1
