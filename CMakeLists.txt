cmake_minimum_required(VERSION 3.13)
project(grandmaTD)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
	grandmaTD
	src/main.cpp
	src/Logger.cpp
	include/Logger.hpp
	src/Screen.cpp
	include/Screen.hpp
	src/Mob.cpp
	include/Mob.hpp
	src/Tower.cpp
	include/Tower.hpp
	src/Map.cpp
	include/Map.hpp
)

target_link_libraries(
	grandmaTD
	sfml-window
	sfml-system
	sfml-graphics
)
