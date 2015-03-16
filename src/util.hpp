#include "opencv2/opencv.hpp"

using namespace cv;

void showImage(const char* title, const Mat& img)
{
	std::cout << "Showing image: \"" << title << "\"." << std::endl;
	namedWindow(title, CV_WINDOW_NORMAL);
	imshow(title, img);
}

void showImageAndWait(const char* title, const Mat& img)
{
	showImage(title, img);
	std::cout << "Press any key to continue..." << std::endl;
	waitKey(0);
}
