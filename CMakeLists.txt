cmake_minimum_required(VERSION 3.30)
project(rm_stubs)

set(CMAKE_CXX_STANDARD 26)

add_executable(rm_stubs main.cpp)

# Custom target for cppcheck run
find_program(CPPCHECK cppcheck)
if (CPPCHECK)
    add_custom_target(cppcheck
                      COMMAND ${CPPCHECK} --enable=all --suppress=missingIncludeSystem --force ${CMAKE_SOURCE_DIR}/main.cpp
                      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                      COMMENT "Running cppcheck"
    )
else ()
    message(WARNING "cppcheck not found. 'make check' target will not be available.")
endif ()