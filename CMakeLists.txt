cmake_minimum_required(VERSION 3.14)
project(ClashOfClasses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Every .cpp in src/ is part of the game, so new files are picked up automatically.
file(GLOB SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(clash_of_classes ${SOURCES})

if(MSVC)
    target_compile_options(clash_of_classes PRIVATE /W4 /utf-8)
else()
    target_compile_options(clash_of_classes PRIVATE -Wall -Wextra)
endif()
