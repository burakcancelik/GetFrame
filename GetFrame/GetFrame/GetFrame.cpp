// GetFrame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "opencv2/opencv.hpp"
#include "iostream"

using namespace cv;
using namespace std;
int main(int, char**)
{
	string video_path="C:\\Users\\BurakCan\\Desktop\\dataset\\example.avi";
	VideoCapture cap(video_path); // get file
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat frame;
	Mat gray_image;
	//namedWindow("Video", CV_WINDOW_AUTOSIZE);
	double frnb(cap.get(CV_CAP_PROP_FRAME_COUNT));
	std::cout << "frame count = " << frnb << endl;

	
	string path = "C:\\Users\\BurakCan\\Desktop\\dataset\\frames\\";
	for (int i = 0; i <= frnb; i++)
	{
		bool success = cap.read(frame);
		if (!success) {
			cout << "Cannot read  frame " << endl;
		}
		cvtColor(frame, gray_image, CV_BGR2GRAY);
		string s = std::to_string(i);
		imwrite(path + s + ".jpg", gray_image);
	}
	cout << "Frames captured by video" << endl;
	//imshow("Video's Frames", frame);
	/*namedWindow("frame",CV_WINDOW_AUTOSIZE);*/

}




	//for (;;) {
	//	Mat frame;
	//	double fIdx;

	//	/*fldx -> frame we want to see
	//	frnb -> all frame number*/
	//
	//	std::cout << "frame index ? ";
	//	std::cin >> fIdx;

	//	if (fIdx < 0 || fIdx >= frnb) break;
	//	
	//	//girilen sayýya göre istenen frame'i set'et 
	//	cap.set(CV_CAP_PROP_POS_FRAMES, fIdx); // Girilen sayýya göre pozitif frame'i set et

	//	//set edilen frame'i oku
	//	bool success = cap.read(frame);
	//	cvtColor(frame, gray_image, CV_BGR2GRAY);

	//	string path = "C:\\Users\\BurakCan\\Desktop\\dataset\\";
	//	for (int i = 0; i <= frnb; i++)
	//	{
	//		string s = std::to_string(i);
	//		imwrite(path +s + ".jpg", gray_image);
	//	}
	//	
	//	if (!success) {
	//		cout << "Cannot read  frame " << endl;
	//		break;
	//	}
	//	
	//	imshow("Video", gray_image);
	//	if (waitKey(0) == 27) break;
	//}
	//return 0;
//}
