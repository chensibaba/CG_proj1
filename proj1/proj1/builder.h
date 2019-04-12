#ifndef BUILDER_H
#define BUILDER_H
#include "camera.h"
#include "scene.h"

class Builder {
	Scene* scene;
	Camera* camera;
public:
	Builder(){}
	void buildCamera(Vector3 eye, Vector3 origin, Vector3 dx, Vector3 dy);
	void buildScene(Object** objs, int num);
	cv::Mat rayTracer_begin();
};

#endif