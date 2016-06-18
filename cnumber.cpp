#include <iostream>
#include "cnumber.hpp"


int main() {
	cnumber a(1, -3);
	cnumber b(2, 5);

	cout << "a = " << a << " b = " <<  b << " a + b =  " << a + b << endl;
	cout << "a = " << a << " b = " <<  b << " a * b =  " << a * b << endl;
}
