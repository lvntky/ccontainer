# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(unity_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(unity_FRAMEWORKS_FOUND_RELEASE "${unity_FRAMEWORKS_RELEASE}" "${unity_FRAMEWORK_DIRS_RELEASE}")

set(unity_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET unity_DEPS_TARGET)
    add_library(unity_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET unity_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${unity_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${unity_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### unity_DEPS_TARGET to all of them
conan_package_library_targets("${unity_LIBS_RELEASE}"    # libraries
                              "${unity_LIB_DIRS_RELEASE}" # package_libdir
                              "${unity_BIN_DIRS_RELEASE}" # package_bindir
                              "${unity_LIBRARY_TYPE_RELEASE}"
                              "${unity_IS_HOST_WINDOWS_RELEASE}"
                              unity_DEPS_TARGET
                              unity_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "unity"    # package_name
                              "${unity_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${unity_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET unity::unity
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${unity_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${unity_LIBRARIES_TARGETS}>
                 )

    if("${unity_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET unity::unity
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     unity_DEPS_TARGET)
    endif()

    set_property(TARGET unity::unity
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${unity_LINKER_FLAGS_RELEASE}>)
    set_property(TARGET unity::unity
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${unity_INCLUDE_DIRS_RELEASE}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET unity::unity
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${unity_LIB_DIRS_RELEASE}>)
    set_property(TARGET unity::unity
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${unity_COMPILE_DEFINITIONS_RELEASE}>)
    set_property(TARGET unity::unity
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${unity_COMPILE_OPTIONS_RELEASE}>)

########## For the modules (FindXXX)
set(unity_LIBRARIES_RELEASE unity::unity)
