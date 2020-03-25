cmake_minimum_required(VERSION 3.15)
project(program4)

set(CMAKE_CXX_STANDARD 14)

add_executable(program4 main.cpp Inventory.cpp Inventory.h Business.cpp Business.h Customer.cpp Customer.h HashTable.cpp HashTable.h Movie.cpp Movie.h MovieFactory.cpp MovieFactory.h Transaction.cpp Transaction.h Utility.cpp Utility.h)