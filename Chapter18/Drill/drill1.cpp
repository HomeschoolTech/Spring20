//this is the portion of the drill on arrays
#include "iostream"


int ga[10] = { 1,2,4,8,16,32,64,128,256,512};

int fact(int n){
	if(n == 1) return n;
	for(int i = n-1; i > 0; --i){
		n*=i;
	}
	return n;
}

int f(int ar[], int n){
	std::cin >> n;
	int newarray[n]; 
	newarray[0] = 1;

	int la[10];
	for(int i = 0; i < 10; ++i){
		la[i] = ga[i];
		std::cout << la[i] << ", ";
	}
	std::cout << std::endl;
	int* p = new int [n];
	int* p1 = p; 
	for(int i = 0; i < n; ++i){
		p[i] = ar[i];
		std::cout << p[i] << ", ";	
	}
	std::cout << std::endl;	
	delete[] p1;
}
int main(){
	f(ga, 10);
	int aa[10] = {fact(1),fact(2),fact(3),fact(4),fact(5),fact(6),fact(7),fact(8),fact(9),fact(10)};
	f(aa, 10);
}
