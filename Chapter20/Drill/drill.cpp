#include "std_lib_facilities.h"

template <typename Iter1, typename Iter2>
Iter2 copy1(Iter1 f1, Iter1 e1, Iter2 f2){
	while(f1 != e1){	
		f2 = *f1;
		++f2;
		++f1;
	}
}


int main(){
	array<int, 10> a = {0,1,2,3,4,5,6,7,8,9};	//initialize
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	list<int> l = {0,1,2,3,4,5,6,7,8,9};
	array<int, 10> a2 = a;
	vector<int> v2 = v;
	list<int> l2 = l;
	for(int i = 0; i < 10; ++i){	//manual copy array/vector
		a[i] += 2;
		v[i] += 3;
	}
	for(int i : l){		//manual copy list 
		i+=5;
	}
	copy1(a.begin(), a.end(), v.size());	//copy array into vector
	copy1(l.begin(),l.end(), a.size());	//copy list into array
	auto p = find(v.begin(),v.end(),3);	//find first occurance of 3 in vector
	auto r = find(l.begin(),l.end(),27);	//find first occurance of 27 in list
	cout << *p << ',' << *r << endl;	//print position of 3 and 27
}


