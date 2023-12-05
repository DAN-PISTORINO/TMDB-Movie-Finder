# UX ROOT
cmake_minimum_required(VERSION "3.27.6")
project(MF_Root C CXX)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/../Deps.cmake")
    set(IN_SOURCE_BUILD 1)
    set(SDK_ROOT "${CMAKE_BINARY_DIR}/SDK/")
    set(PORT UltralightWin)
    include(${CMAKE_CURRENT_LIST_DIR}/../Deps.cmake)
else ()
    set(IN_SOURCE_BUILD 0)
    set(SDK_ROOT "${CMAKE_CURRENT_LIST_DIR}/../")
endif ()

set(ULTRALIGHT_INCLUDE_DIR "${SDK_ROOT}/include")
set(ULTRALIGHT_BINARY_DIR "${SDK_ROOT}/bin")
set(ULTRALIGHT_INSPECTOR_DIR "${SDK_ROOT}/inspector")
set(ULTRALIGHT_RESOURCES_DIR "${SDK_ROOT}/resources")
set(ULTRALIGHT_LIBRARY_DIR "${SDK_ROOT}/lib")

#######################
# insertion add_subdirectory
set(APP_NAME MovieFinder)
include_directories("${ULTRALIGHT_INCLUDE_DIR}")
link_directories("${ULTRALIGHT_LIBRARY_DIR}")
link_libraries(UltralightCore AppCore Ultralight WebCore)

include_directories("${nlohmann_json_SOURCE_DIR}")
include_directories("${MINGW64_BIN}/include") 
link_directories("${MINGW64_BIN}" "${MINGW64_DIR}/lib")

include_directories("src" "assets" "bin")

link_libraries(nlohmann_json nlohmann_json::nlohmann_json)

set(SOURCES "src/MyApp.h"
            "src/MyApp.cpp"
            "src/RedBlackTree.cpp"
            "src/RedBlackTree.hpp"
            "src/SplayTree.hpp"
            "src/SplayTree.cpp"
)

# Includes
add_executable(${APP_NAME} WIN32 "main.cpp" "${SOURCES}")

# Tell MSVC to use main instead of WinMain for Windows subsystem executables
set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")

# Copy all binaries to target directory
add_custom_command(TARGET ${APP_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHT_BINARY_DIR}" $<TARGET_FILE_DIR:${APP_NAME}>)

# Set the assets path to "/assets" 
set(ASSETS_PATH "$<TARGET_FILE_DIR:${APP_NAME}>/assets") 

# Copy assets to assets directory
add_custom_command(TARGET ${APP_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/assets/" "${ASSETS_PATH}")

# Copy inspector to assets directory
add_custom_command(TARGET ${APP_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHT_INSPECTOR_DIR}" "${ASSETS_PATH}/inspector")

# Copy resources to assets directory
add_custom_command(TARGET ${APP_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHT_RESOURCES_DIR}" "${ASSETS_PATH}/resources")

# insertion exit
###################

if (${IN_SOURCE_BUILD})
    add_custom_target(
        CopySDK ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "${SDK_ROOT}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${SDK_ROOT}/bin"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${SDK_ROOT}/include"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${SDK_ROOT}/inspector"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${SDK_ROOT}/resources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHTCORE_DIR}/bin/" "${SDK_ROOT}/bin"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHTCORE_DIR}/include/" "${SDK_ROOT}/include"
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${SDK_ROOT}/include/Ultralight/private"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${WEBCORE_DIR}/bin/" "${SDK_ROOT}/bin"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${WEBCORE_DIR}/bin/resources" "${SDK_ROOT}/resources"
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${SDK_ROOT}/bin/resources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${WEBCORE_DIR}/include/" "${SDK_ROOT}/include"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${WEBCORE_DIR}/inspector/" "${SDK_ROOT}/inspector"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHT_DIR}/bin/" "${SDK_ROOT}/bin"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHT_DIR}/include/" "${SDK_ROOT}/include"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${APPCORE_DIR}/bin/" "${SDK_ROOT}/bin"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${APPCORE_DIR}/include/" "${SDK_ROOT}/include"
        DEPENDS UltralightCoreBin WebCoreBin UltralightBin AppCoreBin
    )

    add_custom_command(TARGET CopySDK POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${SDK_ROOT}/lib"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHTCORE_DIR}/lib/" "${SDK_ROOT}/lib"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${WEBCORE_DIR}/lib/" "${SDK_ROOT}/lib"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${ULTRALIGHT_DIR}/lib/" "${SDK_ROOT}/lib"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${APPCORE_DIR}/lib/" "${SDK_ROOT}/lib"
    )

    add_dependencies(${APP_NAME} CopySDK)
endif ()

