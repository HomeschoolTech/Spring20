#include "iostream"
#include "std_lib_facilities.h"
void print_array(std::ostream& os, int*a, int n){
	for(int i = 0; i < n; ++i){
		os << a[i] << ", ";
	}
	os << std::endl; 
}
void cout_array(int* i, int n){
	for(int p = 0; p < n;++p){
		std::cout << i[p] << ", ";
	}
        std::cout << std::endl;
}
void print_vector(std::ostream& os, vector <int> a){
	for(int i = 0; i < a.size(); ++i){
		os << a[i] << ", ";
       	}                                                                                                               os << std::endl;
}
int main(){
	std::cout << "what is the file you would like to use: ";
	string os;
	cin >> os;
	std::ofstream ofs(os);
	int* i = new int[10]{100,101,102,103,104,105,106,107,108,109};
	int* p = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
	int* q = new int[20]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
	vector <int> v = {100,101,102,103,104,105,106,107,108,109,110};
	vector <int> v2 = {100,101,102,103,104,105,106,107,108,109,110};
	vector <int> v3 = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
	print_array(ofs, i, 10);
	print_vector(ofs, v);
	print_vector(ofs, v2);
	print_vector(ofs, v3);
	cout_array(i, 10);
	cout_array(p, 11);
	cout_array(q, 20);
	delete[ ] i;
	delete[ ] p;
	delete[ ] q;
	return 0;
}
