cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(PWMExample1 LANGUAGES MikroC)
else()
    project(PWMExample1 LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(PWMExample1 main.c)

############################ PWMExample1 GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(PWMExample1 PUBLIC MikroC.Core)
find_package(MikroC.System REQUIRED)
target_link_libraries(PWMExample1 PUBLIC MikroC.System)
find_package(MikroC.PWM_Remappable REQUIRED)
target_link_libraries(PWMExample1 PUBLIC MikroC.PWM_Remappable)
find_package(MikroC.Peripheral_Pin_Select REQUIRED)
target_link_libraries(PWMExample1 PUBLIC MikroC.Peripheral_Pin_Select)
############################ PWMExample1 GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(PWMExample1
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(PWMExample1
        PUBLIC
            MikroC.System
    )
endif()
