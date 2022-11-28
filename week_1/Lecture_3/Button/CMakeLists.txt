cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Button LANGUAGES MikroC)
else()
    project(Button LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(Button main.c)

############################ Button GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(Button PUBLIC MikroC.Core)
find_package(MikroC.System REQUIRED)
target_link_libraries(Button PUBLIC MikroC.System)
find_package(MikroC.Button REQUIRED)
target_link_libraries(Button PUBLIC MikroC.Button)
############################ Button GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Button
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Button
        PUBLIC
            MikroC.System
    )
endif()
