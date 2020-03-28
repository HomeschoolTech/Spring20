#include "vector.h"
#include <iostream>
using std::cout, std::endl;
//comments tell what is being teste 
//had trouble with assignment opertors recieved "allocater" error

int main(){


	vector<double> vec;		//initialization/pushback
	for(int i = 0; i < 9; ++i)
		vec.push_back(i);
	
	vec.reserve(5);		//reserve()
	
	vector<double> vec2(vec);	//copy constuctor
	
	vec2.resize(5);		//resize()

	for(int i = 0; i < vec.capacity(); ++i){	//capacity()/[]operator
		cout << vec[i] << ',';
	}
	cout << endl;
	for(int i = 0; i < vec2.size(); ++i){	//size()/[]operator
		cout << vec2[i] << ',';
	}

	vector<double> vec3 = vec;
}
