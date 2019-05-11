#include "opencv2/opencv.hpp"

using namespace cv;

Mat src,hsv,gray;
int h=0,s=0,v=0;
int mh=255,ns=255,mv=255;

void show(){
	imshow("original", src);
	imshow("hsv image" ,hsv);
	imshow("gray scale image", hsv);
};

/*void perform(){

}
*/

int main(int argc int **argv)
{
	VideoCapture cap(argv[1]);

	if (!cap.isOpened())
		return -1;
	else{
		cvtColor(cap, gray, CV_BGR2GRAY);
		cvtColor(cap, hsv, CV_BGR2HSV);
	}

	while (cap.isOpened())
	{
		cap >> src;

		if (src.empty())
			break;
		else{
			//createtrackbar();
			//perform();
			show();
		}
	
		int k=waitKey(10);

		if (k==' ')
			while((k=waitKey(10)) != ' ')
			{
				if (k=='q')	return 0;
				//perform();
				show();
			}

		else if(k=='q')
			return 0;

		//perform();
		show();
	}
}
	
	
