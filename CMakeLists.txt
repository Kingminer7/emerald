cmake_minimum_required(VERSION 3.21)
project(Emerald VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} INTERFACE)

if (NOT EMERALD_SKIP_ACTIONS)
    target_sources(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/actions/SizeTo.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/actions/TextTo.cpp)
endif()

if (NOT EMERALD_SKIP_NODES)
    target_sources(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/nodes/DragButton.cpp)
endif()


target_include_directories(${PROJECT_NAME} INTERFACE include)

if (EMERALD_BUILD_TESTS)
    add_subdirectory(test)
endif()
