cmake_minimum_required(VERSION 3.22)
project(LekaController VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TARGET_SRC "./src/*.cpp" )
file(GLOB TARGET_TEST "./src/*.cc" )

add_executable(leka_ctrl ${TARGET_SRC})
add_executable(leka_test ${TARGET_TEST})

# target_include_directories(leka_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR/../build/CMakeFiles/main.dir/src/})

target_link_libraries(
    leka_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(leka_test)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

