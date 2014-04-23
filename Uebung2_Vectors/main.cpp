#include "stdafx.h"
#include <cstdio> 
#include "VectorN.hpp"
#include "AbstractVectorN.hpp"
//#include "Vector3.hpp"
//#include "Vector3f.hpp"

namespace cpp4cg { 
	//typedef Vector3<float> Vector3f; 
	typedef Vector<float, 3> Vector3f;
	//typedef Vector<double, 3> Vector3d;
	typedef Vector<float, 2> Vector2f;
	//typedef Vector<double, 2> Vector2d;
}

//void print_vector(const cpp4cg::Vector3f& v)
//{
//	printf("%4.8f %4.8f %4.8f \n", v.get_x(), v.get_y(), v.get_z());
//}

//->optionale Parameter?
void print_vector(const cpp4cg::Vector3f& v)
{
	printf("%4.8f %4.8f %4.8f \n", v[0], v[1], v[2]);
}

void print_vector(const cpp4cg::Vector2f& v)
{
	printf("%4.8f %4.8f \n", v[0], v[1]);
}

int _tmain(int argc, _TCHAR* argv[]) {
	using namespace cpp4cg;
	printf("Hello World\n");

	Vector3f v1(1.0, 2.0, 3.0);
	print_vector(v1);
	printf("len: %f\n", v1.length()); //sqrt14 3.74165
	v1.normalize(); //0.26726 0.53452 0.80178
	print_vector(v1);
	printf("len: %f (Erwartet: 1.00000)\n", v1.length());
	Vector3f v2(1.0f, 0.0f, 0.0f);
	v1.cross(v2);//Kreuzprodukt falscher Konstruktoraufruf
	Vector3f v3(v1.cross(v2)); //(0,0.80178,-0,53452)
	//v3.normalize();//l=1
	//print_vector(v3);//(0,0.8321,-0,554706)
	//v1 = v2.cross(v3);
	//print_vector(v1); //(0,0.554706,0.832059)
	//printf("len: %f (Erwartet: 1.00002)\n",
	//	v1.length());
	//printf("len: %f (Erwartet: 1.00000)\n",
	//	v2.length());
	//printf("len: %f (Erwartet: 0.96363)\n",
	//	v3.length());
	//printf("test: %f (Erwartet: 0.00000)\n", v1.dot(v2));
	//printf("test: %f (Erwartet: 0.00000)\n", v1.dot(v3));
	//printf("test: %f (Erwartet: 0.00000)\n", v2.dot(v1));
	//printf("test: %f (Erwartet: 0.00000)\n", v2.dot(v3));
	//printf("test: %f (Erwartet: 0.00000)\n", v3.dot(v1));
	//printf("test: %f (Erwartet: 0.00000)\n", v3.dot(v2));
	//// Die Vektoren v1, v2 und v3 sind v1(0,0.55471,0.83206) v2(1,0,0) v3(0,0.832059,-0.55471)
	//Vector3f v4(3.14159265359f, 2.71828182846f, 42.f);
	//print_vector(v4);
	////float s1 = v4.dot(v1);
	////float s2 = v4.dot(v2);
	////float s3 = v4.dot(v3);
	//Vector3f::value_type s1 = v4.dot(v1);
	//Vector3f::value_type s2 = v4.dot(v2);
	//Vector3f::value_type s3 = v4.dot(v3);
	//// Die Skalare s1, s2 und s3 sind s1=36.45433 s2=3.14159 s3=-21.03588
	//printf("s1: %f\n", s1);
	//printf("s2: %f\n", s2);
	//printf("s3: %f\n", s3);
	//Vector3f v5 = s1 * v1 + s2 * v2 + s3 * v3; 
	//print_vector(v5);// 3.14159  2.71849  42.00095
	//printf("All is %s\n", (v4 == v5) ? "right" : "wrong");

//N-Dimensionale Vektoren Tests
	//Vector3f v1_3f;
	//v1_3f[0] = 1.f;
	//v1_3f[1] = 2.f;
	//v1_3f[2] = 3.f;
	//print_vector(v1_3f);
	//Vector3f v2_3f;
	//v2_3f[0] = 5.f;
	//v2_3f[1] = 8.f;
	//v2_3f[2] = 1.f;
	////print_vector(v1_3f);
	////print_vector(v3);
	///*Vector3f v4 = v3 - v2_3f;
	//print_vector(v4);	
	//printf("All is %s\n", (v1_3f == v4) ? "right" : "wrong");
	//v4 = 0.5f * v2_3f;*/
	///*print_vector(v4);*/
	//printf("len: %f\n", v1_3f.length());
	//v1_3f.normalize();
	//print_vector(v1_3f); 
	//printf("len: %f (Erwartet: XXX)\n", v1_3f.length());
	return 0;
}


