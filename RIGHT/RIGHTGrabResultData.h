//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result data class.
*/

#ifndef INCLUDED_RIGHTFILE_H_90437477
#define INCLUDED_RIGHTFILE_H_90437477

#pragma once

#include "RIGHTChunkDataParams.h"
#include <pylon/GrabResultData.h>

namespace Pylon
{
    /// The grab result data.
    class RIGHTGrabResultData : public CGrabResultData, public RIGHTChunkDataParams_Params::RIGHTChunkDataParams
    {
    protected:
        // Internal use only. The grab result data class should only be created by the instant camera class.
        friend class RIGHT;
        RIGHTGrabResultData()
        {
        }

        // Internal use only.
        virtual void Destroy()
        {
            delete this;
        }

        // Internal use only.
        virtual void Initialize()
        {
            _Initialize( &GetChunkDataNodeMap());
        }
    };

} // namespace Pylon

#endif /* INCLUDED_RIGHTFILE_H_90437477 */