//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for acA1920-155uc

Sources:
acA1920-155uc 106880-04;U;acA1920_155u;V0.5-1;1
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_RIGHTSTREAMPARAMS_H
#define BASLER_PYLON_RIGHTSTREAMPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA1920-155uc
namespace Pylon
{
namespace RIGHTStreamParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    
    
    //**************************************************************************************************
    // Parameter class RIGHTStreamParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106880-04;U;acA1920_155u;V0.5-1;1
    */
    class RIGHTStreamParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            RIGHTStreamParams(void);

            //! Destructor
            ~RIGHTStreamParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class RIGHTStreamParams_Data;
        RIGHTStreamParams_Data* m_pData;


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
            RIGHTStreamParams(RIGHTStreamParams&);

            //! not implemented assignment operator
            RIGHTStreamParams& operator=(RIGHTStreamParams&);

        //! \endcond
    };

    //**************************************************************************************************
    // Enumeration support classes
    //**************************************************************************************************
    //! \cond HIDE_CLASS_METHODS

    ///////////////////////////////////////////////////////////////////////////
    //
    namespace EnumParameterClasses
    {
    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class RIGHTStreamParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class RIGHTStreamParams::RIGHTStreamParams_Data
    {
    public:
        Pylon::CIntegerParameter MaxBufferSize;
        Pylon::CIntegerParameter MaxNumBuffer;
        Pylon::CIntegerParameter MaxTransferSize;
        Pylon::CIntegerParameter NumMaxQueuedUrbs;
        Pylon::CIntegerParameter Statistic_Failed_Buffer_Count;
        Pylon::CIntegerParameter Statistic_Last_Block_Id;
        Pylon::CIntegerParameter Statistic_Last_Failed_Buffer_Status;
        Pylon::CStringParameter Statistic_Last_Failed_Buffer_Status_Text;
        Pylon::CIntegerParameter Statistic_Missed_Frame_Count;
        Pylon::CIntegerParameter Statistic_Out_Of_Memory_Error_Count;
        Pylon::CIntegerParameter Statistic_Resynchronization_Count;
        Pylon::CIntegerParameter Statistic_Total_Buffer_Count;
        Pylon::CIntegerParameter TransferLoopThreadPriority;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline RIGHTStreamParams::RIGHTStreamParams(void)
        : m_pData(new RIGHTStreamParams_Data())
        , MaxBufferSize(m_pData->MaxBufferSize)
        , MaxNumBuffer(m_pData->MaxNumBuffer)
        , MaxTransferSize(m_pData->MaxTransferSize)
        , NumMaxQueuedUrbs(m_pData->NumMaxQueuedUrbs)
        , Statistic_Failed_Buffer_Count(m_pData->Statistic_Failed_Buffer_Count)
        , Statistic_Last_Block_Id(m_pData->Statistic_Last_Block_Id)
        , Statistic_Last_Failed_Buffer_Status(m_pData->Statistic_Last_Failed_Buffer_Status)
        , Statistic_Last_Failed_Buffer_Status_Text(m_pData->Statistic_Last_Failed_Buffer_Status_Text)
        , Statistic_Missed_Frame_Count(m_pData->Statistic_Missed_Frame_Count)
        , Statistic_Out_Of_Memory_Error_Count(m_pData->Statistic_Out_Of_Memory_Error_Count)
        , Statistic_Resynchronization_Count(m_pData->Statistic_Resynchronization_Count)
        , Statistic_Total_Buffer_Count(m_pData->Statistic_Total_Buffer_Count)
        , TransferLoopThreadPriority(m_pData->TransferLoopThreadPriority)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline RIGHTStreamParams::~RIGHTStreamParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void RIGHTStreamParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->MaxBufferSize.Attach(pNodeMap, "MaxBufferSize");
        m_pData->MaxNumBuffer.Attach(pNodeMap, "MaxNumBuffer");
        m_pData->MaxTransferSize.Attach(pNodeMap, "MaxTransferSize");
        m_pData->NumMaxQueuedUrbs.Attach(pNodeMap, "NumMaxQueuedUrbs");
        m_pData->Statistic_Failed_Buffer_Count.Attach(pNodeMap, "Statistic_Failed_Buffer_Count");
        m_pData->Statistic_Last_Block_Id.Attach(pNodeMap, "Statistic_Last_Block_Id");
        m_pData->Statistic_Last_Failed_Buffer_Status.Attach(pNodeMap, "Statistic_Last_Failed_Buffer_Status");
        m_pData->Statistic_Last_Failed_Buffer_Status_Text.Attach(pNodeMap, "Statistic_Last_Failed_Buffer_Status_Text");
        m_pData->Statistic_Missed_Frame_Count.Attach(pNodeMap, "Statistic_Missed_Frame_Count");
        m_pData->Statistic_Out_Of_Memory_Error_Count.Attach(pNodeMap, "Statistic_Out_Of_Memory_Error_Count");
        m_pData->Statistic_Resynchronization_Count.Attach(pNodeMap, "Statistic_Resynchronization_Count");
        m_pData->Statistic_Total_Buffer_Count.Attach(pNodeMap, "Statistic_Total_Buffer_Count");
        m_pData->TransferLoopThreadPriority.Attach(pNodeMap, "TransferLoopThreadPriority");
    }

    //! \endcond

} // namespace Pylon
} // namespace RIGHTStreamParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_RIGHTSTREAMPARAMS_H