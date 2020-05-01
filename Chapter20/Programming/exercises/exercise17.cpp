#include "pvector.h"
#include "iostream"

template <typename T>
class ownership_vector : public pvector<T>{
	vector<T*> owned;
public:
	void push_back(const T& val){
		if(this->space == 0) this->reserve(4);
		else if(this->space == this->sz) this->reserve(2*this->space);
		*(this->elem[this->sz]) = val;
		++this->sz;
	}
	void push_back(T* val){
		if(this->space == 0) this->reserve(4);
		else if(this->space == this->sz) this->reserve(2*this->space);
		this->elem[this->sz] = val;
		 owned[owned.size()] = val;
		++this->sz;
	}
	~ownership_vector(){
		std::cout << "ownership destructor" << std::endl;
		for(int i = 0; i < owned.size(); ++i){
			delete owned[i];
		}
	}
};

int main(){
	ownership_vector<int> ownv;
	int x = 94;
	int y = 12;
	int z = -43;
	ownv.push_back(x);
	ownv.push_back(y);
	ownv.push_back(z);
	for(int i = 0; i < 10; ++i){
		ownv.push_back(new int(i));
	}
	for(int i = 0; i < ownv.size(); ++i){
		std::cout << ownv[i] << std::endl;
	}
	std::cout << 'x' << x << 'y' << y << 'z' << z << std::endl;
}
