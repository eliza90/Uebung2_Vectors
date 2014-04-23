#ifndef _Vector3f_hpp_included 
#define _Vector3f_hpp_included 

namespace cpp4cg {
	class Vector3f{
	private:
		float data[3];
		const float epsilon = 0.001f;
	public: Vector3f();
			Vector3f(const Vector3f& src);
			Vector3f(float x, float y, float z);
			~Vector3f(); //destructor
			float length() const;
			void normalize();
			float dot(const Vector3f& rhs) const;
			Vector3f cross(const Vector3f& rhs) const;
			Vector3f operator+(const Vector3f& rhs) const;
			Vector3f operator-(const Vector3f& rhs) const;
			Vector3f operator*(float rhs) const;
			float& operator[](int idx);
			const float& operator[](int idx) const;
			Vector3f& operator=(const Vector3f& rhs);
			bool operator==(const Vector3f& rhs);
			//inline Member
			const float getEpsilon() const{	return epsilon;	}
			float get_x() const{ return data[0];}
			float get_y() const{ return data[1];}
			float get_z() const{ return data[2];}
			void set_x(float x){data[0] = x;}
			void set_y(float y){data[1] = y;}
			void set_z(float z){data[2] = z;}
			void set(float x, float y, float z){data[0] = x; data[1] = y; data[2] = z;}
		//to do -> exception
			//float get_data(int i) const{if (i <0 || i >2){throw;} return data[i];}
	};
	Vector3f operator*(float lhs, const Vector3f& rhs);
}

#endif