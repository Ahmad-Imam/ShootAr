#pragma once
#if UNITY
#   include "Modules/XR/ProviderInterface/UnityXRTypes.h"
#   include "Modules/XR/ProviderInterface/IUnitySubsystem.h"
#else
#   include "UnityXRTypes.h"
#   include "IUnitySubsystem.h"
#   include <stdint.h>
#   include <stdbool.h>
#endif

#if !defined(UINT32_MAX)
#  define UINT32_MAX  4294967295UL
#endif

#if !defined(UINT64_MAX)
#  define UINT64_MAX  18446744073709551615ULL
#endif

typedef void* UnityXRInputDeviceDefinitionHandle;
typedef void* UnityXRInputDeviceStateHandle;

/// An id used to identify individual devices associated with a specific Input Subsystem.  Must be unique for unique devices.
typedef uint32_t UnityXRInternalInputDeviceId;
typedef uint32_t UnityXRInputFeatureIndex;

/// Used to represent an invalid feature index
const uint32_t kUnityInvalidXRInputFeatureIndex = UINT32_MAX;
const uint32_t kUnityInvalidXRInternalInputDeviceId = UINT32_MAX;
const int32_t kUnityMaxCustomInputFeatureSize = 128;

/// Currently supported Input feature types.  Each type represents a unique type of data coming from a device
typedef enum UnityXRInputFeatureType
{
	kUnityXRInputFeatureTypeCustom = 0,
	kUnityXRInputFeatureTypeBinary, /// Boolean
	kUnityXRInputFeatureTypeDiscreteStates, /// Integer
	kUnityXRInputFeatureTypeAxis1D, /// Float
	kUnityXRInputFeatureTypeAxis2D, /// XRVector2
	kUnityXRInputFeatureTypeAxis3D, /// XRVector3
	kUnityXRInputFeatureTypeRotation, /// XRQuaternion

	kUnityXRInputFeatureTypeInvalid = UINT32_MAX,
} UnityXRInputFeatureType;

/// Device Roles are supplied for connected devices to help Unity identify the type of device and how it should be used by developers
typedef enum UnityXRInputDeviceRole
{
	kUnityXRInputDeviceRoleUnknown = 0, /// Default, not mapped to anything
	kUnityXRInputDeviceRoleGeneric, /// Camera's and HMDs
	kUnityXRInputDeviceRoleLeftHanded,
	kUnityXRInputDeviceRoleRightHanded,
	kUnityXRInputDeviceRoleGameController,
	kUnityXRInputDeviceRoleTrackingReference,
	kUnityXRInputDeviceRoleHardwareTracker,
	kUnityXRInputDeviceRoleLegacyController,

	kUnityXRInputDeviceRoleCount,
	kUnityXRInputDeviceRoleInvalid = UINT32_MAX
} UnityXRInputDeviceRole;

typedef const char* UnityXRInputFeatureUsage;

// Pose & Tracking
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageIsTracked = "IsTracked";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageTrackingState = "TrackingState";

const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDevicePosition = "DevicePosition";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDeviceRotation = "DeviceRotation";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDeviceVelocity = "DeviceVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDeviceAngularVelocity = "DeviceAngularVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDeviceAcceleration = "DeviceAcceleration";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDeviceAngularAcceleration = "DeviceAngularAcceleration";

const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLeftEyePosition = "LeftEyePosition";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLeftEyeRotation = "LeftEyeRotation";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLeftEyeVelocity = "LeftEyeVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLeftEyeAngularVelocity = "LeftEyeAngularVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLeftEyeAcceleration = "LeftEyeAcceleration";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLeftEyeAngularAcceleration = "LeftEyeAngularAcceleration";

const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRightEyePosition = "RightEyePosition";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRightEyeRotation = "RightEyeRotation";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRightEyeVelocity = "RightEyeVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRightEyeAngularVelocity = "RightEyeAngularVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRightEyeAcceleration = "RightEyeAcceleration";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRightEyeAngularAcceleration = "RightEyeAngularAcceleration";

const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCenterEyePosition = "CenterEyePosition";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCenterEyeRotation = "CenterEyeRotation";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCenterEyeVelocity = "CenterEyeVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCenterEyeAngularVelocity = "CenterEyeAngularVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCenterEyeAcceleration = "CenterEyeAcceleration";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCenterEyeAngularAcceleration = "CenterEyeAngularAcceleration";

const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageColorCameraPosition = "CameraPosition";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageColorCameraRotation = "CameraRotation";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageColorCameraVelocity = "CameraVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageColorCameraAngularVelocity = "CameraAngularVelocity";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageColorCameraAcceleration = "CameraAcceleration";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageColorCameraAngularAcceleration = "CameraAngularAcceleration";

