cmake_minimum_required(VERSION 3.1...3.22)

project(
    graphics
    VERSION 0.1.0
    DESCRIPTION "Mi proyecto con C++"
    LANGUAGES CXX
)

# Agregando archivos .lib
link_directories(${CMAKE_SOURCE_DIR}/freeglut/lib)

# Agregando archivo de fuentes
file(GLOB_RECURSE SOURCE_FILES
${CMAKE_SOURCE_DIR}/src/*.c 
${CMAKE_SOURCE_DIR}/src/*.cpp
)

#Agregando archivos de cabeceras
file(GLOB_RECURSE HEADER_FILES
${CMAKE_SOURCE_DIR}/src/*.h 
${CMAKE_SOURCE_DIR}/src/*.hpp
)

#Requiere construir fuera de la fuente
# file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
# if(EXISTS "${LOC_PATH}")
#     message(FATAL_ERROR "Tu no puedes construir en el directorio fuente (O ningun directorio con un archivo CMakeLists.txt")
# endif(EXISTS "${LOC_PATH}")


# Configurar activos del archivo cabecera
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/helpers/RootDir.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/helpers/RootDir.h)
include_directories(${CMAKE_BINARY_DIR}/src)
include_directories(${CMAKE_BINARY_DIR}/src/entity)

# Definir los ejecutables
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
#add_executable(graphics main.cpp)

# Para encontrar dependencias externas con CMAKE_DIR
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Inclusion de paquetes requeridos
#OpenGL
find_package(OpenGL REQUIRED)
# FREEGLUT
find_package(GLUT REQUIRED)
message(STATUS "Encontrado FreeGlut en ${GLUT_INCLUDE_DIR}")

#GLEW
find_path(GLEW_INCLUDE_DIR GL/glew.h)
find_library(GLEW_LIBRARY NAMES GLEW glew32 glew glew32s PATH_SUFFIXES lib64)
find_package(GLEW REQUIRED)
message(STATUS "Encontrado GLEW en ${GLEW_INCLUDE_DIR}")

# Threads
find_package(Threads REQUIRED)

add_library(libfreeglut_obj OBJECT ${CMAKE_SOURCE_DIR}/lib/)
target_link_libraries(libfreeglut_obj PUBLIC OpenGL::GL GLUT::GLUT GLEW::GLEW Threads::Threads)
set_target_properties(libfreeglut_obj PROPERTIES LINKER_LAGUAGE CXX)

#Poner todas las librerias dentro de una variable
set(LIBS ${GLUT_LIBRARY} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

# Definir los include DIRs
include_directories(
    "${CMAKE_SOURCE_DIR}/lib/"
    "${CMAKE_SOURCE_DIR}/bin/"
    "${CMAKE_SOURCE_DIR}/include/"
    "${CMAKE_SOURCE_DIR}/include/GL/"
)

# Definir los vinculos de las librerias
target_link_libraries(${PROJECT_NAME} ${LIBS})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)