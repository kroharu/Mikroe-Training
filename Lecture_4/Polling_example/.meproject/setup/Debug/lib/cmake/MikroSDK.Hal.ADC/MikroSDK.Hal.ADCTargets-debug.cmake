#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "MikroSDK.Hal.ADC" for configuration "Debug"
set_property(TARGET MikroSDK.Hal.ADC APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(MikroSDK.Hal.ADC PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "MikroC"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/lib_hal_adc.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS MikroSDK.Hal.ADC )
list(APPEND _IMPORT_CHECK_FILES_FOR_MikroSDK.Hal.ADC "${_IMPORT_PREFIX}/lib/lib_hal_adc.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
