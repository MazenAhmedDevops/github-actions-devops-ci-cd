cmake_minimum_required(VERSION 3.16)

project(HotelProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing globally (required for ctest)
enable_testing()

# Add the hotel library (CMakeLists.txt inside hotel_lib/)
add_subdirectory(hotel_lib)

# Create the main application
add_executable(hotel_app
    Application/main.cpp
)

# Link the hotel library to the app
target_link_libraries(hotel_app PRIVATE hotel_lib)

# Add app tests as a subdirectory (TBD)
#add_subdirectory(tests)