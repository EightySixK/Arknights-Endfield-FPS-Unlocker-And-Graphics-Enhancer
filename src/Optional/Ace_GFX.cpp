#define _CRT_SECURE_NO_WARNINGS
#include <cstdint>
#include <stdio.h>
#include <string>
#include <windows.h>

extern "C" __declspec(dllexport) void Ace_GFX_Dummy() {}

#define INIT_DELAY_MS 10000
#define APPLY_INTERVAL_MS 5000

#define RENDER_PARAMS_GTAO_PTR 0x248
#define RENDER_PARAMS_SETTING_PARAMS_PTR 0x20
#define GTAO_ENABLE_AO 0x0
#define GTAO_SCREEN_WIDTH 0x4
#define GTAO_SCREEN_HEIGHT 0x8
#define GTAO_QUALITY_LEVEL 0xC
#define SETTING_ENABLE_SCREEN_SPACE_SHADOW_MASK 0x9C
#define SETTING_CSM_SHADOW_MAP_TILE_RES 0xA0
#define SETTING_CHARACTER_SHADOW_MAP_RES 0x100
#define SETTING_PUNCTUAL_LIGHT_TILE_MAX_SIZE 0x118
#define SETTING_ASM_SHADOW_MAP_TILE_RES 0x12C
#define SETTING_SSR_ENABLE 0x184
#define SETTING_SSR_RAY_MARCHING_SAMPLE_COUNT 0x188
#define SETTING_SSR_V2 0x18C
#define SETTING_SSR_V2_UPSAMPLE 0x18D
#define SETTING_RENDERING_SCALE 0x158
#define RENDER_PARAMS_SCENE_RT_SIZE 0x98
#define RENDER_PARAMS_FINAL_RT_SIZE 0xB0
#define BEFORE_CULLING_SHADOW_CONFIG_PTR 0x38
#define SHADOW_CONFIG_CSM_DEPTH_BIAS 0x00
#define SHADOW_CONFIG_CSM_NORMAL_BIAS 0x04
#define SHADOW_CONFIG_CSM_INTENSITY 0x08
#define SHADOW_CONFIG_CSM_SOFTNESS 0x18
#define SHADOW_CONFIG_CONTACT_INTENSITY 0x24
#define SHADOW_CONFIG_CONTACT_SURFACE_THICKNESS 0x28
#define SHADOW_CONFIG_CONTACT_BILINEAR 0x2C
#define SHADOW_CONFIG_CONTACT_CONTRACT 0x30

typedef void *Il2CppDomain;
typedef void *Il2CppAssembly;
typedef void *Il2CppImage;
typedef void *Il2CppClass;
typedef void *Il2CppMethodInfo;
typedef void *Il2CppObject;
struct MethodInfo {
  void *methodPointer;
};

typedef Il2CppDomain (*fn_il2cpp_domain_get)();
typedef void *(*fn_il2cpp_thread_attach)(Il2CppDomain);
typedef void **(*fn_il2cpp_domain_get_assemblies)(Il2CppDomain, size_t *);
typedef Il2CppImage (*fn_il2cpp_assembly_get_image)(Il2CppAssembly);
typedef const char *(*fn_il2cpp_image_get_name)(Il2CppImage);
typedef Il2CppClass (*fn_il2cpp_class_from_name)(Il2CppImage, const char *,
                                                 const char *);
typedef Il2CppMethodInfo (*fn_il2cpp_class_get_method_from_name)(Il2CppClass,
                                                                 const char *,
                                                                 int);
typedef void *(*fn_il2cpp_class_get_field_from_name)(Il2CppClass,
                                                     const char *);
typedef void (*fn_il2cpp_field_static_get_value)(void *, void *);
typedef void (*fn_il2cpp_field_static_set_value)(void *, void *);
typedef void (*fn_il2cpp_field_get_value)(void *, void *, void *);
typedef void (*fn_il2cpp_field_set_value)(void *, void *, void *);
typedef size_t (*fn_il2cpp_field_get_offset)(void *);
typedef void *(*fn_il2cpp_class_get_fields)(Il2CppClass, void **);
typedef const char *(*fn_il2cpp_field_get_name)(void *);
typedef int (*fn_il2cpp_field_get_flags)(void *);
typedef Il2CppClass (*fn_il2cpp_class_get_parent)(Il2CppClass);
typedef Il2CppClass (*fn_il2cpp_object_get_class)(void *);
typedef void *(*fn_il2cpp_class_get_type)(Il2CppClass);
typedef void *(*fn_il2cpp_type_get_object)(void *);
typedef void *(*fn_il2cpp_runtime_invoke)(Il2CppMethodInfo, void *, void **, void **);

static fn_il2cpp_domain_get il2cpp_domain_get = nullptr;
static fn_il2cpp_thread_attach il2cpp_thread_attach = nullptr;
static fn_il2cpp_domain_get_assemblies il2cpp_domain_get_assemblies = nullptr;
static fn_il2cpp_assembly_get_image il2cpp_assembly_get_image = nullptr;
static fn_il2cpp_image_get_name il2cpp_image_get_name = nullptr;
static fn_il2cpp_class_from_name il2cpp_class_from_name = nullptr;
static fn_il2cpp_class_get_method_from_name il2cpp_class_get_method_from_name =
    nullptr;
static fn_il2cpp_class_get_field_from_name il2cpp_class_get_field_from_name =
    nullptr;
static fn_il2cpp_field_static_get_value il2cpp_field_static_get_value = nullptr;
static fn_il2cpp_field_static_set_value il2cpp_field_static_set_value = nullptr;
static fn_il2cpp_field_get_value il2cpp_field_get_value = nullptr;
static fn_il2cpp_field_set_value il2cpp_field_set_value = nullptr;
static fn_il2cpp_field_get_offset il2cpp_field_get_offset = nullptr;
static fn_il2cpp_class_get_fields il2cpp_class_get_fields = nullptr;
static fn_il2cpp_field_get_name il2cpp_field_get_name = nullptr;
static fn_il2cpp_field_get_flags il2cpp_field_get_flags = nullptr;
static fn_il2cpp_class_get_parent il2cpp_class_get_parent = nullptr;
static fn_il2cpp_object_get_class il2cpp_object_get_class = nullptr;
static fn_il2cpp_class_get_type il2cpp_class_get_type = nullptr;
static fn_il2cpp_type_get_object il2cpp_type_get_object = nullptr;
static fn_il2cpp_runtime_invoke il2cpp_runtime_invoke = nullptr;

