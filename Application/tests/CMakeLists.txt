# Enable testing
enable_testing()

# Fetch GoogleTest (reuse same settings as library)
file(GLOB APP_TEST_SOURCES ./*.cpp)

# Add executable for app tests
add_executable(hotel_app_tests ${APP_TEST_SOURCES})

target_compile_definitions(hotel_app_tests
    PRIVATE APP_EXECUTABLE_PATH="$<TARGET_FILE:hotel_app>"
)

# Link library and GoogleTest to test executable for the App
target_link_libraries(hotel_app_tests
    PRIVATE
        hotel_lib
        GTest::gtest_main
)

# Auto-discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(hotel_app_tests)