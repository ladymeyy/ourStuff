#include <cv.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat image;
	Mat grayScale;

	if (argc != 2)
	{
		printf("No image argument \n");
		return -1;
	}
	image = imread("/home/physics/workspace/displayImage/Debug/net2.jpg", 1);

	if (!image.data)
	{
		printf("No image data \n");
		return -1;
	}

	cvtColor(image, grayScale, COLOR_BGR2GRAY);

	Mat imageBW;

	threshold(grayScale, imageBW, 128.0, 255.0, THRESH_BINARY);
	namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	bitwise_not(imageBW,imageBW);
	imshow("B-W Image", imageBW);

	Mat dst, cdst;
	//Canny(image, dst, 50, 200, 3); //original
//	Canny(image, dst, 200, 50, 3);
//	imshow("Canny Image", dst);
//	cvtColor(dst, cdst, CV_GRAY2BGR);
#if 0
	vector<Vec2f> lines;
	HoughLines(dst, lines, 1, CV_PI / 180, 100, 0, 0);

	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, CV_AA);
	}
#else
	vector<Vec4i> lines;
	  HoughLinesP(imageBW, lines, 5, CV_PI/180, 100, 50, 10 );
	  for( size_t i = 0; i < lines.size(); i++ )
	  {
	    Vec4i l = lines[i];
	    line( image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,255,255), 3, CV_AA);
	  }
#endif
//	namedWindow("Display Image_grayscale", CV_WINDOW_AUTOSIZE);
//	imshow("Display Image_grayscale", grayScale);

	imshow("detected lines", image);

	waitKey(0);
	destroyAllWindows();
	return 0;
}
