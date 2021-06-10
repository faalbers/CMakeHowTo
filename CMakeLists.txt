# check version with "cmake --version" and fill it in
cmake_minimum_required(VERSION 3.20.2)

project(CMakeHowTo)

# Code block to also extract git submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodel was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    adder
    glfw
)
target_include_directories(${PROJECT_NAME}
    PUBLIC Adder
    PUBLIC external/glfw/include
)

# add Adder lib
add_subdirectory(Adder)

# add GLFW submodule
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Don't build docs")
add_subdirectory(external/glfw)