#define FIELD_ATTRIBUTE_STATIC 0x0010

Il2CppImage FindImage(const char *name);
void *GetMethodPointer(Il2CppMethodInfo mi);

static HMODULE g_hGameAssembly = nullptr;
static bool g_initialized = false;
static int g_screenWidth = 0, g_screenHeight = 0;
static bool g_gtaoPatched = false;
static bool g_shadowPatched = false;
static int g_patchCount = 0;
static float g_gtaoScale = -1.0f;
static float g_csmShadowSoftness = -1.0f;
static int g_csmShadowRes = -1;
static int g_charShadowRes = -1;
static int g_punctualShadowRes = -1;
static int g_asmShadowRes = -1;
static int g_csmShadowSampleMode = -1;
static int g_charShadowSampleMode = -1;
static float g_csmDepthBias = -1.0f;
static float g_csmNormalBias = -1.0f;
static float g_csmIntensity = -1.0f;
static float g_contactShadowIntensity = -1.0f;
static float g_contactShadowThickness = -1.0f;
static float g_contactShadowBilinear = -1.0f;
static float g_contactShadowContract = -1.0f;
static int g_screenSpaceShadowMask = -1;
static int g_aaMode = 1;
static int g_smaaQuality = -1;
static int g_ssrQuality = -1;
static int g_ssrEnable = -1;
static int g_ssrSampleCount = -1;
static int g_ssrUpsampling = -1;
static float g_renderScale = -1.0f;
static int g_anisoLevel = -1;
static float g_sharpening = -1.0f;

static char g_iniPath[MAX_PATH] = {0};

typedef void *(*ConvertSettingParamsToCpp_t)(void *settingParameters);
static ConvertSettingParamsToCpp_t g_TrampolineFunc = nullptr;
static void *g_pTrampoline = nullptr;
static void *g_ConvertMethodPtr = nullptr;
static uint8_t g_OriginalBytes[16] = {0};
static bool g_HookInstalled = false;

bool IsMainGameProcess() {
  char exePath[MAX_PATH];
  GetModuleFileNameA(NULL, exePath, MAX_PATH);
  return strstr(exePath, "EndlessField.exe") != nullptr ||
         strstr(exePath, "Endfield.exe") != nullptr;
}

void CreateDebugConsole() {}
void Log(const char *fmt, ...) {}
void LogColored(WORD color, const char *fmt, ...) {}
#define LOG_SUCCESS(fmt, ...) do {} while(0)
#define LOG_WARNING(fmt, ...) do {} while(0)
#define LOG_ERROR(fmt, ...) do {} while(0)
#define LOG_INFO(fmt, ...) do {} while(0)
template <typename T> inline bool SafeRead(uintptr_t addr, T *out) {
  __try {
    if (addr < 0x10000 || addr > 0x00007FFFFFFFFFFF)
      return false;
    *out = *(T *)addr;
    return true;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    return false;
  }
}

template <typename T> inline bool SafeWrite(uintptr_t addr, T val) {
  __try {
    if (addr < 0x10000 || addr > 0x00007FFFFFFFFFFF)
      return false;
    *(T *)addr = val;
    return true;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    return false;
  }
}

void *FindFieldByName(void *klass, const char *fieldName) {
  if (!klass || !fieldName || !il2cpp_class_get_fields || !il2cpp_field_get_name)
    return nullptr;

  std::string targetName(fieldName);
  std::string backingName = "<" + targetName + ">k__BackingField";

  void *currentClass = klass;
  while (currentClass) {
    void *iter = nullptr;
    while (void *field = il2cpp_class_get_fields(currentClass, &iter)) {
      const char *name = il2cpp_field_get_name(field);
      if (!name)
        continue;
      std::string fName(name);
      if (fName == targetName || fName == backingName) {
        return field;
      }
    }
    if (il2cpp_class_get_parent) {
      currentClass = il2cpp_class_get_parent(currentClass);
    } else {
      break;
    }
  }
  return nullptr;
}

void *GetObjectClass(uintptr_t objAddr) {
  if (!il2cpp_object_get_class)
    return nullptr;
  return il2cpp_object_get_class((void *)objAddr);
}

