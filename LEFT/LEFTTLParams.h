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

#ifndef BASLER_PYLON_LEFTTLPARAMS_H
#define BASLER_PYLON_LEFTTLPARAMS_H

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
namespace LEFTTLParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    
    
    //**************************************************************************************************
    // Parameter class LEFTTLParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106880-04;U;acA1920_155u;V0.5-1;1
    */
    class LEFTTLParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            LEFTTLParams(void);

            //! Destructor
            ~LEFTTLParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class LEFTTLParams_Data;
        LEFTTLParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: Root
    //@{
    /*!
        \brief Enables mapping of certain SFNC 1 x node names to SFNC 2 x node names - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MigrationModeEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& MigrationModeEnable;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Last error status of a read or write operation - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Last_Error_Status" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Last_Error_Status;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Last error status of a read or write operation - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Last_Error_Status_Text" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& Statistic_Last_Error_Status_Text;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of failed read operations - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Read_Operations_Failed_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Read_Operations_Failed_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of read pipe resets - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Read_Pipe_Reset_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Read_Pipe_Reset_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of failed write operations - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Write_Operations_Failed_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Write_Operations_Failed_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Number of write pipe resets - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Write_Pipe_Reset_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Write_Pipe_Reset_Count;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            LEFTTLParams(LEFTTLParams&);

            //! not implemented assignment operator
            LEFTTLParams& operator=(LEFTTLParams&);

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
    // Parameter class LEFTTLParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class LEFTTLParams::LEFTTLParams_Data
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
    inline LEFTTLParams::LEFTTLParams(void)
        : m_pData(new LEFTTLParams_Data())
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
    inline LEFTTLParams::~LEFTTLParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void LEFTTLParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
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

} // namespace Pylon
} // namespace LEFTTLParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_LEFTTLPARAMS_H