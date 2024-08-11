cmake_minimum_required(VERSION 3.21)

include(cmake/prelude.cmake)

project(
    ccontainer
    VERSION 0.1.0
    DESCRIPTION "Comprehensive library of data structures implemented in C."
    HOMEPAGE_URL "https://leventkaya.com"
    LANGUAGES NONE
)

include(cmake/variables.cmake)

# ---- Declare library ----

add_library(ccontainer_ccontainer INTERFACE)
add_library(ccontainer::ccontainer ALIAS ccontainer_ccontainer)

set_property(
    TARGET ccontainer_ccontainer PROPERTY
    EXPORT_NAME ccontainer
)

target_include_directories(
    ccontainer_ccontainer ${warning_guard}
    INTERFACE
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(ccontainer_ccontainer INTERFACE c_std_99)

find_package(unity REQUIRED)
target_link_libraries(ccontainer_ccontainer INTERFACE json-c::json-c)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT ccontainer_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of ccontainer"
  )
endif()

include(cmake/dev-mode.cmake)
