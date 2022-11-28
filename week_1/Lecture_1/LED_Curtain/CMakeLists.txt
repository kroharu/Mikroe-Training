cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(LED_Curtain LANGUAGES MikroC)
else()
    project(LED_Curtain LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(LED_Curtain main.c)
############################ LED_Curtain GENERATED CODE START ###########################
############################ LED_Curtain GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(LED_Curtain
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(LED_Curtain
        PUBLIC
            MikroC.System
    )
endif()
