#include <iostream>

#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;





int main()
{


	Mat img = imread("C:/Users/1/Desktop/opencv/j1.jpg");
	Mat scr = img;








	
	Mat grayimg, blurred, thresholded,contr;
	if (img.empty())
	{
		cout << "File opening error";
	}
	
	namedWindow("windowimg");
	imshow("windowimg", img);
    Mat graymat;
	cvtColor(img, graymat, COLOR_BGR2GRAY);

	Mat raz;
	medianBlur(graymat, raz, 5);


	 Mat edges;// = Canny(gray, 0, 50);
	 Canny(raz, edges,200, 200);
     Mat g= getStructuringElement(MORPH_RECT, Size (7, 7));
     Mat kernel;
	 morphologyEx(edges, kernel, MORPH_CLOSE, g);



	// vector< vector< cv::Point> > contours;

	 vector < vector<  Point> >  contours;
	 vector<Vec4i> hierarchy;
	// Scalar color(rand() & 255, rand() & 255, rand() & 255);
	 findContours(kernel, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	 
	 int index = 0; 
	
		 drawContours(scr, contours, index, Scalar(0, 100, 100), FILLED, 0, hierarchy);
	

	namedWindow("windowimg1");
	imshow("windowimg1", scr);

	waitKey(0);
	destroyWindow("windowimg");
	
	return 0;
}





//// Загрузка изображения
//Mat image = imread("spoon.jpg");
//
//// Определение параметров спичечного коробка: ширина, высота и цвет
//int width = 40; int height = 50; Vec3b color = Scalar(0, 255, 0);
//
//// Поиск спичечного коробка на изображении с использованием функции findContours()
//vector<vector<Point>> contours;
//findContours(image, contours, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
//
//for (vector<Point> contour : contours) {
//	// Если контур имеет форму спичечного коробка и соответствует заданным параметрам
//	if (contourArea(contour) > 500 &&
//		contourPerim(contour) / abs(contourArea(contour)) < 0.05 &&
//		matchShapes(contour, Rect(0, 0, width, height), color, 1, 0.5) != -1) {
//
//		// Вывод координат центра спичечного коробка на экран
//		cout << contourCenter(contour)[0] << " " << contourCenter(contour)[1] << endl;
//	}
//}

