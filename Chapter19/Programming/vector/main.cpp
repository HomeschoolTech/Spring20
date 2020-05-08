#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.h"
#include <iostream>
using std::cout;
using std::endl;
//comments tell what is being teste 
//had trouble with assignment opertors recieved "allocater" error

TEST_CASE("vectors can be sized and resized", "[vector]"){
	
	//default constructor
	//empty vector
	vector<double> vec;

	//push_back
	//0,1,2,3,4,5,6,7,8
	for(double i = 0; i < 9; ++i){
		vec.push_back(i);
	}

	REQUIRE(vec.size() == 9);
	REQUIRE(vec.capacity() >= 9);
	
	SECTION("reserving bigger changes capacity but not size"){
	//reserve
	//0,1,2,3,4,5,6,7,8,0,0,0,0,0	five extra spaces
	vec.reserve(5);	
	REQUIRE(vec.size() == 9);
	REQUIRE(vec.capacity() >= 14);
	}
	SECTION("reserving smaller does not change size or capacity"){
		vec.reserve(0);
		REQUIRE(vec.size() == 9);
		REQUIRE(vec.capacity() >= 9;
	}
	SECTION("resizing smaller changes size but not capacity"){
	//resize
	//vec = unchanged
	//vec2 = 0,1,2,3,4	//atlers the vecto so only 5 spaces remain
	vec.resize(5);	
	REQUIRE(vec.size() ==5);
	REQUIRE(vec.capacity() >= 9);	
	}
	SECTION("resizing bigger changes size and capacity"){
		vec.resize(15);
		REQUIRE(vec.size() == 15);
		REQUIRE(vec.capacity() >= 15);
	}
	SECTION("copying doesn't change vector"){
		vector<double> vec2(vec);
		cout << "vec: (";
		//testing subscripts
		for(int i = 0; i < vec.size(); ++i){
			cout << vec[i] << ',';
		}
		cout << endl;
		cout << "vec: (";
		for(int i = 0; i < vec2.size(); ++i){
			cout << vec2[i] << ',';
		}
		cout << endl;
		REQUIRE(vec.size() == 9);
		REQUIRE(vec.capacity() >= 9);
		REQUIRE(vec2.size() == 9);
		REQUIRE(vec.capacity() >=9);
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
