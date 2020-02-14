#include "iostream"

int main(){
	std::cout << "enter characters(! to stop): ";
	char ch;
	char* pc = new char[100000000];
	int n = 0;
	while(std::cin >> ch){
		if(ch == '!') break;
		else{
		pc[n] = ch;
		++n;
		}
	}
	delete[] pc;
}
