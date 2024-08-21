// Include files to use the pylon API.
#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif

// Namespace for using pylon objects.
using namespace Pylon;

// Settings to use any camera type.
#include "LEFT.h"
#include "LEFTArray.h"

using namespace Pylon;
using namespace Pylon::LEFTCameraParams_Params;

// Number of images to be grabbed.
static const uint32_t c_countOfImagesToGrab = 10;

// Namespace for using cout.
using namespace std;

int main(int argc, char* argv[])
{
    // The exit code of the sample application.
    int exitCode = 0;

    // Before using any pylon methods, the pylon runtime must be initialized. 
    PylonInitialize();

    try
    {
        // Create an instant camera object with the first found camera device.
        LEFT camera( CTlFactory::GetInstance().CreateFirstDevice());

        // Print the model name of the camera.
        cout << "Using device " << camera.GetDeviceInfo().GetModelName() << endl;
        
        // Open the camera for accessing the parameters.
        camera.Open();

        // Get parameter values
        cout << "camera.AcquisitionBurstFrameCount = " << camera.AcquisitionBurstFrameCount.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionFrameRate = " << camera.AcquisitionFrameRate.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionFrameRateEnable = " << camera.AcquisitionFrameRateEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionMode = " << camera.AcquisitionMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStart = " << camera.AcquisitionStart.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStatus = " << camera.AcquisitionStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStatusSelector = " << camera.AcquisitionStatusSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStop = " << camera.AcquisitionStop.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoExposureTimeLowerLimit = " << camera.AutoExposureTimeLowerLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoExposureTimeUpperLimit = " << camera.AutoExposureTimeUpperLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionProfile = " << camera.AutoFunctionProfile.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROIHeight = " << camera.AutoFunctionROIHeight.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROIOffsetX = " << camera.AutoFunctionROIOffsetX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROIOffsetY = " << camera.AutoFunctionROIOffsetY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROISelector = " << camera.AutoFunctionROISelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROIUseBrightness = " << camera.AutoFunctionROIUseBrightness.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROIUseWhiteBalance = " << camera.AutoFunctionROIUseWhiteBalance.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionROIWidth = " << camera.AutoFunctionROIWidth.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoGainLowerLimit = " << camera.AutoGainLowerLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoGainUpperLimit = " << camera.AutoGainUpperLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoTargetBrightness = " << camera.AutoTargetBrightness.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceRatio = " << camera.BalanceRatio.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceRatioSelector = " << camera.BalanceRatioSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceWhiteAuto = " << camera.BalanceWhiteAuto.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BinningHorizontal = " << camera.BinningHorizontal.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BinningVertical = " << camera.BinningVertical.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BlackLevel = " << camera.BlackLevel.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BlackLevelSelector = " << camera.BlackLevelSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BslUSBSpeedMode = " << camera.BslUSBSpeedMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CenterX = " << camera.CenterX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CenterY = " << camera.CenterY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkCounterSelector = " << camera.ChunkCounterSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkCounterValue = " << camera.ChunkCounterValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkEnable = " << camera.ChunkEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkExposureTime = " << camera.ChunkExposureTime.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkGain = " << camera.ChunkGain.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkGainSelector = " << camera.ChunkGainSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkLineStatusAll = " << camera.ChunkLineStatusAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkModeActive = " << camera.ChunkModeActive.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkPayloadCRC16 = " << camera.ChunkPayloadCRC16.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkSelector = " << camera.ChunkSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkTimestamp = " << camera.ChunkTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentHue = " << camera.ColorAdjustmentHue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentSaturation = " << camera.ColorAdjustmentSaturation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentSelector = " << camera.ColorAdjustmentSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorSpace = " << camera.ColorSpace.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationSelector = " << camera.ColorTransformationSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationValue = " << camera.ColorTransformationValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationValueSelector = " << camera.ColorTransformationValueSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterDuration = " << camera.CounterDuration.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterEventSource = " << camera.CounterEventSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterReset = " << camera.CounterReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterResetActivation = " << camera.CounterResetActivation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterResetSource = " << camera.CounterResetSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterSelector = " << camera.CounterSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DecimationHorizontal = " << camera.DecimationHorizontal.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DecimationVertical = " << camera.DecimationVertical.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceFirmwareVersion = " << camera.DeviceFirmwareVersion.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceLinkCurrentThroughput = " << camera.DeviceLinkCurrentThroughput.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceLinkSelector = " << camera.DeviceLinkSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceLinkSpeed = " << camera.DeviceLinkSpeed.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceLinkThroughputLimit = " << camera.DeviceLinkThroughputLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceLinkThroughputLimitMode = " << camera.DeviceLinkThroughputLimitMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceManufacturerInfo = " << camera.DeviceManufacturerInfo.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceModelName = " << camera.DeviceModelName.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceReset = " << camera.DeviceReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceSFNCVersionMajor = " << camera.DeviceSFNCVersionMajor.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceSFNCVersionMinor = " << camera.DeviceSFNCVersionMinor.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceSFNCVersionSubMinor = " << camera.DeviceSFNCVersionSubMinor.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceScanType = " << camera.DeviceScanType.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceSerialNumber = " << camera.DeviceSerialNumber.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceTemperature = " << camera.DeviceTemperature.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceTemperatureSelector = " << camera.DeviceTemperatureSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceUserID = " << camera.DeviceUserID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceVendorName = " << camera.DeviceVendorName.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceVersion = " << camera.DeviceVersion.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventExposureEnd = " << camera.EventExposureEnd.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventExposureEndFrameID = " << camera.EventExposureEndFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventExposureEndTimestamp = " << camera.EventExposureEndTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameBurstStart = " << camera.EventFrameBurstStart.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameBurstStartFrameID = " << camera.EventFrameBurstStartFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameBurstStartOvertrigger = " << camera.EventFrameBurstStartOvertrigger.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameBurstStartOvertriggerFrameID = " << camera.EventFrameBurstStartOvertriggerFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameBurstStartOvertriggerTimestamp = " << camera.EventFrameBurstStartOvertriggerTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameBurstStartTimestamp = " << camera.EventFrameBurstStartTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameStart = " << camera.EventFrameStart.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameStartFrameID = " << camera.EventFrameStartFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameStartOvertrigger = " << camera.EventFrameStartOvertrigger.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameStartOvertriggerFrameID = " << camera.EventFrameStartOvertriggerFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameStartOvertriggerTimestamp = " << camera.EventFrameStartOvertriggerTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventFrameStartTimestamp = " << camera.EventFrameStartTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventNotification = " << camera.EventNotification.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventSelector = " << camera.EventSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExpertFeatureAccessKey = " << camera.ExpertFeatureAccessKey.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExpertFeatureAccessSelector = " << camera.ExpertFeatureAccessSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExpertFeatureEnable = " << camera.ExpertFeatureEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureAuto = " << camera.ExposureAuto.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureMode = " << camera.ExposureMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureOverlapTimeMax = " << camera.ExposureOverlapTimeMax.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureOverlapTimeMode = " << camera.ExposureOverlapTimeMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureTime = " << camera.ExposureTime.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileAccessLength = " << camera.FileAccessLength.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileAccessOffset = " << camera.FileAccessOffset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOpenMode = " << camera.FileOpenMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationExecute = " << camera.FileOperationExecute.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationResult = " << camera.FileOperationResult.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationSelector = " << camera.FileOperationSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationStatus = " << camera.FileOperationStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileSelector = " << camera.FileSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileSize = " << camera.FileSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Gain = " << camera.Gain.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GainAuto = " << camera.GainAuto.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GainSelector = " << camera.GainSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Gamma = " << camera.Gamma.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Height = " << camera.Height.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.HeightMax = " << camera.HeightMax.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTEnable = " << camera.LUTEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTIndex = " << camera.LUTIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTSelector = " << camera.LUTSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTValue = " << camera.LUTValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LightSourcePreset = " << camera.LightSourcePreset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineDebouncerTime = " << camera.LineDebouncerTime.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineFormat = " << camera.LineFormat.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineInverter = " << camera.LineInverter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineLogic = " << camera.LineLogic.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineMinimumOutputPulseWidth = " << camera.LineMinimumOutputPulseWidth.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineMode = " << camera.LineMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineOverloadStatus = " << camera.LineOverloadStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineSelector = " << camera.LineSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineSource = " << camera.LineSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineStatus = " << camera.LineStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineStatusAll = " << camera.LineStatusAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.OffsetX = " << camera.OffsetX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.OffsetY = " << camera.OffsetY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PayloadSize = " << camera.PayloadSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelColorFilter = " << camera.PixelColorFilter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelDynamicRangeMax = " << camera.PixelDynamicRangeMax.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelDynamicRangeMin = " << camera.PixelDynamicRangeMin.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelFormat = " << camera.PixelFormat.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelSize = " << camera.PixelSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.RemoveParameterLimit = " << camera.RemoveParameterLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.RemoveParameterLimitSelector = " << camera.RemoveParameterLimitSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ResultingFrameRate = " << camera.ResultingFrameRate.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ReverseX = " << camera.ReverseX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ReverseY = " << camera.ReverseY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SIPayloadFinalTransfer1Size = " << camera.SIPayloadFinalTransfer1Size.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SIPayloadFinalTransfer2Size = " << camera.SIPayloadFinalTransfer2Size.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SIPayloadTransferCount = " << camera.SIPayloadTransferCount.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SIPayloadTransferSize = " << camera.SIPayloadTransferSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SensorHeight = " << camera.SensorHeight.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SensorReadoutMode = " << camera.SensorReadoutMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SensorReadoutTime = " << camera.SensorReadoutTime.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SensorWidth = " << camera.SensorWidth.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ShutterMode = " << camera.ShutterMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SoftwareSignalPulse = " << camera.SoftwareSignalPulse.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SoftwareSignalSelector = " << camera.SoftwareSignalSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TemperatureState = " << camera.TemperatureState.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TestImageSelector = " << camera.TestImageSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDelay = " << camera.TimerDelay.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDuration = " << camera.TimerDuration.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerSelector = " << camera.TimerSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerTriggerSource = " << camera.TimerTriggerSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimestampLatch = " << camera.TimestampLatch.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimestampLatchValue = " << camera.TimestampLatchValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerActivation = " << camera.TriggerActivation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerDelay = " << camera.TriggerDelay.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerMode = " << camera.TriggerMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerSelector = " << camera.TriggerSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerSoftware = " << camera.TriggerSoftware.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerSource = " << camera.TriggerSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserDefinedValue = " << camera.UserDefinedValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserDefinedValueSelector = " << camera.UserDefinedValueSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserOutputSelector = " << camera.UserOutputSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserOutputValue = " << camera.UserOutputValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserOutputValueAll = " << camera.UserOutputValueAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetDefault = " << camera.UserSetDefault.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetLoad = " << camera.UserSetLoad.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetSave = " << camera.UserSetSave.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetSelector = " << camera.UserSetSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Width = " << camera.Width.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.WidthMax = " << camera.WidthMax.ToStringOrDefault("<not readable>") << std::endl;
        
        // Set parameter values
        camera.Height.TrySetToMaximum();
        camera.OffsetX.TrySetToMinimum();
        camera.OffsetY.TrySetToMinimum();
        camera.Width.TrySetToMaximum();
        
        // Start the grabbing of c_countOfImagesToGrab images.
        // The camera device is parameterized with a default configuration which
        // sets up free-running continuous acquisition.
        camera.StartGrabbing( c_countOfImagesToGrab);

        // This smart pointer will receive the grab result data.
        CGrabResultPtr ptrGrabResult;

        // Camera.StopGrabbing() is called automatically by the RetrieveResult() method
        // when c_countOfImagesToGrab images have been retrieved.
        while ( camera.IsGrabbing())
        {
            // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
            camera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);

            // Image grabbed successfully?
            if (ptrGrabResult->GrabSucceeded())
            {
                // Access the image data.
                cout << "SizeX: " << ptrGrabResult->GetWidth() << endl;
                cout << "SizeY: " << ptrGrabResult->GetHeight() << endl;
                const uint8_t *pImageBuffer = (uint8_t *) ptrGrabResult->GetBuffer();
                cout << "Gray value of first pixel: " << (uint32_t) pImageBuffer[0] << endl << endl;

#ifdef PYLON_WIN_BUILD
                // Display the grabbed image.
                Pylon::DisplayImage(1, ptrGrabResult);
#endif
            }
            else
            {
                cout << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
            }
        }
        
        // Close the camera.
        camera.Close();
    }
    catch (const GenericException &e)
    {
        // Error handling.
        cerr << "An exception occurred." << endl
        << e.GetDescription() << endl;
        exitCode = 1;
    }

    // Comment the following two lines to disable waiting on exit
    cerr << endl << "Press Enter to exit." << endl;
    while( cin.get() != '\n');

    // Releases all pylon resources. 
    PylonTerminate(); 

    return exitCode;
}