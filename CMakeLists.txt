cmake_minimum_required(VERSION 3.0.0)
project(Particles VERSION 0.1.0 LANGUAGES C CXX)


# Set the SDL2 library path in case cmake doesn't find it
# uncomment with path if needed
#set(SDL2_LIBRARY_PATH "path/to/SDL2")

# finding sdl package
# uncomment with path if needed
# set(SDL2_DIR "path/to/SDL2")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(Particles ${SOURCES} ${HEADERS})

# Link SDL library
target_link_libraries(Particles ${SDL2_LIBRARIES})