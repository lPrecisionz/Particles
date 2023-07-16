cmake_minimum_required(VERSION 3.0.0)
project(Particles VERSION 0.1.0 LANGUAGES C CXX)


# Set the SDL2 library path
set(SDL2_LIBRARY_PATH "C:\\Users\\pedro\\SDL2-devel-2.28.1-mingw\\SDL2-2.28.1\\x86_64-w64-mingw32\\lib")

# finding sdl package
set(SDL2_DIR "C:\\Users\\pedro\\SDL2-devel-2.28.1-mingw\\SDL2-2.28.1\\x86_64-w64-mingw32\\lib\\cmake\\SDL2")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})



file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(Particles ${SOURCES} ${HEADERS})

# Link SDL library
target_link_libraries(Particles ${SDL2_LIBRARIES})