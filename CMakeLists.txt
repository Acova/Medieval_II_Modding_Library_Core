# Basic configuration
cmake_minimum_required(VERSION 3.10)
project(miimlc VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# External libraries
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(sqlite STATIC inc/sqlite/sqlite3.c)
include_directories(BEFORE inc/sqlite src/domain/ModRW/public src/infrastructure/DefinitionsLoader/public)

add_executable(miimlc main.cpp)
add_subdirectory(src/)
target_link_libraries(miimlc PRIVATE ModReader)
target_include_directories(miimlc 
    PUBLIC "${PROJECT_BINARY_DIR}" src/application/ModRW/public ${PROJECT_BINARY_DIR}/generated/
)