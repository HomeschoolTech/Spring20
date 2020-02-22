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
//no destructor
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
	Link* p = this; // Added p, change "this" to p
	while(p->value != s){ 
		p = p->succ;	
		if(!p) return nullptr; 
	}
	return p;
}
Link* Link::advance(int n) {
	if(this == nullptr) return nullptr;
	Link* p = this; // Added p, chaned this to p
	if(0 < n){
		while(n--){
			if( p -> succ == nullptr) return nullptr;
			p = p -> succ;
		}
	}
	else if(n < 0){
		while(n++){
			if(p -> prev == nullptr) return nullptr;
			p = p -> prev;
		}
	}
	return p;		
}
