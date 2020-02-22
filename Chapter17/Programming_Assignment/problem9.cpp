#include "iostream"

int main(){
	int x = 1;
	int* px = &x;
	int y = 2;
    int* py = &y;
	std::cout << "stack grows: " << px << ", " << py << std::endl;
	
	int* i = new int[4];
	int* i2 = new int [7];
	std::cout << "heap grows: " << i << ", " << i2 << std::endl;


	delete[] i;
	delete[] i2;
}
//the stack grows toward lower addresses
//the free store grows toward higher addresss
