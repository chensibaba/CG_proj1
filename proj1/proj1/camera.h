#ifndef CAMERA_H
#define CAMERA_H
#include "vector3.h"
#include "common.h"

class Camera {
	Vector3 eye;
	Vector3 planeOrigin;
	Vector3 dx;
	Vector3 dy;

public:
	Camera(Vector3 _eye,Vector3 _po,Vector3 _dx,Vector3 _dy):
		eye(_eye),planeOrigin(_po),dx(_dx),dy(_dy){
		dx.normalize();
		dy.normalize();
	}
	Ray* getCameraRay(int x, int y) {
		Vector3 p = planeOrigin + dx*double(x) + dy*double(y);
		Vector3 dir = p - eye;
		return new Ray(eye, dir);
	}
};

#endif