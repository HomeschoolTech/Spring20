//vector portion of drill
#include "std_lib_facilities.h"
vector <int> gv = {1,2,4,8,16,32,64,128,256,512};
int fact(int n){
       if(n == 1) return n;
       for(int i = n-1; i > 0; --i){
               n*=i;
       }
       return n;
}

int f(vector <int> v){
	vector <int> lv(v.size());
	for(auto& i : gv){
		lv.push_back(gv[i]);
		cout << lv[i] << ", ";
	}
	cout << endl;
	vector <int> v2 = v;
	for(auto& i : v2){
		cout << v2[i] << ", ";
	}
	cout << endl;
}
int main(){
	f(gv);
	vector <int> vv = {fact(1),fact(2),fact(3),fact(4),fact(5),fact(6),fact(7),fact(8),fact(9), fact(10)};
	f(vv);
}
