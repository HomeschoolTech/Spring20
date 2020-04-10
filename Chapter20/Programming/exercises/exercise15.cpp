#include <iostream>
#include <vector.h>
#include "memory"
using namespace std;
template <typename T>
class pvector : vector<T>{
public:
	~vector() override{
		delete[] *elem;
	}
};
int main(){
	pvector <int*> pv;
	for(int i = 0; i < 10; ++i){
		pv.push_back(&i);
	}
	for(auto& i : pv){
		std::cout << *i;
	}
	std::cout << std::endl;
}
