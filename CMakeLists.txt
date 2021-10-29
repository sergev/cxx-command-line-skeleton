cmake_minimum_required(VERSION 3.0)
project(myapp VERSION 1.0)

# Enable warnings, treat warnings as errors
set(CMAKE_CXX_FLAGS "-Wall -Werror")

# Pass version to the compiler, as a string
add_definitions(-DVERSION="${CMAKE_PROJECT_VERSION}")

add_executable(myapp
    skeleton.cpp
)

# Install to /usr/local/bin
install(TARGETS myapp DESTINATION bin)
