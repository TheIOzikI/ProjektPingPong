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
#include "BaslerCamera123CameraParams.h"

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA1920-155uc
namespace Pylon123
{
namespace BaslerCamera123CameraParams_Params
{
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
        class AcquisitionModeEnumParameter : public Pylon::CEnumParameterT<AcquisitionModeEnums>
        {
        public:
            AcquisitionModeEnumParameter()
            {
            }

            virtual ~AcquisitionModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("SingleFrame", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class AcquisitionStatusSelectorEnumParameter : public Pylon::CEnumParameterT<AcquisitionStatusSelectorEnums>
        {
        public:
            AcquisitionStatusSelectorEnumParameter()
            {
            }

            virtual ~AcquisitionStatusSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameBurstTriggerWait", 22),
                    TableItem_t("FrameTriggerWait", 17)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BalanceRatioSelectorEnumParameter : public Pylon::CEnumParameterT<BalanceRatioSelectorEnums>
        {
        public:
            BalanceRatioSelectorEnumParameter()
            {
            }

            virtual ~BalanceRatioSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Blue", 5),
                    TableItem_t("Green", 6),
                    TableItem_t("Red", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BlackLevelSelectorEnumParameter : public Pylon::CEnumParameterT<BlackLevelSelectorEnums>
        {
        public:
            BlackLevelSelectorEnumParameter()
            {
            }

            virtual ~BlackLevelSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("All", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslUSBSpeedModeEnumParameter : public Pylon::CEnumParameterT<BslUSBSpeedModeEnums>
        {
        public:
            BslUSBSpeedModeEnumParameter()
            {
            }

            virtual ~BslUSBSpeedModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("HighSpeed", 10),
                    TableItem_t("SuperSpeed", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


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


        ///////////////////////////////////////////////////////////////////////////
        //
        class ChunkSelectorEnumParameter : public Pylon::CEnumParameterT<ChunkSelectorEnums>
        {
        public:
            ChunkSelectorEnumParameter()
            {
            }

            virtual ~ChunkSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CounterValue", 13),
                    TableItem_t("ExposureTime", 13),
                    TableItem_t("Gain", 5),
                    TableItem_t("LineStatusAll", 14),
                    TableItem_t("PayloadCRC16", 13),
                    TableItem_t("Timestamp", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ColorAdjustmentSelectorEnumParameter : public Pylon::CEnumParameterT<ColorAdjustmentSelectorEnums>
        {
        public:
            ColorAdjustmentSelectorEnumParameter()
            {
            }

            virtual ~ColorAdjustmentSelectorEnumParameter()
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
        class ColorTransformationSelectorEnumParameter : public Pylon::CEnumParameterT<ColorTransformationSelectorEnums>
        {
        public:
            ColorTransformationSelectorEnumParameter()
            {
            }

            virtual ~ColorTransformationSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("RGBtoRGB", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ColorTransformationValueSelectorEnumParameter : public Pylon::CEnumParameterT<ColorTransformationValueSelectorEnums>
        {
        public:
            ColorTransformationValueSelectorEnumParameter()
            {
            }

            virtual ~ColorTransformationValueSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 9;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Gain00", 7),
                    TableItem_t("Gain01", 7),
                    TableItem_t("Gain02", 7),
                    TableItem_t("Gain10", 7),
                    TableItem_t("Gain11", 7),
                    TableItem_t("Gain12", 7),
                    TableItem_t("Gain20", 7),
                    TableItem_t("Gain21", 7),
                    TableItem_t("Gain22", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterEventSourceEnumParameter : public Pylon::CEnumParameterT<CounterEventSourceEnums>
        {
        public:
            CounterEventSourceEnumParameter()
            {
            }

            virtual ~CounterEventSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameStart", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterResetActivationEnumParameter : public Pylon::CEnumParameterT<CounterResetActivationEnums>
        {
        public:
            CounterResetActivationEnumParameter()
            {
            }

            virtual ~CounterResetActivationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("RisingEdge", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterResetSourceEnumParameter : public Pylon::CEnumParameterT<CounterResetSourceEnums>
        {
        public:
            CounterResetSourceEnumParameter()
            {
            }

            virtual ~CounterResetSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line1", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6),
                    TableItem_t("Off", 4),
                    TableItem_t("Software", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterSelectorEnumParameter : public Pylon::CEnumParameterT<CounterSelectorEnums>
        {
        public:
            CounterSelectorEnumParameter()
            {
            }

            virtual ~CounterSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Counter1", 9),
                    TableItem_t("Counter2", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceLinkThroughputLimitModeEnumParameter : public Pylon::CEnumParameterT<DeviceLinkThroughputLimitModeEnums>
        {
        public:
            DeviceLinkThroughputLimitModeEnumParameter()
            {
            }

            virtual ~DeviceLinkThroughputLimitModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceScanTypeEnumParameter : public Pylon::CEnumParameterT<DeviceScanTypeEnums>
        {
        public:
            DeviceScanTypeEnumParameter()
            {
            }

            virtual ~DeviceScanTypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Areascan", 9),
                    TableItem_t("Linescan", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceTemperatureSelectorEnumParameter : public Pylon::CEnumParameterT<DeviceTemperatureSelectorEnums>
        {
        public:
            DeviceTemperatureSelectorEnumParameter()
            {
            }

            virtual ~DeviceTemperatureSelectorEnumParameter()
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
        class EventNotificationEnumParameter : public Pylon::CEnumParameterT<EventNotificationEnums>
        {
        public:
            EventNotificationEnumParameter()
            {
            }

            virtual ~EventNotificationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class EventSelectorEnumParameter : public Pylon::CEnumParameterT<EventSelectorEnums>
        {
        public:
            EventSelectorEnumParameter()
            {
            }

            virtual ~EventSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExposureEnd", 12),
                    TableItem_t("FrameBurstStart", 16),
                    TableItem_t("FrameBurstStartOvertrigger", 27),
                    TableItem_t("FrameStart", 11),
                    TableItem_t("FrameStartOvertrigger", 22)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExpertFeatureAccessSelectorEnumParameter : public Pylon::CEnumParameterT<ExpertFeatureAccessSelectorEnums>
        {
        public:
            ExpertFeatureAccessSelectorEnumParameter()
            {
            }

            virtual ~ExpertFeatureAccessSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExpertFeature1", 15),
                    TableItem_t("ExpertFeature2", 15),
                    TableItem_t("ExpertFeature3", 15),
                    TableItem_t("ExpertFeature4", 15),
                    TableItem_t("ExpertFeature5", 15),
                    TableItem_t("ExpertFeature6", 15),
                    TableItem_t("ExpertFeature7", 15)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExposureModeEnumParameter : public Pylon::CEnumParameterT<ExposureModeEnums>
        {
        public:
            ExposureModeEnumParameter()
            {
            }

            virtual ~ExposureModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Timed", 6),
                    TableItem_t("TriggerWidth", 13)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileOpenModeEnumParameter : public Pylon::CEnumParameterT<FileOpenModeEnums>
        {
        public:
            FileOpenModeEnumParameter()
            {
            }

            virtual ~FileOpenModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Read", 5),
                    TableItem_t("Write", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileOperationSelectorEnumParameter : public Pylon::CEnumParameterT<FileOperationSelectorEnums>
        {
        public:
            FileOperationSelectorEnumParameter()
            {
            }

            virtual ~FileOperationSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Close", 6),
                    TableItem_t("Open", 5),
                    TableItem_t("Read", 5),
                    TableItem_t("Write", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileOperationStatusEnumParameter : public Pylon::CEnumParameterT<FileOperationStatusEnums>
        {
        public:
            FileOperationStatusEnumParameter()
            {
            }

            virtual ~FileOperationStatusEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Failure", 8),
                    TableItem_t("Success", 8)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileSelectorEnumParameter : public Pylon::CEnumParameterT<FileSelectorEnums>
        {
        public:
            FileSelectorEnumParameter()
            {
            }

            virtual ~FileSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 9;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExpertFeature7File", 19),
                    TableItem_t("UserData", 9),
                    TableItem_t("UserGainShading1", 17),
                    TableItem_t("UserGainShading2", 17),
                    TableItem_t("UserOffsetShading1", 19),
                    TableItem_t("UserOffsetShading2", 19),
                    TableItem_t("UserSet1", 9),
                    TableItem_t("UserSet2", 9),
                    TableItem_t("UserSet3", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class GainSelectorEnumParameter : public Pylon::CEnumParameterT<GainSelectorEnums>
        {
        public:
            GainSelectorEnumParameter()
            {
            }

            virtual ~GainSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("All", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LUTSelectorEnumParameter : public Pylon::CEnumParameterT<LUTSelectorEnums>
        {
        public:
            LUTSelectorEnumParameter()
            {
            }

            virtual ~LUTSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Luminance", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LightSourcePresetEnumParameter : public Pylon::CEnumParameterT<LightSourcePresetEnums>
        {
        public:
            LightSourcePresetEnumParameter()
            {
            }

            virtual ~LightSourcePresetEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Daylight5000K", 14),
                    TableItem_t("Daylight6500K", 14),
                    TableItem_t("Off", 4),
                    TableItem_t("Tungsten2800K", 14)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineFormatEnumParameter : public Pylon::CEnumParameterT<LineFormatEnums>
        {
        public:
            LineFormatEnumParameter()
            {
            }

            virtual ~LineFormatEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("OptoCoupled", 12),
                    TableItem_t("TTL", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineLogicEnumParameter : public Pylon::CEnumParameterT<LineLogicEnums>
        {
        public:
            LineLogicEnumParameter()
            {
            }

            virtual ~LineLogicEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Negative", 9),
                    TableItem_t("Positive", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineModeEnumParameter : public Pylon::CEnumParameterT<LineModeEnums>
        {
        public:
            LineModeEnumParameter()
            {
            }

            virtual ~LineModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Input", 6),
                    TableItem_t("Output", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineSelectorEnumParameter : public Pylon::CEnumParameterT<LineSelectorEnums>
        {
        public:
            LineSelectorEnumParameter()
            {
            }

            virtual ~LineSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line1", 6),
                    TableItem_t("Line2", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineSourceEnumParameter : public Pylon::CEnumParameterT<LineSourceEnums>
        {
        public:
            LineSourceEnumParameter()
            {
            }

            virtual ~LineSourceEnumParameter()
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
        class PixelColorFilterEnumParameter : public Pylon::CEnumParameterT<PixelColorFilterEnums>
        {
        public:
            PixelColorFilterEnumParameter()
            {
            }

            virtual ~PixelColorFilterEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("BayerRG", 8)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class PixelFormatEnumParameter : public Pylon::CEnumParameterT<PixelFormatEnums>
        {
        public:
            PixelFormatEnumParameter()
            {
            }

            virtual ~PixelFormatEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("BayerRG12", 10),
                    TableItem_t("BayerRG12p", 11),
                    TableItem_t("BayerRG8", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class PixelSizeEnumParameter : public Pylon::CEnumParameterT<PixelSizeEnums>
        {
        public:
            PixelSizeEnumParameter()
            {
            }

            virtual ~PixelSizeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Bpp12", 6),
                    TableItem_t("Bpp16", 6),
                    TableItem_t("Bpp8", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class RemoveParameterLimitSelectorEnumParameter : public Pylon::CEnumParameterT<RemoveParameterLimitSelectorEnums>
        {
        public:
            RemoveParameterLimitSelectorEnumParameter()
            {
            }

            virtual ~RemoveParameterLimitSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Gain", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ShutterModeEnumParameter : public Pylon::CEnumParameterT<ShutterModeEnums>
        {
        public:
            ShutterModeEnumParameter()
            {
            }

            virtual ~ShutterModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Global", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class SoftwareSignalSelectorEnumParameter : public Pylon::CEnumParameterT<SoftwareSignalSelectorEnums>
        {
        public:
            SoftwareSignalSelectorEnumParameter()
            {
            }

            virtual ~SoftwareSignalSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("SoftwareSignal1", 16),
                    TableItem_t("SoftwareSignal2", 16)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TestImageSelectorEnumParameter : public Pylon::CEnumParameterT<TestImageSelectorEnums>
        {
        public:
            TestImageSelectorEnumParameter()
            {
            }

            virtual ~TestImageSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("Testimage1", 11),
                    TableItem_t("Testimage2", 11),
                    TableItem_t("Testimage3", 11),
                    TableItem_t("Testimage4", 11),
                    TableItem_t("Testimage5", 11),
                    TableItem_t("Testimage6", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TimerSelectorEnumParameter : public Pylon::CEnumParameterT<TimerSelectorEnums>
        {
        public:
            TimerSelectorEnumParameter()
            {
            }

            virtual ~TimerSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Timer1", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TimerTriggerSourceEnumParameter : public Pylon::CEnumParameterT<TimerTriggerSourceEnums>
        {
        public:
            TimerTriggerSourceEnumParameter()
            {
            }

            virtual ~TimerTriggerSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExposureStart", 14)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerActivationEnumParameter : public Pylon::CEnumParameterT<TriggerActivationEnums>
        {
        public:
            TriggerActivationEnumParameter()
            {
            }

            virtual ~TriggerActivationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FallingEdge", 12),
                    TableItem_t("RisingEdge", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerModeEnumParameter : public Pylon::CEnumParameterT<TriggerModeEnums>
        {
        public:
            TriggerModeEnumParameter()
            {
            }

            virtual ~TriggerModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerSelectorEnumParameter : public Pylon::CEnumParameterT<TriggerSelectorEnums>
        {
        public:
            TriggerSelectorEnumParameter()
            {
            }

            virtual ~TriggerSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameBurstStart", 16),
                    TableItem_t("FrameStart", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerSourceEnumParameter : public Pylon::CEnumParameterT<TriggerSourceEnums>
        {
        public:
            TriggerSourceEnumParameter()
            {
            }

            virtual ~TriggerSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line1", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6),
                    TableItem_t("Software", 9),
                    TableItem_t("SoftwareSignal1", 16),
                    TableItem_t("SoftwareSignal2", 16)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserDefinedValueSelectorEnumParameter : public Pylon::CEnumParameterT<UserDefinedValueSelectorEnums>
        {
        public:
            UserDefinedValueSelectorEnumParameter()
            {
            }

            virtual ~UserDefinedValueSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Value1", 7),
                    TableItem_t("Value2", 7),
                    TableItem_t("Value3", 7),
                    TableItem_t("Value4", 7),
                    TableItem_t("Value5", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserOutputSelectorEnumParameter : public Pylon::CEnumParameterT<UserOutputSelectorEnums>
        {
        public:
            UserOutputSelectorEnumParameter()
            {
            }

            virtual ~UserOutputSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("UserOutput1", 12),
                    TableItem_t("UserOutput2", 12),
                    TableItem_t("UserOutput3", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserSetDefaultEnumParameter : public Pylon::CEnumParameterT<UserSetDefaultEnums>
        {
        public:
            UserSetDefaultEnumParameter()
            {
            }

            virtual ~UserSetDefaultEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("AutoFunctions", 14),
                    TableItem_t("Default", 8),
                    TableItem_t("HighGain", 9),
                    TableItem_t("UserSet1", 9),
                    TableItem_t("UserSet2", 9),
                    TableItem_t("UserSet3", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserSetSelectorEnumParameter : public Pylon::CEnumParameterT<UserSetSelectorEnums>
        {
        public:
            UserSetSelectorEnumParameter()
            {
            }

            virtual ~UserSetSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("AutoFunctions", 14),
                    TableItem_t("Default", 8),
                    TableItem_t("HighGain", 9),
                    TableItem_t("UserSet1", 9),
                    TableItem_t("UserSet2", 9),
                    TableItem_t("UserSet3", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BaslerCamera123CameraParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCamera123CameraParams::BaslerCamera123CameraParams_Data
    {
    public:
        Pylon::CIntegerParameter AcquisitionBurstFrameCount;
        Pylon::CFloatParameter AcquisitionFrameRate;
        Pylon::CBooleanParameter AcquisitionFrameRateEnable;
        EnumParameterClasses::AcquisitionModeEnumParameter AcquisitionMode;
        Pylon::CCommandParameter AcquisitionStart;
        Pylon::CBooleanParameter AcquisitionStatus;
        EnumParameterClasses::AcquisitionStatusSelectorEnumParameter AcquisitionStatusSelector;
        Pylon::CCommandParameter AcquisitionStop;
        Pylon::CFloatParameter BalanceRatio;
        EnumParameterClasses::BalanceRatioSelectorEnumParameter BalanceRatioSelector;
        Pylon::CIntegerParameter BinningHorizontal;
        Pylon::CIntegerParameter BinningVertical;
        Pylon::CFloatParameter BlackLevel;
        EnumParameterClasses::BlackLevelSelectorEnumParameter BlackLevelSelector;
        EnumParameterClasses::BslUSBSpeedModeEnumParameter BslUSBSpeedMode;
        Pylon::CBooleanParameter CenterX;
        Pylon::CBooleanParameter CenterY;
        EnumParameterClasses::ChunkCounterSelectorEnumParameter ChunkCounterSelector;
        Pylon::CIntegerParameter ChunkCounterValue;
        Pylon::CBooleanParameter ChunkEnable;
        Pylon::CFloatParameter ChunkExposureTime;
        Pylon::CFloatParameter ChunkGain;
        EnumParameterClasses::ChunkGainSelectorEnumParameter ChunkGainSelector;
        Pylon::CIntegerParameter ChunkLineStatusAll;
        Pylon::CBooleanParameter ChunkModeActive;
        Pylon::CIntegerParameter ChunkPayloadCRC16;
        EnumParameterClasses::ChunkSelectorEnumParameter ChunkSelector;
        Pylon::CIntegerParameter ChunkTimestamp;
        Pylon::CFloatParameter ColorAdjustmentHue;
        Pylon::CFloatParameter ColorAdjustmentSaturation;
        EnumParameterClasses::ColorAdjustmentSelectorEnumParameter ColorAdjustmentSelector;
        EnumParameterClasses::ColorTransformationSelectorEnumParameter ColorTransformationSelector;
        Pylon::CFloatParameter ColorTransformationValue;
        EnumParameterClasses::ColorTransformationValueSelectorEnumParameter ColorTransformationValueSelector;
        Pylon::CIntegerParameter CounterDuration;
        EnumParameterClasses::CounterEventSourceEnumParameter CounterEventSource;
        Pylon::CCommandParameter CounterReset;
        EnumParameterClasses::CounterResetActivationEnumParameter CounterResetActivation;
        EnumParameterClasses::CounterResetSourceEnumParameter CounterResetSource;
        EnumParameterClasses::CounterSelectorEnumParameter CounterSelector;
        Pylon::CIntegerParameter DecimationHorizontal;
        Pylon::CIntegerParameter DecimationVertical;
        Pylon::CStringParameter DeviceFirmwareVersion;
        Pylon::CIntegerParameter DeviceLinkCurrentThroughput;
        Pylon::CIntegerParameter DeviceLinkSelector;
        Pylon::CIntegerParameter DeviceLinkSpeed;
        Pylon::CIntegerParameter DeviceLinkThroughputLimit;
        EnumParameterClasses::DeviceLinkThroughputLimitModeEnumParameter DeviceLinkThroughputLimitMode;
        Pylon::CStringParameter DeviceManufacturerInfo;
        Pylon::CStringParameter DeviceModelName;
        Pylon::CCommandParameter DeviceReset;
        Pylon::CIntegerParameter DeviceSFNCVersionMajor;
        Pylon::CIntegerParameter DeviceSFNCVersionMinor;
        Pylon::CIntegerParameter DeviceSFNCVersionSubMinor;
        EnumParameterClasses::DeviceScanTypeEnumParameter DeviceScanType;
        Pylon::CStringParameter DeviceSerialNumber;
        Pylon::CFloatParameter DeviceTemperature;
        EnumParameterClasses::DeviceTemperatureSelectorEnumParameter DeviceTemperatureSelector;
        Pylon::CStringParameter DeviceUserID;
        Pylon::CStringParameter DeviceVendorName;
        Pylon::CStringParameter DeviceVersion;
        Pylon::CIntegerParameter EventExposureEnd;
        Pylon::CIntegerParameter EventExposureEndFrameID;
        Pylon::CIntegerParameter EventExposureEndTimestamp;
        Pylon::CIntegerParameter EventFrameBurstStart;
        Pylon::CIntegerParameter EventFrameBurstStartFrameID;
        Pylon::CIntegerParameter EventFrameBurstStartOvertrigger;
        Pylon::CIntegerParameter EventFrameBurstStartOvertriggerFrameID;
        Pylon::CIntegerParameter EventFrameBurstStartOvertriggerTimestamp;
        Pylon::CIntegerParameter EventFrameBurstStartTimestamp;
        Pylon::CIntegerParameter EventFrameStart;
        Pylon::CIntegerParameter EventFrameStartFrameID;
        Pylon::CIntegerParameter EventFrameStartOvertrigger;
        Pylon::CIntegerParameter EventFrameStartOvertriggerFrameID;
        Pylon::CIntegerParameter EventFrameStartOvertriggerTimestamp;
        Pylon::CIntegerParameter EventFrameStartTimestamp;
        EnumParameterClasses::EventNotificationEnumParameter EventNotification;
        EnumParameterClasses::EventSelectorEnumParameter EventSelector;
        Pylon::CIntegerParameter ExpertFeatureAccessKey;
        EnumParameterClasses::ExpertFeatureAccessSelectorEnumParameter ExpertFeatureAccessSelector;
        Pylon::CBooleanParameter ExpertFeatureEnable;
        EnumParameterClasses::ExposureModeEnumParameter ExposureMode;
        Pylon::CFloatParameter ExposureOverlapTimeMax;
        Pylon::CFloatParameter ExposureTime;
        Pylon::CArrayParameter FileAccessBuffer;
        Pylon::CIntegerParameter FileAccessLength;
        Pylon::CIntegerParameter FileAccessOffset;
        EnumParameterClasses::FileOpenModeEnumParameter FileOpenMode;
        Pylon::CCommandParameter FileOperationExecute;
        Pylon::CIntegerParameter FileOperationResult;
        EnumParameterClasses::FileOperationSelectorEnumParameter FileOperationSelector;
        EnumParameterClasses::FileOperationStatusEnumParameter FileOperationStatus;
        EnumParameterClasses::FileSelectorEnumParameter FileSelector;
        Pylon::CIntegerParameter FileSize;
        Pylon::CFloatParameter Gain;
        EnumParameterClasses::GainSelectorEnumParameter GainSelector;
        Pylon::CFloatParameter Gamma;
        Pylon::CIntegerParameter Height;
        Pylon::CIntegerParameter HeightMax;
        Pylon::CBooleanParameter LUTEnable;
        Pylon::CIntegerParameter LUTIndex;
        EnumParameterClasses::LUTSelectorEnumParameter LUTSelector;
        Pylon::CIntegerParameter LUTValue;
        Pylon::CArrayParameter LUTValueAll;
        EnumParameterClasses::LightSourcePresetEnumParameter LightSourcePreset;
        Pylon::CFloatParameter LineDebouncerTime;
        EnumParameterClasses::LineFormatEnumParameter LineFormat;
        Pylon::CBooleanParameter LineInverter;
        EnumParameterClasses::LineLogicEnumParameter LineLogic;
        Pylon::CFloatParameter LineMinimumOutputPulseWidth;
        EnumParameterClasses::LineModeEnumParameter LineMode;
        Pylon::CBooleanParameter LineOverloadStatus;
        EnumParameterClasses::LineSelectorEnumParameter LineSelector;
        EnumParameterClasses::LineSourceEnumParameter LineSource;
        Pylon::CBooleanParameter LineStatus;
        Pylon::CIntegerParameter LineStatusAll;
        Pylon::CIntegerParameter OffsetX;
        Pylon::CIntegerParameter OffsetY;
        Pylon::CIntegerParameter PayloadSize;
        EnumParameterClasses::PixelColorFilterEnumParameter PixelColorFilter;
        Pylon::CIntegerParameter PixelDynamicRangeMax;
        Pylon::CIntegerParameter PixelDynamicRangeMin;
        EnumParameterClasses::PixelFormatEnumParameter PixelFormat;
        EnumParameterClasses::PixelSizeEnumParameter PixelSize;
        Pylon::CBooleanParameter RemoveParameterLimit;
        EnumParameterClasses::RemoveParameterLimitSelectorEnumParameter RemoveParameterLimitSelector;
        Pylon::CFloatParameter ResultingFrameRate;
        Pylon::CBooleanParameter ReverseX;
        Pylon::CBooleanParameter ReverseY;
        Pylon::CIntegerParameter SIPayloadFinalTransfer1Size;
        Pylon::CIntegerParameter SIPayloadFinalTransfer2Size;
        Pylon::CIntegerParameter SIPayloadTransferCount;
        Pylon::CIntegerParameter SIPayloadTransferSize;
        Pylon::CIntegerParameter SensorHeight;
        Pylon::CFloatParameter SensorReadoutTime;
        Pylon::CIntegerParameter SensorWidth;
        EnumParameterClasses::ShutterModeEnumParameter ShutterMode;
        Pylon::CCommandParameter SoftwareSignalPulse;
        EnumParameterClasses::SoftwareSignalSelectorEnumParameter SoftwareSignalSelector;
        EnumParameterClasses::TestImageSelectorEnumParameter TestImageSelector;
        Pylon::CFloatParameter TimerDelay;
        Pylon::CFloatParameter TimerDuration;
        EnumParameterClasses::TimerSelectorEnumParameter TimerSelector;
        EnumParameterClasses::TimerTriggerSourceEnumParameter TimerTriggerSource;
        Pylon::CCommandParameter TimestampLatch;
        Pylon::CIntegerParameter TimestampLatchValue;
        EnumParameterClasses::TriggerActivationEnumParameter TriggerActivation;
        Pylon::CFloatParameter TriggerDelay;
        EnumParameterClasses::TriggerModeEnumParameter TriggerMode;
        EnumParameterClasses::TriggerSelectorEnumParameter TriggerSelector;
        Pylon::CCommandParameter TriggerSoftware;
        EnumParameterClasses::TriggerSourceEnumParameter TriggerSource;
        Pylon::CIntegerParameter UserDefinedValue;
        EnumParameterClasses::UserDefinedValueSelectorEnumParameter UserDefinedValueSelector;
        EnumParameterClasses::UserOutputSelectorEnumParameter UserOutputSelector;
        Pylon::CBooleanParameter UserOutputValue;
        Pylon::CIntegerParameter UserOutputValueAll;
        EnumParameterClasses::UserSetDefaultEnumParameter UserSetDefault;
        Pylon::CCommandParameter UserSetLoad;
        Pylon::CCommandParameter UserSetSave;
        EnumParameterClasses::UserSetSelectorEnumParameter UserSetSelector;
        Pylon::CIntegerParameter Width;
        Pylon::CIntegerParameter WidthMax;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    BaslerCamera123CameraParams::BaslerCamera123CameraParams(void)
        : m_pData(new BaslerCamera123CameraParams_Data())
        , AcquisitionBurstFrameCount(m_pData->AcquisitionBurstFrameCount)
        , AcquisitionFrameRate(m_pData->AcquisitionFrameRate)
        , AcquisitionFrameRateEnable(m_pData->AcquisitionFrameRateEnable)
        , AcquisitionMode(m_pData->AcquisitionMode)
        , AcquisitionStart(m_pData->AcquisitionStart)
        , AcquisitionStatus(m_pData->AcquisitionStatus)
        , AcquisitionStatusSelector(m_pData->AcquisitionStatusSelector)
        , AcquisitionStop(m_pData->AcquisitionStop)
        , BalanceRatio(m_pData->BalanceRatio)
        , BalanceRatioSelector(m_pData->BalanceRatioSelector)
        , BinningHorizontal(m_pData->BinningHorizontal)
        , BinningVertical(m_pData->BinningVertical)
        , BlackLevel(m_pData->BlackLevel)
        , BlackLevelSelector(m_pData->BlackLevelSelector)
        , BslUSBSpeedMode(m_pData->BslUSBSpeedMode)
        , CenterX(m_pData->CenterX)
        , CenterY(m_pData->CenterY)
        , ChunkCounterSelector(m_pData->ChunkCounterSelector)
        , ChunkCounterValue(m_pData->ChunkCounterValue)
        , ChunkEnable(m_pData->ChunkEnable)
        , ChunkExposureTime(m_pData->ChunkExposureTime)
        , ChunkGain(m_pData->ChunkGain)
        , ChunkGainSelector(m_pData->ChunkGainSelector)
        , ChunkLineStatusAll(m_pData->ChunkLineStatusAll)
        , ChunkModeActive(m_pData->ChunkModeActive)
        , ChunkPayloadCRC16(m_pData->ChunkPayloadCRC16)
        , ChunkSelector(m_pData->ChunkSelector)
        , ChunkTimestamp(m_pData->ChunkTimestamp)
        , ColorAdjustmentHue(m_pData->ColorAdjustmentHue)
        , ColorAdjustmentSaturation(m_pData->ColorAdjustmentSaturation)
        , ColorAdjustmentSelector(m_pData->ColorAdjustmentSelector)
        , ColorTransformationSelector(m_pData->ColorTransformationSelector)
        , ColorTransformationValue(m_pData->ColorTransformationValue)
        , ColorTransformationValueSelector(m_pData->ColorTransformationValueSelector)
        , CounterDuration(m_pData->CounterDuration)
        , CounterEventSource(m_pData->CounterEventSource)
        , CounterReset(m_pData->CounterReset)
        , CounterResetActivation(m_pData->CounterResetActivation)
        , CounterResetSource(m_pData->CounterResetSource)
        , CounterSelector(m_pData->CounterSelector)
        , DecimationHorizontal(m_pData->DecimationHorizontal)
        , DecimationVertical(m_pData->DecimationVertical)
        , DeviceFirmwareVersion(m_pData->DeviceFirmwareVersion)
        , DeviceLinkCurrentThroughput(m_pData->DeviceLinkCurrentThroughput)
        , DeviceLinkSelector(m_pData->DeviceLinkSelector)
        , DeviceLinkSpeed(m_pData->DeviceLinkSpeed)
        , DeviceLinkThroughputLimit(m_pData->DeviceLinkThroughputLimit)
        , DeviceLinkThroughputLimitMode(m_pData->DeviceLinkThroughputLimitMode)
        , DeviceManufacturerInfo(m_pData->DeviceManufacturerInfo)
        , DeviceModelName(m_pData->DeviceModelName)
        , DeviceReset(m_pData->DeviceReset)
        , DeviceSFNCVersionMajor(m_pData->DeviceSFNCVersionMajor)
        , DeviceSFNCVersionMinor(m_pData->DeviceSFNCVersionMinor)
        , DeviceSFNCVersionSubMinor(m_pData->DeviceSFNCVersionSubMinor)
        , DeviceScanType(m_pData->DeviceScanType)
        , DeviceSerialNumber(m_pData->DeviceSerialNumber)
        , DeviceTemperature(m_pData->DeviceTemperature)
        , DeviceTemperatureSelector(m_pData->DeviceTemperatureSelector)
        , DeviceUserID(m_pData->DeviceUserID)
        , DeviceVendorName(m_pData->DeviceVendorName)
        , DeviceVersion(m_pData->DeviceVersion)
        , EventExposureEnd(m_pData->EventExposureEnd)
        , EventExposureEndFrameID(m_pData->EventExposureEndFrameID)
        , EventExposureEndTimestamp(m_pData->EventExposureEndTimestamp)
        , EventFrameBurstStart(m_pData->EventFrameBurstStart)
        , EventFrameBurstStartFrameID(m_pData->EventFrameBurstStartFrameID)
        , EventFrameBurstStartOvertrigger(m_pData->EventFrameBurstStartOvertrigger)
        , EventFrameBurstStartOvertriggerFrameID(m_pData->EventFrameBurstStartOvertriggerFrameID)
        , EventFrameBurstStartOvertriggerTimestamp(m_pData->EventFrameBurstStartOvertriggerTimestamp)
        , EventFrameBurstStartTimestamp(m_pData->EventFrameBurstStartTimestamp)
        , EventFrameStart(m_pData->EventFrameStart)
        , EventFrameStartFrameID(m_pData->EventFrameStartFrameID)
        , EventFrameStartOvertrigger(m_pData->EventFrameStartOvertrigger)
        , EventFrameStartOvertriggerFrameID(m_pData->EventFrameStartOvertriggerFrameID)
        , EventFrameStartOvertriggerTimestamp(m_pData->EventFrameStartOvertriggerTimestamp)
        , EventFrameStartTimestamp(m_pData->EventFrameStartTimestamp)
        , EventNotification(m_pData->EventNotification)
        , EventSelector(m_pData->EventSelector)
        , ExpertFeatureAccessKey(m_pData->ExpertFeatureAccessKey)
        , ExpertFeatureAccessSelector(m_pData->ExpertFeatureAccessSelector)
        , ExpertFeatureEnable(m_pData->ExpertFeatureEnable)
        , ExposureMode(m_pData->ExposureMode)
        , ExposureOverlapTimeMax(m_pData->ExposureOverlapTimeMax)
        , ExposureTime(m_pData->ExposureTime)
        , FileAccessBuffer(m_pData->FileAccessBuffer)
        , FileAccessLength(m_pData->FileAccessLength)
        , FileAccessOffset(m_pData->FileAccessOffset)
        , FileOpenMode(m_pData->FileOpenMode)
        , FileOperationExecute(m_pData->FileOperationExecute)
        , FileOperationResult(m_pData->FileOperationResult)
        , FileOperationSelector(m_pData->FileOperationSelector)
        , FileOperationStatus(m_pData->FileOperationStatus)
        , FileSelector(m_pData->FileSelector)
        , FileSize(m_pData->FileSize)
        , Gain(m_pData->Gain)
        , GainSelector(m_pData->GainSelector)
        , Gamma(m_pData->Gamma)
        , Height(m_pData->Height)
        , HeightMax(m_pData->HeightMax)
        , LUTEnable(m_pData->LUTEnable)
        , LUTIndex(m_pData->LUTIndex)
        , LUTSelector(m_pData->LUTSelector)
        , LUTValue(m_pData->LUTValue)
        , LUTValueAll(m_pData->LUTValueAll)
        , LightSourcePreset(m_pData->LightSourcePreset)
        , LineDebouncerTime(m_pData->LineDebouncerTime)
        , LineFormat(m_pData->LineFormat)
        , LineInverter(m_pData->LineInverter)
        , LineLogic(m_pData->LineLogic)
        , LineMinimumOutputPulseWidth(m_pData->LineMinimumOutputPulseWidth)
        , LineMode(m_pData->LineMode)
        , LineOverloadStatus(m_pData->LineOverloadStatus)
        , LineSelector(m_pData->LineSelector)
        , LineSource(m_pData->LineSource)
        , LineStatus(m_pData->LineStatus)
        , LineStatusAll(m_pData->LineStatusAll)
        , OffsetX(m_pData->OffsetX)
        , OffsetY(m_pData->OffsetY)
        , PayloadSize(m_pData->PayloadSize)
        , PixelColorFilter(m_pData->PixelColorFilter)
        , PixelDynamicRangeMax(m_pData->PixelDynamicRangeMax)
        , PixelDynamicRangeMin(m_pData->PixelDynamicRangeMin)
        , PixelFormat(m_pData->PixelFormat)
        , PixelSize(m_pData->PixelSize)
        , RemoveParameterLimit(m_pData->RemoveParameterLimit)
        , RemoveParameterLimitSelector(m_pData->RemoveParameterLimitSelector)
        , ResultingFrameRate(m_pData->ResultingFrameRate)
        , ReverseX(m_pData->ReverseX)
        , ReverseY(m_pData->ReverseY)
        , SIPayloadFinalTransfer1Size(m_pData->SIPayloadFinalTransfer1Size)
        , SIPayloadFinalTransfer2Size(m_pData->SIPayloadFinalTransfer2Size)
        , SIPayloadTransferCount(m_pData->SIPayloadTransferCount)
        , SIPayloadTransferSize(m_pData->SIPayloadTransferSize)
        , SensorHeight(m_pData->SensorHeight)
        , SensorReadoutTime(m_pData->SensorReadoutTime)
        , SensorWidth(m_pData->SensorWidth)
        , ShutterMode(m_pData->ShutterMode)
        , SoftwareSignalPulse(m_pData->SoftwareSignalPulse)
        , SoftwareSignalSelector(m_pData->SoftwareSignalSelector)
        , TestImageSelector(m_pData->TestImageSelector)
        , TimerDelay(m_pData->TimerDelay)
        , TimerDuration(m_pData->TimerDuration)
        , TimerSelector(m_pData->TimerSelector)
        , TimerTriggerSource(m_pData->TimerTriggerSource)
        , TimestampLatch(m_pData->TimestampLatch)
        , TimestampLatchValue(m_pData->TimestampLatchValue)
        , TriggerActivation(m_pData->TriggerActivation)
        , TriggerDelay(m_pData->TriggerDelay)
        , TriggerMode(m_pData->TriggerMode)
        , TriggerSelector(m_pData->TriggerSelector)
        , TriggerSoftware(m_pData->TriggerSoftware)
        , TriggerSource(m_pData->TriggerSource)
        , UserDefinedValue(m_pData->UserDefinedValue)
        , UserDefinedValueSelector(m_pData->UserDefinedValueSelector)
        , UserOutputSelector(m_pData->UserOutputSelector)
        , UserOutputValue(m_pData->UserOutputValue)
        , UserOutputValueAll(m_pData->UserOutputValueAll)
        , UserSetDefault(m_pData->UserSetDefault)
        , UserSetLoad(m_pData->UserSetLoad)
        , UserSetSave(m_pData->UserSetSave)
        , UserSetSelector(m_pData->UserSetSelector)
        , Width(m_pData->Width)
        , WidthMax(m_pData->WidthMax)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    BaslerCamera123CameraParams::~BaslerCamera123CameraParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    void BaslerCamera123CameraParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->AcquisitionBurstFrameCount.Attach(pNodeMap, "AcquisitionBurstFrameCount");
        m_pData->AcquisitionFrameRate.Attach(pNodeMap, "AcquisitionFrameRate");
        m_pData->AcquisitionFrameRateEnable.Attach(pNodeMap, "AcquisitionFrameRateEnable");
        m_pData->AcquisitionMode.Attach(pNodeMap, "AcquisitionMode");
        m_pData->AcquisitionStart.Attach(pNodeMap, "AcquisitionStart");
        m_pData->AcquisitionStatus.Attach(pNodeMap, "AcquisitionStatus");
        m_pData->AcquisitionStatusSelector.Attach(pNodeMap, "AcquisitionStatusSelector");
        m_pData->AcquisitionStop.Attach(pNodeMap, "AcquisitionStop");
        m_pData->BalanceRatio.Attach(pNodeMap, "BalanceRatio");
        m_pData->BalanceRatioSelector.Attach(pNodeMap, "BalanceRatioSelector");
        m_pData->BinningHorizontal.Attach(pNodeMap, "BinningHorizontal");
        m_pData->BinningVertical.Attach(pNodeMap, "BinningVertical");
        m_pData->BlackLevel.Attach(pNodeMap, "BlackLevel");
        m_pData->BlackLevelSelector.Attach(pNodeMap, "BlackLevelSelector");
        m_pData->BslUSBSpeedMode.Attach(pNodeMap, "BslUSBSpeedMode");
        m_pData->CenterX.Attach(pNodeMap, "CenterX");
        m_pData->CenterY.Attach(pNodeMap, "CenterY");
        m_pData->ChunkCounterSelector.Attach(pNodeMap, "ChunkCounterSelector");
        m_pData->ChunkCounterValue.Attach(pNodeMap, "ChunkCounterValue");
        m_pData->ChunkEnable.Attach(pNodeMap, "ChunkEnable");
        m_pData->ChunkExposureTime.Attach(pNodeMap, "ChunkExposureTime");
        m_pData->ChunkGain.Attach(pNodeMap, "ChunkGain");
        m_pData->ChunkGainSelector.Attach(pNodeMap, "ChunkGainSelector");
        m_pData->ChunkLineStatusAll.Attach(pNodeMap, "ChunkLineStatusAll");
        m_pData->ChunkModeActive.Attach(pNodeMap, "ChunkModeActive");
        m_pData->ChunkPayloadCRC16.Attach(pNodeMap, "ChunkPayloadCRC16");
        m_pData->ChunkSelector.Attach(pNodeMap, "ChunkSelector");
        m_pData->ChunkTimestamp.Attach(pNodeMap, "ChunkTimestamp");
        m_pData->ColorAdjustmentHue.Attach(pNodeMap, "ColorAdjustmentHue");
        m_pData->ColorAdjustmentSaturation.Attach(pNodeMap, "ColorAdjustmentSaturation");
        m_pData->ColorAdjustmentSelector.Attach(pNodeMap, "ColorAdjustmentSelector");
        m_pData->ColorTransformationSelector.Attach(pNodeMap, "ColorTransformationSelector");
        m_pData->ColorTransformationValue.Attach(pNodeMap, "ColorTransformationValue");
        m_pData->ColorTransformationValueSelector.Attach(pNodeMap, "ColorTransformationValueSelector");
        m_pData->CounterDuration.Attach(pNodeMap, "CounterDuration");
        m_pData->CounterEventSource.Attach(pNodeMap, "CounterEventSource");
        m_pData->CounterReset.Attach(pNodeMap, "CounterReset");
        m_pData->CounterResetActivation.Attach(pNodeMap, "CounterResetActivation");
        m_pData->CounterResetSource.Attach(pNodeMap, "CounterResetSource");
        m_pData->CounterSelector.Attach(pNodeMap, "CounterSelector");
        m_pData->DecimationHorizontal.Attach(pNodeMap, "DecimationHorizontal");
        m_pData->DecimationVertical.Attach(pNodeMap, "DecimationVertical");
        m_pData->DeviceFirmwareVersion.Attach(pNodeMap, "DeviceFirmwareVersion");
        m_pData->DeviceLinkCurrentThroughput.Attach(pNodeMap, "DeviceLinkCurrentThroughput");
        m_pData->DeviceLinkSelector.Attach(pNodeMap, "DeviceLinkSelector");
        m_pData->DeviceLinkSpeed.Attach(pNodeMap, "DeviceLinkSpeed");
        m_pData->DeviceLinkThroughputLimit.Attach(pNodeMap, "DeviceLinkThroughputLimit");
        m_pData->DeviceLinkThroughputLimitMode.Attach(pNodeMap, "DeviceLinkThroughputLimitMode");
        m_pData->DeviceManufacturerInfo.Attach(pNodeMap, "DeviceManufacturerInfo");
        m_pData->DeviceModelName.Attach(pNodeMap, "DeviceModelName");
        m_pData->DeviceReset.Attach(pNodeMap, "DeviceReset");
        m_pData->DeviceSFNCVersionMajor.Attach(pNodeMap, "DeviceSFNCVersionMajor");
        m_pData->DeviceSFNCVersionMinor.Attach(pNodeMap, "DeviceSFNCVersionMinor");
        m_pData->DeviceSFNCVersionSubMinor.Attach(pNodeMap, "DeviceSFNCVersionSubMinor");
        m_pData->DeviceScanType.Attach(pNodeMap, "DeviceScanType");
        m_pData->DeviceSerialNumber.Attach(pNodeMap, "DeviceSerialNumber");
        m_pData->DeviceTemperature.Attach(pNodeMap, "DeviceTemperature");
        m_pData->DeviceTemperatureSelector.Attach(pNodeMap, "DeviceTemperatureSelector");
        m_pData->DeviceUserID.Attach(pNodeMap, "DeviceUserID");
        m_pData->DeviceVendorName.Attach(pNodeMap, "DeviceVendorName");
        m_pData->DeviceVersion.Attach(pNodeMap, "DeviceVersion");
        m_pData->EventExposureEnd.Attach(pNodeMap, "EventExposureEnd");
        m_pData->EventExposureEndFrameID.Attach(pNodeMap, "EventExposureEndFrameID");
        m_pData->EventExposureEndTimestamp.Attach(pNodeMap, "EventExposureEndTimestamp");
        m_pData->EventFrameBurstStart.Attach(pNodeMap, "EventFrameBurstStart");
        m_pData->EventFrameBurstStartFrameID.Attach(pNodeMap, "EventFrameBurstStartFrameID");
        m_pData->EventFrameBurstStartOvertrigger.Attach(pNodeMap, "EventFrameBurstStartOvertrigger");
        m_pData->EventFrameBurstStartOvertriggerFrameID.Attach(pNodeMap, "EventFrameBurstStartOvertriggerFrameID");
        m_pData->EventFrameBurstStartOvertriggerTimestamp.Attach(pNodeMap, "EventFrameBurstStartOvertriggerTimestamp");
        m_pData->EventFrameBurstStartTimestamp.Attach(pNodeMap, "EventFrameBurstStartTimestamp");
        m_pData->EventFrameStart.Attach(pNodeMap, "EventFrameStart");
        m_pData->EventFrameStartFrameID.Attach(pNodeMap, "EventFrameStartFrameID");
        m_pData->EventFrameStartOvertrigger.Attach(pNodeMap, "EventFrameStartOvertrigger");
        m_pData->EventFrameStartOvertriggerFrameID.Attach(pNodeMap, "EventFrameStartOvertriggerFrameID");
        m_pData->EventFrameStartOvertriggerTimestamp.Attach(pNodeMap, "EventFrameStartOvertriggerTimestamp");
        m_pData->EventFrameStartTimestamp.Attach(pNodeMap, "EventFrameStartTimestamp");
        m_pData->EventNotification.Attach(pNodeMap, "EventNotification");
        m_pData->EventSelector.Attach(pNodeMap, "EventSelector");
        m_pData->ExpertFeatureAccessKey.Attach(pNodeMap, "ExpertFeatureAccessKey");
        m_pData->ExpertFeatureAccessSelector.Attach(pNodeMap, "ExpertFeatureAccessSelector");
        m_pData->ExpertFeatureEnable.Attach(pNodeMap, "ExpertFeatureEnable");
        m_pData->ExposureMode.Attach(pNodeMap, "ExposureMode");
        m_pData->ExposureOverlapTimeMax.Attach(pNodeMap, "ExposureOverlapTimeMax");
        m_pData->ExposureTime.Attach(pNodeMap, "ExposureTime");
        m_pData->FileAccessBuffer.Attach(pNodeMap, "FileAccessBuffer");
        m_pData->FileAccessLength.Attach(pNodeMap, "FileAccessLength");
        m_pData->FileAccessOffset.Attach(pNodeMap, "FileAccessOffset");
        m_pData->FileOpenMode.Attach(pNodeMap, "FileOpenMode");
        m_pData->FileOperationExecute.Attach(pNodeMap, "FileOperationExecute");
        m_pData->FileOperationResult.Attach(pNodeMap, "FileOperationResult");
        m_pData->FileOperationSelector.Attach(pNodeMap, "FileOperationSelector");
        m_pData->FileOperationStatus.Attach(pNodeMap, "FileOperationStatus");
        m_pData->FileSelector.Attach(pNodeMap, "FileSelector");
        m_pData->FileSize.Attach(pNodeMap, "FileSize");
        m_pData->Gain.Attach(pNodeMap, "Gain");
        m_pData->GainSelector.Attach(pNodeMap, "GainSelector");
        m_pData->Gamma.Attach(pNodeMap, "Gamma");
        m_pData->Height.Attach(pNodeMap, "Height");
        m_pData->HeightMax.Attach(pNodeMap, "HeightMax");
        m_pData->LUTEnable.Attach(pNodeMap, "LUTEnable");
        m_pData->LUTIndex.Attach(pNodeMap, "LUTIndex");
        m_pData->LUTSelector.Attach(pNodeMap, "LUTSelector");
        m_pData->LUTValue.Attach(pNodeMap, "LUTValue");
        m_pData->LUTValueAll.Attach(pNodeMap, "LUTValueAll");
        m_pData->LightSourcePreset.Attach(pNodeMap, "LightSourcePreset");
        m_pData->LineDebouncerTime.Attach(pNodeMap, "LineDebouncerTime");
        m_pData->LineFormat.Attach(pNodeMap, "LineFormat");
        m_pData->LineInverter.Attach(pNodeMap, "LineInverter");
        m_pData->LineLogic.Attach(pNodeMap, "LineLogic");
        m_pData->LineMinimumOutputPulseWidth.Attach(pNodeMap, "LineMinimumOutputPulseWidth");
        m_pData->LineMode.Attach(pNodeMap, "LineMode");
        m_pData->LineOverloadStatus.Attach(pNodeMap, "LineOverloadStatus");
        m_pData->LineSelector.Attach(pNodeMap, "LineSelector");
        m_pData->LineSource.Attach(pNodeMap, "LineSource");
        m_pData->LineStatus.Attach(pNodeMap, "LineStatus");
        m_pData->LineStatusAll.Attach(pNodeMap, "LineStatusAll");
        m_pData->OffsetX.Attach(pNodeMap, "OffsetX");
        m_pData->OffsetY.Attach(pNodeMap, "OffsetY");
        m_pData->PayloadSize.Attach(pNodeMap, "PayloadSize");
        m_pData->PixelColorFilter.Attach(pNodeMap, "PixelColorFilter");
        m_pData->PixelDynamicRangeMax.Attach(pNodeMap, "PixelDynamicRangeMax");
        m_pData->PixelDynamicRangeMin.Attach(pNodeMap, "PixelDynamicRangeMin");
        m_pData->PixelFormat.Attach(pNodeMap, "PixelFormat");
        m_pData->PixelSize.Attach(pNodeMap, "PixelSize");
        m_pData->RemoveParameterLimit.Attach(pNodeMap, "RemoveParameterLimit");
        m_pData->RemoveParameterLimitSelector.Attach(pNodeMap, "RemoveParameterLimitSelector");
        m_pData->ResultingFrameRate.Attach(pNodeMap, "ResultingFrameRate");
        m_pData->ReverseX.Attach(pNodeMap, "ReverseX");
        m_pData->ReverseY.Attach(pNodeMap, "ReverseY");
        m_pData->SIPayloadFinalTransfer1Size.Attach(pNodeMap, "SIPayloadFinalTransfer1Size");
        m_pData->SIPayloadFinalTransfer2Size.Attach(pNodeMap, "SIPayloadFinalTransfer2Size");
        m_pData->SIPayloadTransferCount.Attach(pNodeMap, "SIPayloadTransferCount");
        m_pData->SIPayloadTransferSize.Attach(pNodeMap, "SIPayloadTransferSize");
        m_pData->SensorHeight.Attach(pNodeMap, "SensorHeight");
        m_pData->SensorReadoutTime.Attach(pNodeMap, "SensorReadoutTime");
        m_pData->SensorWidth.Attach(pNodeMap, "SensorWidth");
        m_pData->ShutterMode.Attach(pNodeMap, "ShutterMode");
        m_pData->SoftwareSignalPulse.Attach(pNodeMap, "SoftwareSignalPulse");
        m_pData->SoftwareSignalSelector.Attach(pNodeMap, "SoftwareSignalSelector");
        m_pData->TestImageSelector.Attach(pNodeMap, "TestImageSelector");
        m_pData->TimerDelay.Attach(pNodeMap, "TimerDelay");
        m_pData->TimerDuration.Attach(pNodeMap, "TimerDuration");
        m_pData->TimerSelector.Attach(pNodeMap, "TimerSelector");
        m_pData->TimerTriggerSource.Attach(pNodeMap, "TimerTriggerSource");
        m_pData->TimestampLatch.Attach(pNodeMap, "TimestampLatch");
        m_pData->TimestampLatchValue.Attach(pNodeMap, "TimestampLatchValue");
        m_pData->TriggerActivation.Attach(pNodeMap, "TriggerActivation");
        m_pData->TriggerDelay.Attach(pNodeMap, "TriggerDelay");
        m_pData->TriggerMode.Attach(pNodeMap, "TriggerMode");
        m_pData->TriggerSelector.Attach(pNodeMap, "TriggerSelector");
        m_pData->TriggerSoftware.Attach(pNodeMap, "TriggerSoftware");
        m_pData->TriggerSource.Attach(pNodeMap, "TriggerSource");
        m_pData->UserDefinedValue.Attach(pNodeMap, "UserDefinedValue");
        m_pData->UserDefinedValueSelector.Attach(pNodeMap, "UserDefinedValueSelector");
        m_pData->UserOutputSelector.Attach(pNodeMap, "UserOutputSelector");
        m_pData->UserOutputValue.Attach(pNodeMap, "UserOutputValue");
        m_pData->UserOutputValueAll.Attach(pNodeMap, "UserOutputValueAll");
        m_pData->UserSetDefault.Attach(pNodeMap, "UserSetDefault");
        m_pData->UserSetLoad.Attach(pNodeMap, "UserSetLoad");
        m_pData->UserSetSave.Attach(pNodeMap, "UserSetSave");
        m_pData->UserSetSelector.Attach(pNodeMap, "UserSetSelector");
        m_pData->Width.Attach(pNodeMap, "Width");
        m_pData->WidthMax.Attach(pNodeMap, "WidthMax");
    }

    //! \endcond

} // namespace Pylon123
} // namespace BaslerCamera123CameraParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif