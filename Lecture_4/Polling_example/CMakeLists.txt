cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Polling_example LANGUAGES MikroC)
else()
    project(Polling_example LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(Polling_example main.c)

############################ Polling_example GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(Polling_example PUBLIC MikroC.Core)
############################ Polling_example GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Polling_example
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Polling_example
        PUBLIC
            MikroC.System
    )
endif()
