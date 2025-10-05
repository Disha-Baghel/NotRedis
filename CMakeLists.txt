cmake_minimum_required(VERSION 3.15)

project(KVick VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(kvick_core STATIC
    src/kvick_core.cpp
)

add_executable(kvick_server src/main.cpp)
target_link_libraries(kvick_server PRIVATE kvick_core)

# 6️⃣ (Optional) Add kv_server and kv_tests later
# add_executable(kv_server src/main.cpp)
# add_executable(kv_tests tests/test_main.cpp)
