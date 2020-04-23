#include "iostream"
//relatively slow code

bool is_prime(int num){
	if(num % 2 == 0) return false;	//if even quit
	for(int i = 3; i <num/2; i+=2){		//all factors of num are less than num/2
		if(num % i == 0) return false;	//if a factor is found quit
	}
	return true;		//no factors found
}

int main(){
	long long total = 2;	//start value with 2 so we can start counting at 3 and increment by 2
	for(int i = 3; i < 2000000; i += 2){	//for all odds < 2000000
		if(is_prime(i)) total += i;	//if i is prime add to total
	}
	std::cout << total << std::endl;
}
