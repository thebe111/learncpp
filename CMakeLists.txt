cmake_minimum_required(VERSION 3.10)

set(PROJECT "learncpp")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(
    ${PROJECT} 
    VERSION 1.0.0 
    DESCRIPTION "learn cpp tutorial site examples"
    LANGUAGES CXX
)

# need to be defined before `target_*` functions
add_executable(
    ${PROJECT}
    src/main.cpp
)

add_executable(
    unit_test
    test/unit/test_add.cpp
    src/example/add.cpp
)

enable_testing()

add_test(NAME unit_test COMMAND unit_test)

target_link_libraries(
    unit_test
    PRIVATE
    gtest
    gtest_main
    pthread
)

# setting up the compiler standard
target_compile_features(${PROJECT} PRIVATE cxx_std_20)

# setting up compiler options
target_compile_options(
    ${PROJECT}
    PRIVATE
    -Wall
    -Weffc++
    -Werror
    -Wextra
    -Wsign-conversion
    # necessary to prevent fallthrough errors on switch statement
    # -Wimplicit-fallthrough 
)

# to works need to make a new `CMakeLists` file inside included subdirectory
# add_subdirectory(src)
