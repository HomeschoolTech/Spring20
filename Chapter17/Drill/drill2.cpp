#include "iostream"
void cout_array(int* i, int n){                                                                                         for(int p = 0; p < n;++p){                                                                                              std::cout << i[p] << ", ";                                                                              }                                                                                                               std::cout << std::endl;                                                                                 }
int main(){
	int i = 7;
	int* p1 = &i;
	int* a = new int[7]{1,2,4,8,16,32,64};
	int* p2 = a;
	int* p3 = p2;
	p1 = p2;
	p3 = p2;
	int* ar = new int[10]{1,2,4,8,16,32,64,128,256,512};
	p1 = ar;
	int* a10 = new int[10];
	p2 = a10;
	p2 = *p1;
	std::cout << "p1: " << p1 << ", " << *p1 << std::endl
		<< "p2: " << p2 << ", " << *p2 << std::endl;
	std::cout << p2 << ", ";
	cout_array(p2, 7);
	std::cout << std::endl;
	std::cout << p1 << ", " << i << std::endl;
	delete[ ] a;
}
