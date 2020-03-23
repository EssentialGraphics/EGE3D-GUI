CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#About this project
#----------------------------------
PROJECT(EGE)
SET(VERSION_MAJOR "2")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
SET(PROGRAM_NAME "tester")

SET(EGE_TARGET_OS "WIN64")
SET(EGE_TARGET_OS "OSX")
SET(EGE_TARGET_OS "WEBGL")
SET(EGE_TARGET_OS "LINUX")

SET(EGE_TARGET_OS "WIN64")


if(${EGE_TARGET_OS} STREQUAL "LINUX" OR ${EGE_TARGET_OS} STREQUAL "OSX" OR ${EGE_TARGET_OS} STREQUAL "WEBGL")
    SET(EGE_GRAPHIC_MODE "GLFW3")
endif()
if(${EGE_TARGET_OS} STREQUAL "WIN64")
    # SET(EGE_GRAPHIC_MODE "DirectX")
    SET(EGE_GRAPHIC_MODE "GLFW3")      # still OpenGL also for Windows ? Hope NOT
endif()

message("                                          ******* EGE 2D/3D [v"  ${VERSION}  "] *******")
message("                                   - Target host operating system : " ${EGE_TARGET_OS})
message("                                   - Graphic mode (directx/opengl): " ${EGE_GRAPHIC_MODE} "\n")

message(" (1) BEGIN Library dependencies test { ------------------------------------------------------------- >>>")

# Common console output messages
set(libOkMessage " : Library found - OK" )
set(libBadMessage " : Library NOT found --------- >>>> CRITICAL ERROR !" )

if((${EGE_GRAPHIC_MODE} STREQUAL "GLFW3"))
    # GLFW3-3.3.2
    find_library(GLFW3_LIB glfw3 REQUIRED)
    set(actualLibName "     (1.1) GLFW3 : ")
    if(GLFW3_LIB)
	    message(${actualLibName} ${libOkMessage} "	<" ${GLFW3_LIB} ">")
    else()
        message(${actualLibName} ${libBadMessage})
    endif()
endif()

if((${EGE_TARGET_OS} STREQUAL "OSX"))
    # OpenGL
    find_library(OPENGL_LIB OpenGL REQUIRED)
    set(actualLibName "     (2.1) OPENGL")
    if(OPENGL_LIB)
        message(${actualLibName} ${libOkMessage})
    else()
        message(${actualLibName} ${libBadMessage})
    endif()

    # Cocoa
    find_library(COCOA_LIB Cocoa REQUIRED)
    set(actualLibName "     (2.2) Cocoa")
    if(COCOA_LIB)
        message(${actualLibName} ${libOkMessage})
    else()
        message(${actualLibName} ${libBadMessage})
    endif()

    #IOKit
    find_library(IOKIT_LIB IOKit REQUIRED)
    set(actualLibName "     (2.3) IOKit")
    if(IOKIT_LIB)
        message(${actualLibName} ${libOkMessage})
    else()
        message(${actualLibName} ${libBadMessage})
    endif()
endif()

message(" (1) END of Library dependencies test -------------------------------------------------------------- }\n")

INCLUDE_DIRECTORIES(${CMAKE_SYSTEM_PREFIX_PATH})
LINK_DIRECTORIES(${CMAKE_SYSTEM_LIBRARY_PATH})    
SET (CMAKE_C_FLAGS "-std=c++11 -w -g")			#-std=c++17 -w -Wall -Wno-c++17-extensions
SET (CMAKE_CXX_FLAGS "-std=c++11 -w -g")			# -std=c++17 -w -Wall -Wno-c++17-extensions
	
if(${EGE_TARGET_OS} STREQUAL "LINUX" OR ${EGE_TARGET_OS} STREQUAL "WEBGL")
	SET(CMAKE_C_COMPILER /usr/bin/g++)
	SET(CMAKE_CXX_COMPILER /usr/bin/g++)
	ADD_EXECUTABLE(${PROGRAM_NAME} main.cpp )
    TARGET_LINK_LIBRARIES(${PROGRAM_NAME} stdc++ m dl pthread glfw3 X11)
endif()

if(${EGE_TARGET_OS} STREQUAL "WIN64")
	SET(GLFW3_LIB_COPIED "C:/Users/Giovanni/Desktop/egex")					# Moved to other folder due to SPACE LINK ERROR
	INCLUDE_DIRECTORIES("C:/Program Files (x86)/GLFW/include")
	
	ADD_EXECUTABLE(${PROGRAM_NAME} main.cpp )
	TARGET_LINK_LIBRARIES(${PROGRAM_NAME} -L${GLFW3_LIB_COPIED} libglfw3.a)
endif()

if(${EGE_TARGET_OS} STREQUAL "OSX")
	SET(CMAKE_C_COMPILER /usr/bin/clang)
	SET(CMAKE_CXX_COMPILER /usr/bin/clang)
	ADD_EXECUTABLE(${PROGRAM_NAME} main.cpp )
	TARGET_LINK_LIBRARIES(${PROGRAM_NAME} stdc++ m dl pthread glfw3 "-framework Cocoa" "-framework IOKit" "-framework OpenGL" )
endif()
