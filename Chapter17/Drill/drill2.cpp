#include "iostream"
void cout_array(int* array, int size){                                                                                         
    for(int i = 0; i < size; ++i){                                                                                              
       std::cout << array[i] << ", ";                                                                              
    }                                                                                                               
    std::cout << std::endl;                                                                                 
}

void copy_array(int* array1, int* array2, int size){
    for(int i=0; i < size; ++i)
        array2[i] = array1[i];
}

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
	copy_array(p1, p2, 10);
	std::cout << "p1: " << p1 << ", " << *p1 << std::endl
		<< "p2: " << p2 << ", " << *p2 << std::endl;
	std::cout << p2 << ", ";
	cout_array(p2, 10);
	std::cout << std::endl;
	std::cout << p1 << ", " << i << std::endl;
	delete[ ] a;
}
