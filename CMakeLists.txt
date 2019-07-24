cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(dukkit-engine)

list(APPEND CMAKE_PREFIX_PATH "libs/libtorch")
find_package(Torch REQUIRED)

list(APPEND CMAKE_PREFIX_PATH "libs")
list(APPEND CMAKE_MODULE_PATH "libs")
find_package(MsgpackLib REQUIRED)

include_directories("libs/${Msgpack_INCLUDE_DIRS}")
include_directories("${TORCH_INCLUDE_DIRS}")

set(DUKKIT_ENGINE_SOURCES
	"src/Main.cpp"
	"src/Connection.hpp"
	"src/Connection.cpp"
	"src/Server.hpp"
	"src/Server.cpp"
	"src/StringUtils.hpp"
	"src/UUID.hpp"
	"src/UUID.cpp")
add_executable(dukkit-engine ${DUKKIT_ENGINE_SOURCES})
target_link_libraries(dukkit-engine "${TORCH_LIBRARIES}" "${MSGPACK_LIBRARIES}")
set_property(TARGET dukkit-engine PROPERTY CXX_STANDARD 11)
