//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result ptr class.
*/

#ifndef INCLUDED_LEFTFILE_H_19854797
#define INCLUDED_LEFTFILE_H_19854797

#pragma once

#include "LEFTGrabResultData.h"
#include <pylon/private/DeviceSpecificGrabResultPtr.h>

namespace Pylon
{
    /// The grab result smart pointer.
    PYLON_DEFINE_DEVICE_SPECIFIC_GRAB_RESULT_PTR( LEFTGrabResultPtr, LEFTGrabResultData)

} // namespace Pylon

#endif /* INCLUDED_LEFTFILE_H_19854797 */