#include <iostream>
#include "../fractions/fractions.hpp"

using namespace std;

class cnumber {
	private:
		fraction r,i;

	public:
		// Constructor
		cnumber(const fraction &a, const fraction &b) {
			r = a;
			i = b;
		}
		cnumber(int a, int b) {
			r = a;
			i = b;
		}
		cnumber(double a, double b) {
			r = a;
			i = b;
		}
		// Member functions
		cnumber conjugate() const {
			fraction a(this->r.get_n(), this->r.get_d());
			fraction b(this->i.get_n(), this->i.get_d());
			cnumber z(a,b * -1);
			return z;
		}

		// Operators
		cnumber operator+(const cnumber &that) const {
			cnumber z(this->r + that.r, this->i + that.i);
			return z;
		}
		cnumber operator-(const cnumber &that) const {
			cnumber z(this->r - that.r, this->i - that.i);
			return z;
		}
		cnumber operator*(const cnumber &that) const {
			cnumber z( (that.r * this->r ) - (that.i * this->i) , (that.r * this->i) + (this->r * that.i) );
			return z;
		}
		cnumber operator*(const fraction &q) const {
			cnumber that(q,fraction(0));
			return *this * that;
		}
		cnumber operator/(const cnumber &that) const {
			cnumber numerator( (this->r * that.r ) - (this->i * ( that.i * -1)) , (this->r * (that.i * -1)) + (that.r * this->i) );
			cnumber denominator( (that.r * that.r ) - (that.i * ( that.i * -1)) , (that.r * (that.i * -1)) + (that.r * that.i) );
			cnumber ratio(numerator.r / denominator.r, numerator.i / denominator.r);
			return ratio;
		}

		friend ostream &operator<<( ostream &os, const cnumber &z ) { 
			if (z.r != 0) {
				os << z.r; 
				if ((z.i.get_sign() == 1) && (z.i > 0)) {
					os << '+';
				}
			}
			if (z.i != 0) {
				if ((z.i != 1) && (z.i != -1)) {
					os << z.i;
				} else if (z.i == -1) {
					os << '-';
				}	
				os << 'i';
			}
			return os;            
		}
		void operator=(const cnumber &z ) { 
			r = z.r;
			i = z.i;
		}
}; 

