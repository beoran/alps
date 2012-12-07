cmake_minimum_required(VERSION 2.8)
# Set policy: link_directories is relative to source dir
cmake_policy(SET CMP0015 NEW)

# Set the project name.
project(ALPS C)

# Tell CMake to search first in the cmake subdirectory for FIND_PACKAGE() or INCLUDE().
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

include(CheckCSourceCompiles)
include(CheckCXXSourceCompiles)

if(CMAKE_COMPILER_IS_GNUCC)
 set(COMPILER_GCC 1)
set(CMAKE_C_FLAGS "-Wall -Wno-unused -Wno-unknown-pragmas -g -std=gnu99 -ffast-math")  
# always use gnu99, debugging, all warnings except unused and unknown pragmas.
# when compiling with gnu compiler    
endif(CMAKE_COMPILER_IS_GNUCC)

# or for PCC
# set(CMAKE_C_FLAGS "-fpic -fPIC")  

# Find the needed packages.
# find_package(Mruby REQUIRED)
find_package(Chipmunk REQUIRED)
find_package(Allegro50 REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

# Set include and lib dirs. 
include_directories(${ALLEGRO_INCLUDE_DIR} ${PNG_INCLUDE_DIR} ${JPEG_INCLUDE_DIR} ${MRUBY_INCLUDE_DIR} ${CHIPMUNK_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR})

set(ALPS_LIBS ${LIBS} ${ALLEGRO_LIBRARIES} ${PNG_LIBRARY} ${JPEG_LIBRARY} ${MRUBY_LIBRARIES} ${CHIPMUNK_LIBRARIES} ${LIBXML2_LIBRARIES})

include_directories("include")
include(AlpsFiles)


# Alps exe in the bin subdir (first one should work, but doesnt, hmmm...)
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
# Compile all files except main
add_library(ALPS_OBJECTS OBJECT ${ALPS_SRC_FILES})
# Alps test exectable
add_executable(alps $<TARGET_OBJECTS:ALPS_OBJECTS> src/main.c)
target_link_libraries(alps ${ALPS_LIBS})
