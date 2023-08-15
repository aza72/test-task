#include <iostream>

//#include <opencv2/core/core.hpp> 
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{
	Mat img= imread("C:/Users/1/Desktop/opencv/j1.jpg");
	Mat gimg;
	if (img.empty())
	{
		cout << "File opening error";
	}
	
	namedWindow("windowimg");
	imshow("windowimg", img);

	Mat graymat;
	//cvtcolor(img.graymat, cv::COLOR_BGR2GRAY);
	cvtColor(img,gimg, COLOR_BGR2GRAY);
	//gimg = GaussianBlur(gray, (5, 5), 0);

	namedWindow("windowimg1");
	imshow("windowimg1", gimg);

	waitKey(0);
	destroyWindow("windowimg");
	
	return 0;
}