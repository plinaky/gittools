cmake_minimum_required(VERSION 3.5)

project(clean_submodules)

# Recherche de la bibliothèque libgit2
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBGIT2 REQUIRED libgit2)

set(CMAKE_GENERATOR "Ninja")
set(CMAKE_C_COMPILER "clang")

# Inclure les fichiers d'en-tête de libgit2
include_directories(${LIBGIT2_INCLUDE_DIRS})

#add_library(clean_submodules OBJECT clean_submodules.c)
add_executable(clean_submodules clean_submodules.c)
target_compile_definitions(clean_submodules PRIVATE TEST_CLEAN_SUBMODULES)

# Spécifier le chemin de recherche des bibliothèques avec rpath lors de l'installation
set(CMAKE_INSTALL_RPATH "$ORIGIN;/usr/local/lib")


#cmake -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ..

target_include_directories(clean_submodules PUBLIC clean_submodules.h)
message(${LIBGIT2_LIBRARIES})
target_link_libraries(clean_submodules ${LIBGIT2_LIBRARIES})

install(TARGETS clean_submodules DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

