cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(STM32_GPIO_interrupt_example LANGUAGES MikroC)
else()
    project(STM32_GPIO_interrupt_example LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(STM32_GPIO_interrupt_example main.c)
############################ STM32_GPIO_interrupt_example GENERATED CODE START ###########################
############################ STM32_GPIO_interrupt_example GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(STM32_GPIO_interrupt_example
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(STM32_GPIO_interrupt_example
        PUBLIC
            MikroC.System
    )
endif()
