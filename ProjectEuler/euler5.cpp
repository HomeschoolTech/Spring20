#include "iostream"
using std::cout, std::endl;
int main(){
	int multiple = 0;				
	bool divis;
	for(int i = 2520; multiple == 0; i += 20){	//as long as there is no answer we loop 
		divis = true;				
		for(int n = 1; divis == true; ++n){	//loop as long as divis is true
			if(n == 20) multiple = i;	//if n = 20 we have an answer
			if(i % n != 0) divis = false;	//if i/n leaves a remainder then break the loop
		}
	}
	cout << multiple << endl;	//print answer

}
