#include "iostream"

void swap(int* pa[], int* pb[]){
	int* p = *pa; 
	*pa = *pb;
	*pb = p;
}

int main(){
	int x = 9;

	int* px = &x;

	int* a = new int [5] {1,2,3,4,5};
	int* b = new int [5] {5,4,3,2,1};
	//int** ap = a;
	//int** bp = b;
	swap(&a, &b);
	for(int i = 0; i < 5; ++i){
		std::cout << a[i] << ", ";
	}
	std::cout << std::endl;
	for(int i = 0; i < 5; ++i){
		std::cout <<  b[i] << ", ";
	}
	std::cout << std::endl;
	delete[] a;
	delete[] b;
}
