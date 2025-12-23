#library code
add_library(hotel_lib
    src/Hotel.cpp
    src/HotelRoom.cpp
)

# Include directory for public headers
target_include_directories(hotel_lib PUBLIC include)

# Add library tests (subdirectory)
add_subdirectory(tests)