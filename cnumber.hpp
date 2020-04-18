#include <iostream>

using namespace std;

class cnumber {
	private:
		int r, i;
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
		// Member functions
		cnumber conjugate() {
			cnumber z(this->r, this->i * -1);
			return z;
		}


		// Operators
		cnumber operator+(const cnumber &that) {
			cnumber z(that.r + this->r, that.i + this->i);
			return z;
		}
		cnumber operator*(const cnumber &that) {
			cnumber z( (that.r * this->r ) - (that.i * this->i) , (that.r * this->i) + (this->r * that.i) );
			return z;
		}

		friend ostream &operator<<( ostream &os, const cnumber &z ) { 
			if (z.r != 0) {
				os << z.r; 
				if (z.signi && (z.i != 0)) {
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

