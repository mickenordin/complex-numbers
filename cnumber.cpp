#include <iostream>
#include "cnumber.hpp"


int main() {
	cnumber a(1, -3);
	cnumber b(2, 5);

	cout << "a = " << a << endl;
	cout << "a* = " << a.conjugate() << endl;
	cout << "b = " <<  b << endl;
	cout << "b* = " << b.conjugate() << endl;
	cout << "a + b =  " << a + b << endl;
	cout << "(a + b)* =  " << (a + b).conjugate() << endl;
	cout << "a * b =  " << a * b << endl;
	cout << "(a * b)* =  " << (a * b).conjugate() << endl;
}
