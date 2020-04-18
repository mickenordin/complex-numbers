#include <iostream>
#include "cnumber.hpp"


int main() {
	cnumber a(3,2);
	cnumber b(4,-3);

	cout << "a = " << a << endl;
	cout << "a* = " << a.conjugate() << endl;
	cout << "a*a* = " << a * a.conjugate() << endl;
	cout << "b = " <<  b << endl;
	cout << "b* = " << b.conjugate() << endl;
	cout << "b*b* = " << b * b.conjugate() << endl;
	cout << "a + b =  " << a + b << endl;
	cout << "(a + b)* =  " << (a + b).conjugate() << endl;
	cout << "a - b =  " << a - b << endl;
	cout << "(a - b)* =  " << (a - b).conjugate() << endl;
	cout << "a * b =  " << a * b << endl;
	cout << "(a * b)* =  " << (a * b).conjugate() << endl;
	cout << "a / b =  " << a / b << endl;
	cout << "(a / b)* =  " << (a / b).conjugate() << endl;
}
