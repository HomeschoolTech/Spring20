#include <iostream>
#include <vector.h>
#include "memory"
using namespace std;
template <typename T>
class pvector : public vector<T*>{
public:
	~pvector(){
		cout << "pvector destructor" << endl;
		for(int i = 0; i < this->size(); ++i){
			delete (this->elem)[i];
		}
	}
};
int main(){
	
	pvector <int> pv;
	
	for(int i = 0; i < 10; ++i){
		pv.push_back(new int (i));
	}
	/*for(auto& i : pv){
		std::cout << *i;
	}*/
	for(int i = 0; i < pv.size(); ++i){
		cout << "pv[" << i << "] = " << *pv[i] << endl;
	}
}
