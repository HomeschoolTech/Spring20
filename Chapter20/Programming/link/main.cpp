#include "link.h"
#include "iostream"
using std::cout, std::endl;

int main(){
	//create empty list
	List<int> l();
	//fill list
	//l = 0,1,2,3,4
	for(int i = 0; i < 5; ++i){
		l.insert_front(i);
	}	
	//testing i and *i
	//address, 0
	//address, 1 (etc)
	for(auto& i : l){
		cout << i << ", " << *i << endl;		
	}
	//testing '=='
	//same address for 2 as above 
	for(auto& i : l){
		if(*i == 2) cout << i << endl;
	}
	//testing '!='
	//same addresses as first skipping 3
	for(auto& i : l){
		if(*i != 3) cout << i << endl;
	}
	//testing ++
	//same addresses as above including 3
	Iterator<> i = l.begin();
	while(i != l.end()){
		cout << i << ',';
		++i;
		cout << endl;
	}	
	//testing --
	//same as last but in reverse order
	while(i != l.begin()){
		cout << i << ',';
		--i;
		cout << endl;
	}
}
