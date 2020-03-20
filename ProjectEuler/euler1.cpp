#include "iostream"

int main(){
	int sum = 0;
	for(int i = 0; i < 1000; ++i){		//check every number < 1000
		if(i % 3 == 0) sum += i;	//check if it is evenly divisible by three
		else if(i % 5 == 0) sum += i;	//if not divisible by three check if divisible by 5
	}
	std::cout << sum << std::endl;		//print answer
}
