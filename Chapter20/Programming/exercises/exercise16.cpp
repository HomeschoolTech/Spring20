#include "iostream"
#include "memory"
#include "pvector.h"
using std::allocator;
//works but T must = int
//didn't know what type to return for [] operators
template <typename T>
class ovector : public pvector<T>{
public:
	T& operator[](int n) {
		std::cout << "ovector subscript" << std::endl;
		return *((this->elem)[n]);
	}	
	const T& operator[](int n) const{
		std::cout << "ovector const subscript" << std::endl;
		return *((this->elem)[n]);
	}
};

int main(){
	ovector<int> ov;
	for(int i = 0; i < 10; ++i){
		ov.push_back(new int(i));
	}
	for(int i = 0; i < ov.size(); ++i){
		std::cout << "ov[" << i << "] = " << ov[i] << std::endl;
	}
	/*for(auto& i : ov){
		std::cout << '(' << *i << ", ";
	}*/
	std::cout << ')' << std::endl;
}
