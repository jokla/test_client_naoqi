# In CMakeLists.txt

cmake_minimum_required(VERSION 2.8)
project(test_client)
find_package(qibuild)

include_directories(".")
qi_create_bin(client main.cpp)
qi_use_lib(client QI)
