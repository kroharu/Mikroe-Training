cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Malloc_Learn LANGUAGES MikroC)
else()
    project(Malloc_Learn LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(Malloc_Learn main.c)
############################ Malloc_Learn GENERATED CODE START ###########################
############################ Malloc_Learn GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Malloc_Learn
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Malloc_Learn
        PUBLIC
            MikroC.System
    )
endif()
