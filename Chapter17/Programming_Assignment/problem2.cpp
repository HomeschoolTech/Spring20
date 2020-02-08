//4 byte in an int
//8 bytes in a double
//1 byte in a bool
#include "iostream"

int main(){
	std::cout << "size of int: " << sizeof(int) << '\n' 
		<< "size of double: " << sizeof(double) << '\n'
		<< "size of bool: " << sizeof(bool) << '\n';
	return 0;
}
