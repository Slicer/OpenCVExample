message(STATUS "FindSOCV: OpenCVExample binary dir = ${OpenCVExample_BINARY_DIR}")

# For the Slicer dashboard, the build directories should be at the same level.
# For local development, they might be in subdirs collecting the source and build dirs, or just one might be in a subdir
set(SOCV_CONFIG_PATHS
        ${OpenCVExample_BINARY_DIR}/../SlicerOpenCV-build/inner-build
        ${OpenCVExample_BINARY_DIR}/../../OpenCV/SlicerOpenCV-build-release/inner-build
        ${OpenCVExample_BINARY_DIR}/../OpenCV/SlicerOpenCV-build-release/inner-build
)

find_file(
        SLICEROPENCV_CONFIG_FILE
        SlicerOpenCVConfig.cmake
        PATHS ${SOCV_CONFIG_PATHS}
        DOC "The path to the SlicerOpenCVConfig.cmake file"
         )
message(STATUS "FindSOCV: SLICEROPENCV_CONFIG_FILE = ${SLICEROPENCV_CONFIG_FILE}")
include(${SLICEROPENCV_CONFIG_FILE})
message(STATUS "FindSOCV: SlicerOpenCV_DIR set to = ${SlicerOpenCV_DIR}")

