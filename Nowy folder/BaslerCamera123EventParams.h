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

#ifndef BASLER_PYLON_BASLERCAMERA123EVENTPARAMS_H
#define BASLER_PYLON_BASLERCAMERA123EVENTPARAMS_H

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
namespace BaslerCamera123EventParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    
    
    //**************************************************************************************************
    // Parameter class BaslerCamera123EventParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106591-14;U;acA1920_155u;V0.2-2;1
    */
    class BaslerCamera123EventParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCamera123EventParams(void);

            //! Destructor
            ~BaslerCamera123EventParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCamera123EventParams_Data;
        BaslerCamera123EventParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: Root
    //@{
    /*!
        \brief Number of buffers to be used - Applies to: acA1920-155uc

        Number of Buffers that are going to be used receiving events.
    
        Visibility: Expert

    */
    Pylon::IIntegerEx& NumBuffer;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Maximum number of USB request blocks (URBs) to be enqueued simultaneously - Applies to: acA1920-155uc

    
        Visibility: Guru

    */
    Pylon::IIntegerEx& NumMaxQueuedUrbs;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Count of processed events with an error status - Applies to: acA1920-155uc

    
        Visibility: Expert

    */
    Pylon::IIntegerEx& Statistic_Failed_Event_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Status code of the last failed event buffer - Applies to: acA1920-155uc

    
        Visibility: Expert

    */
    Pylon::IIntegerEx& Statistic_Last_Failed_Event_Buffer_Status;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Total count of processed events - Applies to: acA1920-155uc

    
        Visibility: Expert

    */
    Pylon::IIntegerEx& Statistic_Total_Event_Count;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Priority of the thread that handles USB requests from the stream interface - Applies to: acA1920-155uc

    
        Visibility: Guru

    */
    Pylon::IIntegerEx& TransferLoopThreadPriority;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCamera123EventParams(BaslerCamera123EventParams&);

            //! not implemented assignment operator
            BaslerCamera123EventParams& operator=(BaslerCamera123EventParams&);

        //! \endcond
    };

} // namespace Pylon123
} // namespace BaslerCamera123EventParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERA123EVENTPARAMS_H