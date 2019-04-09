#include "vector3.h"

vector3::vector3(vector3* v){
	x = v->x;
	y = v->y;
	z = v->z;
}

vector3::vector3(float a,float b,float c){
	x = a;
	y = b;
	z = c;
}

float vector3::getX(){
	return x;
}

float vector3::getY(){
	return y;
}

float vector3::getZ(){
	return z;
}


void vector3::show(){
	printf("%f,%f,%f\n",x,y,z);
}

void vector3::normalize(){
	float s = sqrt(x*x + y*y + z*z);
	x /= s;
	y /= s;
	z /= s;
}
