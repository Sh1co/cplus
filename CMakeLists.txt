cmake_minimum_required(VERSION 3.0)

project(cplus LANGUAGES CXX)

find_package(FLEX)
find_package(BISON)
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# automatically put the built compiler at the root of the project
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

FLEX_TARGET(MyScanner lexer.l  ${CMAKE_BINARY_DIR}/lexer.cpp)
BISON_TARGET(MyParser parser.y ${CMAKE_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

set(HEADERS "shell.hpp" "lexer.h" "ast.hpp" "type_checker.hpp" "llvm.hpp")

set(SOURCES "main.cpp" "shell.cpp" "type_checker.cpp" "llvm.cpp")

add_executable(cplus ${HEADERS} ${SOURCES} ${BISON_MyParser_OUTPUTS} ${FLEX_MyScanner_OUTPUTS})

llvm_map_components_to_libnames(llvm_libs support core irreader)

target_compile_features(cplus PUBLIC cxx_std_17)

# disable warnings
target_compile_options(cplus PRIVATE "-Wno-inconsistent-missing-override")
target_compile_options(cplus PRIVATE "-Wno-switch")

target_include_directories(cplus PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})

target_link_libraries(cplus ${llvm_libs})

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT cplus)
