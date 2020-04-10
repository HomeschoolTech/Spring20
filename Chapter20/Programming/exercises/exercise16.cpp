#include "vector.h"
#include "iostream"
#include "memory"
using std::allocator;

template <typename T,typename A = allocator<T> >
class ovector : vector{
public:
	T& operator[](int n) override{
		return elem[n]&;
	}	
	const T& operator[](int n) const override{
		return elem[n]&;
	}
		
};

int main(){
	ovector<int*> ov;
	for(int i = 0; i < 10; ++i){
		ov.push_back(&i);
	}
	for(auto& i : ov){
		std::cout << *i;
	}
	std::cout << std::endl;
}
