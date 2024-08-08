cmake_minimum_required(VERSION 3.21)

project(ccontainerTests LANGUAGES C)

include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(ccontainer REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

# Create a list of test sources
set(TEST_SOURCES
    source/main_test.c
    source/cc_vector_test.c
)

# Add the test executable
add_executable(ccontainer_tests ${TEST_SOURCES})

# Ensure the implementation macro is defined
target_compile_definitions(ccontainer_tests PRIVATE CC_VECTOR_IMPLEMENTATION)

# Include the downloaded utest.h
target_include_directories(ccontainer_tests PRIVATE ${CMAKE_BINARY_DIR})

# Link against the ccontainer library
target_link_libraries(ccontainer_tests PRIVATE ccontainer::ccontainer)

# Ensure C99 standard
target_compile_features(ccontainer_tests PRIVATE c_std_99)

# Add the test executable to CTest
add_test(NAME ccontainer_tests COMMAND ccontainer_tests)

# ---- End-of-file commands ----

add_folders(Test)
