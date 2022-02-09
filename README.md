# 1. Automatic test execution
Automatic test execution during cmake

# 2. How to

```bash
git clone https://github.com/triccyx/codecoverage.git
cd codecoverage
mkdir build
cmake -DCMAKE_INSTALL_PREFIX=<clone path>/codecoverage/install/ ..
make
make install
```
# 3. Key feature

The automatic test execution is achieved by these lines in `unittets\CMakeLists.txt`

```cmake
enable_testing()
...
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

add_custom_target(run_unit_test ALL
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ${PROJECT_NAME})
```