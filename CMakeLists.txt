

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#About this project
#----------------------------------
PROJECT(EGE)
SET(VERSION_MAJOR "2")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

SET(EGE_TARGET_OS "WIN64")
SET(EGE_TARGET_OS "OSX")
SET(EGE_TARGET_OS "WEBGL")
SET(EGE_TARGET_OS "LINUX")

SET(EGE_TARGET_OS "WIN64")


if(${EGE_TARGET_OS} STREQUAL "LINUX" OR ${EGE_TARGET_OS} STREQUAL "OSX" OR ${EGE_TARGET_OS} STREQUAL "WEBGL")
    SET(EGE_GRAPHIC_MODE "GLFW3")
endif()
if(${EGE_TARGET_OS} STREQUAL "WIN64")
    SET(EGE_GRAPHIC_MODE "DirectX")
    SET(EGE_GRAPHIC_MODE "GLFW3")      # still OpenGL also for Windows ?
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
    set(actualLibName "     (1.1) GLFW3")
    if(GLFW3_LIB)
        message(${actualLibName} ${libOkMessage})
        include_directories(${glfw3_INCLUDE_DIRS})
        set(LIBS ${LIBS} ${glfw3_LIBRARIES})
    else()
        message(${actualLibName} ${libBadMessage})
    endif()
endif()
message(" (1) END of Library dependencies test -------------------------------------------------------------- }\n")




