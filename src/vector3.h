#ifndef VECTOR3_H
#define VECTOR3_H

#include <stdlib.h>
#include <iostream>
#include <math.h>

class vector3{
	private:
		float x,y,z;
	public:
		float getX();
		float getY();
		float getZ();
		vector3(float,float,float);
		vector3(vector3*);
		void show();
		void normalize();
	
		static vector3 mul(vector3 v1,vector3 v2){
			return vector3(v2.x*v1.x,v1.y*v2.y,v1.z*v2.z);
		}
		static vector3 add(vector3 v1,vector3 v2){
			return vector3(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
		}
		static vector3 sub(vector3 v1,vector3 v2){
			return vector3(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
		}
		static vector3 div(vector3 v1,vector3 v2){
			return vector3(v1.x/v2.x,v1.y/v2.y,v1.z/v2.z);
		}

		void operator += (vector3 v){
			x += v.x;
			y += v.y;
			z += v.z;
		}
		void operator -= (vector3 v){
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}
		void operator /= (vector3 v){
			x /= v.x;
			y /= v.y;
			z /= v.z;
		}
		void operator *= (vector3 v){
			x *= v.x;
			y *= v.y;
			z *= v.z;
		}
		
		friend vector3 operator + (vector3 v1,vector3 v2){
			return vector3::add(v1,v2);
		}	
		friend vector3 operator - (vector3 v1,vector3 v2){
			return vector3::sub(v1,v2);
		}	
		friend vector3 operator * (vector3 v1,vector3 v2){
			return vector3::mul(v1,v2);
		}	
		friend vector3 operator * (vector3 v1,float f){
			return vector3::mul(v1,vector3(f,f,f));
		}
		friend vector3 operator / (vector3 v1,vector3 v2){
			return vector3::sub(v1,v2);
		}	


};

#endif
