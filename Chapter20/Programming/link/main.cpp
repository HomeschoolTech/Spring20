#include "link.h"
#include "iostream"
using std::cout, std::endl;
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
/*
TEST_CASE("Iterator Tests", "[list]"){
	// setup link
	Link<int> link, link_prev;
	link.elem = 5;
	link_prev.elem = 4;
	link.prev = &link_prev;
	link_prev.next = &link;
	auto it_null = Iterator<int>(nullptr);	

	SECTION("Test Constctor"){
		auto it = Iterator<int>(&link);
	}
	SECTION("TEST * operator"){
		auto it = Iterator<int>(&link);
		REQUIRE(*it == 5);
		
		REQUIRE_THROWS(*it_null); 

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

		REQUIRE(it_null != it1);
		REQUIRE_NOTHROW(it_null != it1);
	}
	SECTION("TEST ++ operator"){
		auto it_prev = Iterator<int>(&link_prev);
		auto it_current = Iterator<int>(&link);

		++it_prev;
		REQUIRE(it_prev == it_current);

		REQUIRE_THROWS(++it_null);
	}
	SECTION("TEST -- operator"){
		auto it_prev = Iterator<int>(&link_prev);
		auto it_current = Iterator<int>(&link);

		--it_current;
		REQUIRE( it_current == it_prev);

		REQUIRE_THROWS(--it_null);
	}
}*/
TEST_CASE("a list filled with items"){
	//create empty list
	List<int> l{};
	//fill list
	//l = 0,1,2,3,4
	for(int i = 0; i < 5; ++i){
		l.insert_front(i);
	}
	REQUIRE(l.size() == 5);

	SECTION("TEST default constructor"){	
		List<int> ls{};
		REQUIRE(ls.size() == 0);
	}
	SECTION("TEST insert"){
		auto null_it = Iterator<int>(nullptr);
		REQUIRE_THROWS(l.insert(null_it, 45));	//using nullptr
*	
		auto it = Iterator<int>(l.begin());
		++it;
		l.insert(it, 34);
		REQUIRE(l.size() == 6);	//expected use*/
	}
	SECTION("TEST insert_front"){
		l.insert_front(54);
		//`REQUIRE(l.size() == 6);
	}
	SECTION("TEST insert_back"){
		l.insert_back(12);
		auto it = Iterator<int>(l.end());
		--it;
		REQUIRE(l.size() == 6);
	}
	SECTION("TEST erase"){
		auto null_it = Iterator<int>(nullptr);
		REQUIRE_THROWS(l.erase(null_it));	//using nullptr
		
		auto it = Iterator<int>(l.begin());
		++it;
		l.erase(it);
		REQUIRE(l.size() == 4);	//expected use
	}
	SECTION("TEST erase_front"){
		l.erase_front();
		REQUIRE(l.size() == 4);
	}	
	SECTION("TEST erase_back"){
		l.erase_back();
		REQUIRE(l.size() == 4);
	}
	SECTION("TEST size()"){
		REQUIRE(l.size() == 5);
	}
	SECTION("TEST empty()"){
		REQUIRE(l.empty() != true);

		List<int> ls{};
		REQUIRE(ls.empty() == true);
	}
}
