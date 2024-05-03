# add_subdirectory(infrastructure/ModRW)
add_library(ModReader application/ModRW/private/ModReader.cpp)
target_include_directories(ModReader PRIVATE application/ModRW/public)
include_directories(domain/ModRW/public)