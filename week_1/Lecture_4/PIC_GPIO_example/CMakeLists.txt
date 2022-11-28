cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(PIC_GPIO_example LANGUAGES MikroC)
else()
    project(PIC_GPIO_example LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(PIC_GPIO_example main.c)
############################ PIC_GPIO_example GENERATED CODE START ###########################
############################ PIC_GPIO_example GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(PIC_GPIO_example
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(PIC_GPIO_example
        PUBLIC
            MikroC.System
    )
endif()
