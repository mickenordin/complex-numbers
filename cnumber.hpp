#include <iostream>

using namespace std;

class cnumber {
	private:
		float r, i;
		bool signr, signi;
		bool get_sign(int i) {
			return (i >= 0);
		}

	public:
		// Constructor
		cnumber(int a, int b) {
			r = a;
			i = b;
			signr = get_sign(r);
			signi = get_sign(i);
			
		}
		cnumber(float a, float b) {
			r = a;
			i = b;
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
			cnumber z(this->r, this->i * -1);
			return z;
		}


		// Operators
		cnumber operator+(const cnumber &that) {
			cnumber z(this->r + that.r, this->i + that.i);
			return z;
		}
		cnumber operator-(const cnumber &that) {
			cnumber z(this->r - that.r, this->i - that.i);
			return z;
		}
		cnumber operator*(const cnumber &that) {
			cnumber z( (this->r * that.r ) - (this->i * that.i) , (this->r * that.i) + (that.r * this->i) );
			return z;
		}
		cnumber operator/(const cnumber &that) {
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

