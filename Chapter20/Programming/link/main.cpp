#include "link.h"
#include "iostream"
using std::cout, std::endl;
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Iterator Tests", "[list]"){
	// setup link
	Link<int> link, link_prev;
	link.elem = 5;
	link_prev.elem = 4;
	link.prev = &link_prev;
	link_prev.next = &link;	

	SECTION("Test Constctor"){
		auto it = Iterator<int>(&link);
	}
	SECTION("TEST * operator"){
		auto it = Iterator<int>(&link);
		REQUIRE(*it == 5);
		
		auto it_null = Iterator<int>(nullptr);
		//REQUIRE_THROWS(*it_null); 

	}
	SECTION("TEST == operator"){
		auto it1 = Iterator<int>(&link);
		auto it2 = Iterator<int>(&link);
		REQUIRE(it1 == it2);
		
		auto it3 = Iterator<int>(&link_prev);
		REQUIRE_FALSE(it1 == it3);
		

		auto it_null1 = Iterator<int>(nullptr);
		auto it_null2 = Iterator<int>(nullptr);
		REQUIRE(it_null1 == it_null2);
		REQUIRE_NOTHROW(it_null1 == it_null2);
	}
	SECTION("TEST != operator"){
		auto it1 = Iterator<int>(&link);
		auto it2 = Iterator<int>(&link);
		REQUIRE_FALSE(it1 != it2);
		
		auto it3 = Iterator<int>(&link_prev);
		REQUIRE(it1 != it3);

		auto it_null1 = Iterator<int>(nullptr);
		REQUIRE(it_null1 != it1);
		REQUIRE_NOTHROW(it_null1 != it1);
	}
	SECTION("TEST ++ operator"){
		auto it_prev = Iterator<int>(&link_prev);
		auto it_current = Iterator<int>(&link);

		++it_prev;
		REQUIRE( it_prev == it_current);
	}
	SECTION("TEST -- operator"){
		auto it_prev = Iterator<int>(&link_prev);
		auto it_current = Iterator<int>(&link);

		--it_current;
		REQUIRE( it_current == it_prev);
	}
/*
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
*/
}
