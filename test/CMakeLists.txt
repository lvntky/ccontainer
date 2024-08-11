cmake_minimum_required(VERSION 3.21)

project(ccontainerTests LANGUAGES C CXX)

include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(ccontainer REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(
    ccontainer_test
    source/ccontainer_test_main.c
)
target_link_libraries(
    ccontainer_test PRIVATE
    ccontainer::ccontainer
    Catch2::Catch2WithMain
)
target_compile_features(ccontainer_test PRIVATE c_std_99 cxx_std_11)

catch_discover_tests(ccontainer_test)

# ---- End-of-file commands ----

add_folders(Test)
