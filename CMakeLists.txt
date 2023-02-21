project(aed C CXX)

file(GLOB_RECURSE src *.cc)
file(GLOB_RECURSE headers *.h)

include_directories(.)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(aed ${src})
