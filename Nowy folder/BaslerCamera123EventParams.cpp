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
#include "BaslerCamera123EventParams.h"

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA1920-155uc
namespace Pylon123
{
namespace BaslerCamera123EventParams_Params
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
    // Parameter class BaslerCamera123EventParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCamera123EventParams::BaslerCamera123EventParams_Data
    {
    public:
        Pylon::CIntegerParameter NumBuffer;
        Pylon::CIntegerParameter NumMaxQueuedUrbs;
        Pylon::CIntegerParameter Statistic_Failed_Event_Count;
        Pylon::CIntegerParameter Statistic_Last_Failed_Event_Buffer_Status;
        Pylon::CIntegerParameter Statistic_Total_Event_Count;
        Pylon::CIntegerParameter TransferLoopThreadPriority;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    BaslerCamera123EventParams::BaslerCamera123EventParams(void)
        : m_pData(new BaslerCamera123EventParams_Data())
        , NumBuffer(m_pData->NumBuffer)
        , NumMaxQueuedUrbs(m_pData->NumMaxQueuedUrbs)
        , Statistic_Failed_Event_Count(m_pData->Statistic_Failed_Event_Count)
        , Statistic_Last_Failed_Event_Buffer_Status(m_pData->Statistic_Last_Failed_Event_Buffer_Status)
        , Statistic_Total_Event_Count(m_pData->Statistic_Total_Event_Count)
        , TransferLoopThreadPriority(m_pData->TransferLoopThreadPriority)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    BaslerCamera123EventParams::~BaslerCamera123EventParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    void BaslerCamera123EventParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->NumBuffer.Attach(pNodeMap, "NumBuffer");
        m_pData->NumMaxQueuedUrbs.Attach(pNodeMap, "NumMaxQueuedUrbs");
        m_pData->Statistic_Failed_Event_Count.Attach(pNodeMap, "Statistic_Failed_Event_Count");
        m_pData->Statistic_Last_Failed_Event_Buffer_Status.Attach(pNodeMap, "Statistic_Last_Failed_Event_Buffer_Status");
        m_pData->Statistic_Total_Event_Count.Attach(pNodeMap, "Statistic_Total_Event_Count");
        m_pData->TransferLoopThreadPriority.Attach(pNodeMap, "TransferLoopThreadPriority");
    }

    //! \endcond

} // namespace Pylon123
} // namespace BaslerCamera123EventParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif