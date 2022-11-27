cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Keywords LANGUAGES MikroC)
else()
    project(Keywords LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(Keywords main.c)
############################ Keywords GENERATED CODE START ###########################
############################ Keywords GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Keywords
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Keywords
        PUBLIC
            MikroC.System
    )
endif()
