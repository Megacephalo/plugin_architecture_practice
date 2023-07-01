cmake_minimum_required(VERSION 3.2)

project(Plugin_Architecture_Practice)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

# Build plugins
add_subdirectory(src)

# Build applications
add_subdirectory(applications)