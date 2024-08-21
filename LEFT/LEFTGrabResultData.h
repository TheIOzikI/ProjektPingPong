//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result data class.
*/

#ifndef INCLUDED_LEFTFILE_H_90437477
#define INCLUDED_LEFTFILE_H_90437477

#pragma once

#include "LEFTChunkDataParams.h"
#include <pylon/GrabResultData.h>

namespace Pylon
{
    /// The grab result data.
    class LEFTGrabResultData : public CGrabResultData, public LEFTChunkDataParams_Params::LEFTChunkDataParams
    {
    protected:
        // Internal use only. The grab result data class should only be created by the instant camera class.
        friend class LEFT;
        LEFTGrabResultData()
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

#endif /* INCLUDED_LEFTFILE_H_90437477 */