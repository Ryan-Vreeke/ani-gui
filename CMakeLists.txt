cmake_minimum_required(VERSION 3.10)
project(ani-gui)

# Find GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

find_package(CURL REQUIRED)

# Compiler options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${GTKMM_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)
link_directories(${GTKMM_LIBRARY_DIRS} ${CURL_LIBRARY_DIRS})


# Source files
set(SOURCES src/main.cpp src/MyWindow.cpp)
set(HEADERS includes/MyWindow.h)

# Executable
add_executable(ani-gui ${SOURCES} ${HEADERS})

# Link GTKMM
target_include_directories(ani-gui PRIVATE includes)
target_link_libraries(ani-gui ${GTKMM_LIBRARIES} ${CURL_LIBRARIES})
