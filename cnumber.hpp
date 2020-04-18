#include <iostream>
#include "../fractions/fractions.hpp"

using namespace std;

class cnumber {
	private:
		fraction r, i;
		bool signr, signi;
		bool get_sign(const fraction &q) {
			return q.sign();
		}

	public:
		// Constructor
		cnumber(const fraction &a, const fraction &b) {
			r = a;
			i = b;
			signr = get_sign(r);
			signi = get_sign(i);
		}
		cnumber(int a, int b) {
			fraction qa(a);
			fraction qb(b);
			r = qa;
			i = qb;
			signr = get_sign(r);
			signi = get_sign(i);
		}
		cnumber(double a, double b) {
			fraction qa(a);
			fraction qb(b);
			r = qa;
			i = qb;
			signr = get_sign(r);
			signi = get_sign(i);
		}
		cnumber(const cnumber &z) {
			r = z.r;
			i = z.i;
			signr = z.signr;
			signi = z.signi;
		}
		// Member functions
		cnumber conjugate() const {
			cnumber z(fraction(this->r.get_n(),this->r.get_d()),fraction(this->i.get_n() * -1, this->i.get_d()));
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
		cnumber operator*(const int i) const {
			cnumber that(i,0);
			cnumber z( *this * that);
			return z;
		}
		cnumber operator*(const fraction &dec) const {
			cnumber that(dec,0);
			cnumber z( *this * that);
			return z;
		}
		cnumber operator*(const cnumber &that) const {
			cnumber z( (this->r * that.r ) - (this->i * that.i) , (this->r * that.i) + (that.r * this->i) );
			return z;
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
				if (z.signi && (z.i > 0)) {
					os << '+';
				}
			}
			if (z.i != 0) {
				if ((z.i != 1) && (z.i != -1)) {
					os << z.i;
				}	
				else {
					if (! z.signi) {
						os << '-';
					}
				}
				os << 'i';
			}
			return os;            
		}
		void operator=(const cnumber &z ) { 
			r = z.r;
			i = z.i;
			signr = z.signr;
			signi = z.signi;
		}
}; 

