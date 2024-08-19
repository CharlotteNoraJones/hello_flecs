cmake_minimum_required(VERSION 3.14)

project(HelloFlecs VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)
set(FETCHCONTENt_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    flecs
    GIT_REPOSITORY "https://github.com/SanderMertens/flecs"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(flecs)
FetchContent_MakeAvailable(raylib)

add_executable(HelloFlecs src/main.cpp)

if (MSVC)
    target_compile_options(HelloFlecs PRIVATE /W4 /Wall /WX)
else()
    target_compile_options(HelloFlecs PRIVATE -Wall -Wextra -Werror -pedantic )
endif()

set_target_properties(HelloFlecs PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)

target_link_libraries(HelloFlecs PRIVATE flecs::flecs_static)
target_link_libraries(HelloFlecs PRIVATE raylib)