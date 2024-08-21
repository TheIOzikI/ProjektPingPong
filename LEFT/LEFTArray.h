//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief instant camera array class.
*/

#ifndef INCLUDED_LEFTFILE_H_75902398
#define INCLUDED_LEFTFILE_H_75902398

#pragma once

#include "LEFT.h"
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /*!
    \class  LEFTArrayArray
    \brief  LEFT based instant camera array.

    \threading
        The LEFTArrayArray class is not thread-safe.
    */
    class LEFTArrayArray: public CDeviceSpecificInstantCameraArrayT<LEFT>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        LEFTArrayArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        LEFTArrayArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<LEFT>(numberOfCameras) {}

    };

} // namespace Pylon

#endif /* INCLUDED_LEFTFILE_H_75902398 */