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


    };

} // end namespace Mk1

#endif
