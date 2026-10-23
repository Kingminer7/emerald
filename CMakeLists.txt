cmake_minimum_required(VERSION 3.21)
project(Emerald VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} INTERFACE)

option(EMERALD_SKIP_ACTIONS "If Emerald should skip building actions." OFF)
option(EMERALD_SKIP_NODES "If Emerald should skip building nodes." OFF)
option(EMERALD_SKIP_UTILS "If Emerald should skip building utils." OFF)
option(EMERALD_ADD_UIBUILDER "If Emerald should add UIBuilder." ON)

if (NOT EMERALD_SKIP_ACTIONS)
    file(GLOB_RECURSE ACTIONS CONFIGURE_DEPENDS src/actions/*.cpp)
    target_sources(${PROJECT_NAME} INTERFACE ${ACTIONS})
endif()

if (NOT EMERALD_SKIP_NODES)
    file(GLOB_RECURSE NODES CONFIGURE_DEPENDS src/nodes/*.cpp)
    target_sources(${PROJECT_NAME} INTERFACE ${NODES})
endif()

if (NOT EMERALD_SKIP_UTILS)
    file(GLOB_RECURSE UTILS CONFIGURE_DEPENDS src/utils/*.cpp)
    target_sources(${PROJECT_NAME} INTERFACE ${UTILS})
endif()

target_include_directories(${PROJECT_NAME} INTERFACE include)

if (EMERALD_BUILD_TESTS)
    add_subdirectory(test)
endif()

if (EMERALD_ADD_UIBUILDER)
    set(UIBUILDER_VERSION "main" CACHE STRING "What UIBuilder version to download and use")
    CPMAddPackage("gh:camila314/uibuilder#${UIBUILDER_VERSION}")
    target_link_libraries(${PROJECT_NAME} INTERFACE UIBuilder)
endif()