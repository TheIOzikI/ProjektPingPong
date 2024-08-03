//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result ptr class.
*/

#ifndef INCLUDED_BASLERCAMERA123FILE_H_19854797
#define INCLUDED_BASLERCAMERA123FILE_H_19854797

#pragma once

#include "BaslerCamera123GrabResultData.h"
#include <pylon/private/DeviceSpecificGrabResultPtr.h>

namespace Pylon123
{
    /// The grab result smart pointer.
    PYLON_DEFINE_DEVICE_SPECIFIC_GRAB_RESULT_PTR( BaslerCamera123GrabResultPtr, BaslerCamera123GrabResultData)

} // namespace Pylon123

#endif /* INCLUDED_BASLERCAMERA123FILE_H_19854797 */