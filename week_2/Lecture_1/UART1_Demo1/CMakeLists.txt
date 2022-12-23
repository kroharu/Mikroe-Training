cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(UART1_Demo LANGUAGES MikroC)
else()
    project(UART1_Demo LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(UART1_Demo main.c)

############################ UART1_Demo GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(UART1_Demo PUBLIC MikroC.Core)
find_package(MikroC.UART_Remappable REQUIRED)
target_link_libraries(UART1_Demo PUBLIC MikroC.UART_Remappable)
find_package(MikroC.System REQUIRED)
target_link_libraries(UART1_Demo PUBLIC MikroC.System)
find_package(MikroC.Software_UART REQUIRED)
target_link_libraries(UART1_Demo PUBLIC MikroC.Software_UART)
find_package(MikroC.Peripheral_Pin_Select REQUIRED)
target_link_libraries(UART1_Demo PUBLIC MikroC.Peripheral_Pin_Select)
find_package(MikroC.Conversions REQUIRED)
target_link_libraries(UART1_Demo PUBLIC MikroC.Conversions)
############################ UART1_Demo GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(UART1_Demo
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(UART1_Demo
        PUBLIC
            MikroC.System
    )
endif()
