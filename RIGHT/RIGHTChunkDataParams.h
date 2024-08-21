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

#ifndef BASLER_PYLON_RIGHTCHUNKDATAPARAMS_H
#define BASLER_PYLON_RIGHTCHUNKDATAPARAMS_H

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
namespace RIGHTChunkDataParams_Params
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
    // Parameter class RIGHTChunkDataParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106880-04;U;acA1920_155u;V0.5-1;1
    */
    class RIGHTChunkDataParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            RIGHTChunkDataParams(void);

            //! Destructor
            ~RIGHTChunkDataParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class RIGHTChunkDataParams_Data;
        RIGHTChunkDataParams_Data* m_pData;


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
            RIGHTChunkDataParams(RIGHTChunkDataParams&);

            //! not implemented assignment operator
            RIGHTChunkDataParams& operator=(RIGHTChunkDataParams&);

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
        ///////////////////////////////////////////////////////////////////////////
        //
        class ChunkCounterSelectorEnumParameter : public Pylon::CEnumParameterT<ChunkCounterSelectorEnums>
        {
        public:
            ChunkCounterSelectorEnumParameter()
            {
            }

            virtual ~ChunkCounterSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ChunkGainSelectorEnumParameter : public Pylon::CEnumParameterT<ChunkGainSelectorEnums>
        {
        public:
            ChunkGainSelectorEnumParameter()
            {
            }

            virtual ~ChunkGainSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class RIGHTChunkDataParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class RIGHTChunkDataParams::RIGHTChunkDataParams_Data
    {
    public:
        EnumParameterClasses::ChunkCounterSelectorEnumParameter ChunkCounterSelector;
        Pylon::CIntegerParameter ChunkCounterValue;
        Pylon::CFloatParameter ChunkExposureTime;
        Pylon::CFloatParameter ChunkGain;
        EnumParameterClasses::ChunkGainSelectorEnumParameter ChunkGainSelector;
        Pylon::CIntegerParameter ChunkLineStatusAll;
        Pylon::CIntegerParameter ChunkPayloadCRC16;
        Pylon::CIntegerParameter ChunkTimestamp;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline RIGHTChunkDataParams::RIGHTChunkDataParams(void)
        : m_pData(new RIGHTChunkDataParams_Data())
        , ChunkCounterSelector(m_pData->ChunkCounterSelector)
        , ChunkCounterValue(m_pData->ChunkCounterValue)
        , ChunkExposureTime(m_pData->ChunkExposureTime)
        , ChunkGain(m_pData->ChunkGain)
        , ChunkGainSelector(m_pData->ChunkGainSelector)
        , ChunkLineStatusAll(m_pData->ChunkLineStatusAll)
        , ChunkPayloadCRC16(m_pData->ChunkPayloadCRC16)
        , ChunkTimestamp(m_pData->ChunkTimestamp)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline RIGHTChunkDataParams::~RIGHTChunkDataParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void RIGHTChunkDataParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->ChunkCounterSelector.Attach(pNodeMap, "ChunkCounterSelector");
        m_pData->ChunkCounterValue.Attach(pNodeMap, "ChunkCounterValue");
        m_pData->ChunkExposureTime.Attach(pNodeMap, "ChunkExposureTime");
        m_pData->ChunkGain.Attach(pNodeMap, "ChunkGain");
        m_pData->ChunkGainSelector.Attach(pNodeMap, "ChunkGainSelector");
        m_pData->ChunkLineStatusAll.Attach(pNodeMap, "ChunkLineStatusAll");
        m_pData->ChunkPayloadCRC16.Attach(pNodeMap, "ChunkPayloadCRC16");
        m_pData->ChunkTimestamp.Attach(pNodeMap, "ChunkTimestamp");
    }

    //! \endcond

} // namespace Pylon
} // namespace RIGHTChunkDataParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_RIGHTCHUNKDATAPARAMS_H