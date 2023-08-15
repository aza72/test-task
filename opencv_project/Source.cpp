#include <iostream>

#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{
	Mat img= imread("C:/Users/1/Desktop/opencv/j1.jpg");
	Mat grayimg, blurred, thresholded,contr;
	if (img.empty())
	{
		cout << "File opening error";
	}
	
	namedWindow("windowimg");
	imshow("windowimg", img);

	//Mat graymat;
	//cvtcolor(img.graymat, cv::COLOR_BGR2GRAY);
	cvtColor(img, grayimg, COLOR_BGR2GRAY);
	//gimg = GaussianBlur(gray, (5, 5), 0);
	 GaussianBlur(grayimg,blurred, Size(3, 3), 0);
	 threshold(blurred, thresholded, 100, 255, THRESH_BINARY);
	 /*findContours(thresholded, contr, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	 drawContours(img, contr, -1, (0, 255, 0), 2);*/
	 Mat edges;// = Canny(gray, 0, 50);
	 Canny(blurred, edges, 0, 50);
	namedWindow("windowimg1");
	imshow("windowimg1", edges);

	waitKey(0);
	destroyWindow("windowimg");
	
	return 0;
}