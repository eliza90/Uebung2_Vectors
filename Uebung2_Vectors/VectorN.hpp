#pragma once 
#include "AbstractVectorN.hpp"

namespace cpp4cg { 
	
	template<class T, unsigned int D>
	class Vector : public AbstractVectorN<T, D> { 
	private: 
		typedef AbstractVectorN<T, D> Super; 
	public: 
		Vector() : Super() {} 
		~Vector() { } 
	}; 

	template<class T>
	class Vector<T, 3> : public AbstractVectorN<T, 3>{
	private: 
		typedef AbstractVectorN<T, 3> Super; 
	public: 
		//Vector(const Vector<T,3>) : Super() { }
		//~Vector() { } 
		Vector(T x, T y, T z): Super(){
			this->set(x,y,z);
		}
		Vector(const Vector<T,3>& src) : Super(src){
		}
		T get_x() const{ return data[0]; }
		T get_y() const{ return data[1]; }
		T get_z() const{ return data[2]; }
		void set_x(T x){ data[0] = x; }
		void set_y(T y){ data[1] = y; }
		void set_z(T z){ data[2] = z; }
		void set(T x, T y, T z){ data[0] = x; data[1] = y; data[2] = z; }
		AbstractVectorN<T, 3> cross(const AbstractVectorN<T, 3>& rhs) const;	
	};

	template<class T>
	AbstractVectorN<T, 3> Vector<T, 3>::cross(const AbstractVectorN<T, 3>& rhs) const{
		T _x= rhs[0];
		T _y = rhs[1];
		T _z = rhs[2];
		return Vector<T, 3>(get_y()*_z - (get_z()*_y),
			get_z()*_x - (get_x()*_z),
			get_x()*_y - (get_y()*_x));
	}
}

//#ifndef VectorN_hpp
//#define VectorN_hpp
//
//#include <cmath>
//#include <cstdlib> //für die exit Fkt
//#include <iostream>
//
//namespace cpp4cg {
//	template<class T, unsigned int D> class Vector{
//	private:
//		T data[D];
//		const T epsilon = 0.000001f;
//	public:
//		typedef T value_type;
//		Vector();
//		Vector(const Vector<T,D>& src);
//		~Vector(); //destructor
//		T length() const;
//		void normalize();
//		T dot(const Vector<T, D>& rhs) const;
//		Vector<T, D> operator+(const Vector<T, D>& rhs) const;
//		Vector<T, D> operator-(const Vector<T, D>& rhs) const;
//		Vector<T, D> operator*(T rhs) const;
//		T& operator[](int idx);
//		const T& operator[](int idx) const;
//		Vector<T, D>& operator=(const Vector<T, D>& rhs);
//		bool operator==(const Vector<T, D>& rhs);		
//	};
//	template<class T, unsigned int D>
//	inline Vector<T, D> operator*(T lhs, const Vector<T, D>& rhs);
//
//	template<class T, unsigned int D>
//	Vector<T, D>::Vector(){
//		for (int i = 0; i < D; ++i){
//			this->data[i] = static_cast<T>(0);
//		}
//	}
//
//	template<class T, unsigned int D>
//	Vector<T, D>::Vector(const Vector<T, D>& src){
//		//Abfrage ob die Vektoren dieselbe Dimension haben notwendig?
//		for (int i = 0; i < D; ++i){
//			this->data[i] = src[i];
//		}
//	}
//
//	template<class T, unsigned int D>
//	Vector<T, D>::~Vector(){
//	}
//
//	template<class T, unsigned int D>
//	T Vector<T, D>::length() const{
//		return sqrt(dot(*this));
//	}
//
//	//static_cast<T> geht hier nicht wieso
//	template<class T, unsigned int D>
//	T Vector<T, D>::dot(const Vector<T, D>& rhs) const{
//		T product(0);
//		for (int i = 0; i < D; ++i){
//			product += this->data[i] * rhs[i];
//		}
//		return product;
//	}
//
//	template<class T, unsigned int D>
//	void Vector<T, D>::normalize(){
//		T magnitude = length();
//		if (magnitude != 0){
//			for (int i = 0; i < D; ++i){
//				this->data[i] = this->data[i] / magnitude;
//			}
//		}
//	}
//
//	template<class T, unsigned int D>
//	Vector<T, D> Vector<T, D>::operator+(const Vector<T, D>& rhs) const{		
//		Vector v = *this;
//		for (int i = 0; i < D; ++i){
//			v[i] += static_cast<T>(rhs[i]);
//		}
//		return v;
//	}
//
//	template<class T, unsigned int D>
//	Vector<T, D> Vector<T, D>::operator-(const Vector<T, D>& rhs) const{
//		Vector v = *this;
//		for (int i = 0; i < D; ++i){
//			v[i] -= static_cast<T>(rhs[i]);
//		}
//		return v;
//	}
//
//	template<class T, unsigned int D>
//	Vector<T, D> Vector<T, D>::operator*(T rhs) const{
//		Vector v = *this;
//		for (int i = 0; i < D; ++i){
//			v[i] *= static_cast<T>(rhs);
//		}
//		return v;
//	}
//
//	template<class T, unsigned int D>
//	T& Vector<T, D>::operator[](int idx){
//		if (idx <0 || idx >D){
//			std::cerr << "Out of range: " << idx << "\n";
//			exit(-1);
//		}
//		return data[idx];
//	}
//
//	template<class T, unsigned int D>
//	const T& Vector<T, D>::operator[](int idx) const{
//		if (idx <0 || idx >D){
//			std::cerr << "Out of range: " << idx << "\n";
//			exit(-1);
//		}
//		return data[idx];
//	}
//
//	template<class T, unsigned int D>
//	Vector<T, D>& Vector<T, D>::operator=(const Vector<T,D>& rhs){
//		if (*this == rhs){
//			return *this;
//		}
//		for (int i = 0; i < D; ++i){
//			this->data[i] = static_cast<T>(rhs[i]);
//		}
//		return *this;
//	}
//
//	//todo
//	template<class T, unsigned int D>
//	bool Vector<T, D>::operator==(const Vector<T, D>& rhs){
//		Vector v = *this;
//		for (int i = 0; i < D; ++i){
//			if (!abs(v[i] - rhs[i]) < epsilon)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//
//	template<class T, unsigned int D>
//	inline Vector<T,D> operator*(T lhs, const Vector<T, D>& rhs){
//		Vector<T, D> temp = Vector<T, D>();
//		for (int i = 0; i < D; ++i){
//			temp[i]=lhs*rhs[i];
//		}
//		return temp;
//	}
//}
//#endif