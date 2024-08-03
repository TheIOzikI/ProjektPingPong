//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

// common parameter types
#if defined(PYLON_GENERATED_PARAMETER_CLASSES_USE_STDAFX)
#include "stdafx.h"
#endif
#include "BaslerCamera123StreamParams.h"

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
    // Parameter class BaslerCamera123StreamParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCamera123StreamParams::BaslerCamera123StreamParams_Data
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
    BaslerCamera123StreamParams::BaslerCamera123StreamParams(void)
        : m_pData(new BaslerCamera123StreamParams_Data())
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
    BaslerCamera123StreamParams::~BaslerCamera123StreamParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    void BaslerCamera123StreamParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
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

} // namespace Pylon123
} // namespace BaslerCamera123StreamParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif