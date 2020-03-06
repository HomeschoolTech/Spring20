#include "iostream"

int triplet_1000(){
	int sum = 0;
	int sum_sq;
	for(int cp = 0; cp < 1000; ++cp){		//iterate through every possible c value
		for(int bp = 0; bp < 1000; ++bp){		//iterate through every possible b value
			for(int ap = 0; ap < 1000; ++ap){	//iterate through every possible a value
				sum = ap + bp + cp;		//add the values
				if(sum == 1000){		//check if sum is equal to 1000
					sum_sq = ap*ap + bp*bp;	
					if(sum_sq == cp*cp) return ap*bp*cp;	//if a^2 + b^2 = c^2 return a*b*c
					sum_sq = 0;
				}
				else sum = 0;		//reset the sum
			}
		}
	}
}
int main(){
	int x = triplet_1000();
	std::cout << x << std::endl;
}
