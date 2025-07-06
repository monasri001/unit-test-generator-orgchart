cmake_minimum_required(VERSION 3.5)
project(org_chart_test CXX)

# Find all test source files matching test_*.cc
file(GLOB TEST_SOURCES "test_*.cc")

# Define the test executable
add_executable(${PROJECT_NAME}
    ${TEST_SOURCES}
)

# Link against Google Test and Drogon
target_link_libraries(${PROJECT_NAME}
    gtest
    gtest_main
    pthread
    drogon
)

# Optional: If using Drogon-style test discovery (can be removed if not needed)
# ParseAndAddDrogonTests(${PROJECT_NAME})