bool SetSettingParameterValue(const char *settingName, int value) {
  if (!il2cpp_class_get_field_from_name || !il2cpp_field_static_get_value ||
      !il2cpp_field_get_offset)
    return false;

  Il2CppImage coreImage = FindImage("UnityEngine.CoreModule");
  if (!coreImage)
    return false;

  Il2CppClass rpmClass = il2cpp_class_from_name(
      coreImage, "UnityEngine.Rendering", "RenderPipelineManager");
  if (!rpmClass)
    return false;

  void *pipelineField = il2cpp_class_get_field_from_name(rpmClass, "s_currentPipeline");
  if (!pipelineField)
    pipelineField = FindFieldByName(rpmClass, "s_currentPipeline");
  if (!pipelineField)
    return false;

  uintptr_t pipelinePtr = 0;
  il2cpp_field_static_get_value(pipelineField, &pipelinePtr);
  if (!pipelinePtr)
    return false;

  void *pipelineClass = GetObjectClass(pipelinePtr);
  if (!pipelineClass) {
    for (int o = 0; o < 0x200; o += 8) {
      uintptr_t p;
      if (SafeRead(pipelinePtr - o, &p) && p > 0x10000) {
        pipelineClass = (void *)p;
        break;
      }
    }
  }

  void *settingsField = FindFieldByName(pipelineClass, "settingParameters");
  if (!settingsField)
    return false;

  size_t settingsOffset = il2cpp_field_get_offset(settingsField);
  uintptr_t settingsPtr = 0;
  if (!SafeRead(pipelinePtr + settingsOffset, &settingsPtr) || !settingsPtr)
    return false;

  void *settingsClass = GetObjectClass(settingsPtr);
  if (!settingsClass) {
    for (int o = 0; o < 0x200; o += 8) {
      uintptr_t p;
      if (SafeRead(settingsPtr - o, &p) && p > 0x10000) {
        settingsClass = (void *)p;
        break;
      }
    }
  }

  void *targetField = FindFieldByName(settingsClass, settingName);
  if (!targetField)
    return false;

  size_t targetOffset = il2cpp_field_get_offset(targetField);
  uintptr_t settingParamPtr = 0;
  if (!SafeRead(settingsPtr + targetOffset, &settingParamPtr) || !settingParamPtr)
    return false;

  void *paramClass = GetObjectClass(settingParamPtr);
  if (!paramClass) {
    for (int o = 0; o < 0x100; o += 8) {
      uintptr_t p;
      if (SafeRead(settingParamPtr - o, &p) && p > 0x10000) {
        paramClass = (void *)p;
        break;
      }
    }
  }

  void *paramValueField = FindFieldByName(paramClass, "paramValue");
  if (!paramValueField)
    return false;

  size_t paramOffset = il2cpp_field_get_offset(paramValueField);
  uintptr_t valueAddr = settingParamPtr + paramOffset;

  int oldValue = 0;
  SafeRead(valueAddr, &oldValue);

  if (!SafeWrite(valueAddr, value))
    return false;

  return true;
}

bool SetShadowManagerValue(const char* fieldName, size_t fieldOffset, int value) {
  if (!il2cpp_class_get_field_from_name || !il2cpp_field_static_get_value)
    return false;

  Il2CppImage coreImage = FindImage("UnityEngine.CoreModule");
  if (!coreImage)
    return false;

  Il2CppClass rpmClass = il2cpp_class_from_name(
      coreImage, "UnityEngine.Rendering", "RenderPipelineManager");
  if (!rpmClass)
    return false;

  void *pipelineField = il2cpp_class_get_field_from_name(rpmClass, "s_currentPipeline");
  if (!pipelineField)
    pipelineField = FindFieldByName(rpmClass, "s_currentPipeline");
  if (!pipelineField)
    return false;

  uintptr_t pipelinePtr = 0;
  il2cpp_field_static_get_value(pipelineField, &pipelinePtr);
  if (!pipelinePtr)
    return false;

  const size_t SHADOW_MANAGER_OFFSET = 0x728;
  uintptr_t shadowManagerPtr = 0;
  if (!SafeRead(pipelinePtr + SHADOW_MANAGER_OFFSET, &shadowManagerPtr) || !shadowManagerPtr)
    return false;

  uintptr_t valueAddr = shadowManagerPtr + fieldOffset;

  int oldValue = 0;
  SafeRead(valueAddr, &oldValue);

  if (!SafeWrite(valueAddr, value))
    return false;

  return true;
}

bool ApplyManagedShadowSettings() {
  bool success = true;

  if (g_csmShadowRes >= 0)
    success &= SetSettingParameterValue("csmShadowMapTileResolution", g_csmShadowRes);
  if (g_charShadowRes >= 0)
    success &= SetSettingParameterValue("characterShadowMapResolution", g_charShadowRes);
  if (g_punctualShadowRes >= 0)
    success &= SetSettingParameterValue("punctualLightTileMaxSize", g_punctualShadowRes);
  if (g_asmShadowRes >= 0)
    success &= SetSettingParameterValue("asmShadowMapTileResolution", g_asmShadowRes);

  if (g_csmShadowSampleMode >= 0)
    success &= SetShadowManagerValue("m_csmShadowSampleMode", 0x198, g_csmShadowSampleMode);

  return success;
}

static float g_ssrResScale = -1.0f;

void ApplySSRQualityPreset(int& ssrEnable, int& sampleCount, int& upsampling) {
  switch (g_ssrQuality) {
    case 0:
      ssrEnable = 0;
      break;
    case 1:
      ssrEnable = 1; sampleCount = 128; upsampling = 1;
      break;
    case 2:
      ssrEnable = 1; sampleCount = 192; upsampling = 1;
      break;
    case 3:
      ssrEnable = 1; sampleCount = 256; upsampling = 1;
      break;
    case 4:
      ssrEnable = 1; sampleCount = 512; upsampling = 0;
      g_ssrResScale = 1.0f;
      break;
    default:
      break;
  }
}

bool SetSettingParameterFloatValue(const char *settingName, float value) {
  if (!il2cpp_class_get_field_from_name || !il2cpp_field_static_get_value ||
      !il2cpp_field_get_offset)
    return false;

  Il2CppImage coreImage = FindImage("UnityEngine.CoreModule");
  if (!coreImage) return false;

  Il2CppClass rpmClass = il2cpp_class_from_name(
      coreImage, "UnityEngine.Rendering", "RenderPipelineManager");
  if (!rpmClass) return false;

  void *pipelineField = il2cpp_class_get_field_from_name(rpmClass, "s_currentPipeline");
  if (!pipelineField) pipelineField = FindFieldByName(rpmClass, "s_currentPipeline");
  if (!pipelineField) return false;

  uintptr_t pipelinePtr = 0;
  il2cpp_field_static_get_value(pipelineField, &pipelinePtr);
  if (!pipelinePtr) return false;

  void *pipelineClass = GetObjectClass(pipelinePtr);
  void *settingsField = FindFieldByName(pipelineClass, "settingParameters");
  if (!settingsField) return false;

  size_t settingsOffset = il2cpp_field_get_offset(settingsField);
  uintptr_t settingsPtr = 0;
  if (!SafeRead(pipelinePtr + settingsOffset, &settingsPtr) || !settingsPtr) return false;

  void *settingsClass = GetObjectClass(settingsPtr);
  void *targetField = FindFieldByName(settingsClass, settingName);
  if (!targetField)
    return false;

  size_t targetOffset = il2cpp_field_get_offset(targetField);
  uintptr_t settingParamPtr = 0;
  if (!SafeRead(settingsPtr + targetOffset, &settingParamPtr) || !settingParamPtr) return false;

  void *paramClass = GetObjectClass(settingParamPtr);
  void *paramValueField = FindFieldByName(paramClass, "paramValue");
  if (!paramValueField) return false;

  size_t paramOffset = il2cpp_field_get_offset(paramValueField);
  uintptr_t valueAddr = settingParamPtr + paramOffset;

  float oldValue = 0;
  SafeRead(valueAddr, &oldValue);

  if (!SafeWrite(valueAddr, value)) return false;

  return true;
}

