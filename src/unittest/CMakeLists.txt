cmake_minimum_required(VERSION 3.5)

include(GoogleTest)

project(unittest LANGUAGES CXX)

enable_testing()

add_executable(${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_EXE_LINKER_FLAGS  "-rdynamic")
set(CMAKE_INSTALL_RPATH ./)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_sources(${PROJECT_NAME}
    PRIVATE
    general.cpp
    gtest_main.cc
  )

target_link_libraries(${PROJECT_NAME}
PRIVATE 
  pthread
  multiplier
  gtest 
  gmock
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

add_custom_target(run_unit_test ALL
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})