// Device Information
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageBatteryLevel = "BatteryLevel";

// Legacy Axes
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsagePrimary2DAxis = "Primary2DAxis";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageDPad = "DPad";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageTrigger = "Trigger";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageGrip = "Grip";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageIndexTouch = "IndexTouch";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageThumbTouch = "ThumbTouch";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageSecondary2DAxis = "Secondary2DAxis";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageIndexFinger = "IndexFinger";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageMiddleFinger = "MiddleFinger";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageRingFinger = "RingFinger";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsagePinkyFinger = "PinkyFinger";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageCombinedTrigger = "CombinedTrigger";

// Legacy Buttons
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsagePrimaryButton = "PrimaryButton";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsagePrimaryTouch = "PrimaryTouch";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageSecondaryButton = "SecondaryButton";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageSecondaryTouch = "SecondaryTouch";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageGripButton = "GripButton";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageTriggerButton = "TriggerButton";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageMenuButton = "MenuButton";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsagePrimary2DAxisClick = "2DAxisClick";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsagePrimary2DAxisTouch = "2DAxisTouch";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageThumbrest = "Thumbrest";

// Direct Legacy Buttons
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton0 = "ButtonId0";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton1 = "ButtonId1";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton2 = "ButtonId2";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton3 = "ButtonId3";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton4 = "ButtonId4";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton5 = "ButtonId5";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton6 = "ButtonId6";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton7 = "ButtonId7";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton8 = "ButtonId8";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton9 = "ButtonId9";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton10 = "ButtonId10";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton11 = "ButtonId11";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton12 = "ButtonId12";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton13 = "ButtonId13";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton14 = "ButtonId14";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton15 = "ButtonId15";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton16 = "ButtonId16";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton17 = "ButtonId17";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton18 = "ButtonId18";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyButton19 = "ButtonId19";

const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis0 = "AxisId0";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis1 = "AxisId1";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis2 = "AxisId2";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis3 = "AxisId3";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis4 = "AxisId4";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis5 = "AxisId5";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis6 = "AxisId6";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis7 = "AxisId7";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis8 = "AxisId8";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis9 = "AxisId9";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis10 = "AxisId10";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis11 = "AxisId11";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis12 = "AxisId12";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis13 = "AxisId13";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis14 = "AxisId14";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis15 = "AxisId15";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis16 = "AxisId16";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis17 = "AxisId17";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis18 = "AxisId18";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis19 = "AxisId19";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis20 = "AxisId20";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis21 = "AxisId21";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis22 = "AxisId22";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis23 = "AxisId23";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis24 = "AxisId24";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis25 = "AxisId25";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis26 = "AxisId26";
const UnityXRInputFeatureUsage kUnityXRInputFeatureUsageLegacyAxis27 = "AxisId27";

typedef enum UnityXRInputTrackingStateFlags
{
	kUnityXRInputTrackingStateNone = 0,
	kUnityXRInputTrackingStatePosition = 1 << 0,
	kUnityXRInputTrackingStateRotation = 1 << 1,
	kUnityXRInputTrackingStateVelocity = 1 << 2,
	kUnityXRInputTrackingStateAngularVelocity = 1 << 3,
	kUnityXRInputTrackingStateAcceleration = 1 << 4,
	kUnityXRInputTrackingStateAngularAcceleration = 1 << 5,

	kUnityXRInputTrackingStateAll = (1 << 6) - 1 // Keep this as the last entry, if you add an entry, bump this shift up by 1 as well
} UnityXRInputTrackingStateFlags;

typedef enum UnityXRInputUpdateType
{
	kUnityXRInputUpdateTypeDynamic = 0,
	kUnityXRInputUpdateTypeBeforeRender,
} UnityXRInputUpdateType;