bool ApplyAnisotropicFiltering(int level) {
  if (!il2cpp_class_from_name || !il2cpp_class_get_method_from_name)
    return false;

  Il2CppImage coreImage = FindImage("UnityEngine.CoreModule");
  if (!coreImage) return false;

  Il2CppClass textureClass = il2cpp_class_from_name(coreImage, "UnityEngine", "Texture");
  if (!textureClass)
    return false;

  Il2CppMethodInfo setLimitsMethod = il2cpp_class_get_method_from_name(
      textureClass, "SetGlobalAnisotropicFilteringLimits", 2);
  if (setLimitsMethod) {
    void *methodPtr = GetMethodPointer(setLimitsMethod);
    if (methodPtr) {
      typedef void (*SetLimitsFunc)(int, int);
      ((SetLimitsFunc)methodPtr)(level, level);
      return true;
    }
  }

  Il2CppClass qualityClass = il2cpp_class_from_name(coreImage, "UnityEngine", "QualitySettings");
  if (qualityClass) {
    Il2CppMethodInfo setAniso = il2cpp_class_get_method_from_name(
        qualityClass, "set_anisotropicFiltering", 1);
    if (setAniso) {
      void *methodPtr = GetMethodPointer(setAniso);
      if (methodPtr) {
        int mode = (level > 1) ? 2 : (level > 0 ? 1 : 0);
        typedef void (*SetAnisoFunc)(int);
        ((SetAnisoFunc)methodPtr)(mode);
      }
    }
  }

  return true;
}

bool ApplyGraphicsSettings() {
  bool success = true;

  int ssrEnable = g_ssrEnable;
  int ssrSamples = g_ssrSampleCount;
  int ssrUpsample = g_ssrUpsampling;

  if (g_ssrQuality >= 0)
    ApplySSRQualityPreset(ssrEnable, ssrSamples, ssrUpsample);

  if (g_ssrEnable >= 0) ssrEnable = g_ssrEnable;
  if (g_ssrSampleCount >= 0) ssrSamples = g_ssrSampleCount;
  if (g_ssrUpsampling >= 0) ssrUpsample = g_ssrUpsampling;

  if (ssrEnable >= 0)
    success &= SetSettingParameterValue("ssrEnable", ssrEnable);
  if (ssrSamples >= 0)
    success &= SetSettingParameterValue("ssrRayMarchingSampleCount", ssrSamples);
  if (ssrUpsample >= 0)
    success &= SetSettingParameterValue("ssrV2Upsample", ssrUpsample);

  if (g_anisoLevel > 0)
    ApplyAnisotropicFiltering(g_anisoLevel);

  if (g_sharpening >= 0) {
    SetSettingParameterFloatValue("sharpenStrength1K", g_sharpening);
    SetSettingParameterFloatValue("sharpenStrength2K", g_sharpening);
    SetSettingParameterFloatValue("sharpenStrength4K", g_sharpening);
  }

  return success;
}

static int g_lastAppliedAAMode = -99;
static int g_lastAppliedSMAAQuality = -99;
static bool g_aaFieldOffsetCached = false;
static uint32_t g_aaFieldOffset = 0;

bool ApplyAAToAllCameras(int aaMode) {
  if (!il2cpp_class_from_name || !il2cpp_class_get_fields || !il2cpp_field_get_name ||
      !il2cpp_field_get_offset || !il2cpp_class_get_type || !il2cpp_type_get_object ||
      !il2cpp_runtime_invoke || !il2cpp_class_get_method_from_name)
    return false;

  Il2CppImage hgRenderImage = FindImage("HG.RenderPipelines.Runtime");
  if (!hgRenderImage)
    return false;

  Il2CppClass camDataClass = il2cpp_class_from_name(
      hgRenderImage, "HG.Rendering.Runtime", "HGAdditionalCameraData");
  if (!camDataClass)
    return false;

  if (!g_aaFieldOffsetCached) {
    void *iter = nullptr;
    while (void *field = il2cpp_class_get_fields(camDataClass, &iter)) {
      const char *name = il2cpp_field_get_name(field);
      if (name && strcmp(name, "antialiasing") == 0) {
        g_aaFieldOffset = (uint32_t)il2cpp_field_get_offset(field);
        g_aaFieldOffsetCached = true;
        break;
      }
    }
    if (!g_aaFieldOffsetCached)
      return false;
  }

  void *type = il2cpp_class_get_type(camDataClass);
  void *systemType = il2cpp_type_get_object(type);
  if (!systemType)
    return false;

  Il2CppImage coreImage = FindImage("UnityEngine.CoreModule");
  if (!coreImage)
    return false;

  Il2CppClass unityObjectClass = il2cpp_class_from_name(coreImage, "UnityEngine", "Object");
  if (!unityObjectClass)
    return false;

  Il2CppMethodInfo findMethod = il2cpp_class_get_method_from_name(
      unityObjectClass, "FindObjectsOfType", 1);
  if (!findMethod)
    return false;

  void *args[1] = { systemType };
  void *exc = nullptr;
  void *result = il2cpp_runtime_invoke(findMethod, nullptr, args, &exc);

  if (exc)
    return false;

  if (!result)
    return true;

  uint32_t count = 0;
  SafeRead((uintptr_t)result + 0x18, &count);

  if (count == 0)
    return true;

  for (uint32_t i = 0; i < count; i++) {
    uintptr_t objAddr = 0;
    SafeRead((uintptr_t)result + 0x20 + (i * 8), &objAddr);
    if (objAddr) {
      int currentVal = 0;
      SafeRead(objAddr + g_aaFieldOffset, &currentVal);
      if (currentVal != aaMode)
        SafeWrite(objAddr + g_aaFieldOffset, aaMode);
    }
  }

  return true;
}

