//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result data class.
*/

#ifndef INCLUDED_BASLERCAMERA123FILE_H_90437477
#define INCLUDED_BASLERCAMERA123FILE_H_90437477

#pragma once

#include "BaslerCamera123ChunkDataParams.h"
#include <pylon/GrabResultData.h>

namespace Pylon123
{
    /// The grab result data.
    class BaslerCamera123GrabResultData : public CGrabResultData, public BaslerCamera123ChunkDataParams_Params::BaslerCamera123ChunkDataParams
    {
    protected:
        // Internal use only. The grab result data class should only be created by the instant camera class.
        friend class BaslerCamera123;
        BaslerCamera123GrabResultData()
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

} // namespace Pylon123

#endif /* INCLUDED_BASLERCAMERA123FILE_H_90437477 */