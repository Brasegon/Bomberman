cmake_minimum_required(VERSION 3.11)
project("OOP_indie_studio_2019")
set(CMAKE_CXX_STANDARD 11)

# Call cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
# Set executable output path
if (WIN32)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
endif ()
# Set include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link libaries directories for Windows, MacOsX or Linux
# No way found to differenciate 32 and 64 for MacOsX and Linux...
if (WIN32)
    if (CMAKE_CL_64)
        link_directories(${CMAKE_SOURCE_DIR}/libs/win64)
    else (CMAKE_CL_64)
        link_directories(${CMAKE_SOURCE_DIR}/libs/win32)
    endif (CMAKE_CL_64)
endif (WIN32)

# Path to assets
set(ASSETS_PATH ${CMAKE_SOURCE_DIR}/assets/)

# Build type: Debug, RelWithDebInfo, MinSizeRel or Release
# Debug: print debug messages and use -g for valgrind
# RelWithDebInfo: print debug messages and don't use -g
# Release: no debug message and no -g
if (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
    set(CMAKE_CXX_FLAGS "-DASSETS_PATH=${ASSETS_PATH} -DWIN32 -EHsc")
else (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
    set(CMAKE_CXX_FLAGS "-DASSETS_PATH=${ASSETS_PATH} -W -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-deprecated -Wno-deprecated-copy")
endif (WIN32)

# Create executable
add_executable(bomberman
                src/Core/Core.cpp
                src/Core/Core.hpp
                src/Player/Player.cpp
                src/Player/Player.hpp
                src/Logger/Logger.cpp
                src/Logger/Logger.hpp
                src/my.hpp
                src/main.cpp)

# Find library package
find_package(Irrlicht 1.8.4 REQUIRED)
find_package(SFML 2.5.1 REQUIRED)

# Link external libaries to executable
if (UNIX)
    target_link_libraries(bomberman
            Irrlicht sfml-audio sfml-system
            GL Xxf86vm X11
            pthread)
else (UNIX)
    target_link_libraries(bomberman
            Irrlicht sfml-audio sfml-system)
endif (UNIX)


# Copy ddls if windows, else copy executable
if (WIN32)
    set(DLLS_FILES Irrlicht.dll openal32.dll sfml-audio-2.dll sfml-system-2.dll)
    if (CMAKE_CL_64)
        set(DLLS_PATH ${CMAKE_SOURCE_DIR}/libs/win64/)
    else (CMAKE_CL_64)
        set(DLLS_PATH ${CMAKE_SOURCE_DIR}/libs/win32/)
    endif (CMAKE_CL_64)
    foreach (file_i ${DLLS_FILES})
        add_custom_command(TARGET bomberman POST_BUILD
                COMMAND ${CMAKE_COMMAND}
                ARGS -E copy ${DLLS_PATH}${file_i} ${CMAKE_SOURCE_DIR}/)
    endforeach (file_i)
else (WIN32)
    add_custom_command(TARGET bomberman POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            ARGS -E copy bomberman ${CMAKE_SOURCE_DIR}/)
endif (WIN32)