########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(unity_COMPONENT_NAMES "")
if(DEFINED unity_FIND_DEPENDENCY_NAMES)
  list(APPEND unity_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES unity_FIND_DEPENDENCY_NAMES)
else()
  set(unity_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(unity_PACKAGE_FOLDER_RELEASE "/home/levent/.conan2/p/unity49ed08775f64e/p")
set(unity_BUILD_MODULES_PATHS_RELEASE )


set(unity_INCLUDE_DIRS_RELEASE "${unity_PACKAGE_FOLDER_RELEASE}/include"
			"${unity_PACKAGE_FOLDER_RELEASE}/include/unity")
set(unity_RES_DIRS_RELEASE )
set(unity_DEFINITIONS_RELEASE )
set(unity_SHARED_LINK_FLAGS_RELEASE )
set(unity_EXE_LINK_FLAGS_RELEASE )
set(unity_OBJECTS_RELEASE )
set(unity_COMPILE_DEFINITIONS_RELEASE )
set(unity_COMPILE_OPTIONS_C_RELEASE )
set(unity_COMPILE_OPTIONS_CXX_RELEASE )
set(unity_LIB_DIRS_RELEASE "${unity_PACKAGE_FOLDER_RELEASE}/lib")
set(unity_BIN_DIRS_RELEASE )
set(unity_LIBRARY_TYPE_RELEASE STATIC)
set(unity_IS_HOST_WINDOWS_RELEASE 0)
set(unity_LIBS_RELEASE unity)
set(unity_SYSTEM_LIBS_RELEASE )
set(unity_FRAMEWORK_DIRS_RELEASE )
set(unity_FRAMEWORKS_RELEASE )
set(unity_BUILD_DIRS_RELEASE )
set(unity_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(unity_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${unity_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${unity_COMPILE_OPTIONS_C_RELEASE}>")
set(unity_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${unity_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${unity_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${unity_EXE_LINK_FLAGS_RELEASE}>")


set(unity_COMPONENTS_RELEASE )