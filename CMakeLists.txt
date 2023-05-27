cmake_minimum_required(VERSION 3.25)
project(Shop)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shop main.cpp Product.h Order.h OrderItem.h Warehouse.h ConsoleHelper.h)
