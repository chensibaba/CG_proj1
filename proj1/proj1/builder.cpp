#include "builder.h"

void Builder::buildCamera(Vector3 eye, Vector3 origin, Vector3 dx, Vector3 dy) {
	camera = new Camera(eye, origin, dx, dy);
}

void Builder::buildScene(Object** objs, int num) {
	scene = new Scene();
	for (int i = 0; i < num; i++) {
		scene->addObj(objs[i]);
	}
	//build the room
	Meterial* wall_m = new Meterial(0, 0, 0, 0.8);
	ColorTexture* wall_t = new ColorTexture(Color(255, 0, 0));
	Plane* w1 = new  Plane(wall_m, wall_t, Vector3(0, 0, 0), Vector3(1, 0, 0), 0);
	Plane* w2 = new  Plane(wall_m, wall_t, Vector3(0, 0, 0), Vector3(0, 1, 0), 0);
	Plane* w3 = new  Plane(wall_m, wall_t, Vector3(0, 0, 0), Vector3(0, 0, 1), 0);
	Plane* w4 = new  Plane(wall_m, wall_t, Vector3(0, 0, 0), Vector3(1, 0, 0), 1000);
	Plane* w5 = new  Plane(wall_m, wall_t, Vector3(0, 0, 0), Vector3(0, 1, 0), 1000);
	Plane* w6 = new  Plane(wall_m, wall_t, Vector3(0, 0, 0), Vector3(0, 0, 1), 1000);
	Sphere* lightSource = new Sphere(new Meterial(0, 0, 0, 0),new ColorTexture(Color(255, 255, 255)), Vector3(500, 500, 1000),40.0);
	lightSource->setAsLight(new Light(Vector3(500, 500, 1000),Color(255,255,255),40,1));
	scene->addObj(w1);
	scene->addObj(w2);
	scene->addObj(w3);
	scene->addObj(w4);
	scene->addObj(w5);
	scene->addObj(w6);
	scene->addObj(lightSource);
}