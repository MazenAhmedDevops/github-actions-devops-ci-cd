cmake_minimum_required(VERSION 3.16)

project(HotelProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the hotel library (CMakeLists.txt inside hotel_lib/)
add_subdirectory(hotel_lib)

# Add the application (CMakeLists.txt inside Application/)
add_subdirectory(Application)