cmake_minimum_required(VERSION 3.21)

project(ccontainerTests LANGUAGES C)

include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(ccontainer REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(ccontainer_test source/ccontainer_test.c)
set_property(
    SOURCE source/ccontainer_test.c PROPERTY
    COMPILE_DEFINITIONS CCONTAINER_IMPLEMENTATION
)
target_link_libraries(ccontainer_test PRIVATE ccontainer::ccontainer)
target_compile_features(ccontainer_test PRIVATE c_std_99)

add_test(NAME ccontainer_test COMMAND ccontainer_test)

# ---- End-of-file commands ----

add_folders(Test)
