cmake_minimum_required(VERSION 2.8.9)

project(OpenCVExample)

#-----------------------------------------------------------------------------
# Extension meta-information
set(EXTENSION_HOMEPAGE "http://slicer.org/slicerWiki/index.php/Documentation/Nightly/Extensions/OpenCVExample")
set(EXTENSION_CATEGORY "Examples")
set(EXTENSION_CONTRIBUTORS "Nicole Aucoin (BWH)")
set(EXTENSION_DESCRIPTION "This is an example of an extension that depends on the SlicerOpenCV extension")
set(EXTENSION_ICONURL "https://raw.githubusercontent.com/nicole/OpenCVExample/master/OpenCVExample.png")
set(EXTENSION_SCREENSHOTURLS "")
set(EXTENSION_DEPENDS "SlicerOpenCV")

#-----------------------------------------------------------------------------
# Extension dependencies
find_package(Slicer REQUIRED)
include(${Slicer_USE_FILE})

# Add the CMake subdirectory which contains a FindSlicerOpenCV.cmake file that will help find the package automatically
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})

find_package(SlicerOpenCV REQUIRED)

#-----------------------------------------------------------------------------
# Extension modules
add_subdirectory(BlendVectorVolumes)
## NEXT_MODULE

#-----------------------------------------------------------------------------
include(${Slicer_EXTENSION_CPACK})
