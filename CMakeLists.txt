cmake_minimum_required(VERSION 3.10)
project(xdb)

set(CMAKE_CXX_STANDARD 14)


include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/ext/linenoise
    ${CMAKE_SOURCE_DIR}/ext/libelfin
    ${CMAKE_SOURCE_DIR}/include
)
    
add_library(linenoise STATIC ext/linenoise/linenoise.c)

add_subdirectory(src)

# include_directories(src)
# target_include_directories(libelfin PUBLIC ${CMAKE_SOURCE_DIR}/ext/libelfin)


# add_subdirectory(src)
# add_subdirectory(tests)
# add_subdirectory(lib/googletest)