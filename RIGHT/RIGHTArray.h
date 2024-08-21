//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief instant camera array class.
*/

#ifndef INCLUDED_RIGHTFILE_H_75902398
#define INCLUDED_RIGHTFILE_H_75902398

#pragma once

#include "RIGHT.h"
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /*!
    \class  RIGHTArrayArray
    \brief  RIGHT based instant camera array.

    \threading
        The RIGHTArrayArray class is not thread-safe.
    */
    class RIGHTArrayArray: public CDeviceSpecificInstantCameraArrayT<RIGHT>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        RIGHTArrayArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        RIGHTArrayArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<RIGHT>(numberOfCameras) {}

    };

} // namespace Pylon

#endif /* INCLUDED_RIGHTFILE_H_75902398 */