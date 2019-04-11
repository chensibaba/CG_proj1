#include "objects.h"

Texture::Texture() {}

Texture::Type Texture::getType() {
	return type;
}
/****************************************************/
/******************    PicTexture   ******************/
/*****************************************************/
PicTexture::PicTexture(std::string p){
	type = PICTURE;
	picPath = p;
	loadPic();
}

void PicTexture::loadPic() {
	pic = cv::imread(picPath);
	cv::imshow("test", pic);
	cv::waitKey(0);
}

Color PicTexture::getColor(double x,double y) {
	int xx = int(x);
	int yy = int(y);
	xx = xx%pic.rows;
	yy = yy%pic.cols;
	while (xx <= 0) xx += pic.rows;
	while (yy <= 0) yy += pic.cols;
	double r = pic.at<cv::Vec3b>(xx, yy)[0];
	double g = pic.at<cv::Vec3b>(xx, yy)[1];
	double b = pic.at<cv::Vec3b>(xx, yy)[2];
	return Color(r,g,b);
}

/****************************************************/
/***************    ColorTexture   ******************/
/*****************************************************/

Color ColorTexture::getColor(double x, double y) {
	return textureColor; 
}


/****************************************************/
/******************    Plane   **********************/
/*****************************************************/
Plane::Plane(Meterial* m, Texture* t,Vector3 _P, Vector3 _n, double _D) :P(_P),n(_n), D(_D) {
	objMeterial = m;
	objTexture = t;
	if (n.getX() == 0) {
		dx = Vector3(1, 0, 0);
		if (n.getY() == 0) {
			dy = Vector3(0, 1, 0);
		}else {
			dy = Vector3(0, 0, 1);
		}
	}else {
		dx = Vector3(0, 0, 1);
		dy = Vector3(0, 1, 0);
	}
}

double Plane::intersect(Ray &r) {
	double deno = r.dir*n;
	if (deno == 0) return -1;
	double res = -(D + n*r.o);
	res /= deno;
	if (res > 0) return res;
	else return -1;
}

Color Plane::getColor(Vector3 &pos) {
	if (objTexture->getType() == Texture::PURE) {
		return objTexture->getColor(pos.getX(), pos.getY());
	} else {
		double tx = ((pos - P) * dx) / dx.getLength();
		double ty = ((pos - P) * dy) / dy.getLength();
		return objTexture->getColor(tx, ty);
	}
}

/****************************************************/
/******************    Sphere  **********************/
/****************************************************/
Sphere::Sphere(Meterial* m, Texture* t, Vector3 _P, double _r) :P(_P), r(_r) {
	objMeterial = m;
	objTexture = t;
}

Color Sphere::getColor(Vector3 &pos) {
	if (objTexture->getType() == Texture::PURE) {
		return objTexture->getColor(0, 0);
	} else  {
		Vector3 tmp = (pos - P) *(1 / r);
		double x = asin(tmp.getZ()) + PI / 2;
		double y = atan2(tmp.getX(), tmp.getY());
		return objTexture->getColor(x, y);
	}
}

double Sphere::intersect(Ray &ray) {
	Vector3 l = P - ray.o;
	double tp = l*ray.dir;
	double ll = l*l;
	double rr = r*r;
	if (ll > rr) {
		if (tp < 0) {
			return -1;
		}
	}
	double d = sqrt(ll - tp*tp);
	if (d > r) return -1;
	double t_ = sqrt(rr - d*d);
	if (ll > rr) {
		return tp - t_;
	}
	else if (ll < rr) {
		return tp + t_;
	}
	return -1;
}