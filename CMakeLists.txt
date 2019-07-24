cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(dukkit-engine)

list(APPEND CMAKE_PREFIX_PATH "libs/libtorch")
find_package(Torch REQUIRED)

set(DUKKIT_ENGINE_SOURCES
	"src/Main.cpp"
	"src/RestfulServer.hpp"
	"src/Connection.hpp"
	"src/Connection.cpp"
	"src/Server.hpp"
	"src/Server.cpp")
add_executable(dukkit-engine ${DUKKIT_ENGINE_SOURCES})
target_link_libraries(dukkit-engine "${TORCH_LIBRARIES}")
set_property(TARGET dukkit-engine PROPERTY CXX_STANDARD 11)
