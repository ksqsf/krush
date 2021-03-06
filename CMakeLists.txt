cmake_minimum_required(VERSION 2.6)
project(krush)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FRAMEWORK_SOURCES
	framework.cpp
	graphics.cpp
	logger.cpp
	object.cpp
	overlay.cpp
	scene.cpp
)

# link with SDL2
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_image REQUIRED SDL2_image)
pkg_search_module(SDL2_ttf REQUIRED SDL2_ttf)

# cxxflags
include_directories("${PROJECT_SOURCE_DIR}" ${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS} ${SDL2_ttf_INCLUDE_DIRS})
add_definitions(-DDATA_PATH="${PROJECT_SOURCE_DIR}/data")
link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_image_LIBRARY_DIRS} ${SDL2_ttf_LIBRARY_DIRS})

# test
add_executable(tester bin/test.cpp ${FRAMEWORK_SOURCES})
target_link_libraries(tester ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_ttf_LIBRARIES})

# maze
add_executable(maze bin/maze.cpp ${FRAMEWORK_SOURCES})
target_link_libraries(maze ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_ttf_LIBRARIES})

# rush
add_executable(rush bin/rush.cpp ${FRAMEWORK_SOURCES})
target_link_libraries(rush ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_ttf_LIBRARIES})
