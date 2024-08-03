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

#ifndef BASLER_PYLON_BASLERCAMERA123CHUNKDATAPARAMS_H
#define BASLER_PYLON_BASLERCAMERA123CHUNKDATAPARAMS_H

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
namespace BaslerCamera123ChunkDataParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for ChunkCounterSelector
    enum ChunkCounterSelectorEnums
    {
        ChunkCounterSelector_Todo  //!< TODO - Applies to: acA1920-155uc
    };

    //! Valid values for ChunkGainSelector
    enum ChunkGainSelectorEnums
    {
        ChunkGainSelector_Todo  //!< TODO - Applies to: acA1920-155uc
    };


    
    
    //**************************************************************************************************
    // Parameter class BaslerCamera123ChunkDataParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106591-14;U;acA1920_155u;V0.2-2;1
    */
    class BaslerCamera123ChunkDataParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCamera123ChunkDataParams(void);

            //! Destructor
            ~BaslerCamera123ChunkDataParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCamera123ChunkDataParams_Data;
        BaslerCamera123ChunkDataParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Selects which counter to retrieve data from - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selecting Parameters: ChunkCounterValue

    */
    Pylon::IEnumParameterT<ChunkCounterSelectorEnums>& ChunkCounterSelector;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Indicates the value of the selected Chunk counter - Applies to: acA1920-155uc

        Indicates the value of the selected Chunk counter.
    
        Visibility: Beginner

        Selected by: ChunkCounterSelector

    */
    Pylon::IIntegerEx& ChunkCounterValue;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Returns the exposure time used to capture the image - Applies to: acA1920-155uc

    
        Visibility: Beginner

    */
    Pylon::IFloatEx& ChunkExposureTime;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Returns the gain used to capture the image - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selected by: ChunkGainSelector

    */
    Pylon::IFloatEx& ChunkGain;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Selects which Gain to retrieve data from - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selecting Parameters: ChunkGain

    */
    Pylon::IEnumParameterT<ChunkGainSelectorEnums>& ChunkGainSelector;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief A bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: acA1920-155uc

        This value is a bit field that indicates the status of all of the camera's input and output lines when the image was acquired.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkLineStatusAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Indicates the value of CRC checksum - Applies to: acA1920-155uc

        This integer indicates the value of CRC checksum.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Indicates the value of the timestamp when the image was acquired - Applies to: acA1920-155uc

        This integer indicates the value of the timestamp when the image was acquired.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkTimestamp;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCamera123ChunkDataParams(BaslerCamera123ChunkDataParams&);

            //! not implemented assignment operator
            BaslerCamera123ChunkDataParams& operator=(BaslerCamera123ChunkDataParams&);

        //! \endcond
    };

} // namespace Pylon123
} // namespace BaslerCamera123ChunkDataParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERA123CHUNKDATAPARAMS_H