bool ApplySMAAQuality(int quality) {
  if (!il2cpp_class_from_name || !il2cpp_class_get_field_from_name ||
      !il2cpp_field_static_get_value || !il2cpp_field_get_offset)
    return false;

  Il2CppImage hgRenderImage = FindImage("HG.RenderPipelines.Runtime");
  if (!hgRenderImage)
    return false;

  Il2CppClass smaaClass = il2cpp_class_from_name(
      hgRenderImage, "HG.Rendering.Runtime", "HGSMAA");
  if (!smaaClass)
    return false;

  void *instanceField = il2cpp_class_get_field_from_name(smaaClass, "s_instance");
  if (!instanceField)
    return false;

  uintptr_t lazyPtr = 0;
  il2cpp_field_static_get_value(instanceField, &lazyPtr);
  if (!lazyPtr)
    return false;

  uintptr_t smaaInstance = 0;

  SafeRead(lazyPtr + 0x10, &smaaInstance);

  if (!smaaInstance)
    SafeRead(lazyPtr + 0x18, &smaaInstance);

  if (!smaaInstance) {
    Il2CppMethodInfo getInstanceMethod = il2cpp_class_get_method_from_name(smaaClass, "get_instance", 0);
    if (getInstanceMethod) {
      void *exc = nullptr;
      void *result = il2cpp_runtime_invoke(getInstanceMethod, nullptr, nullptr, &exc);
      if (exc)
        return false;
      if (result)
        smaaInstance = (uintptr_t)result;
    }

    if (!smaaInstance)
      return false;
  }

  const size_t SMAA_MODE_OFFSET = 0x10;

  int currentMode = 0;
  SafeRead(smaaInstance + SMAA_MODE_OFFSET, &currentMode);

  if (currentMode != quality)
    SafeWrite(smaaInstance + SMAA_MODE_OFFSET, quality);

  return true;
}

bool ApplyAASettings() {
  bool success = true;

  if (g_aaMode == 0) {
    if (ApplyAAToAllCameras(0))
      g_lastAppliedAAMode = 0;
    else
      success = false;

    if (g_smaaQuality >= 0) {
      if (ApplySMAAQuality(g_smaaQuality))
        g_lastAppliedSMAAQuality = g_smaaQuality;
    }
  } else {
    g_lastAppliedAAMode = 1;
  }

  return success;
}

float GetPrivateProfileFloat(const char *section, const char *key,
                             float defaultVal, const char *iniPath) {
  char buffer[64];
  GetPrivateProfileStringA(section, key, "", buffer, sizeof(buffer), iniPath);
  if (buffer[0] == '\0')
    return defaultVal;
  return (float)atof(buffer);
}

int GetPrivateProfileBool(const char *section, const char *key, int defaultVal,
                          const char *iniPath) {
  return GetPrivateProfileIntA(section, key, defaultVal, iniPath);
}

void LoadConfig() {
  char exePath[MAX_PATH];
  GetModuleFileNameA(NULL, exePath, MAX_PATH);
  std::string dir(exePath);
  size_t lastSlash = dir.rfind('\\');
  if (lastSlash != std::string::npos)
    dir = dir.substr(0, lastSlash + 1);
  std::string iniPath = dir + "EndfieldGFX.ini";
  strncpy(g_iniPath, iniPath.c_str(), MAX_PATH - 1);

  DWORD attrib = GetFileAttributesA(g_iniPath);
  if (attrib == INVALID_FILE_ATTRIBUTES)
    return;

  g_gtaoScale = GetPrivateProfileFloat("Graphics", "GTAORes", -1.0f, g_iniPath);
  g_csmShadowSoftness = GetPrivateProfileFloat("Graphics", "CSMShadowSoftness", -1.0f, g_iniPath);

  g_csmShadowRes = GetPrivateProfileIntA("Graphics", "CSMShadowRes", -1, g_iniPath);
  g_charShadowRes = GetPrivateProfileIntA("Graphics", "CharacterShadowRes", -1, g_iniPath);
  g_punctualShadowRes = GetPrivateProfileIntA("Graphics", "PunctualLightShadowRes", -1, g_iniPath);
  g_asmShadowRes = GetPrivateProfileIntA("Graphics", "ASMShadowRes", -1, g_iniPath);

  g_screenSpaceShadowMask = GetPrivateProfileIntA("Graphics", "ScreenSpaceShadowMask", -1, g_iniPath);

  g_csmShadowSampleMode = GetPrivateProfileIntA("Graphics", "CSMShadowSampleMode", -1, g_iniPath);
  g_charShadowSampleMode = GetPrivateProfileIntA("Graphics", "CharacterShadowSampleMode", -1, g_iniPath);

  g_csmDepthBias = GetPrivateProfileFloat("Graphics", "CSMDepthBias", -1.0f, g_iniPath);
  g_csmNormalBias = GetPrivateProfileFloat("Graphics", "CSMNormalBias", -1.0f, g_iniPath);
  g_csmIntensity = GetPrivateProfileFloat("Graphics", "CSMIntensity", -1.0f, g_iniPath);

  g_contactShadowIntensity = GetPrivateProfileFloat("Graphics", "ContactShadowIntensity", -1.0f, g_iniPath);
  g_contactShadowThickness = GetPrivateProfileFloat("Graphics", "ContactShadowThickness", -1.0f, g_iniPath);
  g_contactShadowBilinear = GetPrivateProfileFloat("Graphics", "ContactShadowBilinear", -1.0f, g_iniPath);
  g_contactShadowContract = GetPrivateProfileFloat("Graphics", "ContactShadowContract", -1.0f, g_iniPath);

  g_aaMode = GetPrivateProfileIntA("Graphics", "AA", 1, g_iniPath);
  g_smaaQuality = GetPrivateProfileIntA("Graphics", "SMAA", -1, g_iniPath);
  if (g_smaaQuality < -1)
    g_smaaQuality = -g_smaaQuality;

  g_ssrQuality = GetPrivateProfileIntA("Graphics", "SSRQuality", -1, g_iniPath);
  g_ssrEnable = GetPrivateProfileIntA("Graphics", "SSREnable", -1, g_iniPath);
  g_ssrSampleCount = GetPrivateProfileIntA("Graphics", "SSRSampleCount", -1, g_iniPath);
  g_ssrUpsampling = GetPrivateProfileIntA("Graphics", "SSRUpsampling", -1, g_iniPath);

  g_renderScale = GetPrivateProfileFloat("Graphics", "RenderScale", -1.0f, g_iniPath);

  g_anisoLevel = GetPrivateProfileIntA("Graphics", "AnisoLevel", -1, g_iniPath);
  if (g_anisoLevel < -1)
    g_anisoLevel = -g_anisoLevel;

  g_sharpening = GetPrivateProfileFloat("Graphics", "Sharpening", -1.0f, g_iniPath);
}

