#pragma once 
#include "AbstractVectorN.hpp"

namespace cpp4cg { 
	
	template<class T, unsigned int D>
	class Vector: public AbstractVectorN<T, D> { 
	private: 
		typedef AbstractVectorN<T, D> Super; 
	public: 
		Vector() : Super() {}
		Vector(const Vector<T, D>& src) : Super(src){}
		~Vector() { } 
		using Super::operator =;
		using Super::operator +;
		using Super::operator -;
		using Super::operator *;
		using Super::operator ==;
	}; 

	template<class T>
	class Vector<T,3>: public AbstractVectorN<T, 3>{
	private: 
		typedef AbstractVectorN<T, 3> Super; 
	public: 
		Vector() : Super() {}
		~Vector() { } 
		Vector(T x, T y, T z): Super(){
			this->set(x,y,z);
		}
		Vector(const Vector<T, 3>& src) : Super(src){
			this->set_x(src.get_x());
			this->set_y(src.get_y());
			this->set_z(src.get_z());
		}
		using Super::operator =;
		using Super::operator +;
		using Super::operator -;
		using Super::operator *;
		using Super::operator ==;
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
	//Spezialisierung für 2D Vektoren
	template<class T>
	class Vector<T, 2>: public AbstractVectorN<T, 2>{
	private:
		typedef AbstractVectorN<T, 2> Super;
	public:
		Vector() : Super() {}
		~Vector() { }
		Vector(T x, T y) : Super(){
			this->set(x,y);
		}
		Vector(const Vector<T, 2>& src) : Super(src){
			this->set_x(src.get_x());
			this->set_y(src.get_y());
		}
		using Super::operator =;
		using Super::operator +;
		using Super::operator -;
		using Super::operator *;
		using Super::operator ==;
		T get_x() const{ return data[0]; }
		T get_y() const{ return data[1]; }
		void set_x(T x){ data[0] = x; }
		void set_y(T y){ data[1] = y; }
		void set(T x, T y){ data[0] = x; data[1] = y;}
	};	
}


