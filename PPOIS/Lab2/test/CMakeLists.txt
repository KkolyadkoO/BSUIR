cmake_minimum_required(VERSION 3.14)
project(POSTAL_OFFICE_TEST)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/adc514538678a61b13c240f7b41babbc03b2ac24.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
file(GLOB_RECURSE SRC_FILES
  ${PROJECT_SOURCE_DIR}/../src/*.cpp
)
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/../src/main.cpp)
enable_testing()

add_executable(
  POST_Test
  test.cpp
  ${SRC_FILES}
)
target_link_libraries(
  POST_Test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(POST_Test)
