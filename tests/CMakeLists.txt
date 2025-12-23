# Enable FetchContent module to download GoogleTest
include(FetchContent)

# Download GoogleTest automatically
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Ensure proper runtime linkage on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make GoogleTest available as targets
FetchContent_MakeAvailable(googletest)

# Add executable for app tests
add_executable(HotelAppTests 
    test_main.cpp
)

# Link library and GoogleTest to test executable for the App
target_link_libraries(HotelAppTests
    PRIVATE
        hotel_lib
        GTest::gtest_main
)

# Auto-discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(HotelAppTests)




