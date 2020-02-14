#include "std_lib_facilities.h"

class Link{
	public:
		string value;
		
		Link(const string& v, Link* p = nullptr, Link* s = nullptr)
			: value(v), prev{p}, succ{s} {}

		Link* insert(Link* n);
		Link* add(Link*  n);
		Link* erase();
		Link* find(const string&s);

		Link* advance(int n);

		Link* next() const {return succ;}
		Link* previous() const {return prev;}
	private:
		Link* prev;
		Link* succ;
};
Link* Link::insert(Link* n){
	if(n == nullptr) return this;
	if(this == nullptr) return n;
	n -> succ = this;
	if(this -> prev) this -> prev -> succ = n;
	n -> prev = this -> prev;
	this -> prev = n;
	return n;
}
Link* Link::erase(){
	if(this == nullptr) return nullptr;
	if(this -> succ) this -> succ -> prev = this -> prev;
	if(this -> prev) this -> prev -> succ = this -> succ;
	return this -> succ;
}
Link* Link::find(const string& s){
	while(this){
		if(this -> value == s) return this;
		this = this -> succ;
	}
	return nullptr;
}
Link* Link::advance(int n) {
	if(this == nullptr) return nullptr;
	if(0 < n){
		while(n--){
			if(this -> succ == nullptr) return nullptr;
			this = this -> succ;
		}
	}
	else if(n < 0){
		while(n++){
			if(this -> prev == nullptr) return nullptr;
			this = this -> prev;
		}
	}
	return this;		
}
