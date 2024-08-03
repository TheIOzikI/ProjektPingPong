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
#include "BaslerCamera123TLParams.h"

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA1920-155uc
namespace Pylon123
{
namespace BaslerCamera123TLParams_Params
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
    // Parameter class BaslerCamera123TLParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCamera123TLParams::BaslerCamera123TLParams_Data
    {
    public:
        Pylon::CBooleanParameter MigrationModeEnable;
        Pylon::CIntegerParameter Statistic_Last_Error_Status;
        Pylon::CStringParameter Statistic_Last_Error_Status_Text;
        Pylon::CIntegerParameter Statistic_Read_Operations_Failed_Count;
        Pylon::CIntegerParameter Statistic_Read_Pipe_Reset_Count;
        Pylon::CIntegerParameter Statistic_Write_Operations_Failed_Count;
        Pylon::CIntegerParameter Statistic_Write_Pipe_Reset_Count;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    BaslerCamera123TLParams::BaslerCamera123TLParams(void)
        : m_pData(new BaslerCamera123TLParams_Data())
        , MigrationModeEnable(m_pData->MigrationModeEnable)
        , Statistic_Last_Error_Status(m_pData->Statistic_Last_Error_Status)
        , Statistic_Last_Error_Status_Text(m_pData->Statistic_Last_Error_Status_Text)
        , Statistic_Read_Operations_Failed_Count(m_pData->Statistic_Read_Operations_Failed_Count)
        , Statistic_Read_Pipe_Reset_Count(m_pData->Statistic_Read_Pipe_Reset_Count)
        , Statistic_Write_Operations_Failed_Count(m_pData->Statistic_Write_Operations_Failed_Count)
        , Statistic_Write_Pipe_Reset_Count(m_pData->Statistic_Write_Pipe_Reset_Count)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    BaslerCamera123TLParams::~BaslerCamera123TLParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    void BaslerCamera123TLParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->MigrationModeEnable.Attach(pNodeMap, "MigrationModeEnable");
        m_pData->Statistic_Last_Error_Status.Attach(pNodeMap, "Statistic_Last_Error_Status");
        m_pData->Statistic_Last_Error_Status_Text.Attach(pNodeMap, "Statistic_Last_Error_Status_Text");
        m_pData->Statistic_Read_Operations_Failed_Count.Attach(pNodeMap, "Statistic_Read_Operations_Failed_Count");
        m_pData->Statistic_Read_Pipe_Reset_Count.Attach(pNodeMap, "Statistic_Read_Pipe_Reset_Count");
        m_pData->Statistic_Write_Operations_Failed_Count.Attach(pNodeMap, "Statistic_Write_Operations_Failed_Count");
        m_pData->Statistic_Write_Pipe_Reset_Count.Attach(pNodeMap, "Statistic_Write_Pipe_Reset_Count");
    }

    //! \endcond

} // namespace Pylon123
} // namespace BaslerCamera123TLParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif