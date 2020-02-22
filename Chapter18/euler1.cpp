#include "iostream"

int main(){
	int prime = 0;		//initialize
	int num_prime = 0;
	int check = 0;
	for(int i = 0; num_prime < 10001; ++i){		//check every number until 10,001 primes are found
		if(i % 2 == 0)check = 1;		//if divisible by two skip to end
		else{
			for(int n = 3; n < i; n+=2){	//divide by all numbers less than i 
				if(i % n == 0){		
					if(i == n);
					else check = 1;
				}
				else;
			}
		}
		if(check == 0){			//if check was changed num_prime won't increase and prime won't change
		    	++num_prime;
			prime = i;
		}
		check = 0;	//reset check for next loop
	}
	std::cout << "the 10001 prime number is " << prime << std::endl;
}
