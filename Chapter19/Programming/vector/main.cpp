#include "vector.h"
#include <iostream>
using std::cout, std::endl;

int main(){

	vector<double> vec;
	for(int i = 0; i < 9; ++i)
		vec.push_back(i);
	
	vec.reserve(5);


}
