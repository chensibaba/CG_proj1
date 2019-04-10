#include <iostream>
#include "objects.h"


using namespace cv;

/*
	Reference
		http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_1_Introduction.shtml
		https://mhy12345.xyz/category/tutorials/graph-render/
		SPPM:
			https://blog.csdn.net/libing_zeng/article/details/76222498


*/
int main(void){
	PicTexture t = PicTexture("test.jpg");
	Color a = t.getColor(1000, 1000);
	a.show();
	ColorTexture c = ColorTexture(new Color(100, 100, 100));
	Color b = c.getColor(100, 100);
	b.show();
	system("pause");
	return 0;
}
