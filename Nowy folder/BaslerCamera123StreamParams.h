//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for acA1920-155uc

Sources:
acA1920-155uc 106591-14;U;acA1920_155u;V0.2-2;1
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_BASLERCAMERA123STREAMPARAMS_H
#define BASLER_PYLON_BASLERCAMERA123STREAMPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA1920-155uc
namespace Pylon123
{
namespace BaslerCamera123StreamParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    
    
    //**************************************************************************************************
    // Parameter class BaslerCamera123StreamParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106591-14;U;acA1920_155u;V0.2-2;1
    */
    class BaslerCamera123StreamParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCamera123StreamParams(void);

            //! Destructor
            ~BaslerCamera123StreamParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCamera123StreamParams_Data;
        BaslerCamera123StreamParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: Root
    //@{
    /*!
        \brief Maximum size (in bytes) of a buffer used for grabbing images - Applies to: acA1920-155uc

        Maximum size (in bytes) of a buffer used for grabbing images. A grab application must set this parameter before grabbing starts.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MaxBufferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MaxBufferSize;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Maximum number of buffers that can be used simultaneously for grabbing images - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MaxNumBuffer" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MaxNumBuffer;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Maximum USB data transfer size in bytes - Applies to: acA1920-155uc

        
            
            Maximum USB data transfer size in bytes. 
            The default value is appropriate for most applications. 
            Decreasing the value may increase the CPU load. 
            USB host adapter drivers may require decreasing the value 
            if the application fails to receive the image stream. 
            The maximum value also depends on the operating system.
            
        
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MaxTransferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MaxTransferSize;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Maximum number of USB request blocks (URBs) to be enqueued simultaneously - Applies to: acA1920-155uc

        Maximum number of USB request blocks (URBs) to be enqueued simultaneously. Increasing this value may improve stability and reduce jitter, but requires more resources on the host computer.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NumMaxQueuedUrbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& NumMaxQueuedUrbs;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief GigE cameras: Number of buffers with at least one failed packet  A packet is considered failed if its status is not 'success'  Other cameras: Number of buffers that returned with an error status   - Applies to: acA1920-155uc

        GigE cameras: Number of buffers with at least one failed packet. A packet is considered failed if its status is not 'success'. Other cameras: Number of buffers that returned an error. 
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Failed_Buffer_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Failed_Buffer_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Last grabbed block ID - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Last_Block_Id" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Last_Block_Id;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Status code of the last failed buffer - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Last_Failed_Buffer_Status" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Last_Failed_Buffer_Status;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Status code of the last failed buffer - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Last_Failed_Buffer_Status_Text" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& Statistic_Last_Failed_Buffer_Status_Text;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of corrupt or lost frames between successfully grabbed images - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Missed_Frame_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Missed_Frame_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of out-of-memory errors - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Out_Of_Memory_Error_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Out_Of_Memory_Error_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of stream resynchronizations - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Resynchronization_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Resynchronization_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief GigE cameras: Number of frames received  Other cameras: Number of buffers processed - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Total_Buffer_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Total_Buffer_Count;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Priority of the thread that handles USB requests from the stream interface - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TransferLoopThreadPriority" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TransferLoopThreadPriority;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCamera123StreamParams(BaslerCamera123StreamParams&);

            //! not implemented assignment operator
            BaslerCamera123StreamParams& operator=(BaslerCamera123StreamParams&);

        //! \endcond
    };

} // namespace Pylon123
} // namespace BaslerCamera123StreamParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERA123STREAMPARAMS_H