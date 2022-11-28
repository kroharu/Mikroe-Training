cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(LED_Blinking LANGUAGES MikroC)
else()
    project(LED_Blinking LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(LED_Blinking main.c)
############################ LED_Blinking GENERATED CODE START ###########################
############################ LED_Blinking GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(LED_Blinking
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(LED_Blinking
        PUBLIC
            MikroC.System
    )
endif()
