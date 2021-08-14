cmake_minimum_required (VERSION 3.8)
project ("YourSQL")

include_directories ("../include/antlr4-cpp-runtime/")
get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}")

add_executable (yourSQL "YourSQL.cpp" "Functions.cpp" "StorageEngine.h" "Analysis.h" "Analysis.cpp")
add_executable (testStorageEngine "TestStorageEngine.cpp" "StorageEngine.cpp" "Functions.cpp")
