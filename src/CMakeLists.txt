add_library(ModReader STATIC application/ModRW/private/ModReader.cpp)
target_include_directories(ModReader PRIVATE application/ModRW/public)

add_subdirectory(infrastructure/DefinitionsLoader/)

target_link_libraries(ModReader PRIVATE DefinitionsLoader)
target_include_directories(ModReader PRIVATE infrastructure/DefinitionsLoader/public)
