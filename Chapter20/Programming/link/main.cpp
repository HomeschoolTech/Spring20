#include "link.h"
#include "iostream"
using std::cout, std::endl;
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("a list filled with items"){
	//create empty list
	List<int> l{};
	Iterator<int> iter = l.begin();
	//fill list
	//l = 0,1,2,3,4
	for(int i = 0; i < 5; ++i){
		l.insert_front(i);
	}
	REQUIRE(l.size() == 5);
	REQUIRE(iter == l.begin());

	SECTION("'*' operator returns the value at a location"){	
		//testing i and *i
		//address, 0
		//address, 1 (etc)
		//also tests "!="
		//also tests "++"
		for(iter = l.begin(); iter != l.end(); ++iter){
			cout << ", " << *iter << endl;		
		}
		REQUIRE(l.size() == 5);
		REQUIRE(iter == l.end());
	}
	SECTION("== is true if iter is equal to what is being compared"){
		//same address for 2 as above 
		for(iter = l.begin(); iter != l.end(); ++iter){
			if(iter == (++(++l.begin()))) cout << *iter << endl;
		}
		REQUIRE(l.size() == 5);
		REQUIRE(iter == l.end());
	}
	SECTION("-- goes back to the previous value"){
		//testing --
		//same as last but in reverse order
		for(iter = l.end(); iter != l.begin(); --iter){
			cout << *iter << ',';
		}
		cout << endl;
		REQUIRE(l.size() == 5);
		REQUIRE(iter == l.begin());
	}
}
