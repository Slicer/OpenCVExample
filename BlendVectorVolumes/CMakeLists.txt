
#-----------------------------------------------------------------------------
set(MODULE_NAME BlendVectorVolumes)

#-----------------------------------------------------------------------------

#
# SlicerExecutionModel
#
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

#
# ITK
#
set(${PROJECT_NAME}_ITK_COMPONENTS
  ITKIOImageBase
  ITKSmoothing
  )
find_package(ITK 4.6 COMPONENTS ${${PROJECT_NAME}_ITK_COMPONENTS} REQUIRED)
set(ITK_NO_IO_FACTORY_REGISTER_MANAGER 1) # See Libs/ITKFactoryRegistration/CMakeLists.txt
include(${ITK_USE_FILE})

#-----------------------------------------------------------------------------
find_package(OpenCV 3.1 REQUIRED)

message(STATUS "Blend: OpenCV dir = ${OpenCV_DIR}")
get_filename_component(OpenCV_INCLUDE_DIR ${OpenCV_DIR}/../../include ABSOLUTE)
message(STATUS "Blend: OpenCV include dir = ${OpenCV_INCLUDE_DIR}")

set(MODULE_INCLUDE_DIRECTORIES
  ${OpenCV_INCLUDE_DIR}
  )

set(MODULE_SRCS
  BlendVectorVolumes.cxx
  )

message(STATUS "BlendVectorVolumes: OpenCV Libs = ${OpenCV_LIBS}")
set(MODULE_TARGET_LIBRARIES
  ${ITK_LIBRARIES}
  ${OpenCV_LIBS}
  )

#-----------------------------------------------------------------------------
SEMMacroBuildCLI(
  NAME ${MODULE_NAME}
  TARGET_LIBRARIES ${MODULE_TARGET_LIBRARIES}
  INCLUDE_DIRECTORIES ${MODULE_INCLUDE_DIRECTORIES}
  ADDITIONAL_SRCS ${MODULE_SRCS}
  )

#-----------------------------------------------------------------------------
if(BUILD_TESTING)
  add_subdirectory(Testing)
endif()
