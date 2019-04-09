#include <iostream>
#include <opencv2/opencv.hpp>
#include "vector3.h"

using namespace cv;

int main(void){
	vector3 a = vector3(1,2,3);
	a.show();
	vector3 b = vector3(1,2,3);
	vector3 c = vector3::mul(a,b);
	c.show();
	c = a+b;
	c = a;
	c.show();
	system("pause");
	return 0;
}
