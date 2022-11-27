cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(LED_Test LANGUAGES MikroC)
else()
    project(LED_Test LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(LED_Test main.c)
############################ LED_Test GENERATED CODE START ###########################
############################ LED_Test GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(LED_Test
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(LED_Test
        PUBLIC
            MikroC.System
    )
endif()
