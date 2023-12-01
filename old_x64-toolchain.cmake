cmake_minimum_required(VERSION 3.10)

# Set the C and C++ compilers to the MinGW-w64 x64 executables
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

# Set the linker to the MinGW-w64 x64 executable
set(CMAKE_LINKER "C:/msys64/mingw64/bin/ld.exe")

# Set the appropriate runtime libraries
set(CMAKE_RUNTIME_LIBRARY_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib64")
set(CMAKE_FIND_LIBRARY_PATHS "${CMAKE_INSTALL_PREFIX}/lib64")

# Set the architecture to x64
set(CMAKE_ARCH_x64 1)

# Set the system name to MinGW-w64 x64
set(CMAKE_SYSTEM_NAME "Windows")