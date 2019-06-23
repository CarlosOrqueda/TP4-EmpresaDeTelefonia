cmake_minimum_required(VERSION 3.14)
project(TP4_EmpresaDeTelefonia)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(TP4_EmpresaDeTelefonia
        .idea/misc.xml
        .idea/modules.xml
        .idea/TP4-EmpresaDeTelefonia.iml
        .idea/vcs.xml
        .idea/workspace.xml
        .gitignore
        Abb.cpp
        Abb.hpp
        abonable.hpp
        cliente.cpp
        cliente.hpp
        familia.cpp
        familia.hpp
        individuo.cpp
        individuo.hpp
        listadoClientes.csv
        main.cpp
        menu.cpp
        menu.hpp
        Nodo.hpp)
