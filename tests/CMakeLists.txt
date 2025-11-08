cmake_minimum_required(VERSION 3.14)
project(BaseEncodingTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  base_encoding_tests
  test_base2.cpp
  test_base8.cpp
  test_base10.cpp
  test_base16.cpp
  test_base32.cpp
  test_base36.cpp
  test_base58.cpp
  test_base62.cpp
  test_base64.cpp
  test_base85.cpp
)

target_link_libraries(
  base_encoding_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(base_encoding_tests)
