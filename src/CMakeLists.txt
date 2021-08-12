cmake_minimum_required (VERSION 3.8)
project ("YourSQL")

include_directories(include)

add_executable (YourSQL "YourSQL.cpp" "Functions.cpp" "StorageEngine.cpp")