bool ResolveIL2CppAPI() {
  g_hGameAssembly = GetModuleHandleW(L"GameAssembly.dll");
  if (!g_hGameAssembly)
    return false;
#define RESOLVE(name) name = (fn_##name)GetProcAddress(g_hGameAssembly, #name);
  RESOLVE(il2cpp_domain_get);
  RESOLVE(il2cpp_thread_attach);
  RESOLVE(il2cpp_domain_get_assemblies);
  RESOLVE(il2cpp_assembly_get_image);
  RESOLVE(il2cpp_image_get_name);
  RESOLVE(il2cpp_class_from_name);
  RESOLVE(il2cpp_class_get_method_from_name);
  RESOLVE(il2cpp_class_get_field_from_name);
  RESOLVE(il2cpp_field_static_get_value);
  RESOLVE(il2cpp_field_static_set_value);
  RESOLVE(il2cpp_field_get_value);
  RESOLVE(il2cpp_field_set_value);
  RESOLVE(il2cpp_field_get_offset);
  RESOLVE(il2cpp_class_get_fields);
  RESOLVE(il2cpp_field_get_name);
  RESOLVE(il2cpp_field_get_flags);
  RESOLVE(il2cpp_class_get_parent);
  RESOLVE(il2cpp_object_get_class);
  RESOLVE(il2cpp_class_get_type);
  RESOLVE(il2cpp_type_get_object);
  RESOLVE(il2cpp_runtime_invoke);
#undef RESOLVE
  return il2cpp_domain_get && il2cpp_class_from_name;
}

Il2CppImage FindImage(const char *name) {
  Il2CppDomain domain = il2cpp_domain_get();
  if (!domain)
    return nullptr;
  size_t count = 0;
  void **assemblies = il2cpp_domain_get_assemblies(domain, &count);
  if (!assemblies)
    return nullptr;
  for (size_t i = 0; i < count; i++) {
    Il2CppImage image = il2cpp_assembly_get_image(assemblies[i]);
    if (!image)
      continue;
    const char *n = il2cpp_image_get_name(image);
    if (n && strstr(n, name))
      return image;
  }
  return nullptr;
}

void *GetMethodPointer(Il2CppMethodInfo mi) {
  return mi ? ((MethodInfo *)mi)->methodPointer : nullptr;
}

int CallStaticIntGetter(Il2CppClass k, const char *m) {
  Il2CppMethodInfo mi = il2cpp_class_get_method_from_name(k, m, 0);
  if (!mi)
    return -1;
  void *p = GetMethodPointer(mi);
  return p ? ((int (*)())p)() : -1;
}

void GetScreenRes() {
  Il2CppImage coreImage = FindImage("UnityEngine.CoreModule");
  if (!coreImage)
    return;
  Il2CppClass screenClass =
      il2cpp_class_from_name(coreImage, "UnityEngine", "Screen");
  if (!screenClass)
    return;
  g_screenWidth = CallStaticIntGetter(screenClass, "get_width");
  g_screenHeight = CallStaticIntGetter(screenClass, "get_height");
}

bool ApplyUnityShadowSettings(int32_t targetRes) {
  static bool initialized = false;
  static void *settingParamsField = nullptr;
  static void *csmResField = nullptr;
  static void *charResField = nullptr;
  static void *paramValueField = nullptr;
  static Il2CppClass renderPipelineManagerClass = nullptr;
  static void *s_currentPipelineField = nullptr;

  if (!il2cpp_class_get_field_from_name || !il2cpp_field_static_get_value ||
      !il2cpp_field_get_value || !il2cpp_field_set_value) {
    return false;
  }

  if (!initialized) {
    Il2CppImage renderingImage = FindImage("UnityEngine.CoreModule");
    if (!renderingImage)
      return false;

    renderPipelineManagerClass = il2cpp_class_from_name(
        renderingImage, "UnityEngine.Rendering", "RenderPipelineManager");
    if (!renderPipelineManagerClass)
      return false;

    s_currentPipelineField = il2cpp_class_get_field_from_name(
        renderPipelineManagerClass, "s_currentPipeline");
    if (!s_currentPipelineField)
      return false;

    Il2CppImage hgRenderImage = FindImage("HG.RenderPipelines.Runtime");
    if (hgRenderImage) {
      Il2CppClass settingParamsClass = il2cpp_class_from_name(
          hgRenderImage, "HG.Rendering.Runtime", "HGSettingParameters");
      if (settingParamsClass) {
        csmResField = il2cpp_class_get_field_from_name(
            settingParamsClass, "<csmShadowMapTileResolution>k__BackingField");
        charResField = il2cpp_class_get_field_from_name(
            settingParamsClass,
            "<characterShadowMapResolution>k__BackingField");

        Il2CppClass settingParamIntClass = il2cpp_class_from_name(
            hgRenderImage, "HG.Rendering.Runtime", "SettingParameter`1");
        if (settingParamIntClass) {
          paramValueField = il2cpp_class_get_field_from_name(
              settingParamIntClass, "<paramValue>k__BackingField");
        }
      }
    }

    initialized = true;
  }

  if (!s_currentPipelineField)
    return false;

  void *currentPipeline = nullptr;
  il2cpp_field_static_get_value(s_currentPipelineField, &currentPipeline);
  if (!currentPipeline)
    return false;

  void *settingParams = nullptr;

  Il2CppMethodInfo getterMethod = il2cpp_class_get_method_from_name(
      *(Il2CppClass *)currentPipeline, "get_settingParameters", 0);
  if (getterMethod) {
    void *methodPtr = GetMethodPointer(getterMethod);
    if (methodPtr)
      settingParams = ((void *(*)(void *))methodPtr)(currentPipeline);
  }

  if (!settingParams) {
    void *field = il2cpp_class_get_field_from_name(
        *(Il2CppClass *)currentPipeline, "<settingParameters>k__BackingField");
    if (field)
      il2cpp_field_get_value(currentPipeline, field, &settingParams);
  }

  if (!settingParams)
    return false;

  if (csmResField && paramValueField) {
    void *csmSettingParam = nullptr;
    il2cpp_field_get_value(settingParams, csmResField, &csmSettingParam);
    if (csmSettingParam)
      il2cpp_field_set_value(csmSettingParam, paramValueField, &targetRes);
  }

  if (charResField && paramValueField) {
    void *charSettingParam = nullptr;
    il2cpp_field_get_value(settingParams, charResField, &charSettingParam);
    if (charSettingParam)
      il2cpp_field_set_value(charSettingParam, paramValueField, &targetRes);
  }

  return true;
}

