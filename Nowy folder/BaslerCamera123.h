//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief instant camera class
*/

#ifndef INCLUDED_BASLERCAMERA123FILE_H_87483470
#define INCLUDED_BASLERCAMERA123FILE_H_87483470

#pragma once

#include "BaslerCamera123CameraParams.h"
#include "BaslerCamera123StreamParams.h"
#include "BaslerCamera123EventParams.h"
#include "BaslerCamera123TLParams.h"
#include "BaslerCamera123ConfigurationEventHandler.h"
#include "BaslerCamera123ImageEventHandler.h"
#include "BaslerCamera123CameraEventHandler.h"
#include "BaslerCamera123GrabResultPtr.h"
#include <pylon/private/DeviceSpecificInstantCamera.h>
#include <pylon/gige/PylonGigEDevice.h>
#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <Base/GCException.h>

namespace Pylon123
{
    class BaslerCamera123;

    /// Lists all the types used by the BaslerCamera123 camera class.
    struct BaslerCamera123Traits
    {
        /// The type of the final camera class.
        typedef BaslerCamera123 InstantCamera_t;
        /// \copybrief BaslerCamera123CameraParams_Params::BaslerCamera123CameraParams
        typedef BaslerCamera123CameraParams_Params::BaslerCamera123CameraParams CameraParams_t;
        /// \copybrief Pylon::IPylonDevice
        typedef IPylonDevice IPylonDevice_t;
        /// \copybrief Pylon::CDeviceInfo
        typedef Pylon::CDeviceInfo DeviceInfo_t;
        /// \copybrief BaslerCamera123TLParams_Params::BaslerCamera123TLParams
        typedef CNodeMapProxyT<BaslerCamera123TLParams_Params::BaslerCamera123TLParams> TlParams_t;
        /// The parameters of the stream grabber.
        typedef CNodeMapProxyT<BaslerCamera123StreamParams_Params::BaslerCamera123StreamParams> StreamGrabberParams_t;
        /// The parameters of the event grabber.
        typedef CNodeMapProxyT<BaslerCamera123EventParams_Params::BaslerCamera123EventParams> EventGrabberParams_t;
        /// The configuration event handler class.
        typedef BaslerCamera123ConfigurationEventHandler ConfigurationEventHandler_t;
        /// The image event handler class.
        typedef BaslerCamera123ImageEventHandler ImageEventHandler_t;
        /// The camera event handler class.
        typedef BaslerCamera123CameraEventHandler CameraEventHandler_t;
        /// The grab result data.
        typedef BaslerCamera123GrabResultData GrabResultData_t;
        /// The grab result smart pointer.
        typedef BaslerCamera123GrabResultPtr GrabResultPtr_t;
        
        //! Can be used to check whether the DeviceClass() can be used for enumeration.
        static bool HasSpecificDeviceClass() { return false; }
        //! The name of this device class. Use this one for enumeration.
        static String_t DeviceClass() { throw LOGICAL_ERROR_EXCEPTION("The BaslerCamera123 has no specific device class. The method DeviceClass() cannot be used."); }
       
    };
    /*!
    \class  BaslerCamera123
    \brief  Extends the CInstantCamera by a generated parameter interface classes combining user selected sources.
    */
    class BaslerCamera123 : public CDeviceSpecificInstantCameraT<BaslerCamera123Traits>
    {
    public:
        /*!
            \copybrief CInstantCamera::CInstantCamera()
            \copydetails CInstantCamera::CInstantCamera
        */
        BaslerCamera123()
        {
        }

        /*!
            \copybrief CInstantCamera::CInstantCamera( IPylonDevice* , ECleanup )
            \copydetails CInstantCamera::CInstantCamera( IPylonDevice* , ECleanup )
        */
        BaslerCamera123(IPylonDevice* pDevice, ECleanup cleanupProcedure = Cleanup_Delete)
            : CDeviceSpecificInstantCameraT<BaslerCamera123Traits>(pDevice, cleanupProcedure)
        {
        }

        /*!
            \copybrief CInstantCamera::~CInstantCamera
            \copydetails CInstantCamera::~CInstantCamera
        */
        ~BaslerCamera123()
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

} // namespace Pylon123

#endif /* INCLUDED_BASLERCAMERA123FILE_H_87483470 */