//#include "stdafx.h"
//#include <cstdio> 
//#include "Vector3.hpp"
////#include "Vector3f.hpp"
//using namespace cpp4cg;
//namespace cpp4cg { typedef Vector3<float> Vector3f; }
//
//void print_vector(const Vector3f& v) 
//{ 
//	printf("floats: %4.1f %4.1f %4.1f \n", v.get_x(), v.get_y(), v.get_z());
//}
//
////Vector3f operator*(float lhs, const Vector3f& rhs){
////	return Vector3f(lhs*rhs.get_x(), lhs*rhs.get_y(), lhs*rhs.get_z());
////}
//
//int _tmain(int argc, _TCHAR* argv[]) {
//	printf("Hello World\n");
//
//	Vector3f v1(1.0f, 2.0f, 3.0f); 
//	print_vector(v1);
//	printf("len: %f\n", v1.length()); //sqrt14 3.74165
//	v1.normalize(); //0.26726 0.53452 0.80178
//	print_vector(v1); 
//	printf("len: %f (Erwartet: 1.00000)\n", v1.length());
//	Vector3f v2(1.0f, 0.0f, 0.0f);
//	Vector3f v3(v1.cross(v2)); //(0,0.80178,-0,53452)
//	v3.normalize();//l=1
//	print_vector(v3);//(0,0.8321,-0,554706)
//	v1 = v2.cross(v3); 
//	print_vector(v1); //(0,0.554706,0.832059)
//	printf("len: %f (Erwartet: 1.00002)\n", 
//	v1.length()); 
//	printf("len: %f (Erwartet: 1.00000)\n", 
//	v2.length()); 
//	printf("len: %f (Erwartet: 0.96363)\n", 
//	v3.length());	
//	printf("test: %f (Erwartet: 0.00000)\n", v1.dot(v2)); 
//	printf("test: %f (Erwartet: 0.00000)\n", v1.dot(v3)); 
//	printf("test: %f (Erwartet: 0.00000)\n", v2.dot(v1)); 
//	printf("test: %f (Erwartet: 0.00000)\n", v2.dot(v3)); 
//	printf("test: %f (Erwartet: 0.00000)\n", v3.dot(v1)); 
//	printf("test: %f (Erwartet: 0.00000)\n", v3.dot(v2));
//	// Die Vektoren v1, v2 und v3 sind v1(0,0.55471,0.83206) v2(1,0,0) v3(0,0.832059,-0.55471)
//	Vector3f v4(3.14159265359f, 2.71828182846f, 42.f); 
//	print_vector(v4);
//	float s1 = v4.dot(v1);
//	float s2 = v4.dot(v2); 
//	float s3 = v4.dot(v3);
//	// Die Skalare s1, s2 und s3 sind s1=36.45433 s2=3.14159 s3=-21.03588
//	printf("s1: %f\n", s1);
//	printf("s2: %f\n", s2); 
//	printf("s3: %f\n", s3);
////Linkerfehler in * wenn Methode in vector3f.cpp.....warum....??!!
//	//Vector3f v5 = s1 * v1 + s2 * v2 + s3 * v3; 
//	//print_vector(v5);// 3.14159  2.71849  42.00095
//	//printf("All is %s\n", (v4 == v5) ? "right" : "wrong");
//	return 0;
//}
