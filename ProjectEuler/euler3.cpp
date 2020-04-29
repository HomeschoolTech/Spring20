#include "iostream"
#include <cmath>
#include "vector"
#include <algorithm>
using namespace std;
//relatively slow code

bool is_prime(int num){
	if(num <= 1) return false;
	if(num == 2) return true;
	if(num % 2 == 0) return false;	//if even quit
	if(num == 3) return true;
	for(int i = 3; i < sqrt(num); i+=2){		//all factors of num are less than num/2
		if(num % i == 0) return false;	//if a factor is found quit
	}
	return true;		//no factors found
}

int main(){
	vector<int> answer;
	long long max = 600851475143;
	for(int i = 0; i < max; ++i){	//for all odds < 2000000
		if(is_prime(max)){
			answer.push_back(max);
			i = max;
		}
		if(is_prime(i) && max % i == 0 && 600851475143 % i == 0){
		       	answer.push_back(i);	//if i is prime add to total
			max = max /i;
			i = 0;
		}
	}
	cout << *max_element(answer.begin(), answer.end()) << endl;
}
