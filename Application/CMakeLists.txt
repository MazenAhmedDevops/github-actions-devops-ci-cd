# Build the CLI application
add_executable(hotel_app
    src/main.cpp
)

# Include headers
target_include_directories(hotel_app
    PRIVATE
        include
        ${PROJECT_SOURCE_DIR}/hotel_lib/include
)

# Link the library
target_link_libraries(hotel_app
    PRIVATE hotel_lib
)

# Add library tests (subdirectory)
add_subdirectory(tests)