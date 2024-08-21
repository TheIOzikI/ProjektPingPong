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

#ifndef BASLER_PYLON_LEFTCAMERAPARAMS_H
#define BASLER_PYLON_LEFTCAMERAPARAMS_H

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
namespace LEFTCameraParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_Continuous,  //!< Sets the acquisition mode to continuous - Applies to: acA1920-155uc
        AcquisitionMode_SingleFrame  //!< Sets the acquisition mode to single frame - Applies to: acA1920-155uc
    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_FrameBurstTriggerWait,  //!< Device is currently waiting for a trigger for the capture of one or many frames - Applies to: acA1920-155uc
        AcquisitionStatusSelector_FrameTriggerWait  //!< Device is currently waiting for a Frame trigger - Applies to: acA1920-155uc
    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_MinimizeExposureTime,  //!< Keeps exposure time at minimum - Applies to: acA1920-155uc
        AutoFunctionProfile_MinimizeGain  //!< Keeps gain at minimum - Applies to: acA1920-155uc
    };

    //! Valid values for AutoFunctionROISelector
    enum AutoFunctionROISelectorEnums
    {
        AutoFunctionROISelector_ROI1,  //!< Selects Auto Function ROI 1 - Applies to: acA1920-155uc
        AutoFunctionROISelector_ROI2  //!< Selects Auto Function ROI 2 - Applies to: acA1920-155uc
    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Blue,  //!< Selects the blue balance ratio control for adjustment - Applies to: acA1920-155uc
        BalanceRatioSelector_Green,  //!< Selects the green balance ratio control for adjustment - Applies to: acA1920-155uc
        BalanceRatioSelector_Red  //!< Selects the red balance ratio control for adjustment - Applies to: acA1920-155uc
    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Continuous,  //!< Sets the balance white auto function to 'continuous' operation mode - Applies to: acA1920-155uc
        BalanceWhiteAuto_Off,  //!< Disables the balance white auto function - Applies to: acA1920-155uc
        BalanceWhiteAuto_Once  //!< Sets the balance white auto function to 'once' operation mode - Applies to: acA1920-155uc
    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All  //!< Selects all black level controls for adjustment - Applies to: acA1920-155uc
    };

    //! Valid values for BslUSBSpeedMode
    enum BslUSBSpeedModeEnums
    {
        BslUSBSpeedMode_HighSpeed,  //!< Indicates the USB 'Hi-Speed' speed mode - Applies to: acA1920-155uc
        BslUSBSpeedMode_SuperSpeed  //!< Indicates the USB 'Super Speed' speed mode - Applies to: acA1920-155uc
    };

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

    //! Valid values for ChunkSelector
    enum ChunkSelectorEnums
    {
        ChunkSelector_CounterValue,  //!< Selects the counter value chunk for configuration - Applies to: acA1920-155uc
        ChunkSelector_ExposureTime,  //!< Selects the exposure time chunk for enabling - Applies to: acA1920-155uc
        ChunkSelector_Gain,  //!< Selects the gain chunk for enabling - Applies to: acA1920-155uc
        ChunkSelector_LineStatusAll,  //!< Selects the line status all chunk for enabling - Applies to: acA1920-155uc
        ChunkSelector_PayloadCRC16,  //!< Selects the CRC checksum chunk for configuration - Applies to: acA1920-155uc
        ChunkSelector_Timestamp  //!< Selects the timestamp chunk for enabling - Applies to: acA1920-155uc
    };

    //! Valid values for ColorAdjustmentSelector
    enum ColorAdjustmentSelectorEnums
    {
        ColorAdjustmentSelector_Todo  //!< TODO - Applies to: acA1920-155uc
    };

    //! Valid values for ColorSpace
    enum ColorSpaceEnums
    {
        ColorSpace_RGB,  //!< Colors in accord with the RGB color space - Applies to: acA1920-155uc
        ColorSpace_sRGB  //!< Colors in accord with the sRGB color space - Applies to: acA1920-155uc
    };

    //! Valid values for ColorTransformationSelector
    enum ColorTransformationSelectorEnums
    {
        ColorTransformationSelector_RGBtoRGB  //!< Matrix color transformation from RGB to RGB - Applies to: acA1920-155uc
    };

    //! Valid values for ColorTransformationValueSelector
    enum ColorTransformationValueSelectorEnums
    {
        ColorTransformationValueSelector_Gain00,  //!< Element in row 0 and column 0 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain01,  //!< Element in row 0 and column 1 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain02,  //!< Element in row 0 and column 2 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain10,  //!< Element in row 1 and column 0 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain11,  //!< Element in row 1 and column 1 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain12,  //!< Element in row 1 and column 2 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain20,  //!< Element in row 2 and column 0 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain21,  //!< Element in row 2 and column 1 of the color transformation matrix - Applies to: acA1920-155uc
        ColorTransformationValueSelector_Gain22  //!< Element in row 2 and column 2 of the color transformation matrix - Applies to: acA1920-155uc
    };

    //! Valid values for CounterEventSource
    enum CounterEventSourceEnums
    {
        CounterEventSource_FrameStart  //!< Counts the number of Frame Start - Applies to: acA1920-155uc
    };

    //! Valid values for CounterResetActivation
    enum CounterResetActivationEnums
    {
        CounterResetActivation_RisingEdge  //!< Resets the counter on the rising edge of the signal - Applies to: acA1920-155uc
    };

    //! Valid values for CounterResetSource
    enum CounterResetSourceEnums
    {
        CounterResetSource_Line1,  //!< Selects line 1 as the source for counter reset - Applies to: acA1920-155uc
        CounterResetSource_Line3,  //!< Selects line 3 as the source for counter reset - Applies to: acA1920-155uc
        CounterResetSource_Line4,  //!< Selects line 4 as the source for counter reset - Applies to: acA1920-155uc
        CounterResetSource_Off,  //!< Disable the Counter Reset trigger - Applies to: acA1920-155uc
        CounterResetSource_Software  //!< Selects software command as the source for counter reset - Applies to: acA1920-155uc
    };

    //! Valid values for CounterSelector
    enum CounterSelectorEnums
    {
        CounterSelector_Counter1,  //!< Selects Counter 1 for configuration - Applies to: acA1920-155uc
        CounterSelector_Counter2  //!< Selects Counter 2 for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for DeviceLinkThroughputLimitMode
    enum DeviceLinkThroughputLimitModeEnums
    {
        DeviceLinkThroughputLimitMode_Off,  //!< Disables the device link throughput limit feature - Applies to: acA1920-155uc
        DeviceLinkThroughputLimitMode_On  //!< Enables the device link throughput limit feature - Applies to: acA1920-155uc
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!< Indicates that the device has an area scan type of sensor - Applies to: acA1920-155uc
        DeviceScanType_Linescan  //!< Indicates that the device has an Line scan type of sensor - Applies to: acA1920-155uc
    };

    //! Valid values for DeviceTemperatureSelector
    enum DeviceTemperatureSelectorEnums
    {
        DeviceTemperatureSelector_Coreboard  //!< Temperature on core board - Applies to: acA1920-155uc
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_Off,  //!< The selected Event notification is disabled - Applies to: acA1920-155uc
        EventNotification_On  //!< The selected Event notification is enabled - Applies to: acA1920-155uc
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_ExposureEnd,  //!< Device just completed the exposure of one Frame - Applies to: acA1920-155uc
        EventSelector_FrameBurstStart,  //!< Device just started the capture of a frame burst - Applies to: acA1920-155uc
        EventSelector_FrameBurstStartOvertrigger,  //!< Selects the frame burst start overtrigger event for enabling - Applies to: acA1920-155uc
        EventSelector_FrameStart,  //!< Device just started the capture of one frame - Applies to: acA1920-155uc
        EventSelector_FrameStartOvertrigger  //!< Selects the frame start overtrigger event for enabling - Applies to: acA1920-155uc
    };

    //! Valid values for ExpertFeatureAccessSelector
    enum ExpertFeatureAccessSelectorEnums
    {
        ExpertFeatureAccessSelector_ExpertFeature1,  //!< Selects the Expert Feature 1 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature2,  //!< Selects the Expert Feature 2 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature3,  //!< Selects the Expert Feature 3 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature4,  //!< Selects the Expert Feature 4 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature5,  //!< Selects the Expert Feature 5 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature6,  //!< Selects the Expert Feature 6 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature7,  //!< Selects the Expert Feature 7 for configuration - Applies to: acA1920-155uc
        ExpertFeatureAccessSelector_ExpertFeature8  //!< Selects the Expert Feature 8 for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Continuous,  //!< Sets the exposure auto function mode of operation to 'continuous' - Applies to: acA1920-155uc
        ExposureAuto_Off,  //!< Disables the exposure auto function - Applies to: acA1920-155uc
        ExposureAuto_Once  //!< Sets the exposure auto function mode of operation to 'once' - Applies to: acA1920-155uc
    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!< Sets the exposure mode to 'timed' - Applies to: acA1920-155uc
        ExposureMode_TriggerWidth  //!< Sets the exposure mode to 'trigger width' - Applies to: acA1920-155uc
    };

    //! Valid values for ExposureOverlapTimeMode
    enum ExposureOverlapTimeModeEnums
    {
        ExposureOverlapTimeMode_Todo  //!< TODO - Applies to: acA1920-155uc
    };

    //! Valid values for FileOpenMode
    enum FileOpenModeEnums
    {
        FileOpenMode_Read,  //!< Selects read-only open mode - Applies to: acA1920-155uc
        FileOpenMode_Write  //!< Selects write-only open mode - Applies to: acA1920-155uc
    };

    //! Valid values for FileOperationSelector
    enum FileOperationSelectorEnums
    {
        FileOperationSelector_Close,  //!< Closes the file selected by FileSelector - Applies to: acA1920-155uc
        FileOperationSelector_Open,  //!< Opens the file selected by FileSelector - Applies to: acA1920-155uc
        FileOperationSelector_Read,  //!< Reads data from the selected file - Applies to: acA1920-155uc
        FileOperationSelector_Write  //!< Writes data to the selected file - Applies to: acA1920-155uc
    };

    //! Valid values for FileOperationStatus
    enum FileOperationStatusEnums
    {
        FileOperationStatus_Failure,  //!< Failing file operation - Applies to: acA1920-155uc
        FileOperationStatus_Success  //!< Successful file operation - Applies to: acA1920-155uc
    };

    //! Valid values for FileSelector
    enum FileSelectorEnums
    {
        FileSelector_ExpertFeature7File,  //!< Selects the file 'Expert Feature 7 File' - Applies to: acA1920-155uc
        FileSelector_UserData,  //!< Selects the file 'User Data' - Applies to: acA1920-155uc
        FileSelector_UserGainShading1,  //!< Selects the file 'User Gain Shading 1' - Applies to: acA1920-155uc
        FileSelector_UserGainShading2,  //!< Selects the file 'User Gain Shading 2' - Applies to: acA1920-155uc
        FileSelector_UserOffsetShading1,  //!< Selects the file 'User Offset Shading 1' - Applies to: acA1920-155uc
        FileSelector_UserOffsetShading2,  //!< Selects the file 'User Offset Shading 2' - Applies to: acA1920-155uc
        FileSelector_UserSet1,  //!< Selects the file 'User Set 1' - Applies to: acA1920-155uc
        FileSelector_UserSet2,  //!< Selects the file 'User Set 2' - Applies to: acA1920-155uc
        FileSelector_UserSet3  //!< Selects the file 'User Set 3' - Applies to: acA1920-155uc
    };

    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Continuous,  //!< Sets the auto function mode of operation to 'continuous' - Applies to: acA1920-155uc
        GainAuto_Off,  //!< Disables the Gain Auto function - Applies to: acA1920-155uc
        GainAuto_Once  //!< Sets the auto function mode of operation to 'once' - Applies to: acA1920-155uc
    };

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All  //!< Selects all gain controls for adjustment - Applies to: acA1920-155uc
    };

    //! Valid values for LUTSelector
    enum LUTSelectorEnums
    {
        LUTSelector_Luminance  //!< Selects the luminance LUT for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for LightSourcePreset
    enum LightSourcePresetEnums
    {
        LightSourcePreset_Daylight5000K,  //!< Color preset for image acquisition with daylight of 5000 K - Applies to: acA1920-155uc
        LightSourcePreset_Daylight6500K,  //!< Color preset for image acquisition with daylight of 6500 K - Applies to: acA1920-155uc
        LightSourcePreset_Off,  //!< No light source preset selected - Applies to: acA1920-155uc
        LightSourcePreset_Tungsten2800K  //!< Color preset for image acquisition with tungsten incandescent light (2800 K) - Applies to: acA1920-155uc
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_OptoCoupled,  //!< Sets the electrical configuration of the selected line to 'opto-coupled' - Applies to: acA1920-155uc
        LineFormat_TTL  //!< Sets the electrical configuration of the selected line to 'TTL' - Applies to: acA1920-155uc
    };

    //! Valid values for LineLogic
    enum LineLogicEnums
    {
        LineLogic_Negative,  //!< Negative line logic - Applies to: acA1920-155uc
        LineLogic_Positive  //!< Positive line logic - Applies to: acA1920-155uc
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!< Sets the mode for the selected line to 'input' - Applies to: acA1920-155uc
        LineMode_Output  //!< Sets the mode for the selected line to 'output' - Applies to: acA1920-155uc
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!< Selects line 1 for configuration - Applies to: acA1920-155uc
        LineSelector_Line2,  //!< Selects line 2 for configuration - Applies to: acA1920-155uc
        LineSelector_Line3,  //!< Selects line 3 for configuration - Applies to: acA1920-155uc
        LineSelector_Line4  //!< Selects line 4 for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_Todo  //!< TODO - Applies to: acA1920-155uc
    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_BayerBG,  //!< The Bayer filter has a BG/GR alignment to the pixels in the acquired images - Applies to: acA1920-155uc
        PixelColorFilter_BayerGB,  //!< The Bayer filter has a GB/RG alignment to the pixels in the acquired images - Applies to: acA1920-155uc
        PixelColorFilter_BayerGR,  //!< The Bayer filter has a GR/BG alignment to the pixels in the acquired images - Applies to: acA1920-155uc
        PixelColorFilter_BayerRG,  //!< The Bayer filter has an RG/GB alignment to the pixels in the acquired images - Applies to: acA1920-155uc
        PixelColorFilter_None  //!< No Bayer filter is present on the camera - Applies to: acA1920-155uc
    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_BayerBG12,  //!< Sets the pixel format to Bayer BG 12 - Applies to: acA1920-155uc
        PixelFormat_BayerBG12p,  //!< Sets the pixel format to Bayer BG 12p - Applies to: acA1920-155uc
        PixelFormat_BayerBG8,  //!< Sets the pixel format to Bayer BG 8 - Applies to: acA1920-155uc
        PixelFormat_BayerGB12,  //!< Sets the pixel format to Bayer GB 12 - Applies to: acA1920-155uc
        PixelFormat_BayerGB12p,  //!< Sets the pixel format to Bayer GB 12p - Applies to: acA1920-155uc
        PixelFormat_BayerGB8,  //!< Sets the pixel format to Bayer GB 8 - Applies to: acA1920-155uc
        PixelFormat_BayerGR12,  //!< Sets the pixel format to Bayer GR 12 - Applies to: acA1920-155uc
        PixelFormat_BayerGR12p,  //!< Sets the pixel format to Bayer GR 12p - Applies to: acA1920-155uc
        PixelFormat_BayerGR8,  //!< Sets the pixel format to Bayer GR 8 - Applies to: acA1920-155uc
        PixelFormat_BayerRG12,  //!< Sets the pixel format to Bayer RG 12 - Applies to: acA1920-155uc
        PixelFormat_BayerRG12p,  //!< Sets the pixel format to Bayer RG 12p - Applies to: acA1920-155uc
        PixelFormat_BayerRG8  //!< Sets the pixel format to Bayer RG 8 - Applies to: acA1920-155uc
    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp10,  //!< The depth of the pixel values in the acquired images is 10 bits per pixel - Applies to: acA1920-155uc
        PixelSize_Bpp12,  //!< The depth of the pixel values in the acquired images is 12 bits per pixel - Applies to: acA1920-155uc
        PixelSize_Bpp16,  //!< The depth of the pixel values in the acquired images is 16 bits per pixel - Applies to: acA1920-155uc
        PixelSize_Bpp24,  //!< The depth of the pixel values in the acquired images is 24 bits per pixel - Applies to: acA1920-155uc
        PixelSize_Bpp8  //!< The depth of the pixel values in the acquired images is 8 bits per pixel - Applies to: acA1920-155uc
    };

    //! Valid values for RemoveParameterLimitSelector
    enum RemoveParameterLimitSelectorEnums
    {
        RemoveParameterLimitSelector_Gain  //!< Selects the gain limits for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for SensorReadoutMode
    enum SensorReadoutModeEnums
    {
        SensorReadoutMode_Todo  //!< TODO - Applies to: acA1920-155uc
    };

    //! Valid values for ShutterMode
    enum ShutterModeEnums
    {
        ShutterMode_Global  //!< Sets the shutter mode to global shutter - Applies to: acA1920-155uc
    };

    //! Valid values for SoftwareSignalSelector
    enum SoftwareSignalSelectorEnums
    {
        SoftwareSignalSelector_SoftwareSignal1,  //!< Applies to: acA1920-155uc
        SoftwareSignalSelector_SoftwareSignal2  //!< Applies to: acA1920-155uc
    };

    //! Valid values for TemperatureState
    enum TemperatureStateEnums
    {
        TemperatureState_Todo  //!< TODO - Applies to: acA1920-155uc
    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!< No test image will be output from the camera - Applies to: acA1920-155uc
        TestImageSelector_Testimage1,  //!< The camera generates and transmits test images with a test image 1 pattern - Applies to: acA1920-155uc
        TestImageSelector_Testimage2,  //!< The camera generates and transmits test images with a test image 2 pattern - Applies to: acA1920-155uc
        TestImageSelector_Testimage3,  //!< The camera generates and transmits test images with a test image 3 pattern - Applies to: acA1920-155uc
        TestImageSelector_Testimage4,  //!< The camera generates and transmits test images with a test image 4 pattern - Applies to: acA1920-155uc
        TestImageSelector_Testimage5,  //!< The camera generates and transmits test images with a test image 5 pattern - Applies to: acA1920-155uc
        TestImageSelector_Testimage6  //!< The camera generates and transmits test images with a test image 6 pattern - Applies to: acA1920-155uc
    };

    //! Valid values for TimerSelector
    enum TimerSelectorEnums
    {
        TimerSelector_Timer1  //!< Selects Timer 1 for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for TimerTriggerSource
    enum TimerTriggerSourceEnums
    {
        TimerTriggerSource_ExposureStart  //!< Starts with the reception of the Exposure Start - Applies to: acA1920-155uc
    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_FallingEdge,  //!< Sets the selected trigger to become active on the falling edge of the source signal - Applies to: acA1920-155uc
        TriggerActivation_RisingEdge  //!< Sets the selected trigger to become active on the rising edge of the source signal - Applies to: acA1920-155uc
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!< Sets the mode for the selected trigger to 'off' - Applies to: acA1920-155uc
        TriggerMode_On  //!< Sets the mode for the selected trigger to 'on' - Applies to: acA1920-155uc
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_FrameBurstStart,  //!< Selects the frame burst start trigger for configuration - Applies to: acA1920-155uc
        TriggerSelector_FrameStart  //!< Selects the frame start trigger for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Line1,  //!< Sets the signal source for the selected trigger to 'line 1' - Applies to: acA1920-155uc
        TriggerSource_Line3,  //!< Sets the signal source for the selected trigger to 'line 3' - Applies to: acA1920-155uc
        TriggerSource_Line4,  //!< Sets the signal source for the selected trigger to 'line 4' - Applies to: acA1920-155uc
        TriggerSource_Software,  //!< Sets the software trigger as the signal source for the selected trigger - Applies to: acA1920-155uc
        TriggerSource_SoftwareSignal1,  //!< Selects the SoftwareSignal1 software command - Applies to: acA1920-155uc
        TriggerSource_SoftwareSignal2  //!< Selects the SoftwareSignal2 software command - Applies to: acA1920-155uc
    };

    //! Valid values for UserDefinedValueSelector
    enum UserDefinedValueSelectorEnums
    {
        UserDefinedValueSelector_Value1,  //!< Selects Value1 - Applies to: acA1920-155uc
        UserDefinedValueSelector_Value2,  //!< Selects Value2 - Applies to: acA1920-155uc
        UserDefinedValueSelector_Value3,  //!< Selects Value3 - Applies to: acA1920-155uc
        UserDefinedValueSelector_Value4,  //!< Selects Value4 - Applies to: acA1920-155uc
        UserDefinedValueSelector_Value5  //!< Selects Value5 - Applies to: acA1920-155uc
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput1,  //!< Selects user settable output signal 1 for configuration - Applies to: acA1920-155uc
        UserOutputSelector_UserOutput2,  //!< Selects user settable output signal 2 for configuration - Applies to: acA1920-155uc
        UserOutputSelector_UserOutput3  //!< Selects user settable output signal 3 for configuration - Applies to: acA1920-155uc
    };

    //! Valid values for UserSetDefault
    enum UserSetDefaultEnums
    {
        UserSetDefault_AutoFunctions,  //!< Selects the auto function user set as the default startup set - Applies to: acA1920-155uc
        UserSetDefault_ColorRaw,  //!< Selects the color raw user set as the default startup set - Applies to: acA1920-155uc
        UserSetDefault_Default,  //!< Selects the default user set as the default startup set - Applies to: acA1920-155uc
        UserSetDefault_HighGain,  //!< Selects the high gain user set as the default startup set - Applies to: acA1920-155uc
        UserSetDefault_UserSet1,  //!< Selects user set 1 as the default startup set - Applies to: acA1920-155uc
        UserSetDefault_UserSet2,  //!< Selects user set 2 as the default startup set - Applies to: acA1920-155uc
        UserSetDefault_UserSet3  //!< Selects user set 3 as the default startup set - Applies to: acA1920-155uc
    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_AutoFunctions,  //!< Factory set using auto functions - Applies to: acA1920-155uc
        UserSetSelector_ColorRaw,  //!< Factory set disabling color adjustments - Applies to: acA1920-155uc
        UserSetSelector_Default,  //!< Selects the default user set - Applies to: acA1920-155uc
        UserSetSelector_HighGain,  //!< High gain factory set - Applies to: acA1920-155uc
        UserSetSelector_UserSet1,  //!< Selects the user set 1 configuration set - Applies to: acA1920-155uc
        UserSetSelector_UserSet2,  //!< Selects the user set 2 configuration set - Applies to: acA1920-155uc
        UserSetSelector_UserSet3  //!< Selects the user set 3 configuration set - Applies to: acA1920-155uc
    };


    
    
    //**************************************************************************************************
    // Parameter class LEFTCameraParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA1920-155uc

    Sources:
    acA1920-155uc 106880-04;U;acA1920_155u;V0.5-1;1
    */
    class LEFTCameraParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            LEFTCameraParams(void);

            //! Destructor
            ~LEFTCameraParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class LEFTCameraParams_Data;
        LEFTCameraParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Number of frames to acquire for each FrameBurstStart trigger - Applies to: acA1920-155uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionBurstFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionBurstFrameCount;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the camera's acquisition frame rate in frames per second - Applies to: acA1920-155uc

        The Acquisition Frame Rate parameter sets the 'absolute' value of the acquisition frame rate. The 'absolute' value is a float value that sets the acquisition frame rate in frames per second.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionFrameRate;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Enables setting the camera's acquisition frame rate to a specified value - Applies to: acA1920-155uc

        This boolean value enables setting the camera's acquisition frame rate to a specified value.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionFrameRateEnable;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the image acquisition mode - Applies to: acA1920-155uc

        This enumeration sets the image acquisition mode. 
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionModeEnums>& AcquisitionMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Starts the acquisition of images - Applies to: acA1920-155uc

        This command starts the acquisition of images. If the camera is set for single frame acquisition, it will start acquisition of one frame. If the camera is set for continuous frame acquisition, it will start continuous acquisition of frames.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStart;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Reports the selected acquisition status - Applies to: acA1920-155uc

        This feature is used to read the state (true or false) of the internal acquisition signal selected using the Acquisition Status Selector parameter.
    
        Visibility: Expert

        Selected by: AcquisitionStatusSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionStatus;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Selects which internal acquisition signal to read using the Acquisition Status parameter - Applies to: acA1920-155uc

        This enumeration is used to select which internal acquisition signal to read using Acquisition Status parameter.
    
        Visibility: Expert

        Selecting Parameters: AcquisitionStatus

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatusSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionStatusSelectorEnums>& AcquisitionStatusSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Stops the acquisition of images - Applies to: acA1920-155uc

        If the camera is set for continuous image acquisition and acquisition has been started, this command stops the acquisition of images.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStop" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStop;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Sets the lower limit of the Exposure Time parameter - Applies to: acA1920-155uc

        This float value sets the lower limit of the Exposure Time parameter.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeLowerLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Sets the upper limit of the Exposure Time parameter - Applies to: acA1920-155uc

        This float value sets the upper limit of the Exposure Time parameter.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeUpperLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Selects the strategy for controlling gain and shutter simultaneously - Applies to: acA1920-155uc

        The auto function profile specifies whether the gain or the exposure time will be kept as low as possible when the camera is making automatic adjustments to achieve a target average gray value for the pixel data from the Auto Function AOI that was related to the gain auto and the exposure auto function. By default, the auto function profile feature minimizes gain.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionProfile" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionProfileEnums>& AutoFunctionProfile;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Sets the height of the auto function region of interest in pixels - Applies to: acA1920-155uc

        This value sets the height of the auto function region of interest in pixels.
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIHeight;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Sets the starting column of the auto function region of interest in pixels - Applies to: acA1920-155uc

        The Offset X parameter determines the position of the auto function region of interest in the x direction.
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIOffsetX;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Sets the starting line of the auto function region of interest in pixels - Applies to: acA1920-155uc

        The Offset Y parameter determines the position of the auto function region of interest in the y direction.
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIOffsetY;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Selects the Auto Function ROI - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selecting Parameters: AutoFunctionROIWidth, AutoFunctionROIHeight, AutoFunctionROIOffsetX, AutoFunctionROIOffsetY, AutoFunctionROIUseBrightness and AutoFunctionROIUseWhiteBalance

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROISelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionROISelectorEnums>& AutoFunctionROISelector;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Selects brightness to be adjusted by an auto function - Applies to: acA1920-155uc

        For the selected Auto Function ROI, brightness will be adjusted by an auto function. Depending on the Auto Function Profile setting, the adjustment will be done either by the Gain Auto or by the Exposure Auto auto function. 
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIUseBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionROIUseBrightness;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Selects white balance to be adjusted by the related auto function - Applies to: acA1920-155uc

        For the selected Auto Function ROI, white balance will be adjusted by the Balance White Auto auto function.
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIUseWhiteBalance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionROIUseWhiteBalance;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Sets the width of the auto function region of interest in pixels - Applies to: acA1920-155uc

        This value sets the width of the auto function region of interest in pixels.
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIWidth;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Sets the lower limit of the Gain parameter - Applies to: acA1920-155uc

        This float value sets the lower limit of the Gain parameter.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoGainLowerLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Sets the upper limit of the Gain parameter - Applies to: acA1920-155uc

        This float value sets the upper limit of the Gain parameter.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoGainUpperLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Sets the target average brightness for the gain auto function and the exposure auto function - Applies to: acA1920-155uc

        This float value sets the target average brightness for the gain auto function and the exposure auto function.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoTargetBrightness;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the value of the selected balance ratio control as a float - Applies to: acA1920-155uc

        This value sets the selected balance ratio control as a float value.
    
        Visibility: Beginner

        Selected by: BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatio" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceRatio;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Selects a balance ratio to configure - Applies to: acA1920-155uc

        This enumeration selects a balance ratio control to configure. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.
    
        Visibility: Beginner

        Selecting Parameters: BalanceRatio

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceRatioSelectorEnums>& BalanceRatioSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Adjusts the white balance setting automatically - Applies to: acA1920-155uc

        Balance White Auto is the 'automatic' counterpart to manually setting the white balance. Automatic white balancing is a two-step process. First, the Balance Ratio Abs parameter values for red, green, and blue are each set to 1.5. Then, assuming a 'gray world' model, the Balance Ratio Abs parameter values are automatically adjusted such that the average values for the 'red' and 'blue' pixels match the average value for the 'green' pixels.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceWhiteAutoEnums>& BalanceWhiteAuto;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the number of adjacent horizontal pixels to be summed - Applies to: acA1920-155uc

        Binning increases the camera's response to light by summing the charges from adjacent pixels into one pixel. The Binning Horizontal parameter sets the number of adjacent horizontal pixels to be summed. Their summed charges will be reported out of the camera as a single pixel.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningHorizontal;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the number of adjacent vertical pixels to be summed - Applies to: acA1920-155uc

        Binning increases the camera's response to light by summing the charges from adjacent pixels into one pixel. The Binning Vertical parameter sets the number of adjacent vertical pixels to be summed. Their summed charges will be reported out of the camera as a single pixel.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningVertical;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Sets the value of the selected black level control as a float - Applies to: acA1920-155uc

        This value sets the selected black level control as a float value. Adjusting the camera's black level will result in an offset to the pixel values output by the camera.
    
        Visibility: Beginner

        Selected by: BlackLevelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevel" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BlackLevel;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Selcts a black level control to configure - Applies to: acA1920-155uc

        This enumeration selects the black level control to configure. Once a black level control has been selected, all changes to the black level settings will be applied to the selected control.
    
        Visibility: Beginner

        Selecting Parameters: BlackLevel

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BlackLevelSelectorEnums>& BlackLevelSelector;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Informs about the USB speed mode - Applies to: acA1920-155uc

        Informs about the current USB speed mode.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslUSBSpeedMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslUSBSpeedModeEnums>& BslUSBSpeedMode;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables the horizontal centering of the image - Applies to: acA1920-155uc

        This feature is used to center the image horizontally.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables the vertical centering of the image - Applies to: acA1920-155uc

        This feature is used to center the image vertically.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterY;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Selects which counter to retrieve data from - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selecting Parameters: ChunkCounterValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkCounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkCounterSelectorEnums>& ChunkCounterSelector;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Indicates the value of the selected Chunk counter - Applies to: acA1920-155uc

        Indicates the value of the selected Chunk counter.
    
        Visibility: Beginner

        Selected by: ChunkCounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkCounterValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkCounterValue;

    //@}


    //! \name Categories: ChunkDataControl
    //@{
    /*!
        \brief Enables the inclusion of the selected chunk in the payload data - Applies to: acA1920-155uc

        This boolean value enables the inclusion of the selected chunk in the payload data.
    
        Visibility: Beginner

        Selected by: ChunkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkEnable;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Returns the exposure time used to capture the image - Applies to: acA1920-155uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkExposureTime;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Returns the gain used to capture the image - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selected by: ChunkGainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGain" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkGain;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Selects which Gain to retrieve data from - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selecting Parameters: ChunkGain

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkGainSelectorEnums>& ChunkGainSelector;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief A bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: acA1920-155uc

        This value is a bit field that indicates the status of all of the camera's input and output lines when the image was acquired.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineStatusAll;

    //@}


    //! \name Categories: ChunkDataControl
    //@{
    /*!
        \brief Enables the chunk mode - Applies to: acA1920-155uc

        This boolean value enables the camera's chunk mode.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkModeActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkModeActive;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Indicates the value of CRC checksum - Applies to: acA1920-155uc

        This integer indicates the value of CRC checksum.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkPayloadCRC16" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;

    //@}


    //! \name Categories: ChunkDataControl
    //@{
    /*!
        \brief Selects chunks for enabling - Applies to: acA1920-155uc

        This enumeration selects chunks for enabling.
    
        Visibility: Beginner

        Selecting Parameters: ChunkEnable

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkSelectorEnums>& ChunkSelector;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Indicates the value of the timestamp when the image was acquired - Applies to: acA1920-155uc

        This integer indicates the value of the timestamp when the image was acquired.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkTimestamp;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Adjustment of hue of the selected color (float) - Applies to: acA1920-155uc

        Sets a floating point value for the adjustment of hue of the selected color.
    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentHue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Adjustment of saturation of the selected color (float) - Applies to: acA1920-155uc

        Sets a floating point value for the adjustment of saturation of the selected color.
    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentSaturation;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Selects the color for color adjustment - Applies to: acA1920-155uc

        Selects the color for color adjustment.
Those colors in the image will be adjusted where the selected color predominates.
    
        Visibility: Expert

        Selecting Parameters: ColorAdjustmentHue and ColorAdjustmentSaturation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorAdjustmentSelectorEnums>& ColorAdjustmentSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Currently effective color space - Applies to: acA1920-155uc

        Reports the currently effective color space (read only). When no light source preset is selected, the camera delivers colors in accord with the RGB color space. RGB is reported as the currently effective color space. When a light source preset is selected the colors are automatically corrected to bring them in accord with the sRGB color space. sRGB is reported as the currently effective color space.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorSpace" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorSpaceEnums>& ColorSpace;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Selects the matrix color transformation between color spaces - Applies to: acA1920-155uc

        Selects the matrix color transformation between color spaces.
Generally, the related color spaces are used for internal processing: The color signals provided by the sensor are transformed to the RGB color space to allow further transformations (to account for the type of light source, for color adjustment, for white balance, etc.).
The color transformation selected here does not refer to the color space selected for the transmission of image data out of the camera.

    
        Visibility: Guru

        Selecting Parameters: ColorTransformationValueSelector and ColorTransformationValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationSelectorEnums>& ColorTransformationSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets a floating point value for the selected element in the color transformation matrix - Applies to: acA1920-155uc

        Sets a floating point value for the selected element in the color transformation matrix.
    
        Visibility: Guru

        Selected by: ColorTransformationSelector and ColorTransformationValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorTransformationValue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Selects the element to be entered in the color transformation matrix - Applies to: acA1920-155uc

        Selects the element to be entered in the 3 x 3 color transformation matrix for custom matrix color transformation.
Note: Depending on the camera model, some elements in the color transformation matrix may be preset and can not be changed.

    
        Visibility: Guru

        Selected by: ColorTransformationSelector

        Selecting Parameters: ColorTransformationValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationValueSelectorEnums>& ColorTransformationValueSelector;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets the duration (or number of events) before the CounterEnd event is generated - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CounterDuration;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Select the events that will be the source to increment the Counter - Applies to: acA1920-155uc

        Select the events that will be the source to increment the Counter.
    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterEventSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterEventSourceEnums>& CounterEventSource;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Does a software reset of the selected counter - Applies to: acA1920-155uc

        Does a software reset of the selected counter.
    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& CounterReset;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Selects the Activation mode of the Counter Reset Source signal - Applies to: acA1920-155uc

        Selects the Activation mode of the Counter Reset Source signal.
    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetActivationEnums>& CounterResetActivation;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Selects the signals that will be the source to reset the Counter - Applies to: acA1920-155uc

        Selects the signals that will be the source to reset the Counter.
    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetSourceEnums>& CounterResetSource;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Selects which Counter to configure - Applies to: acA1920-155uc

        Selects which Counter to configure.
    
        Visibility: Beginner

        Selecting Parameters: CounterEventSource, CounterResetSource, CounterResetActivation and CounterReset

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterSelectorEnums>& CounterSelector;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets horizontal sub-sampling - Applies to: acA1920-155uc

        Horizontal sub-sampling of the image. This has the net effect of reducing the horizontal resolution (width) of the image by the specified horizontal decimation factor. A value of 1 indicates that the camera performs no horizontal decimation.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationHorizontal;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets vertical sub-sampling - Applies to: acA1920-155uc

        Vertical sub-sampling of the image. This has the net effect of reducing the vertical resolution (height) of the image by the specified vertical decimation factor. A value of 1 indicates that the camera performs no vertical decimation.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationVertical;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the version of the device's firmware and software - Applies to: acA1920-155uc

        This is a read only element. It is a string that indicates the version of the device's firmware and software.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceFirmwareVersion;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the actual bandwidth the camera will use - Applies to: acA1920-155uc

        This value indicates the actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data given the current AOI settings, chunk feature settings, and the pixel format setting.
    
        Visibility: Expert

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkCurrentThroughput" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkCurrentThroughput;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Selects the link of the device to control - Applies to: acA1920-155uc

        The Device Link Selector parameter is of type integer and selects the link of the device to control.
    
        Visibility: Expert

        Selecting Parameters: DeviceLinkCurrentThroughput, DeviceLinkThroughputLimit, DeviceLinkThroughputLimitMode and DeviceLinkSpeed

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the speed of transmission negotiated on the selected link - Applies to: acA1920-155uc

        The Device Link Speed parameter is of type integer and indicates the speed of transmission negotiated on the selected link.
    
        Visibility: Expert

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSpeed" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSpeed;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Limits the average stream interface bandwidth to device link throughput limit bytes per second - Applies to: acA1920-155uc

        The Device Link Throughput Limit parameter is of type integer and sets the limit of the average stream interface bandwidth to device link throughput limit bytes per second.
    
        Visibility: Beginner

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkThroughputLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkThroughputLimit;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Controls if the device link throughput limit is active - Applies to: acA1920-155uc

        Controls if the device link throughput limit is active. When disabled, lower level throughput limit specific features are expected to control the throughput. When enabled, the device link throughput limit controls the overall throughput.
    
        Visibility: Beginner

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkThroughputLimitMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceLinkThroughputLimitModeEnums>& DeviceLinkThroughputLimitMode;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Provides additional information from the vendor about the device - Applies to: acA1920-155uc

        This is a read only element. It is a string that provides additional information from the vendor about the camera.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceManufacturerInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceManufacturerInfo;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the model name of the device - Applies to: acA1920-155uc

        This is a read only element. It is a text description that indicates the model name of the device.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceModelName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Immediately resets and reboots the device - Applies to: acA1920-155uc

        This is a command that immediately resets and reboots the device.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceReset;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Major version of the underlying SFNC - Applies to: acA1920-155uc

        Indicates the Major version of the Standard Features Naming Convention (SFNC) that was used for the camera's GenICam XML file.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMajor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Minor version of the underlying SFNC - Applies to: acA1920-155uc

        Indicates the Minor version of the Standard Features Naming Convention (SFNC) that was used for the camera's GenICam XML file.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief SubMinor version of the underlying SFNC - Applies to: acA1920-155uc

        Indicates the SubMinor version of the Standard Features Naming Convention (SFNC) that was used for the camera's GenICam XML file.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionSubMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionSubMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the scan type of the device's sensor - Applies to: acA1920-155uc

        This enumeration lists the possible scan types for the sensor in the device.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceScanType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceScanTypeEnums>& DeviceScanType;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the serial number of the device - Applies to: acA1920-155uc

        This is a read only element. It is a string that indicates the serial number of the device.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSerialNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceSerialNumber;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Shows the current temperature of the selected target in degrees centigrade - Applies to: acA1920-155uc

        This float value shows the current temperature of the selected target in degrees centigrade.
    
        Visibility: Expert

        Selected by: DeviceTemperatureSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& DeviceTemperature;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Lists the temperature sources available for readout - Applies to: acA1920-155uc

        This enumeration lists the temperature sources available for readout.
    
        Visibility: Expert

        Selecting Parameters: DeviceTemperature

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperatureSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceTemperatureSelectorEnums>& DeviceTemperatureSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief A device ID that is user programmable - Applies to: acA1920-155uc

        This is a read/write element. It is a user programmable string.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceUserID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceUserID;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the name of the device's vendor - Applies to: acA1920-155uc

        This is a read only element. It is a text description that indicates the name of the device's vendor.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVendorName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVendorName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the version of the device - Applies to: acA1920-155uc

        This is a read only element. It is a string that indicates the version of the device.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVersion;

    //@}


    //! \name Categories: EventExposureEndData
    //@{
    /*!
        \brief Returns the unique identifier of the ExposureEnd type of Event - Applies to: acA1920-155uc

        Returns the unique identifier of the ExposureEnd type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEnd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEnd;

    //@}


    //! \name Categories: EventExposureEndData
    //@{
    /*!
        \brief Indicates the frame ID for an exposure end event - Applies to: acA1920-155uc

        This enumeration value indicates the frame ID for an exposure end event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEndFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEndFrameID;

    //@}


    //! \name Categories: EventExposureEndData
    //@{
    /*!
        \brief Indicates the time stamp for an exposure end event - Applies to: acA1920-155uc

        This enumeration value indicates the time stamp for an exposure end event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEndTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEndTimestamp;

    //@}


    //! \name Categories: EventFrameBurstStartData
    //@{
    /*!
        \brief Returns the unique identifier of the FrameBurstStart type of Event - Applies to: acA1920-155uc

        Returns the unique identifier of the FrameBurstStart type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStart;

    //@}


    //! \name Categories: EventFrameBurstStartData
    //@{
    /*!
        \brief Indicates the frame ID for a frame burst start event - Applies to: acA1920-155uc

        This enumeration value indicates the frame ID for a frame burst start event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartFrameID;

    //@}


    //! \name Categories: EventFrameBurstStartOvertriggerData
    //@{
    /*!
        \brief Returns the unique identifier of the FrameBurstOvertriggerStart type of Event - Applies to: acA1920-155uc

        Returns the unique identifier of the FrameBurstStartOvertrigger type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertrigger;

    //@}


    //! \name Categories: EventFrameBurstStartOvertriggerData
    //@{
    /*!
        \brief Indicates the frame ID for a frame burst start overtrigger event - Applies to: acA1920-155uc

        This enumeration value indicates the frame ID for a frame burst start overtrigger event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertriggerFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertriggerFrameID;

    //@}


    //! \name Categories: EventFrameBurstStartOvertriggerData
    //@{
    /*!
        \brief Indicates the time stamp for a frame burst start overtrigger event - Applies to: acA1920-155uc

        This enumeration value indicates the time stamp for a frame burst start overtrigger event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertriggerTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertriggerTimestamp;

    //@}


    //! \name Categories: EventFrameBurstStartData
    //@{
    /*!
        \brief Indicates the time stamp for a frame burst start event - Applies to: acA1920-155uc

        This enumeration value indicates the time stamp for a frame burst start event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartTimestamp;

    //@}


    //! \name Categories: EventFrameStartData
    //@{
    /*!
        \brief Returns the unique identifier of the FrameStart type of Event - Applies to: acA1920-155uc

        Returns the unique identifier of the FrameStart type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStart;

    //@}


    //! \name Categories: EventFrameStartData
    //@{
    /*!
        \brief Indicates the frame ID for a frame start event - Applies to: acA1920-155uc

        This enumeration value indicates the frame ID for a frame start event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartFrameID;

    //@}


    //! \name Categories: EventFrameStartOvertriggerData
    //@{
    /*!
        \brief Returns the unique identifier of the FrameOvertriggerStart type of Event - Applies to: acA1920-155uc

        Returns the unique identifier of the FrameStartOvertrigger type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertrigger;

    //@}


    //! \name Categories: EventFrameStartOvertriggerData
    //@{
    /*!
        \brief Indicates the frame ID for a frame start overtrigger event - Applies to: acA1920-155uc

        This enumeration value indicates the frame ID for a frame start overtrigger event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertriggerFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertriggerFrameID;

    //@}


    //! \name Categories: EventFrameStartOvertriggerData
    //@{
    /*!
        \brief Indicates the time stamp for a frame start overtrigger event - Applies to: acA1920-155uc

        This enumeration value indicates the time stamp for a frame start overtrigger event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertriggerTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertriggerTimestamp;

    //@}


    //! \name Categories: EventFrameStartData
    //@{
    /*!
        \brief Indicates the time stamp for a frame start event - Applies to: acA1920-155uc

        This enumeration value indicates the time stamp for a frame start event.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartTimestamp;

    //@}


    //! \name Categories: EventControl
    //@{
    /*!
        \brief Activate or deactivate the notification to the host application of the occurrence of the selected
Event - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selected by: EventSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventNotification" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventNotificationEnums>& EventNotification;

    //@}


    //! \name Categories: EventControl
    //@{
    /*!
        \brief Selects which Event to signal to the host application - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selecting Parameters: EventNotification

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventSelectorEnums>& EventSelector;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Sets the key to access the selected feature - Applies to: acA1920-155uc

    
        Visibility: Guru

        Selected by: ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExpertFeatureAccessKey;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Selects the feature to configure  Once a feature has been selected, all changes made using the feature enable feature will be applied to the selected feature - Applies to: acA1920-155uc

    
        Visibility: Guru

        Selecting Parameters: ExpertFeatureEnable and ExpertFeatureAccessKey

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExpertFeatureAccessSelectorEnums>& ExpertFeatureAccessSelector;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Enable the selected Feature - Applies to: acA1920-155uc

    
        Visibility: Guru

        Selected by: ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ExpertFeatureEnable;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Adjusts the Auto Exposure Time Abs parameter value automatically - Applies to: acA1920-155uc

        Exposure Auto is the 'automatic' counterpart to manually setting the Exposure Time Abs parameter. It adjusts the Exposure Time Abs parameter value automatically within set limits until a target average gray value for the pixel data of the related Auto Function AOI is reached.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureAutoEnums>& ExposureAuto;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the exposure mode - Applies to: acA1920-155uc

        This enumeration sets the exposure mode.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureModeEnums>& ExposureMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the maximum overlap time of the sensor exposure with sensor readout in trigger width exposure mode in microseconds - Applies to: acA1920-155uc

        This float value sets the maximum overlap time (in microseconds) of the sensor exposure with sensor readout in trigger width exposure mode.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureOverlapTimeMax;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Selects the Exposure Overlap Time Mode - Applies to: acA1920-155uc

        Selects the manual or automatic control of the maximum overlap between immediately succeeding image acquisitions.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureOverlapTimeModeEnums>& ExposureOverlapTimeMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the camera's exposure time directly in microseconds - Applies to: acA1920-155uc

        This float value sets the camera's exposure time in microseconds.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTime;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Defines the intermediate access buffer - Applies to: acA1920-155uc

        The File Access Buffer feature defines the intermediate access buffer that allows the exchange of data between the device file storage and the application.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessBuffer" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& FileAccessBuffer;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Controls the mapping between the device file storage and the FileAccessBuffer - Applies to: acA1920-155uc

        This feature controls the mapping between the device file storage and the FileAccessBuffer.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessLength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessLength;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Controls the mapping between the device file storage and the FileAccessBuffer - Applies to: acA1920-155uc

        This feature controls the mapping between the device file storage and the FileAccessBuffer.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessOffset;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Selects the access mode in which a file is opened - Applies to: acA1920-155uc

        The File Open Mode feature selects the access mode in which a file is opened in the device.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOpenMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOpenModeEnums>& FileOpenMode;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Executes the selected operation - Applies to: acA1920-155uc

        The File Operation Execute feature is the command that executes the operation selected by FileOperationSelector on the selected file.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationExecute" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& FileOperationExecute;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Represents the file operation result - Applies to: acA1920-155uc

        The File Operation Result feature represents the file operation result. For Read or Write operations, the number of successfully read/written bytes is returned.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationResult" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileOperationResult;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Selects the target operation for the selected file - Applies to: acA1920-155uc

        The File Operation Selector feature selects the target operation for the selected file in the device. This Operation is executed when the FileOperationExecute feature is called.
    
        Visibility: Guru

        Selected by: FileSelector

        Selecting Parameters: FileOperationExecute, FileOperationResult, FileOperationStatus, FileAccessLength and FileAccessOffset

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationSelectorEnums>& FileOperationSelector;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Represents the file operation execution status - Applies to: acA1920-155uc

        The File Operation Status feature represents the file operation execution status.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationStatusEnums>& FileOperationStatus;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief This feature selects the target file in the device - Applies to: acA1920-155uc

        The File Selector feature selects the target file in the device.
    
        Visibility: Guru

        Selecting Parameters: FileOperationExecute, FileSize, FileOperationResult, FileOperationStatus, FileAccessLength, FileAccessOffset, FileAccessBuffer, FileOpenMode and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileSelectorEnums>& FileSelector;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Represents the size of the selected file - Applies to: acA1920-155uc

        The File Size feature represents the size of the selected file in bytes.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileSize;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Sets the selected gain control in dB - Applies to: acA1920-155uc

        This is a float value that sets the selected gain control in dB.
    
        Visibility: Beginner

        Selected by: GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gain" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gain;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Adjusts the Gain Raw parameter value automatically - Applies to: acA1920-155uc

        The gain auto function is the 'automatic' counterpart to manually setting the Gain Raw parameter. It allows to adjust the Gain Raw parameter value automatically within set limits until a target average gray value for the pixel data from the related Auto Function AOI is reached.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainAutoEnums>& GainAuto;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Selects the gain control to configure - Applies to: acA1920-155uc

        The Gain Selector parameter is used to select the gain control to configure. Once a gain control has been selected, all changes to the gain settings will be applied to the selected control.
    
        Visibility: Beginner

        Selecting Parameters: Gain

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainSelectorEnums>& GainSelector;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Performs gamma correction of pixel intensity - Applies to: acA1920-155uc

        The gamma correction feature lets you modify the brightness of the pixel values output by the camera's sensor to account for a non-linearity in the human perception of brightness.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gamma" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gamma;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the height of the camera's area of interest (AOI) in pixels - Applies to: acA1920-155uc

        This parameter is of integer type and determines the height of the camera's area of interest (AOI) in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Height" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Height;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the camera's maximum allowed height of the area of interest (AOI) in pixels - Applies to: acA1920-155uc

        This is a read only parameter. It is of integer type and indicates the maximum allowed height of the camera's area of interest (AOI) in pixels. It takes into account any function that may limit the maximum height.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=HeightMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& HeightMax;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Enables the selected LUT - Applies to: acA1920-155uc

        This boolean value enables the selected LUT.
    
        Visibility: Expert

        Selected by: LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LUTEnable;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Sets the LUT element to access  - Applies to: acA1920-155uc

        This value sets the LUT element to access. This value is used to index into a LUT array.
    
        Visibility: Guru

        Selected by: LUTSelector

        Selecting Parameters: LUTValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTIndex;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Selects the lookup table (LUT) to configure  Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT - Applies to: acA1920-155uc

        This enumeration the lookup table (LUT) to configure. Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT.
    
        Visibility: Expert

        Selecting Parameters: LUTEnable, LUTIndex, LUTValue and LUTValueAll

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LUTSelectorEnums>& LUTSelector;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Sets the value of the LUT element at the LUT index - Applies to: acA1920-155uc

        This value sets the value of the LUT element at the LUT index.
    
        Visibility: Guru

        Selected by: LUTSelector and LUTIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTValue;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Accesses the entire content of the selected LUT in one chunk access - Applies to: acA1920-155uc

    
        Visibility: Expert

        Selected by: LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& LUTValueAll;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Selects the light source preset - Applies to: acA1920-155uc

        This parameter determines the light source preset. The colors in the image will be corrected to compensate for the color shift due to the selected light source. When a light source preset is selected the colors in the image will be corrected to compensate for the color shift due to the selected light source.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LightSourcePreset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LightSourcePresetEnums>& LightSourcePreset;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the absolute value of the selected line debouncer time in microseconds - Applies to: acA1920-155uc

        This float value sets the absolute value of the selected line debouncer time in microseconds.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineDebouncerTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineDebouncerTime;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Reports the electrical configuration of the selected line - Applies to: acA1920-155uc

        This feature reports the current electrical format of the selected physical input or output line. The Line Format parameter can take any of the following values: No Connect: The line is not connected. Tri-state: The line is currently in tri-state mode (not driven). TTL: The line is currently accepting or sending TTL level signals. LVDS: The line is currently accepting or sending LVDS level signals. RS-422: The line is currently accepting or sending RS-422 level signals. Opto-coupled: The line is opto-coupled.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineFormatEnums>& LineFormat;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Enables the signal inverter function for the selected input or output line - Applies to: acA1920-155uc

        This boolean value enables the signal inverter function for the selected input or output line.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineInverter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineInverter;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Reports the line logic of the selected line - Applies to: acA1920-155uc

        Reports the line logic of the selected line. The line logic can be positive or negative.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineLogic" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineLogicEnums>& LineLogic;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the absolute value (in microseconds) for the minimum signal width of an output signal - Applies to: acA1920-155uc

        This float value sets the absolute value (in microseconds) for the minimum signal width of a signal that is received from the frequency converter or from the shaft encoder module and that is associated with a digital output line.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMinimumOutputPulseWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineMinimumOutputPulseWidth;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the mode for the selected line - Applies to: acA1920-155uc

        This feature controls whether the physical line is used to input or output a signal. When a line supports input and output mode, the default state is 'input' to avoid possible electrical contention. The Line Mode parameter can take any of the following values: Input: The selected physical line is used to input an electrical signal. Output: The selected physical line is used to output an electrical signal.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineModeEnums>& LineMode;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Indicates that an overload condition was detected on the selected line - Applies to: acA1920-155uc

        This boolean value indicates that an overload condition was detected on the selected line.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineOverloadStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineOverloadStatus;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Selects the I/O line to configure - Applies to: acA1920-155uc

        This enumeration selects the I/O line to configure. Once a line has been selected, all changes to the line settings will be applied to the selected line.
    
        Visibility: Beginner

        Selecting Parameters: LineMode, LineFormat, LineLogic, LineSource, LineInverter, LineDebouncerTime, LineMinimumOutputPulseWidth, LineOverloadStatus and LineStatus

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSelectorEnums>& LineSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the source signal for the selected line (if the selected line is an output) - Applies to: acA1920-155uc

        This enumeration selects the internally generated camera signal (source signal) for the selected line when the selected line is an output. 
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSourceEnums>& LineSource;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Indicates the current logical state for the selected line - Applies to: acA1920-155uc

        This boolean value indicates the current logical state for the selected line at the time of polling.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineStatus;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief A single bitfield indicating the current logical state of all available line signals at time of polling - Applies to: acA1920-155uc

        This integer value is a single bitfield that indicates the current logical state of all available lines at time of polling.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStatusAll;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the X offset (left offset) of the area of interest (AOI) in pixels - Applies to: acA1920-155uc

        The Offset X parameter determines the position of the area of interest (AOI) in the x direction. Since the position of the AOI is referenced to the top left corner of the sensor array, the Offset X parameter sets the distance in pixels between the left side of the sensor and the left side of the AOI.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the Y offset (top offset) of the area of interest (AOI) in pixels - Applies to: acA1920-155uc

        The Offset Y parameter determines the position of the area of interest (AOI) in the y direction. Since the position of the AOI is referenced to the top left corner of the sensor array, the Offset Y parameter sets the distance in pixels between the top of the sensor and the top of the AOI.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetY;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Size of the payload in bytes - Applies to: acA1920-155uc

        Size of the payload in bytes. This is the total number of bytes sent in the payload. 
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadSize;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the current alignment of the camera's Bayer filter to the pixels in the acquired images - Applies to: acA1920-155uc

        This is a read only feature. This enumeration provides a list of values that indicate the current alignment of the camera's Bayer filter to the pixels in the acquired images. The alignment of the Bayer filter depends on the camera model.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelColorFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelColorFilterEnums>& PixelColorFilter;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the maximum possible pixel value that could be transferred from the camera - Applies to: acA1920-155uc

        This a read only feature. The Dynamic Range Max parameter indicates the maximum possible pixel value that could be transferred from the camera.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMax;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the minimum possible pixel value that could be transferred from the camera - Applies to: acA1920-155uc

        This a read only feature. The Dynamic Range Min parameter indicates the minimum possible pixel value that could be transferred from the camera.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMin;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the format of the pixel data transmitted for acquired images - Applies to: acA1920-155uc

        The Pixel Format parameter determines the format (layout) of the image data that will be output from the camera. The available pixel formats depend on the camera model and whether the camera is monochrome or color.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelFormatEnums>& PixelFormat;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the depth of the pixel values in the image in bits per pixel - Applies to: acA1920-155uc

        This is a read only feature. This enumeration provides a list of values that indicate the depth of the pixel values in the acquired images in bits per pixel. This value will always be coherent with the pixel format setting.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelSizeEnums>& PixelSize;

    //@}


    //! \name Categories: RemoveParameterLimitControl
    //@{
    /*!
        \brief Removes the factory-set limits of the selected parameter - Applies to: acA1920-155uc

        Removes the factory-set limits of the selected parameter. Having removed the factory-set limits you may set the parameter within extended limits. These are only defined by technical restrictions. Note:  Inferior image quality may result.
    
        Visibility: Guru

        Selected by: RemoveParameterLimitSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveParameterLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& RemoveParameterLimit;

    //@}


    //! \name Categories: RemoveParameterLimitControl
    //@{
    /*!
        \brief Selects the parameter to configure  Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter - Applies to: acA1920-155uc

        This enumeration selects the parameter to configure. Selects the parameter to configure. Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter
    
        Visibility: Guru

        Selecting Parameters: RemoveParameterLimit

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveParameterLimitSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<RemoveParameterLimitSelectorEnums>& RemoveParameterLimitSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Indicates the maximum allowed frame acquisition rate - Applies to: acA1920-155uc

        The Resulting Frame Rate parameter indicates the 'absolute' value of the maximum allowed acquisition frame rate. The 'absolute' value is a float value that indicates the maximum allowed acquisition frame rate in frames per second given the current settings for the area of interest, exposure time, and bandwidth.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFrameRate;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables the horizontal mirroring of the image - Applies to: acA1920-155uc

        This feature is used to mirror the captured image horizontally. The pixel values for each line in a captured image will be swapped end-for-end about the line's center. You can use the AOI feature when using the reverse X feature. Note that the position of the AOI relative to the sensor remains the same.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables the vertical mirroring of the image - Applies to: acA1920-155uc

        This feature is used to mirror the captured image vertically. The pixel values for each row in a captured image will be swapped end-for-end about the row's center. You can use the AOI feature when using the reverse Y feature. Note that the position of the AOI relative to the sensor remains the same.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseY;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Size of first final Payload Transfer - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadFinalTransfer1Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadFinalTransfer1Size;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Size of second final Payload Transfer - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadFinalTransfer2Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadFinalTransfer2Size;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Expected Number of Payload Transfers - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadTransferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadTransferCount;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Expected Size of a single Payload Transfer - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadTransferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadTransferSize;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the height of the camera's sensor in pixels - Applies to: acA1920-155uc

        This is a read only parameter. It is of integer type and indicates the actual height of the camera's sensor in pixels.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorHeight;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the readout mode of the device - Applies to: acA1920-155uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorReadoutModeEnums>& SensorReadoutMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Indicates the sensor readout time given the current settings - Applies to: acA1920-155uc

        The Sensor Readout Time parameter indicates the sensor readout time given the current settings.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SensorReadoutTime;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the width of the camera's sensor in pixels - Applies to: acA1920-155uc

        This is a read only parameter. It is of integer type and indicates the actual width of the camera's sensor in pixels.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorWidth;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the shutter mode - Applies to: acA1920-155uc

        This enumeration sets the shutter mode.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShutterMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShutterModeEnums>& ShutterMode;

    //@}


    //! \name Categories: SoftwareSignalControl
    //@{
    /*!
        \brief Generates a signal that can be used as a software trigger - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selected by: SoftwareSignalSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SoftwareSignalPulse" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SoftwareSignalPulse;

    //@}


    //! \name Categories: SoftwareSignalControl
    //@{
    /*!
        \brief Selects the software signal to control - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selecting Parameters: SoftwareSignalPulse

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SoftwareSignalSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SoftwareSignalSelectorEnums>& SoftwareSignalSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Temperature State - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureState" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureStateEnums>& TemperatureState;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Selecting a test image from the list will output the test image - Applies to: acA1920-155uc

        The Test Image Selector is used to set the camera to output a test image. You can set the value of the Test Image Selector to one of the test images or to 'test image off'.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TestImageSelectorEnums>& TestImageSelector;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets the delay (in microseconds) of the Timer pulse - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDelay;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets the duration (in microseconds) of the Timer pulse - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDuration;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Selects which Timer to configure - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selecting Parameters: TimerDuration, TimerDelay and TimerTriggerSource

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerSelectorEnums>& TimerSelector;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Selects the source of the trigger to start the Timer - Applies to: acA1920-155uc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerTriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerTriggerSourceEnums>& TimerTriggerSource;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Latches the current timestamp counter into TimestampLatchValue - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TimestampLatch;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Returns the latched value of the timestamp counter - Applies to: acA1920-155uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatchValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimestampLatchValue;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the signal transition needed to activate the selected trigger - Applies to: acA1920-155uc

        This enumeration sets the signal transition needed to activate the selected trigger.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerActivationEnums>& TriggerActivation;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the trigger delay time in microseconds - Applies to: acA1920-155uc

        This float value sets the absolute trigger delay in microseconds to apply after the trigger reception before effectively activating it.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TriggerDelay;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the mode for the selected trigger - Applies to: acA1920-155uc

        This enumeration sets the trigger mode for the selected trigger.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerModeEnums>& TriggerMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Selects the trigger type to configure - Applies to: acA1920-155uc

        This enumeration selects the trigger type to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.
    
        Visibility: Expert

        Selecting Parameters: TriggerMode, TriggerSoftware, TriggerSource and TriggerActivation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSelectorEnums>& TriggerSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Generates a software trigger signal that is used when the trigger source is set to 'software trigger' - Applies to: acA1920-155uc

        This command generates a software trigger signal. The software trigger signal will be used when the trigger source is set to 'software trigger'.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSoftware" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TriggerSoftware;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the signal source for the selected trigger - Applies to: acA1920-155uc

        The Trigger Source parameter specifies the source signal that will act as the frame start trigger signal.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSourceEnums>& TriggerSource;

    //@}


    //! \name Categories: UserDefinedValueControl
    //@{
    /*!
        \brief Sets a value for a User Defined Value - Applies to: acA1920-155uc

        Sets a parameter value for the currently selected User Defined Value.
    
        Visibility: Guru

        Selected by: UserDefinedValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserDefinedValue;

    //@}


    //! \name Categories: UserDefinedValueControl
    //@{
    /*!
        \brief Selects a User Defined Value - Applies to: acA1920-155uc

    
        Visibility: Guru

        Selecting Parameters: UserDefinedValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserDefinedValueSelectorEnums>& UserDefinedValueSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Selects the user settable output signal to configure - Applies to: acA1920-155uc

        This enumeration selects the user settable output signal to configure. Once a user settable output signal has been selected, all changes to the user settable output signal settings will be applied to the selected user settable output signal.
    
        Visibility: Beginner

        Selecting Parameters: UserOutputValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserOutputSelectorEnums>& UserOutputSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the state of the selected user settable output signal - Applies to: acA1920-155uc

        This boolean value sets the state of the selected user settable output signal.
    
        Visibility: Beginner

        Selected by: UserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& UserOutputValue;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief A single bitfield that sets the state of all user settable output signals in one access - Applies to: acA1920-155uc

        This integer value is a single bitfield that sets the state of all user settable output signals in one access.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserOutputValueAll;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Sets the user set to be used as the default startup set - Applies to: acA1920-155uc

        This enumeration sets the user set to be used as the default startup set. The user set that has been selected as the default startup set will be loaded as the active set whenever the camera is powered on or reset.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetDefault" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetDefaultEnums>& UserSetDefault;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Loads the selected configuration into the camera's volatile memory and makes it the active user set - Applies to: acA1920-155uc

        This command loads the selected user set from the non-volatile memory in the camera to the volatile memory and makes the selected set the active user set. Once the selected set is loaded, the parameters in the selected set will control the camera.
    
        Visibility: Beginner

        Selected by: UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetLoad;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Saves the current active user set into the selected user set   - Applies to: acA1920-155uc

        This command copies the parameters in the current active user set into the selected user set in the camera's non-volatile memory.
    
        Visibility: Beginner

        Selected by: UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSave" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetSave;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Selects the user set to load, save, or configure - Applies to: acA1920-155uc

        This enumeration selects the user set to load, save, or configure. Once a user set has been selected, all changes to the user set settings will be applied to the selected user set.
    
        Visibility: Beginner

        Selecting Parameters: UserSetSave and UserSetLoad

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetSelectorEnums>& UserSetSelector;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the width of the camera's area of interest (AOI) in pixels - Applies to: acA1920-155uc

        This parameter is of integer type and determines the width of the camera's area of interest (AOI) in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Width" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Width;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the camera's maximum allowed width of the area of interest (AOI) in pixels - Applies to: acA1920-155uc

        This is a read only parameter. It is of integer type and indicates the maximum allowed width of the camera's area of interest (AOI) in pixels. It takes into account any function that may limit the maximum width.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WidthMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WidthMax;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            LEFTCameraParams(LEFTCameraParams&);

            //! not implemented assignment operator
            LEFTCameraParams& operator=(LEFTCameraParams&);

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
        class AutoFunctionProfileEnumParameter : public Pylon::CEnumParameterT<AutoFunctionProfileEnums>
        {
        public:
            AutoFunctionProfileEnumParameter()
            {
            }

            virtual ~AutoFunctionProfileEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("MinimizeExposureTime", 21),
                    TableItem_t("MinimizeGain", 13)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class AutoFunctionROISelectorEnumParameter : public Pylon::CEnumParameterT<AutoFunctionROISelectorEnums>
        {
        public:
            AutoFunctionROISelectorEnumParameter()
            {
            }

            virtual ~AutoFunctionROISelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ROI1", 5),
                    TableItem_t("ROI2", 5)
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
        class BalanceWhiteAutoEnumParameter : public Pylon::CEnumParameterT<BalanceWhiteAutoEnums>
        {
        public:
            BalanceWhiteAutoEnumParameter()
            {
            }

            virtual ~BalanceWhiteAutoEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("Off", 4),
                    TableItem_t("Once", 5)
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
        class ColorSpaceEnumParameter : public Pylon::CEnumParameterT<ColorSpaceEnums>
        {
        public:
            ColorSpaceEnumParameter()
            {
            }

            virtual ~ColorSpaceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("RGB", 4),
                    TableItem_t("sRGB", 5)
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
                    TableItem_t("Coreboard", 10)
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
                static const size_t cItemCount = 8;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExpertFeature1", 15),
                    TableItem_t("ExpertFeature2", 15),
                    TableItem_t("ExpertFeature3", 15),
                    TableItem_t("ExpertFeature4", 15),
                    TableItem_t("ExpertFeature5", 15),
                    TableItem_t("ExpertFeature6", 15),
                    TableItem_t("ExpertFeature7", 15),
                    TableItem_t("ExpertFeature8", 15)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExposureAutoEnumParameter : public Pylon::CEnumParameterT<ExposureAutoEnums>
        {
        public:
            ExposureAutoEnumParameter()
            {
            }

            virtual ~ExposureAutoEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("Off", 4),
                    TableItem_t("Once", 5)
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
        class ExposureOverlapTimeModeEnumParameter : public Pylon::CEnumParameterT<ExposureOverlapTimeModeEnums>
        {
        public:
            ExposureOverlapTimeModeEnumParameter()
            {
            }

            virtual ~ExposureOverlapTimeModeEnumParameter()
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
        class GainAutoEnumParameter : public Pylon::CEnumParameterT<GainAutoEnums>
        {
        public:
            GainAutoEnumParameter()
            {
            }

            virtual ~GainAutoEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("Off", 4),
                    TableItem_t("Once", 5)
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
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("BayerBG", 8),
                    TableItem_t("BayerGB", 8),
                    TableItem_t("BayerGR", 8),
                    TableItem_t("BayerRG", 8),
                    TableItem_t("None", 5)
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
                static const size_t cItemCount = 12;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("BayerBG12", 10),
                    TableItem_t("BayerBG12p", 11),
                    TableItem_t("BayerBG8", 9),
                    TableItem_t("BayerGB12", 10),
                    TableItem_t("BayerGB12p", 11),
                    TableItem_t("BayerGB8", 9),
                    TableItem_t("BayerGR12", 10),
                    TableItem_t("BayerGR12p", 11),
                    TableItem_t("BayerGR8", 9),
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
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Bpp10", 6),
                    TableItem_t("Bpp12", 6),
                    TableItem_t("Bpp16", 6),
                    TableItem_t("Bpp24", 6),
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
        class SensorReadoutModeEnumParameter : public Pylon::CEnumParameterT<SensorReadoutModeEnums>
        {
        public:
            SensorReadoutModeEnumParameter()
            {
            }

            virtual ~SensorReadoutModeEnumParameter()
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
        class TemperatureStateEnumParameter : public Pylon::CEnumParameterT<TemperatureStateEnums>
        {
        public:
            TemperatureStateEnumParameter()
            {
            }

            virtual ~TemperatureStateEnumParameter()
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
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("AutoFunctions", 14),
                    TableItem_t("ColorRaw", 9),
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
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("AutoFunctions", 14),
                    TableItem_t("ColorRaw", 9),
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
    // Parameter class LEFTCameraParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class LEFTCameraParams::LEFTCameraParams_Data
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
        Pylon::CFloatParameter AutoExposureTimeLowerLimit;
        Pylon::CFloatParameter AutoExposureTimeUpperLimit;
        EnumParameterClasses::AutoFunctionProfileEnumParameter AutoFunctionProfile;
        Pylon::CIntegerParameter AutoFunctionROIHeight;
        Pylon::CIntegerParameter AutoFunctionROIOffsetX;
        Pylon::CIntegerParameter AutoFunctionROIOffsetY;
        EnumParameterClasses::AutoFunctionROISelectorEnumParameter AutoFunctionROISelector;
        Pylon::CBooleanParameter AutoFunctionROIUseBrightness;
        Pylon::CBooleanParameter AutoFunctionROIUseWhiteBalance;
        Pylon::CIntegerParameter AutoFunctionROIWidth;
        Pylon::CFloatParameter AutoGainLowerLimit;
        Pylon::CFloatParameter AutoGainUpperLimit;
        Pylon::CFloatParameter AutoTargetBrightness;
        Pylon::CFloatParameter BalanceRatio;
        EnumParameterClasses::BalanceRatioSelectorEnumParameter BalanceRatioSelector;
        EnumParameterClasses::BalanceWhiteAutoEnumParameter BalanceWhiteAuto;
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
        EnumParameterClasses::ColorSpaceEnumParameter ColorSpace;
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
        EnumParameterClasses::ExposureAutoEnumParameter ExposureAuto;
        EnumParameterClasses::ExposureModeEnumParameter ExposureMode;
        Pylon::CFloatParameter ExposureOverlapTimeMax;
        EnumParameterClasses::ExposureOverlapTimeModeEnumParameter ExposureOverlapTimeMode;
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
        EnumParameterClasses::GainAutoEnumParameter GainAuto;
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
        EnumParameterClasses::SensorReadoutModeEnumParameter SensorReadoutMode;
        Pylon::CFloatParameter SensorReadoutTime;
        Pylon::CIntegerParameter SensorWidth;
        EnumParameterClasses::ShutterModeEnumParameter ShutterMode;
        Pylon::CCommandParameter SoftwareSignalPulse;
        EnumParameterClasses::SoftwareSignalSelectorEnumParameter SoftwareSignalSelector;
        EnumParameterClasses::TemperatureStateEnumParameter TemperatureState;
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
    inline LEFTCameraParams::LEFTCameraParams(void)
        : m_pData(new LEFTCameraParams_Data())
        , AcquisitionBurstFrameCount(m_pData->AcquisitionBurstFrameCount)
        , AcquisitionFrameRate(m_pData->AcquisitionFrameRate)
        , AcquisitionFrameRateEnable(m_pData->AcquisitionFrameRateEnable)
        , AcquisitionMode(m_pData->AcquisitionMode)
        , AcquisitionStart(m_pData->AcquisitionStart)
        , AcquisitionStatus(m_pData->AcquisitionStatus)
        , AcquisitionStatusSelector(m_pData->AcquisitionStatusSelector)
        , AcquisitionStop(m_pData->AcquisitionStop)
        , AutoExposureTimeLowerLimit(m_pData->AutoExposureTimeLowerLimit)
        , AutoExposureTimeUpperLimit(m_pData->AutoExposureTimeUpperLimit)
        , AutoFunctionProfile(m_pData->AutoFunctionProfile)
        , AutoFunctionROIHeight(m_pData->AutoFunctionROIHeight)
        , AutoFunctionROIOffsetX(m_pData->AutoFunctionROIOffsetX)
        , AutoFunctionROIOffsetY(m_pData->AutoFunctionROIOffsetY)
        , AutoFunctionROISelector(m_pData->AutoFunctionROISelector)
        , AutoFunctionROIUseBrightness(m_pData->AutoFunctionROIUseBrightness)
        , AutoFunctionROIUseWhiteBalance(m_pData->AutoFunctionROIUseWhiteBalance)
        , AutoFunctionROIWidth(m_pData->AutoFunctionROIWidth)
        , AutoGainLowerLimit(m_pData->AutoGainLowerLimit)
        , AutoGainUpperLimit(m_pData->AutoGainUpperLimit)
        , AutoTargetBrightness(m_pData->AutoTargetBrightness)
        , BalanceRatio(m_pData->BalanceRatio)
        , BalanceRatioSelector(m_pData->BalanceRatioSelector)
        , BalanceWhiteAuto(m_pData->BalanceWhiteAuto)
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
        , ColorSpace(m_pData->ColorSpace)
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
        , ExposureAuto(m_pData->ExposureAuto)
        , ExposureMode(m_pData->ExposureMode)
        , ExposureOverlapTimeMax(m_pData->ExposureOverlapTimeMax)
        , ExposureOverlapTimeMode(m_pData->ExposureOverlapTimeMode)
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
        , GainAuto(m_pData->GainAuto)
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
        , SensorReadoutMode(m_pData->SensorReadoutMode)
        , SensorReadoutTime(m_pData->SensorReadoutTime)
        , SensorWidth(m_pData->SensorWidth)
        , ShutterMode(m_pData->ShutterMode)
        , SoftwareSignalPulse(m_pData->SoftwareSignalPulse)
        , SoftwareSignalSelector(m_pData->SoftwareSignalSelector)
        , TemperatureState(m_pData->TemperatureState)
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
    inline LEFTCameraParams::~LEFTCameraParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void LEFTCameraParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->AcquisitionBurstFrameCount.Attach(pNodeMap, "AcquisitionBurstFrameCount");
        m_pData->AcquisitionFrameRate.Attach(pNodeMap, "AcquisitionFrameRate");
        m_pData->AcquisitionFrameRateEnable.Attach(pNodeMap, "AcquisitionFrameRateEnable");
        m_pData->AcquisitionMode.Attach(pNodeMap, "AcquisitionMode");
        m_pData->AcquisitionStart.Attach(pNodeMap, "AcquisitionStart");
        m_pData->AcquisitionStatus.Attach(pNodeMap, "AcquisitionStatus");
        m_pData->AcquisitionStatusSelector.Attach(pNodeMap, "AcquisitionStatusSelector");
        m_pData->AcquisitionStop.Attach(pNodeMap, "AcquisitionStop");
        m_pData->AutoExposureTimeLowerLimit.Attach(pNodeMap, "AutoExposureTimeLowerLimit");
        m_pData->AutoExposureTimeUpperLimit.Attach(pNodeMap, "AutoExposureTimeUpperLimit");
        m_pData->AutoFunctionProfile.Attach(pNodeMap, "AutoFunctionProfile");
        m_pData->AutoFunctionROIHeight.Attach(pNodeMap, "AutoFunctionROIHeight");
        m_pData->AutoFunctionROIOffsetX.Attach(pNodeMap, "AutoFunctionROIOffsetX");
        m_pData->AutoFunctionROIOffsetY.Attach(pNodeMap, "AutoFunctionROIOffsetY");
        m_pData->AutoFunctionROISelector.Attach(pNodeMap, "AutoFunctionROISelector");
        m_pData->AutoFunctionROIUseBrightness.Attach(pNodeMap, "AutoFunctionROIUseBrightness");
        m_pData->AutoFunctionROIUseWhiteBalance.Attach(pNodeMap, "AutoFunctionROIUseWhiteBalance");
        m_pData->AutoFunctionROIWidth.Attach(pNodeMap, "AutoFunctionROIWidth");
        m_pData->AutoGainLowerLimit.Attach(pNodeMap, "AutoGainLowerLimit");
        m_pData->AutoGainUpperLimit.Attach(pNodeMap, "AutoGainUpperLimit");
        m_pData->AutoTargetBrightness.Attach(pNodeMap, "AutoTargetBrightness");
        m_pData->BalanceRatio.Attach(pNodeMap, "BalanceRatio");
        m_pData->BalanceRatioSelector.Attach(pNodeMap, "BalanceRatioSelector");
        m_pData->BalanceWhiteAuto.Attach(pNodeMap, "BalanceWhiteAuto");
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
        m_pData->ColorSpace.Attach(pNodeMap, "ColorSpace");
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
        m_pData->ExposureAuto.Attach(pNodeMap, "ExposureAuto");
        m_pData->ExposureMode.Attach(pNodeMap, "ExposureMode");
        m_pData->ExposureOverlapTimeMax.Attach(pNodeMap, "ExposureOverlapTimeMax");
        m_pData->ExposureOverlapTimeMode.Attach(pNodeMap, "ExposureOverlapTimeMode");
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
        m_pData->GainAuto.Attach(pNodeMap, "GainAuto");
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
        m_pData->SensorReadoutMode.Attach(pNodeMap, "SensorReadoutMode");
        m_pData->SensorReadoutTime.Attach(pNodeMap, "SensorReadoutTime");
        m_pData->SensorWidth.Attach(pNodeMap, "SensorWidth");
        m_pData->ShutterMode.Attach(pNodeMap, "ShutterMode");
        m_pData->SoftwareSignalPulse.Attach(pNodeMap, "SoftwareSignalPulse");
        m_pData->SoftwareSignalSelector.Attach(pNodeMap, "SoftwareSignalSelector");
        m_pData->TemperatureState.Attach(pNodeMap, "TemperatureState");
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

} // namespace Pylon
} // namespace LEFTCameraParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_LEFTCAMERAPARAMS_H