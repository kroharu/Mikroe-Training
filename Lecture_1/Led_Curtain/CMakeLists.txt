cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(Led_Curtain LANGUAGES MikroC)
else()
    project(Led_Curtain LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "mikrosdk" CACHE STRING "" FORCE)

add_executable(Led_Curtain main.c)
############################ Led_Curtain GENERATED CODE START ###########################
############################ Led_Curtain GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(Led_Curtain
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(Led_Curtain
        PUBLIC
            MikroC.System
    )
endif()
