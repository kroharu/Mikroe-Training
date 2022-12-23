cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(UART_Demo2 LANGUAGES MikroC)
else()
    project(UART_Demo2 LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(UART_Demo2 main.c)

############################ UART_Demo2 GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(UART_Demo2 PUBLIC MikroC.Core)
find_package(MikroC.UART_Remappable REQUIRED)
target_link_libraries(UART_Demo2 PUBLIC MikroC.UART_Remappable)
find_package(MikroC.System REQUIRED)
target_link_libraries(UART_Demo2 PUBLIC MikroC.System)
find_package(MikroC.Peripheral_Pin_Select REQUIRED)
target_link_libraries(UART_Demo2 PUBLIC MikroC.Peripheral_Pin_Select)
find_package(MikroC.Conversions REQUIRED)
target_link_libraries(UART_Demo2 PUBLIC MikroC.Conversions)
############################ UART_Demo2 GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(UART_Demo2
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(UART_Demo2
        PUBLIC
            MikroC.System
    )
endif()
