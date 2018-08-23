cmake_minimum_required(VERSION 3.12)
project(expo_9)

set(CMAKE_CXX_STANDARD 14)

find_package(dlib REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(
        expo_9
        main.cpp)

target_link_libraries(
        expo_9
        dlib::dlib
        ${ARMADILLO_LIBRARIES}
)

