#include <iostream>
#include "scene.h"
/*
	Reference
		http://www.flipcode.com/archives/Raytracing_Topics_Techniques-Part_1_Introduction.shtml
		https://mhy12345.xyz/category/tutorials/graph-render/
		SPPM:
			https://blog.csdn.net/libing_zeng/article/details/76222498


*/
int main(void){
	time_t start, stop;
	start = time(NULL);
	Scene s = Scene();
	Meterial* m = s.getMeterial(0, 0, 0, 0);
	ColorTexture* t = s.getColorTexture(Color(4, 5, 6));
	Sphere* o = s.getSphere(m, t, Vector3(10, 0, 0), 5);
	Ray r = Ray(Vector3(0, 0, 0), Vector3(1, 0, 0));
	s.addObj(o);
	IntersectPoint* p = s.getIntersectObj(r);
	if (p != NULL) {
		printf("%f", p->t);
	}
	stop = time(NULL);
	printf("Use Time:%ld\n", (stop - start));
	system("pause");
	return 0;
}
