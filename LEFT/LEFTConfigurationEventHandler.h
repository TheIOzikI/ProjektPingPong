//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/**
\file
\brief Contains the configuration event handler base class.
*/

#ifndef INCLUDED_LEFTFILE_H_27473547
#define INCLUDED_LEFTFILE_H_27473547

#pragma once

#include <pylon/stdinclude.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

namespace Pylon
{
    class LEFT;

    /**
    \class  LEFTConfigurationEventHandler
    \brief The configuration event handler base class.
    */
    class LEFTConfigurationEventHandler
    {
    public:
        /**
        \brief This method is called before a %Pylon Device (Pylon::IPylonDevice) is attached by calling the Instant Camera object's Attach() method.

        This method can not be used for detecting that a camera device has been attached to the PC.
        The camera's Attach() method must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnAttach( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after a %Pylon Device (Pylon::IPylonDevice) has been attached by calling the Instant Camera object's Attach() method.

        This method can not be used for detecting that a camera device has been attached to the PC.
        The camera's Attach() method must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnAttached( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called before the attached %Pylon Device is detached from the Instant Camera object.

        The camera's Detach() method  must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnDetach( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after the attached %Pylon Device has been detached from the Instant Camera object.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnDetached( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called before the attached %Pylon Device is destroyed.

        Camera DestroyDevice must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnDestroy( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after the attached %Pylon Device has been destroyed.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnDestroyed( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called before the attached %Pylon Device is opened.

        \param[in]  camera The source of the call.

        \error
            Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnOpen( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after the attached %Pylon Device has been opened.

        \param[in]  camera The source of the call.

        \error
            Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnOpened( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called before the attached %Pylon Device is closed.

        Camera Close must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnClose( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after the attached %Pylon Device has been closed.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnClosed( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called before a grab session is started.

        Camera StartGrabbing must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnGrabStart( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after a grab session has been started.

        \param[in]  camera The source of the call.

        \error
            Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnGrabStarted( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called before a grab session is stopped.

        Camera StopGrabbing must not be called from here or from subsequent calls to avoid infinite recursion.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnGrabStop( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called after a grab session has been stopped.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnGrabStopped( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called when an exception has been triggered during grabbing.

        An exception has been triggered by a grab thread. The grab will be stopped after this event call.

        \param[in]  camera The source of the call.
        \param[in]  errorMessage The message of the exception that signaled an error during grabbing.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnGrabError( LEFT& camera, const char* errorMessage)
        {
            PYLON_UNUSED(&camera);
            PYLON_UNUSED(errorMessage);
        }

        /**
        \brief This method is called when a camera device removal from the PC has been detected.

        The %Pylon Device attached to the Instant Camera is not operable after this event.
        After it is made sure that no access to the %Pylon Device or any of its node maps is made anymore
        the %Pylon Device should be destroyed using InstantCamera::DeviceDestroy().
        The access to the %Pylon Device can be protected using the lock provided by GetLock(), e.g. when accessing parameters.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored. All event handlers are notified.

        \threading
            This method is called inside the lock of the camera object from an additional thread.
        */
        virtual void OnCameraDeviceRemoved( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }


        /**
        \brief This method is called when the configuration event handler has been registered.

        \param[in]  camera The source of the call.

        \error
            Exceptions from this call will propagate through.
        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnConfigurationRegistered( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /**
        \brief This method is called when the configuration event handler has been deregistered.

        The configuration event handler is automatically deregistered when the Instant Camera object
        is destroyed.

        \param[in]  camera The source of the call.

        \error
            C++ exceptions from this call will be caught and ignored.
        \threading
            This method is called inside the lock of the camera object.
        */
        virtual void OnConfigurationDeregistered( LEFT& camera)
        {
            PYLON_UNUSED(&camera);
        }

        /*!
        \brief Destroys the configuration event handler.

        \error
            C++ exceptions from this call will be caught and ignored.
        */
        virtual void DestroyConfiguration()
        {
            //If runtime errors occur here during delete, check the following:
            //Check that the cleanup procedure is correctly set when registering.
            //Ensure that the registered object has been allocated on the heap using new.
            //Ensure that the registered object has not already been deleted.
            delete this;
        }

        /// Create.
        LEFTConfigurationEventHandler()
            : m_eventHandlerRegistrationCount(0)
        {
        }

        /// Copy.
        LEFTConfigurationEventHandler(const LEFTConfigurationEventHandler&)
            : m_eventHandlerRegistrationCount(0)
        {
        }

        /// Assign.
        LEFTConfigurationEventHandler& operator=(const LEFTConfigurationEventHandler&)
        {
            return *this;
        }

        /// Destruct.
        virtual ~LEFTConfigurationEventHandler()
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

} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_LEFTFILE_H_27473547 */