cmake_minimum_required(VERSION 3.5)
project(IA_TRAB1 VERSION 0.1 LANGUAGES CXX)

# set the compiling flags

#-ansi
#-Ofast
add_compile_options(
  -g
  -Wall -Werror
  -Wextra
  -Wpedantic
  -fsanitize=address,undefined
  -lm
)

add_link_options(-fsanitize=address,undefined)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 17)
#--------------------------------

### [1] Application target
## configura o diretório contendo os .hpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(trab1)

target_sources(
  trab1
  PRIVATE
    src/main.cpp
)
