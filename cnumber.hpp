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
		cnumber(int a, int b) {
			r = a;
			i = b;
			signr = get_sign(r);
			signi = get_sign(i);
			
		}

		friend ostream &operator<<( ostream &os, const cnumber &z ) { 
			os << z.r << (z.signi ? '+' : '-') << 'i' << (z.signi ? z.i : z.i * -1); 
			return os;            
		}


}; 

