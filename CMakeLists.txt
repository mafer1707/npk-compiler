cmake_minimum_required(VERSION 3.14)
project(npk-compiler VERSION 1.0 LANGUAGES CXX)

find_package(Designar QUIET)

if(NOT Designar_FOUND)
    message(STATUS "DeSiGNAR no está instalado. Descargándolo desde GitHub...")
    set(DESIGNAR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(DESIGNAR_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
    include(FetchContent)
    
    FetchContent_Declare(
        Designar
        GIT_REPOSITORY https://github.com/R3mmurd/DeSiGNAR.git
        GIT_TAG main 
    )
    
    FetchContent_MakeAvailable(Designar)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(npk_compiler ${SOURCES})

target_include_directories(npk_compiler PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(npk_compiler PRIVATE Designar::Designar)