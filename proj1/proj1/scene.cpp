#include "scene.h"

Scene::Scene() {
	objCnt = 0;
}

Meterial* Scene::getMeterial(double reflect,double refract,
					double diffuse,double specular) {
	return new Meterial(reflect, refract, diffuse, specular);
}

ColorTexture* Scene::getColorTexture(Color c) {
	return new ColorTexture(c);
}
PicTexture* Scene::getPicTexture(std::string path) {
	return new PicTexture(path);
}

Sphere* Scene::getSphere(Meterial* m,Texture* t,Vector3 o,double r) {
	return new Sphere(m, t, o, r);
}

Plane* Scene::getPlane(Meterial* m, Texture* t, Vector3 P, Vector3 n,double D) {
	return new Plane(m, t, P, n, D);
}