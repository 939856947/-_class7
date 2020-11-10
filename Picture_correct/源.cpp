#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat disMat;
	cv::Mat  gry_Mat;
	cv::Mat srcMat = cv::imread("D:\\1212.jpg", 1);
	cvtColor(srcMat, gry_Mat, COLOR_BGR2GRAY);
	int r[10] = { 0 };
	int height = srcMat.rows;
	int width = srcMat.cols;
	Point2f pst_1[4];

	//ÕÒ×óÉÏ½ÇµÄµã

	for (int i = 0; i <  width; i = i ++)
	{
		if (gry_Mat.at<uchar>(0, i)<250)
		{
			pst_1[0] = Point2f(i, 0);
			i = width;
		}

	}


	for (int j = width - 1; j >0; j--)
	{
		if (gry_Mat.at<uchar>(height - 1, j) <250)
			pst_1[1] = Point2f(static_cast<float>(j), static_cast<float>(height - 1)), j = 0;
	}


	for (int i = height - 1; i >0; i--)
	{
		if (gry_Mat.at<uchar>(i, 0) <250)
			pst_1[2] = Point2f(0, static_cast<float>(i)), i = 0;
	}


	for (int i = 0; i < height; i++)
	{
		if (gry_Mat.at<uchar>(i, width - 1) < 250)
			pst_1[3] = Point2f(static_cast<float>(width - 1), static_cast<float>(i)), i = height;
	}

	Point2f pst_2[4]{ Point2f(0,0),Point2f(static_cast<float>(width - 1),static_cast<float>(height - 1)),Point2f(0,static_cast<float>(height - 1)),Point2f(static_cast<float>(width - 1),0) };

	const Mat Matrix = cv::getPerspectiveTransform(pst_1, pst_2);
	cv::warpPerspective(srcMat, disMat, Matrix, srcMat.size());


	cv::imshow("srcMat", srcMat);
	cv::imshow("disMat", disMat);

	waitKey(0);
}
