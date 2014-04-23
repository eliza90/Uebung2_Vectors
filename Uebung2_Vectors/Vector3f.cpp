#include "stdafx.h"
#include "Vector3f.hpp"
#include <cmath>
#include <cstdlib> //für die exit Fkt
#include <iostream>

using namespace cpp4cg;

Vector3f::Vector3f(){
	this->set(0, 0, 0);
}

Vector3f::Vector3f(const Vector3f& src){
	this->set_x(src.get_x());
	this->set_y(src.get_y());
	this->set_z(src.get_z());
}

Vector3f::Vector3f(float x, float y, float z){
	this->set(x, y, z);
}

Vector3f::~Vector3f(){

}

float Vector3f::length() const{
	return sqrt(dot(*this));
}

void Vector3f::normalize(){
	float magnitude = length();
	if (magnitude != 0){
		set_x(get_x() / magnitude);
		set_y(get_y() / magnitude);
		set_z(get_z() / magnitude);
	}
}

float Vector3f::dot(const Vector3f& rhs) const{
	return (get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z());
}

Vector3f Vector3f::cross(const Vector3f& rhs) const{
	return Vector3f(get_y()*rhs.get_z() - (get_z()*rhs.get_y()),
		get_z()*rhs.get_x() - (get_x()*rhs.get_z()),
		get_x()*rhs.get_y() - (get_y()*rhs.get_x()));
}

Vector3f Vector3f::operator+(const Vector3f& rhs) const{
	float x = get_x();
	x += rhs.get_x();
	float y = get_y();
	y += rhs.get_y();
	float z = get_z();
	z += rhs.get_z();
	return Vector3f(x, y, z);
}

Vector3f Vector3f::operator-(const Vector3f& rhs) const{
	return Vector3f(get_x() - rhs.get_x(),
		get_y() - rhs.get_y(),
		get_z() - rhs.get_z());
}

Vector3f Vector3f::operator*(float rhs) const{
	return Vector3f(get_x()*rhs, get_y()*rhs, get_z()*rhs);
}

Vector3f& Vector3f::operator=(const Vector3f& rhs){
	if (*this == rhs){
		return *this;
	}
	this->set_x(rhs.get_x());
	this->set_y(rhs.get_y());
	this->set_z(rhs.get_z());
	return *this;
}

//nachgestelltes & -> Referenz = konstanter Zeiger, der bei jeder Verwendung automatisch dereferenziert wird
//sollte "this" Objekt wiedergeben?!
float& Vector3f::operator[](int idx){
	if (idx <0 || idx >2){
		std::cerr << "Out of range: " << idx << "\n";
		exit(-1);
	}	
	return data[idx];	
}

const float& Vector3f::operator[](int idx) const{
	if (idx <0 || idx >2){
		std::cerr << "Out of range: " << idx << "\n";
		exit(-1);
	}
	return data[idx];
}

//betrag bedenken
bool Vector3f::operator== (const Vector3f& rhs){
	Vector3f v = *this;
	Vector3f _v = v - rhs;
	if (_v.get_x() < getEpsilon() && _v.get_y() < getEpsilon() && _v.get_z() < getEpsilon()){
		return true;
	}
	return false;
}

Vector3f cpp4cg::operator*(float lhs, const Vector3f& rhs){
	return Vector3f(lhs*rhs.get_x(), lhs*rhs.get_y(), lhs*rhs.get_z());
}




