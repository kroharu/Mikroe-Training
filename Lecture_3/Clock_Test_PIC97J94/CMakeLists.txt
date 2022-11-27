cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Clock_Test_PIC97J94 LANGUAGES MikroC)
else()
    project(Clock_Test_PIC97J94 LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(Clock_Test_PIC97J94 main.c)
############################ Clock_Test_PIC97J94 GENERATED CODE START ###########################
############################ Clock_Test_PIC97J94 GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Clock_Test_PIC97J94
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Clock_Test_PIC97J94
        PUBLIC
            MikroC.System
    )
endif()