typedef enum UnityXRInputEventType
{
	kUnityXRInputEventTypeRecenter = 'XRC0',
	kUnityXRInputEventTypeSimpleRumble = 'XRR0'
} UnityXRInputEventType;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Plugin Interface
// Unity->Plugin messaging
typedef struct UnityXRInputProvider
{
	/// Pointer which will be passed to every callback as the userData parameter.
	void* userData;

	/// Called at the beginning of each frame.
	void(UNITY_INTERFACE_API * OnNewInputFrame)(UnitySubsystemHandle handle, void* userData);

	/// Fill in your connected device information here when requested.  Used to create customized device states.
	///
	/// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
	/// @param[in] userData User specified data.
	/// @param[in] deviceId The Id of the device that needs a definition filled
	/// @param[in] definitionHandle The definition to be filled by the plugin
	void(UNITY_INTERFACE_API * FillDeviceDefinition)(UnitySubsystemHandle handle, void* userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceDefinitionHandle definitionHandle);

	/// Called by Unity when it needs a current device snapshot
	///
	/// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
	/// @param[in] userData User specified data.
	/// @param[in] deviceId The Id of the device whose state is requested.
	/// @param[in] updateType The type of update being polled for.   For BeforeRender we are predominantly interested in pose data, in the time expected for rendering
	/// @param[in] stateHandle The customized DeviceState to fill in.  The indices within this state match the order those input features were added from FillDeviceDefinition
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * UpdateDeviceState)(UnitySubsystemHandle handle, void* userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputUpdateType updateType, UnityXRInputDeviceStateHandle stateHandle);

	/// Simple, generic method callback to inform the plugin or individual devices of events occurring within unity
	///
	/// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
	/// @param[in] userData User specified data.
	/// @param[in] eventType the type of event being sent
	/// @param[in] deviceId the Id of the device that should handle the event.  Will be kUnityInvalidXRInputFeatureIndex if event is for all devices.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * HandleEvent)(UnitySubsystemHandle handle, void* userData, UnityXRInputEventType eventType, UnityXRInternalInputDeviceId deviceId, void* buffer, unsigned int size);
} UnityXRInputProvider;

