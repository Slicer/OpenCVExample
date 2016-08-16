#include "BlendVectorVolumesCLP.h"

#include <opencv2/opencv.hpp>

// Use an anonymous namespace to keep class types and function names
// from colliding when module is used as shared object module.  Every
// thing should be in an anonymous namespace except for the module
// entry point, e.g. main()
//
namespace
{
} // end of anonymous namespace


int main( int argc, char * argv[] )
{
  PARSE_ARGS;
  double beta;
  cv::Mat source1, source2, destination;

  std::cout << "alpha = " << alpha << std::endl;
  std::cout << "gamma = " << gamma << std::endl;
  beta = 1.0 - alpha;
  std::cout << "beta = " << beta << std::endl;
  std::cout << "inputVolume1 = " << inputVolume1.c_str() << std::endl;
  std::cout << "inputVolume2 = " << inputVolume2.c_str() << std::endl;
  std::cout << "outputVolume = " << outputVolume.c_str() << std::endl;

  // check if the input volumes were passed via shared memory pointer
  if (inputVolume1.find(std::string("slicer:")) != std::string::npos ||
      inputVolume2.find(std::string("slicer:")) != std::string::npos)
    {
    std::cerr << "Error:\n\tInput volume passed via shared memory pointer, unable to read with OpenCV imread.\n\tTurn on the Slicer option 'Prefer Executable CLIs' via the Edit, Application Settings, Modules panel.\n\tRestart Slicer and try again." << std::endl;
    return EXIT_FAILURE;
    }
  // read in the input images using the OpenCV image reader
  source1 = cv::imread(inputVolume1.c_str());
  if (!source1.data)
    {
    std::cerr << "Error reading input volume 1 " << inputVolume1.c_str() << std::endl;
    return EXIT_FAILURE;
    }

  source2 = cv::imread(inputVolume2.c_str());
  if (!source2.data)
    {
    std::cerr << "Error reading input volume 2 " << inputVolume2.c_str() << std::endl;
    return EXIT_FAILURE;
    }

  try
    {
    // do the blending
    cv::addWeighted(source1, alpha, source2, beta, gamma, destination);
    }
  catch (const cv::Exception& e)
    {
    std::cerr << "Error in addWeighted:\n\t" << e.what() << std::endl;
    return EXIT_FAILURE;
    }

  if (!destination.data)
    {
    std::cerr << "Error: no output from the blending!" << std::endl;
    return EXIT_FAILURE;
    }

  // write output
  if (!cv::imwrite(outputVolume.c_str(), destination))
    {
    std::cerr << "Failed to write output image " << outputVolume.c_str() << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
