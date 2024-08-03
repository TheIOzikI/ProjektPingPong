//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/**
\file
\brief Contains the image event handler base class.
*/

#ifndef INCLUDED_BASLERCAMERA123FILE_H_23893489
#define INCLUDED_BASLERCAMERA123FILE_H_23893489

#pragma once

#include <pylon/stdinclude.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include "BaslerCamera123GrabResultPtr.h"

namespace Pylon123
{
    class BaslerCamera123;

    /**
    \class  BaslerCamera123ImageEventHandler
    \brief  The image event handler base class.
    */
    class BaslerCamera123ImageEventHandler
    {
    public:

        /**
        \brief This method is called when images have been skipped using the GrabStrategy_LatestImageOnly strategy or the GrabStrategy_LatestImages strategy.

        \param[in]  camera The source of the call.
        \param[in]  countOfSkippedImages The number of images skipped. This \c countOfSkippedImages does not include the number of images lost in the case of a buffer under run in the driver.

        \error
            Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

        \threading
            This method is called outside the lock of the camera object but inside the lock of the image event handler registry.
        */
        virtual void OnImagesSkipped( BaslerCamera123& camera, size_t countOfSkippedImages)
        {
            PYLON_UNUSED(&camera);
            PYLON_UNUSED(countOfSkippedImages);
        }

        /**
        \brief This method is called when an image has been grabbed.

        The grab result smart pointer passed does always reference a grab result data object.
        The status of the grab needs to be checked before accessing the grab result data.
        See CGrabResultData::GrabSucceeded(), CGrabResultData::GetErrorCode() and
        CGrabResultData::GetErrorDescription() for more information.

        \param[in]  camera The source of the call.
        \param[in]  grabResult The grab result data.

        \error
            Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

        \threading
            This method is called outside the lock of the camera object but inside the lock of the image event handler registry.
        */
        virtual void OnImageGrabbed( BaslerCamera123& camera, const BaslerCamera123GrabResultPtr& grabResult)
        {
            PYLON_UNUSED(&camera);
            PYLON_UNUSED(grabResult);
        }

        /**
        \brief This method is called when the image event handler has been registered.

        \param[in]  camera The source of the call.

        \error
            Exceptions from this call will propagate through.
        \threading
            This method is called inside the lock of the image event handler registry.
        */
        virtual void OnImageEventHandlerRegistered( BaslerCamera123& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called when the image event handler has been deregistered.

        The image event handler is automatically deregistered when the Instant Camera object
        is destroyed.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored.
        \threading
            This method is called inside the lock of the image event handler registry.
        */
        virtual void OnImageEventHandlerDeregistered( BaslerCamera123& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /*!
        \brief Destroys the image event handler.

        \error
            C++ exceptions from this call will be caught and ignored.
        */
        virtual void DestroyImageEventHandler()
        {
            //If runtime errors occur here during delete, check the following:
            //Check that the cleanup procedure is correctly set when registering.
            //Ensure that the registered object has been allocated on the heap using new.
            //Ensure that the registered object has not already been deleted.
            delete this;
        }

        /// Create.
        BaslerCamera123ImageEventHandler()
            : m_eventHandlerRegistrationCount(0)
        {
        }

        /// Copy.
        BaslerCamera123ImageEventHandler(const BaslerCamera123ImageEventHandler&)
            : m_eventHandlerRegistrationCount(0)
        {
        }

        /// Assign.
        BaslerCamera123ImageEventHandler& operator=(const BaslerCamera123ImageEventHandler&)
        {
            return *this;
        }

        /// Destruct.
        virtual ~BaslerCamera123ImageEventHandler()
        {
            PYLON_ASSERT2( DebugGetEventHandlerRegistrationCount() == 0, "Error: The event handler must not be destroyed while it is registered.");
        }

        // Internal use only. Subject to change without notice.
        const long& DebugGetEventHandlerRegistrationCount()
        {
            return m_eventHandlerRegistrationCount;
        }

    private:
        long m_eventHandlerRegistrationCount; // Counts how many times the event handler is registered.
    };

} // namespace Pylon123

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_BASLERCAMERA123FILE_H_23893489 */