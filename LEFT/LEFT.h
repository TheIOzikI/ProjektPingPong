//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief instant camera class
*/

#ifndef INCLUDED_LEFTFILE_H_87483470
#define INCLUDED_LEFTFILE_H_87483470

#pragma once

#include "LEFTCameraParams.h"
#include "LEFTStreamParams.h"
#include "LEFTEventParams.h"
#include "LEFTTLParams.h"
#include "LEFTConfigurationEventHandler.h"
#include "LEFTImageEventHandler.h"
#include "LEFTCameraEventHandler.h"
#include "LEFTGrabResultPtr.h"
#include <pylon/private/DeviceSpecificInstantCamera.h>
#include <pylon/gige/PylonGigEDevice.h>
#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <Base/GCException.h>

namespace Pylon
{
    class LEFT;

    /// Lists all the types used by the LEFT camera class.
    struct LEFTTraits
    {
        /// The type of the final camera class.
        typedef LEFT InstantCamera_t;
        /// \copybrief LEFTCameraParams_Params::LEFTCameraParams
        typedef LEFTCameraParams_Params::LEFTCameraParams CameraParams_t;
        /// \copybrief Pylon::IPylonDevice
        typedef IPylonDevice IPylonDevice_t;
        /// \copybrief Pylon::CDeviceInfo
        typedef Pylon::CDeviceInfo DeviceInfo_t;
        /// \copybrief LEFTTLParams_Params::LEFTTLParams
        typedef CNodeMapProxyT<LEFTTLParams_Params::LEFTTLParams> TlParams_t;
        /// The parameters of the stream grabber.
        typedef CNodeMapProxyT<LEFTStreamParams_Params::LEFTStreamParams> StreamGrabberParams_t;
        /// The parameters of the event grabber.
        typedef CNodeMapProxyT<LEFTEventParams_Params::LEFTEventParams> EventGrabberParams_t;
        /// The configuration event handler class.
        typedef LEFTConfigurationEventHandler ConfigurationEventHandler_t;
        /// The image event handler class.
        typedef LEFTImageEventHandler ImageEventHandler_t;
        /// The camera event handler class.
        typedef LEFTCameraEventHandler CameraEventHandler_t;
        /// The grab result data.
        typedef LEFTGrabResultData GrabResultData_t;
        /// The grab result smart pointer.
        typedef LEFTGrabResultPtr GrabResultPtr_t;
        
        //! Can be used to check whether the DeviceClass() can be used for enumeration.
        static bool HasSpecificDeviceClass() { return false; }
        //! The name of this device class. Use this one for enumeration.
        static String_t DeviceClass() { throw LOGICAL_ERROR_EXCEPTION("The LEFT has no specific device class. The method DeviceClass() cannot be used."); }
       
    };
    /*!
    \class  LEFT
    \brief  Extends the CInstantCamera by a generated parameter interface classes combining user selected sources.
    */
    class LEFT : public CDeviceSpecificInstantCameraT<LEFTTraits>
    {
    public:
        /*!
            \copybrief CInstantCamera::CInstantCamera()
            \copydetails CInstantCamera::CInstantCamera
        */
        LEFT()
        {
        }

        /*!
            \copybrief CInstantCamera::CInstantCamera( IPylonDevice* , ECleanup )
            \copydetails CInstantCamera::CInstantCamera( IPylonDevice* , ECleanup )
        */
        LEFT(IPylonDevice* pDevice, ECleanup cleanupProcedure = Cleanup_Delete)
            : CDeviceSpecificInstantCameraT<LEFTTraits>(pDevice, cleanupProcedure)
        {
        }

        /*!
            \copybrief CInstantCamera::~CInstantCamera
            \copydetails CInstantCamera::~CInstantCamera
        */
        ~LEFT()
        {
            Attach( NULL);
            InternalShutdownEventHandlers();
        }

        /*!
        \brief Enables/disables use of persistent IP address and DHCP usage of the attached %Pylon Device.

        See Pylon::IPylonGigEDevice::ChangeIpConfiguration()

        \pre
        <ul>
        <li> A %Pylon Device is attached.
        <li> The %Pylon Device is open.
        </ul>

        \error
            The Instant Camera object is still valid after error.

        \threading
            This method is synchronized using the lock provided by GetLock().
        */
        void ChangeIpConfiguration( bool EnablePersistentIp, bool EnableDhcp )
        {
            AutoLock lock( CInstantCamera::GetLock());
            GetGigEDevice()->ChangeIpConfiguration( EnablePersistentIp, EnableDhcp );
        }

        /*!
        \brief Reads the persistent IP address from the attached %Pylon Device.

        See Pylon::IPylonGigEDevice::GetPersistentIpAddress()

        \pre
        <ul>
        <li> A %Pylon Device is attached.
        <li> The %Pylon Device is open.
        </ul>
        \error
            The Instant Camera object is still valid after error.

        \threading
            This method is synchronized using the lock provided by GetLock().
        */
        void GetPersistentIpAddress(String_t& IpAddress, String_t& SubnetMask, String_t& DefaultGateway)
        {
            AutoLock lock( CInstantCamera::GetLock());
            GetGigEDevice()->GetPersistentIpAddress( IpAddress, SubnetMask, DefaultGateway );
        }

        /*!
        \brief Writes a persistent IP address to the attached %Pylon Device.

        See Pylon::IPylonGigEDevice::SetPersistentIpAddress()

        \pre
        <ul>
        <li> A %Pylon Device is attached.
        <li> The %Pylon Device is open.
        </ul>
        \error
            The Instant Camera object is still valid after error.

        \threading
            This method is synchronized using the lock provided by GetLock().
        */
        void SetPersistentIpAddress(const String_t& IpAddress,
            const String_t& SubnetMask,
            const String_t& DefaultGateway)

        {
            AutoLock lock( CInstantCamera::GetLock());
            GetGigEDevice()->SetPersistentIpAddress( IpAddress, SubnetMask, DefaultGateway );
        }

    protected:
        //Get the pointer for the GigE device.
        virtual IPylonGigEDevice* GetGigEDevice()
        {
            IPylonDevice* pDevice = CInstantCamera::GetDevice();
            IPylonGigEDevice* pGigEDevice = dynamic_cast<IPylonGigEDevice*>(pDevice);

            // Check whether device type matches camera type.
            if ( !pGigEDevice )
            {
                throw LOGICAL_ERROR_EXCEPTION("The attached pylon device type must be a GigE device.");
            }

            return pGigEDevice;
        }

        //Create device grab result data. Is subject to change without notice.
        virtual CGrabResultData* CreateDeviceSpecificGrabResultData()
        {
            return new GrabResultData_t();
        }
    };

} // namespace Pylon

#endif /* INCLUDED_LEFTFILE_H_87483470 */