typedef void (*RenderPathFunc_t)(int64_t _ptr, void *renderPathParams,
                                 void *beforeCullingParams, void *camera,
                                 void *renderContext, void *_cmd);
static RenderPathFunc_t g_OriginalRenderPath = nullptr;

void HookedRenderPath(int64_t _ptr, void *renderPathParams,
                      void *beforeCullingParams, void *camera,
                      void *renderContext, void *_cmd) {
  if (renderPathParams) {
    __try {
      uint8_t *base = (uint8_t *)renderPathParams;

      if (g_gtaoScale >= 0) {
        void **gtaoPtrAddr = (void **)(base + RENDER_PARAMS_GTAO_PTR);
        void *gtaoPtr = *gtaoPtrAddr;

        if (gtaoPtr) {
          uint8_t *gtaoSettings = (uint8_t *)gtaoPtr;
          int32_t *pWidth = (int32_t *)(gtaoSettings + GTAO_SCREEN_WIDTH);
          int32_t *pHeight = (int32_t *)(gtaoSettings + GTAO_SCREEN_HEIGHT);

          int32_t oldWidth = *pWidth;
          int32_t oldHeight = *pHeight;

          int32_t targetW = (int32_t)(g_screenWidth * g_gtaoScale);
          int32_t targetH = (int32_t)(g_screenHeight * g_gtaoScale);

          if (oldWidth != targetW || oldHeight != targetH) {
            *pWidth = targetW;
            *pHeight = targetH;
            g_patchCount++;
            g_gtaoPatched = true;
          }
        }
      }

    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
  }

  if (beforeCullingParams) {
    __try {
      uintptr_t shadowConfigPtr = 0;
      if (!SafeRead((uintptr_t)beforeCullingParams + BEFORE_CULLING_SHADOW_CONFIG_PTR, &shadowConfigPtr))
        goto call_original;
      if (!shadowConfigPtr)
        goto call_original;

      float currentSoftness = 0.0f;
      if (!SafeRead(shadowConfigPtr + SHADOW_CONFIG_CSM_SOFTNESS, &currentSoftness))
        goto call_original;

      float curDepthBias = 0, curNormalBias = 0, curIntensity = 0;
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CSM_DEPTH_BIAS, &curDepthBias);
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CSM_NORMAL_BIAS, &curNormalBias);
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CSM_INTENSITY, &curIntensity);

      float contactIntensity = 0, contactThickness = 0, contactBilinear = 0, contactContract = 0;
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CONTACT_INTENSITY, &contactIntensity);
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CONTACT_SURFACE_THICKNESS, &contactThickness);
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CONTACT_BILINEAR, &contactBilinear);
      SafeRead(shadowConfigPtr + SHADOW_CONFIG_CONTACT_CONTRACT, &contactContract);

      if (g_csmShadowSoftness >= 0 && currentSoftness != g_csmShadowSoftness)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CSM_SOFTNESS, g_csmShadowSoftness);
      if (g_csmDepthBias >= 0 && curDepthBias != g_csmDepthBias)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CSM_DEPTH_BIAS, g_csmDepthBias);
      if (g_csmNormalBias >= 0 && curNormalBias != g_csmNormalBias)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CSM_NORMAL_BIAS, g_csmNormalBias);
      if (g_csmIntensity >= 0 && curIntensity != g_csmIntensity)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CSM_INTENSITY, g_csmIntensity);

      if (g_contactShadowIntensity >= 0 && contactIntensity != g_contactShadowIntensity)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CONTACT_INTENSITY, g_contactShadowIntensity);
      if (g_contactShadowThickness >= 0 && contactThickness != g_contactShadowThickness)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CONTACT_SURFACE_THICKNESS, g_contactShadowThickness);
      if (g_contactShadowBilinear >= 0 && contactBilinear != g_contactShadowBilinear)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CONTACT_BILINEAR, g_contactShadowBilinear);
      if (g_contactShadowContract >= 0 && contactContract != g_contactShadowContract)
        SafeWrite(shadowConfigPtr + SHADOW_CONFIG_CONTACT_CONTRACT, g_contactShadowContract);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
  }

call_original:

  if (g_TrampolineFunc) {
    ((RenderPathFunc_t)g_TrampolineFunc)(_ptr, renderPathParams,
                                         beforeCullingParams, camera,
                                         renderContext, _cmd);
  }
}

