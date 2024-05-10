add_library(DefinitionsLoader STATIC private/DefinitionsLoader.cpp)
target_include_directories(DefinitionsLoader PRIVATE public)

target_link_libraries(DefinitionsLoader PRIVATE sqlite Threads::Threads ${CMAKE_DL_LIBS})
target_include_directories(DefinitionsLoader PRIVATE inc/sqlite)