cmake_minimum_required (VERSION 3.8)
project ("YourSQL")

include_directories(include)

add_executable (yourSQL "YourSQL.cpp" "Functions.cpp" "StorageEngine.h" "Analysis.h" "Analysis.cpp")
add_executable (testStorageEngine "TestStorageEngine.cpp" "StorageEngine.cpp" "Functions.cpp")
