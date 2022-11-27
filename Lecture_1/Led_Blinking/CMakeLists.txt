cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Led_Blinking LANGUAGES MikroC)
else()
    project(Led_Blinking LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(Led_Blinking main.c)

############################ Led_Blinking GENERATED CODE START ###########################
find_package(MikroSDK.HalLowLevel.GPIO REQUIRED)
target_link_libraries(Led_Blinking PUBLIC MikroSDK.HalLowLevel.GPIO)
find_package(MikroSDK.Hal.GPIO REQUIRED)
target_link_libraries(Led_Blinking PUBLIC MikroSDK.Hal.GPIO)
find_package(MikroSDK.Driver.GPIO.Port REQUIRED)
target_link_libraries(Led_Blinking PUBLIC MikroSDK.Driver.GPIO.Port)
find_package(MikroSDK.Driver.GPIO.Out REQUIRED)
target_link_libraries(Led_Blinking PUBLIC MikroSDK.Driver.GPIO.Out)
find_package(MikroSDK.Driver.GPIO.In REQUIRED)
target_link_libraries(Led_Blinking PUBLIC MikroSDK.Driver.GPIO.In)
find_package(MikroC.Core REQUIRED)
target_link_libraries(Led_Blinking PUBLIC MikroC.Core)
############################ Led_Blinking GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Led_Blinking
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Led_Blinking
        PUBLIC
            MikroC.System
    )
endif()
