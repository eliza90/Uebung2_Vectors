#ifndef AbstractVectorN_hpp
#define AbstractVectorN_hpp

#include <cmath>
#include <cstdlib> //für die exit Fkt
#include <iostream>

namespace cpp4cg {
	template<class T, unsigned int D> class AbstractVectorN{
	protected:
		const T epsilon = static_cast<T>(0.000001);
		T data[D];
	public:
		typedef T value_type;		
		AbstractVectorN();
		AbstractVectorN(const AbstractVectorN<T,D>& src);
		~AbstractVectorN(); //destructor
		T length() const;
		void normalize();
		T dot(const AbstractVectorN<T, D>& rhs) const;
		AbstractVectorN<T, D> operator+(const AbstractVectorN<T, D>& rhs) const;
		AbstractVectorN<T, D> operator-(const AbstractVectorN<T, D>& rhs) const;
		AbstractVectorN<T, D> operator*(T rhs) const;
		T& operator[](int idx);
		const T& operator[](int idx) const;
		AbstractVectorN<T, D>& operator=(const AbstractVectorN<T, D>& rhs);
		bool operator==(const AbstractVectorN<T, D>& rhs);		
	};
	template<class T, unsigned int D>
	inline AbstractVectorN<T, D> operator*(T lhs, const AbstractVectorN<T, D>& rhs);

	template<class T, unsigned int D>
	AbstractVectorN<T, D>::AbstractVectorN(){
		for (int i = 0; i < D; ++i){
			this->data[i] = static_cast<T>(0);
		}
	}

	template<class T, unsigned int D>
	AbstractVectorN<T, D>::AbstractVectorN(const AbstractVectorN<T, D>& src){
		//Abfrage ob die Vektoren dieselbe Dimension haben notwendig?
		for (int i = 0; i < D; ++i){
			this->data[i] = src[i];
		}
	}

	template<class T, unsigned int D>
	AbstractVectorN<T, D>::~AbstractVectorN(){
	}

	template<class T, unsigned int D>
	T AbstractVectorN<T, D>::length() const{
		return static_cast<T>(sqrt(dot(*this)));
	}

	//static_cast<T> geht hier nicht wieso
	template<class T, unsigned int D>
	T AbstractVectorN<T, D>::dot(const AbstractVectorN<T, D>& rhs) const{
		T product(0);
		for (int i = 0; i < D; ++i){
			product += this->data[i] * static_cast<T>(rhs[i]);
		}
		return product;
	}

	template<class T, unsigned int D>
	void AbstractVectorN<T, D>::normalize(){
		T magnitude = static_cast<T>(length());
		if (magnitude != 0){
			for (int i = 0; i < D; ++i){
				this->data[i] /= magnitude;
			}
		}
	}

	template<class T, unsigned int D>
	AbstractVectorN<T, D> AbstractVectorN<T, D>::operator+(const AbstractVectorN<T, D>& rhs) const{		
		AbstractVectorN v = *this;
		for (int i = 0; i < D; ++i){
			v[i] += static_cast<T>(rhs[i]);
		}
		return v;
	}

	template<class T, unsigned int D>
	AbstractVectorN<T, D> AbstractVectorN<T, D>::operator-(const AbstractVectorN<T, D>& rhs) const{
		AbstractVectorN v = *this;
		for (int i = 0; i < D; ++i){
			v[i] -= static_cast<T>(rhs[i]);
		}
		return v;
	}

	template<class T, unsigned int D>
	AbstractVectorN<T, D> AbstractVectorN<T, D>::operator*(T rhs) const{
		AbstractVectorN v = *this;
		for (int i = 0; i < D; ++i){
			v[i] *= static_cast<T>(rhs);
		}
		return v;
	}

	template<class T, unsigned int D>
	T& AbstractVectorN<T, D>::operator[](int idx){
		if (idx <0 || idx >D){
			std::cerr << "Out of range: " << idx << "\n";
			exit(-1);
		}
		return data[idx];
	}

	template<class T, unsigned int D>
	const T& AbstractVectorN<T, D>::operator[](int idx) const{
		if (idx <0 || idx >D){
			std::cerr << "Out of range: " << idx << "\n";
			exit(-1);
		}
		return data[idx];
	}

	template<class T, unsigned int D>
	AbstractVectorN<T, D>& AbstractVectorN<T, D>::operator=(const AbstractVectorN<T,D>& rhs){
		if (*this == rhs){
			return *this;
		}
		for (int i = 0; i < D; ++i){
			this->data[i] = static_cast<T>(rhs[i]);
		}
		return *this;
	}

	//todo
	template<class T, unsigned int D>
	bool AbstractVectorN<T, D>::operator==(const AbstractVectorN<T, D>& rhs){
		AbstractVectorN<T, D> v = *this;
		for (int i = 0; i < D; ++i){
			if (abs(v[i] - rhs[i]) > epsilon)
			{
				return false;
			}
		}
		return true;
	}

	template<class T, unsigned int D>
	inline AbstractVectorN<T,D> operator*(T lhs, const AbstractVectorN<T, D>& rhs){
		AbstractVectorN<T, D> temp = AbstractVectorN<T, D>();
		for (int i = 0; i < D; ++i){
			temp[i]=lhs*rhs[i];
		}
		return temp;
	}
}
#endif