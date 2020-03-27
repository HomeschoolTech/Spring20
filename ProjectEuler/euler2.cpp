#include <list>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

int main(){
	std::list <int> fib = {1,1};	//initialize
	int sum = 0;
	int next = 0;
	int max = 0;
	while(max < 4000000){		
		next = accumulate(fib.begin(), fib.end(), 0);	//add the last two elements of a two element vector
		fib.push_back(next);				//add the next fibonnacci number
		max = *max_element(fib.begin(), fib.end());	//find the largest element
		if(max % 2 == 0) sum += max;			//if it is even add the largest element to sum
		fib.pop_front();		//erase first element to create a two element vector
	}
	cout << sum << endl;	
}
