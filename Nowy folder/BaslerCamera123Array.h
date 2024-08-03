//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief instant camera array class.
*/

#ifndef INCLUDED_BASLERCAMERA123FILE_H_75902398
#define INCLUDED_BASLERCAMERA123FILE_H_75902398

#pragma once

#include "BaslerCamera123.h"
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon123
{
    /*!
    \class  BaslerCamera123ArrayArray
    \brief  BaslerCamera123 based instant camera array.

    \threading
        The BaslerCamera123ArrayArray class is not thread-safe.
    */
    class BaslerCamera123ArrayArray: public CDeviceSpecificInstantCameraArrayT<BaslerCamera123>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        BaslerCamera123ArrayArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        BaslerCamera123ArrayArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<BaslerCamera123>(numberOfCameras) {}

    };

} // namespace Pylon123

#endif /* INCLUDED_BASLERCAMERA123FILE_H_75902398 */