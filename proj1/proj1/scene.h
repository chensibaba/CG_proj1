#ifndef SCENE_H
#define SCENE_H
#include "objects.h"

struct IntersectPoint {
	Object* obj;
	double t;

	IntersectPoint(){}
	IntersectPoint(Object* o,double _t):obj(o),t(_t){}
	void set(Object* o, double _t) { obj = o; t = _t; }
};

class Scene {
private:
	Object* objs[10];
	int objCnt;
	int lightCnt;
	Light* light[10];
public:
	Scene();

	Meterial* getMeterial(double reflect, double refract,double diffuse, double specular);
	ColorTexture* getColorTexture(Color c);
	PicTexture* getPicTexture(std::string path);
	Sphere* getSphere(Meterial* m, Texture* t, Vector3 o, double r);
	Plane* getPlane(Meterial* m, Texture* t, Vector3 P, Vector3 n, double D);

	void addObj(Object* obj);
	int getObjCnt();
	Object* getObj(int index);

	void addLight(Light* l);
	Light* getLight(int idx);
	int getLightCnt();

	IntersectPoint* getIntersectObj(Ray &r);
};


#endif