cmake_minimum_required(VERSION 3.15)

# project name and language
project(Inventory LANGUAGES CXX)

# Add executable
add_executable(inventory main.cpp database.cpp communication.cpp)

# Find SQLite
find_package(SQLite3 REQUIRED)

# Include directories
target_include_directories(inventory PRIVATE ${SQLite3_INCLUDE_DIRS})

# Link libraries
target_link_libraries(inventory PRIVATE ${SQLite3_LIBRARIES})