UNITY_DECLARE_INTERFACE(IUnityXRInputInterface)
{
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * RegisterLifecycleProvider)(const char* pluginName, const char* id, const UnityLifecycleProvider * provider);

	UnitySubsystemErrorCode(UNITY_INTERFACE_API * RegisterInputProvider)(UnitySubsystemHandle handle, const UnityXRInputProvider * provider);

	void(UNITY_INTERFACE_API * InputSubsystem_DeviceConnected)(UnitySubsystemHandle handle, UnityXRInternalInputDeviceId deviceId);

	void(UNITY_INTERFACE_API * InputSubsystem_DeviceDisconnected)(UnitySubsystemHandle handle, UnityXRInternalInputDeviceId deviceId);

	/// TEMPORARY: Returns native pointer to some sdk specific resources of the active legacy VR SDK.  The format of the data changes depending on the active legacy SDK.
	/// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
	/// @return kUnitySubsystemErrorCodeSuccess if successfully initialized, kUnitySubsystemErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * InputSubsystem_GetPlatformData)(UnitySubsystemHandle handle, void** platformData);

	/////////////////////////////////////////////////////
	/// Device Definition APIs
	/// A Definition of what your device is capable of doing.  Immutable information are provided here when Unity called IUnityXRInputProvider::FillDeviceDefinition with a specific Device Id.
	/// It will only be called once for each device connection.  For APIs that use and update the device definition see IUnityXRInputSubsystem functions prefixed with DeviceDefinition

	/// Sets the name of the device.  Used to inform users of what's connected. deviceName must not be null and must be shorter than kUnityXRStringSize.
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] deviceName The name of the new device.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceDefinition_SetName)(UnityXRInputDeviceDefinitionHandle handle, const char* deviceName);

	/// Identifies the Role of this device.  Roles identify how the device is expected to be used (e.g. is it a tracker, a hand controller, an HMD, or a Gamepad)
	/// For available roles, see UnityXRInputDeviceRole
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] deviceRole The role you'd like to assign the device.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceDefinition_SetRole)(UnityXRInputDeviceDefinitionHandle handle, UnityXRInputDeviceRole role);

	/// Identifies the Manufacturer of this device.  Reported upwards to the Developer to make it easier to identify device families.
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] manufacturer The manufacturer of the device.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceDefinition_SetManufacturer)(UnityXRInputDeviceDefinitionHandle handle, const char* manufacturer);

	/// Identifies the Serial Number of this device.  Reported upwards to the Developer to make it easier to identify very specific devices.
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] serialNumber The serial number of the device
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceDefinition_SetSerialNumber)(UnityXRInputDeviceDefinitionHandle handle, const char* serialNumber);

	/// Reports an input feature of the device, supplying the name specific to this device and a type.  Use the returned index when setting that feature's value within the associated UnityXRInputDeviceState. Name must not be null and must be shorter than kUnityXRStringSize.
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] name The name of this input feature
	/// @param[in] type The type of feature this is, which dictates the space and properties of the input feature
	/// @returns The assigned index, to be used with UnityXRInputDeviceState when setting the value of the added input feature, or kUnityInvalidXRInputFeatureIndex on failure
	UnityXRInputFeatureIndex(UNITY_INTERFACE_API * DeviceDefinition_AddFeature)(UnityXRInputDeviceDefinitionHandle handle, const char* name, UnityXRInputFeatureType type);

	/// Reports an input feature of the device, supplying a name specific to this device, and a size.  This is used for custom data being passed to a specific template.
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] name The name of this input feature
	/// @param[in] size The size of this feature in bytes
	/// @return The assigned index, to be used with UnityXRInputDeviceState when setting the value of the added input feature, or kUnityInvalidXRInputFeatureIndex on failure
	UnityXRInputFeatureIndex(UNITY_INTERFACE_API * DeviceDefinition_AddCustomFeature)(UnityXRInputDeviceDefinitionHandle handle, const char* name, unsigned int size);

	/// Reports an input feature of the device, supplying the name specific to this device, a suggested usage, and a type.  Use the returned index when setting that feature's value within the associated UnityXRInputDeviceState. Name must not be null and must be shorter than kUnityXRStringSize.
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureType The type of feature this is, which dictates the space and properties of the input feature
	/// @param[in] usageHint These are used by our various Input Systems to provide context for your feature.  It let's us know and understand how it should be used.
	/// @return The assigned index, to be used with UnityXRInputDeviceState when setting the value of the added input feature, or kUnityInvalidXRInputFeatureIndex on failure
	UnityXRInputFeatureIndex(UNITY_INTERFACE_API * DeviceDefinition_AddFeatureWithUsage)(UnityXRInputDeviceDefinitionHandle handle, const char* name, UnityXRInputFeatureType type, UnityXRInputFeatureUsage usageHint);

	/// Adds a Usage hint to a specific feature index on an InputDeviceDefinition.  Usage hints are used to provide context for our InputSystems in order to understand how this feature should be used.
	///
	/// @param[in] handle A reference to the device definition you'd like change the usage on.
	/// @param[in] featureIndex The Index of the feature you want to add the UsageHint to.  This is the value returned when you call DeviceDefinition_AddFeature initially
	/// @param[in] usageHint These are used by our various Input Systems to provide context for your feature.  It let's us know and understand how it should be used.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure if index is not found.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceDefinition_AddUsageAtIndex)(UnityXRInputDeviceDefinitionHandle handle, UnityXRInputFeatureIndex featureIndex, UnityXRInputFeatureUsage usageHint);

	//////////////////////////////////////////////////////////
	/// Device State APIs
	/// A Structure setup to hold your individual device's state.  This is customized based on what was filled in for that devices' definition.
	/// The Feature Indices are in the same order that AddFeature was called when filling in your device's definition.

	/// Sets the custom-sized buffer at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeCustom
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureBuffer A pointer to the buffer containing the data you want to set
	/// @param[in] featureSize The size of the feature being set
	/// @return kXRErrorCodeSuccess if successfully set, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetCustomValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, const void* featureBuffer, unsigned int featureSize);

	/// Sets the binary value at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeBinary
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureValue The binary value you want to set the feature to.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetBinaryValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, bool featureValue);

	/// Sets the discrete state value at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeDiscreteStates
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureValue The discrete state value you want to set the feature to.
	/// @return kXRErrorCodeSuccess if successfully set, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetDiscreteStateValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, unsigned int featureValue);

	/// Sets the axis value at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeAxis1D
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureValue The axis value you want to set the feature to.
	/// @return kXRErrIUnityXRInput.horCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetAxis1DValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, float featureValue);

	/// Sets the Axis 2D value at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeAxis2D
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureValue The 2D axis value value you want to set the feature to.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetAxis2DValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, UnityXRVector2 featureValue);

	/// Sets a 3D axis value at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeAxis3D
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureValue The 3D axis value you want to set the feature to.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetAxis3DValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, UnityXRVector3 featureValue);

	/// Sets a rotation value at a specific feature index.  This is used for features of type UnityXRInputFeatureTypeRotation
	///
	/// @param[in] handle A reference to the device state you'd like to change the feature value on.
	/// @param[in] featureIndex The index in device state that the feature is located.
	/// @param[in] featureValue The quaternion value you want to set the feature to.
	/// @return kXRErrorCodeSuccess if successfully started, kXRErrorCodeFailure on error conditions.
	UnitySubsystemErrorCode(UNITY_INTERFACE_API * DeviceState_SetRotationValue)(UnityXRInputDeviceStateHandle handle, UnityXRInputFeatureIndex featureIndex, UnityXRVector4 featureValue);
};

UNITY_REGISTER_INTERFACE_GUID(0x4F420C21716B48C0ULL, 0xA99D839EBBF644ADULL, IUnityXRInputInterface);