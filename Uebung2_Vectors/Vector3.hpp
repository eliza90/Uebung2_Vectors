#ifndef Vector3_hpp
#define Vector3_hpp

#include <cmath>
#include <cstdlib> //für die exit Fkt
#include <iostream>

namespace cpp4cg {
	template<class T> class Vector3{
	private:
		T data[3];
		const T epsilon = 0.000001f; //so epsilon für float und double gleich
	public:
		typedef T value_type;
		Vector3();
		Vector3(const Vector3<T>& src);
		Vector3(T x, T y, T z);
		~Vector3(); //destructor
		T length() const;
		void normalize();
		T dot(const Vector3<T>& rhs) const;
		Vector3<T> cross(const Vector3<T>& rhs) const;
		Vector3<T> operator+(const Vector3<T>& rhs) const;
		Vector3<T> operator-(const Vector3<T>& rhs) const;
		Vector3<T> operator*(T rhs) const;
		T& operator[](int idx);
		const T& operator[](int idx) const;
		Vector3<T>& operator=(const Vector3<T>& rhs);
		bool operator==(const Vector3<T>& rhs);
		T getEpsilon() const{ return epsilon; }
		T get_x() const{ return data[0]; }
		T get_y() const{ return data[1]; }
		T get_z() const{ return data[2]; }
		void set_x(T x){ data[0] = x; }
		void set_y(T y){ data[1] = y; }
		void set_z(T z){ data[2] = z; }
		void set(T x, T y, T z){ data[0] = x; data[1] = y; 	data[2] = z;}
		T get_data(int i) const{ if (i <0 || i >2){ throw; } return data[i];}
	};
	template <class T>
	inline Vector3<T> operator*(T lhs, const Vector3<T>& rhs);

	template <class T>
	Vector3<T>::Vector3(){
		this->set(0, 0, 0);
	}

	template <class T>
	Vector3<T>::Vector3(const Vector3<T>& src){
		this->set_x(src.get_x());
		this->set_y(src.get_y());
		this->set_z(src.get_z());
	}

	template <class T>
	Vector3<T>::Vector3(T x, T y, T z){
		this->set(x, y, z);
	}

	template <class T>
	Vector3<T>::~Vector3(){} //destructor

	template <class T>
	T Vector3<T>::length() const{
		return sqrt(dot(*this));
	}

	template <class T>
	void Vector3<T>::normalize(){
		T magnitude = length();
		if (magnitude != 0){
			set_x(get_x() / magnitude);
			set_y(get_y() / magnitude);
			set_z(get_z() / magnitude);
		}
	}

	template <class T>
	T Vector3<T>::dot(const Vector3<T>& rhs) const{
		return (get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z());
	}

	template <class T>
	Vector3<T> Vector3<T>::cross(const Vector3<T>& rhs) const{
		return Vector3(get_y()*rhs.get_z() - (get_z()*rhs.get_y()),
			get_z()*rhs.get_x() - (get_x()*rhs.get_z()),
			get_x()*rhs.get_y() - (get_y()*rhs.get_x()));
	}

	template <class T>
	Vector3<T> Vector3<T>::operator+(const Vector3<T>& rhs) const{
		T x = get_x();
		x += rhs.get_x();
		T y = get_y();
		y += rhs.get_y();
		T z = get_z();
		z += rhs.get_z();
		return Vector3(x, y, z);
	}

	template <class T>
	Vector3<T> Vector3<T>::operator-(const Vector3<T>& rhs) const{
		return Vector3(get_x() - rhs.get_x(),
			get_y() - rhs.get_y(),
			get_z() - rhs.get_z());
	}

	template <class T>
	Vector3<T> Vector3<T>::operator*(T rhs) const{
		return Vector3(get_x()*rhs, get_y()*rhs, get_z()*rhs);
	}

	template <class T>
	T& Vector3<T>::operator[](int idx){
		if (idx <0 || idx >2){
			std::cerr << "Out of range: " << idx << "\n";
			exit(-1);
		}
		return data[idx];
	}

	template <class T>
	const T& Vector3<T>::operator[](int idx) const{
		if (idx <0 || idx >2){
			std::cerr << "Out of range: " << idx << "\n";
			exit(-1);
		}
		return data[idx];
	}

	template <class T>
	Vector3<T>& Vector3<T>::operator=(const Vector3<T>& rhs){
		if (*this == rhs){
			return *this;
		}
		this->set_x(rhs.get_x());
		this->set_y(rhs.get_y());
		this->set_z(rhs.get_z());
		return *this;
	}

	//to doo
	template <class T>
	bool Vector3<T>::operator==(const Vector3<T>& rhs){
		Vector3<T> v = *this;
		if (abs(v.get_x() - rhs.get_x()) < getEpsilon() &&
			abs(v.get_y() - rhs.get_y()) < getEpsilon() &&
			abs(v.get_z() - rhs.get_z()) < getEpsilon()){
			return true;
		}
		return false;
	}

	template <class T>
	inline Vector3<T> operator*(T lhs, const Vector3<T>& rhs){
		return Vector3<T>(lhs*rhs.get_x(), lhs*rhs.get_y(), lhs*rhs.get_z());
	}	
}
#endif