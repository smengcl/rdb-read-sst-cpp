cmake_minimum_required(VERSION 3.24)
project(rdb_read_sst_cpp)

set(CMAKE_CXX_STANDARD 23)

# brew install rocksdb
include_directories(/opt/homebrew/Cellar/rocksdb/7.8.3/include)
link_directories(/opt/homebrew/Cellar/rocksdb/7.8.3/lib)
# Ref: https://stackoverflow.com/a/28606916

add_executable(rdb_read_sst_cpp main.cpp)
target_link_libraries(rdb_read_sst_cpp rocksdb)
