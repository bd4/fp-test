cmake_minimum_required(VERSION 3.20)
project(fp-test LANGUAGES CXX)

include(cmake/CPM.cmake)

if(CMAKE_CXX_COMPILER_ID STREQUAL "IntelLLVM")
  add_compile_options(-fp-model=precise)
endif()

include(CTest)

if (BUILD_TESTING)
  CPMAddPackage(
    NAME GTest
    GITHUB_REPOSITORY google/googletest
    VERSION 1.13.0
    OPTIONS
      "INSTALL_GTEST OFF"
      "gtest_force_shared crt ON"
    FIND_PACKAGE_ARGUMENTS "CONFIG"
  )
  include(GoogleTest)
  add_subdirectory(tests)
endif()

add_subdirectory(src)
