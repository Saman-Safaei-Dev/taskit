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

add_executable(taskit src/main.c src/app.c)
target_link_libraries(taskit PRIVATE PkgConfig::GTK4)
