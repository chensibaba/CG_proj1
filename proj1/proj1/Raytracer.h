#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "scene.h"
#include "camera.h"
#include <omp.h>

class RayTracer {
private:
	Camera* camera;
	Scene* scene;
	cv::Mat result;
public:
	RayTracer(Camera* c,Scene* s):camera(c),scene(s){}
	cv::Mat getImg() { return result; }
	void showImg() { cv::imshow("raytracer",result); }
	void writeImg() { cv::imwrite("res.png", result); }
};


#endif
