# Enable testing
enable_testing()

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

# Build library tests
file(GLOB LIB_TEST_SOURCES ./*.cpp)

# Add executable for library tests
add_executable(hotel_lib_tests ${LIB_TEST_SOURCES})

# Link library and GoogleTest to test executable
target_link_libraries(hotel_lib_tests
    PRIVATE
        hotel_lib
        GTest::gtest_main
)

# Auto-discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(hotel_lib_tests)