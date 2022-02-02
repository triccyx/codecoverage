cmake_minimum_required(VERSION 3.5)

project(mymain LANGUAGES CXX)

add_executable(${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_sources(${PROJECT_NAME}
    PRIVATE
    main.cpp
  )

target_link_libraries(${PROJECT_NAME}
PRIVATE 
  pthread
  multiplier
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_subdirectory(mylib)
add_subdirectory(unittest)
