cmake_minimum_required(VERSION 3.10.0)
project(pdb)

file(GLOB_RECURSE SHARED_C_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/shared/source/*.c")
set(SHARED_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/shared/source/")
add_library(shared STATIC ${SHARED_C_SOURCE_FILES})
target_include_directories(shared PUBLIC ${SHARED_INCLUDE_DIRS})
set_target_properties(shared PROPERTIES C_STANDARD 17 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
if(NOT MSVC)
    target_compile_options(shared PRIVATE -Wall -Wextra -Wshadow)
endif()

file(GLOB_RECURSE PDB_C_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/pdb/source/*.c")
set(PDB_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/pdb/source/")
add_library(pdb ${PDB_C_SOURCE_FILES})
target_include_directories(pdb PRIVATE ${PDB_INCLUDE_DIRS} ${SHARED_INCLUDE_DIRS})
target_link_libraries(pdb shared)
set_target_properties(pdb PROPERTIES C_STANDARD 17 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
if(NOT MSVC)
    target_compile_options(pdb PRIVATE -Wall -Wextra -Wshadow)
endif()

file(GLOB_RECURSE DUMPER_C_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/dumper/source/*.c")
set(DUMPER_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/dumper/source/")
add_executable(dumper ${DUMPER_C_SOURCE_FILES})
target_include_directories(dumper PRIVATE ${DUMPER_INCLUDE_DIRS} ${PDB_INCLUDE_DIRS} ${SHARED_INCLUDE_DIRS})
target_link_libraries(dumper pdb shared)
set_target_properties(dumper PROPERTIES C_STANDARD 17 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
if(NOT MSVC)
    target_compile_options(dumper PRIVATE -Wall -Wextra -Wshadow)
endif()
