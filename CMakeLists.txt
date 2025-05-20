cmake_minimum_required(VERSION 3.30)
project(taskit)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to \
`${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE
  STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message(STATUS "myProject Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for myProject
set(taskit_Version_Major 0)
set(taskit_Version_Minor 1)
set(taskit_Version_Patch 0)
set(taskit_Version_Status "dev")

set(PROJECT_VERSION
"${taskit_Version_Major}\
.${taskit_Version_Minor}.\
${taskit_Version_Patch}-\
${taskit_Version_Status}"
)

message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

# GLIB_COMPILE_RESOURCES --- STR ----------------------------------------------
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

set(GRESOURCE_C   taskit.gresource.c)
set(GRESOURCE_XML taskit.gresource.xml)

add_custom_command(
    OUTPUT ${GRESOURCE_C}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS
      --generate-source ${GRESOURCE_XML}
      --target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
    VERBATIM
    MAIN_DEPENDENCY ${GRESOURCE_XML}
    DEPENDS
      taskit.gresource.xml
      assets/window.ui
      assets/styles.css
)

add_custom_target(
  taskit-resources
  DEPENDS
  ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)

# GLIB_COMPILE_RESOURCES --- END ----------------------------------------------

# EXECUTABLE --- STR ----------------------------------------------------------

add_executable(taskit
  src/main.c
  src/app.c
  src/win.c
  ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)

target_link_libraries(taskit PRIVATE PkgConfig::GTK4)
add_dependencies(taskit taskit-resources)

# EXECUTABLE --- END ----------------------------------------------------------
