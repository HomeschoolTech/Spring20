#include "iostream"

void swap(int* a[], int* b[]){
	int** p = a; 
	a = b;
	b = p;
}

int main(){
	int* a = new int [5] {1,2,3,4,5};
	int* b = new int [5] {5,4,3,2,1};
	int** ap = a;
	int** bp = b;
	swap(ap, bp);
	for(int i = 0; i < 5; ++i){
		std::cout << ap[i] << ", ";
	}
	std::cout << std::endl;
	for(int i = 0; i < 5; ++i){
		std::cout <<  bp[i] << ", ";
	}
	std::cout << std::endl;
	delete[] a;
	delete[] b;
}