bool InstallHookWithTrampoline(void *target) {
  if (!target)
    return false;

  const int HOOK_SIZE = 16;

  memcpy(g_OriginalBytes, target, HOOK_SIZE);

  uintptr_t targetAddr = (uintptr_t)target;
  g_pTrampoline = nullptr;

  const uintptr_t MAX_RANGE = 0x7FFF0000;
  const uintptr_t STEP = 0x10000;

  for (uintptr_t offset = STEP; offset < MAX_RANGE; offset += STEP) {
    void *tryAddr = (void *)(targetAddr - offset);
    g_pTrampoline = VirtualAlloc(tryAddr, 64, MEM_COMMIT | MEM_RESERVE,
                                 PAGE_EXECUTE_READWRITE);
    if (g_pTrampoline)
      break;

    tryAddr = (void *)(targetAddr + offset);
    g_pTrampoline = VirtualAlloc(tryAddr, 64, MEM_COMMIT | MEM_RESERVE,
                                 PAGE_EXECUTE_READWRITE);
    if (g_pTrampoline)
      break;
  }

  if (!g_pTrampoline)
    return false;

  memcpy(g_pTrampoline, target, HOOK_SIZE);

  uint8_t *trampolineBytes = (uint8_t *)g_pTrampoline;
  if (trampolineBytes[7] == 0x80 && trampolineBytes[8] == 0x3D) {
    int32_t origDisp = *(int32_t *)(trampolineBytes + 9);
    uintptr_t originalTargetAddr = (uintptr_t)target + 14 + origDisp;
    int32_t newDisp =
        (int32_t)(originalTargetAddr - ((uintptr_t)g_pTrampoline + 14));
    *(int32_t *)(trampolineBytes + 9) = newDisp;
  }

  uint8_t *trampolineJump = (uint8_t *)g_pTrampoline + HOOK_SIZE;
  trampolineJump[0] = 0x48;
  trampolineJump[1] = 0xB8;
  uintptr_t returnAddr = (uintptr_t)target + HOOK_SIZE;
  memcpy(&trampolineJump[2], &returnAddr, 8);
  trampolineJump[10] = 0xFF;
  trampolineJump[11] = 0xE0;

  g_TrampolineFunc = (ConvertSettingParamsToCpp_t)g_pTrampoline;

  DWORD oldProtect;
  if (!VirtualProtect(target, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect)) {
    VirtualFree(g_pTrampoline, 0, MEM_RELEASE);
    return false;
  }

  uint8_t hookCode[16] = {
      0x48, 0xB8, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00,
      0xFF, 0xE0,
      0x90, 0x90, 0x90, 0x90
  };
  uintptr_t hookAddr = (uintptr_t)&HookedRenderPath;
  memcpy(&hookCode[2], &hookAddr, 8);

  memcpy(target, hookCode, HOOK_SIZE);

  VirtualProtect(target, HOOK_SIZE, oldProtect, &oldProtect);

  FlushInstructionCache(GetCurrentProcess(), target, HOOK_SIZE);
  FlushInstructionCache(GetCurrentProcess(), g_pTrampoline, 64);

  g_HookInstalled = true;

  return true;
}

bool TryDirectPatch() {
  Il2CppImage graphicsImage = FindImage("UnityEngine.HGGraphicsCPPModule");
  if (!graphicsImage)
    return false;

  Il2CppClass renderGraphClass = il2cpp_class_from_name(
      graphicsImage, "UnityEngine.HyperGryphEngineCode", "HGRenderGraphCPP");
  if (!renderGraphClass)
    renderGraphClass = il2cpp_class_from_name(graphicsImage, "", "HGRenderGraphCPP");

  if (renderGraphClass) {
    Il2CppMethodInfo renderMethod = il2cpp_class_get_method_from_name(
        renderGraphClass, "HGRenderPath_Render", 6);
    if (renderMethod) {
      g_ConvertMethodPtr = GetMethodPointer(renderMethod);
      if (g_ConvertMethodPtr)
        return InstallHookWithTrampoline(g_ConvertMethodPtr);
    }
  }

  return false;
}

void ApplyEnhancements() {
  LoadConfig();
  GetScreenRes();
  TryDirectPatch();
}

DWORD WINAPI EnforcerThread(LPVOID) {
  static bool initialSettingsApplied = false;
  int tick = 0;

  while (true) {
    Sleep(APPLY_INTERVAL_MS);
    if (!g_initialized)
      continue;

    tick++;

    if (!initialSettingsApplied && tick >= 6) {
      bool allSuccess = true;

      if (ApplyManagedShadowSettings())
        g_shadowPatched = true;
      else
        allSuccess = false;

      ApplyGraphicsSettings();
      ApplyAASettings();

      if (allSuccess)
        initialSettingsApplied = true;
    }

    if (initialSettingsApplied && g_aaMode == 0) {
      ApplyAAToAllCameras(0);
      if (g_smaaQuality >= 0)
        ApplySMAAQuality(g_smaaQuality);
    }

    if (tick % 12 == 0)
      GetScreenRes();
  }
  return 0;
}

DWORD WINAPI InitThread(LPVOID) {
  HANDLE hMutex = CreateMutexA(NULL, TRUE, "Local\\Ace_GFX_Mutex");
  if (GetLastError() == ERROR_ALREADY_EXISTS) {
    if (hMutex)
      CloseHandle(hMutex);
    return 0;
  }

  Sleep(INIT_DELAY_MS);

  if (!ResolveIL2CppAPI())
    return 1;

  Il2CppDomain domain = il2cpp_domain_get();
  if (!domain)
    return 1;

  if (il2cpp_thread_attach)
    il2cpp_thread_attach(domain);

  Sleep(2000);

  g_initialized = true;
  ApplyEnhancements();

  CreateThread(NULL, 0, EnforcerThread, NULL, 0, NULL);

  return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
  if (reason == DLL_PROCESS_ATTACH) {
    DisableThreadLibraryCalls(hModule);
    CreateThread(NULL, 0, InitThread, NULL, 0, NULL);
  } else if (reason == DLL_PROCESS_DETACH) {
    if (g_pTrampoline)
      VirtualFree(g_pTrampoline, 0, MEM_RELEASE);
  }
  return TRUE;
}
