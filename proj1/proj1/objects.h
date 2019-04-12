#ifndef OBJECTS_H
#define OBJECTS_H
#include "common.h"

struct Meterial {
	double reflect;
	double refract;
	double diffuse;
	double specular;
	Meterial() {
		reflect = 0;
		refract = 0;
		diffuse = 0;
		specular = 0;
	}
	Meterial(double rfl,double rfr,double dfu,double spcl):reflect(rfl),refract(rfr),diffuse(dfu),specular(spcl){}
};

/*		   Texture
	PicTexture  ColorTexture
*/
class Texture {
public:
	enum Type {
		PICTURE,
		PURE
	};
protected:
	Type type;

public:
	Texture();
	Type getType();
	Color getColor(double x, double y) { return Color(0, 0, 0); };
};

class PicTexture :public Texture {
private:
	std::string picPath;
	cv::Mat pic;
public:
	PicTexture(std::string);
	~PicTexture() {}
	void loadPic();
	Color getColor(double x, double y);
};

class ColorTexture :public Texture {
private:
	Color textureColor;
public:
	ColorTexture(Color c) :textureColor(c) { type = PURE; };
	Color getColor(double x, double y);
};

/*******************************************
					Object
			Sphere Plane Bezier
********************************************/
class Object {
protected:
	Meterial* objMeterial;
	Texture* objTexture;
	std::string name;
	bool light = false;
	Light* l;
public:
	Object(){}
	std::string getName() { return name; }
	double getReflect() { return objMeterial->reflect; }
	double getRefract() { return objMeterial->refract; }
	double getdiffuse() { return objMeterial->diffuse; }
	double getspecular() { return objMeterial->specular; }
	bool isLight() { return light; }
	void setAsLight(Light* _l) { light = true; l = _l; }
	virtual Color getColor(Vector3 &pos) = 0;
	virtual double intersect(Ray &r) = 0;
};

class Plane :public Object {
private:
	Vector3 n;
	Vector3 P;
	Vector3 dx;
	Vector3 dy;
	double D;
public:
	Plane(Meterial* m, Texture* t, Vector3 _P, Vector3 _n, double _D);
	Color getColor(Vector3 &pos);
	double intersect(Ray &r);
};

class Sphere :public Object {
private:
	Vector3 P;
	double r;
public:
	Sphere(Meterial* m, Texture* t, Vector3 _P, double _r);
	Color getColor(Vector3 &pos);
	double intersect(Ray &r);
};

#endif