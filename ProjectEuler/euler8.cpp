#include "iostream"
#include "string"
#include "vector"
#include "std_lib_facilities.h"
using namespace std;

int main(){
	cout << "enter file to read from: ";	//get file with digits
	string iname;		
	cin >> iname;
	ifstream ifs {iname};
	if(!ifs){
		cout << "file " << iname << " not found" << endl;
		return 1;
	}
	vector <int> adj;
	int a;
	for(int i = 0; i < 13; ++i){	//put the first thirteen values in a vector
		ifs >> a;
		adj.push_back(a);
		a = 0;
	}
	long long product = 1;
	long long greatest = 1;
	while(a != -1){		//-1 is last value in the file
		for(int n = 0; n < adj.size(); ++n){	//multiply the values in adj together
			product *= adj[n];
		}
		if(product > greatest){		//check if multiplication is greater than previous greatest product
			greatest = product;
			product = 1;		//reset product
		}
		else product = 1;		//otherwise reset product	
						//get next value from file
		ifs >> a;
		adj.push_back(a);		//add the next value
		adj.erase(adj.begin());		//delete the first value
	}
	cout << greatest;
}
