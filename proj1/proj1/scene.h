#ifndef SCENE_H
#define SCENE_H
#include "objects.h"

class Scene {
private:
	Object* objs[10];
	int objCnt;
	int lightCnt;
	Light* light;
public:
	Scene();
	Meterial* getMeterial(double reflect, double refract,double diffuse, double specular);
	ColorTexture* getColorTexture(Color c);
	PicTexture* getPicTexture(std::string path);
	Sphere* getSphere(Meterial* m, Texture* t, Vector3 o, double r);
	Plane* getPlane(Meterial* m, Texture* t, Vector3 P, Vector3 n, double D);
};


#endif