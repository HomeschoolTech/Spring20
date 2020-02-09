//4 byte in an int
//8 bytes in a double
//1 byte in a bool
#include "iostream"

int main(){

	// Problem wanted you do do this using pointers, not sizeof()
	
    int* pi = new int[2]; // Get two consecutive ints
    void* v1 = &pi[1];    // use trick I showed you to convert the two into char*
    void* v0 = &pi[0];    // Use char* because it is defined to have size 1 byte

	// The difference of the two will be the number of bytes
    std::cout << "size(int) = " << static_cast<char*>(v1) - static_cast<char*>(v0) << std::endl;

    char* pc = new char[2];
    v1 = &pc[1];
    v0 = &pc[0];
    std::cout << "size(char) = " << static_cast<char*>(v1) - static_cast<char*>(v0) << std::endl;
    
    double* pd = new double[2];
    v1 = &pd[1];
    v0 = &pd[0];
    std::cout << "size(double) = " << static_cast<char*>(v1) - static_cast<char*>(v0) << std::endl;

    bool* pb = new bool[2];
    v1 = &pb[1];
    v0 = &pb[0];
    std::cout << "size(bool) = " << static_cast<char*>(v1) - static_cast<char*>(v0) << std::endl;

    delete[] pi, pc, pd, pb;

    // Your code
    std::cout << "size of int: " << sizeof(int) << '\n' 
		<< "size of double: " << sizeof(double) << '\n'
		<< "size of bool: " << sizeof(bool) << '\n';
	return 0;
}
