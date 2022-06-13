
cmake_minimum_required(VERSION 3.23.1)

set(CMSISPATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../..)
set(DAPPATH ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(DAPSOURCEPATH ${DAPPATH}/Source)

project(test)

add_executable(test)
target_sources(test PUBLIC 
    main.c

    ${DAPSOURCEPATH}/DAP.c
    ${DAPSOURCEPATH}/SW_DP.c
)

target_include_directories(test PUBLIC
  .
  ${DAPPATH}/Include
  ${CMSISPATH}/CMSIS/Core/Include
)

target_compile_definitions(test PUBLIC DELAY_SLOW_CYCLES)
target_compile_options(test PUBLIC -g -O0)
