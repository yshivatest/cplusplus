//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int vmain() {
	stringstream version;
	version << "GCC version: "
			<< __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__
			<< "\nVersion string: " << __VERSION__;

	cout << version.str() << endl;

	vector<string> v = { "one", "two" }; // C++11 feature - initializer list

	for( string s : v ) {	// C++11 feature - range-based for loop
		cout << s << ",";
	}

	return 0;
}
int main(void) {
	std::cout<<"!!!Hello World!!!";
	vmain();
	return EXIT_SUCCESS;
}
