set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

set(SOURCES ${SOURCES})

add_executable(${BINARY} ${SOURCES})

target_include_directories(${BINARY} PRIVATE ${CMAKE_SOURCE_DIR}/include)


target_link_libraries(${BINARY} linenoise z)

# add_library(${BINARY}_lib STATIC ${SOURCES})