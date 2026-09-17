cmake_minimum_required(VERSION 3.8)
project(AlphaX_Tests)

find_package(Boost REQUIRED)

add_executable(alpha_x alpha_x.cpp alpha_x_test.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET alpha_x PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(alpha_x PRIVATE ${Boost_INCLUDE_DIRS})