#include <iostream>
#include "vector.h"
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
