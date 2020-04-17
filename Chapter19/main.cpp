#include "vector.h"
#include "iostream"

int main(){
	vector <int> v = {1,2,3,4,5};
	v.resize(10);
	v.push_back(11);
	vector <int> v2 = {5,4,3,2,1};
	v2=v;
	for(auto& i : v2){
		std::cout << v2[i] << ", ";
	}
}
