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
// ======================================================================


#include <Mk1/HWStatus/HWStatusComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

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
  }

  HWStatusComponentImpl ::
    ~HWStatusComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void HWStatusComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
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

} // end namespace Mk1
