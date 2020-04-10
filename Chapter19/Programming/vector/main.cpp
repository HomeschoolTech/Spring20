#include "vector.h"
#include <iostream>
using std::cout, std::endl;
//comments tell what is being teste 
//had trouble with assignment opertors recieved "allocater" error

int main(){

	//default constructor
	//empty vector
	vector<double> vec;

	//push_back
	//0,1,2,3,4,5,6,7,8
	for(int i = 0; i < 9; ++i){
		vec.push_back(i);
	}

	//reserve
	//0,1,2,3,4,5,6,7,8,0,0,0,0,0	five extra spaces
	vec.reserve(5);	

	//copy constructor
	//vec = 0,1,2,3,4,5,6,7,8 + five zeros
	//vec2 = 0,1,2,3,4,5,6,7,8
	vector<double> vec2(vec);
	
	//resize
	//vec = unchanged
	//vec2 = 0,1,2,3,4	//atlers the vecto so only 5 spaces remain
	vec2.resize(5);		

	//capacity
	//vec = 0,1,2,3,4,5,6,7,8,0,0,0,0,0
	for(int i = 0; i < vec.capacity(); ++i){	//capacity() includes unused space
		cout << vec[i] << ',';			//tests subscripting '[]'
	}
	cout << endl;

	//size
	//vec2 = 0,1,2,3,4
	for(int i = 0; i < vec2.size(); ++i){	//size() includes all used space
		cout << vec2[i] << ',';		//also tests subscripts
	}
	
	//copy assignment
	//vec unchanged
	//vec3 = 0,1,2,3,4,5,6,7,8	doesn't copy added space 
	//vector<double> vec3 = vec;

	//move assignment
	//vec = 0,1,2,3,4,5,6,7,8
	//vec3 = 0,1,2,3,4,5,6,7,8
	//vec = vec3;

}
