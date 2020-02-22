#include<iostream>
using namespace std;

void sizes(char ch, int i, int* p, bool b, double d, string s){
	cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
	cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
	cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n';
	cout << "the size of string is " << sizeof(string) << ' ' << sizeof(s) << '\n';
}

int main(){
	int i = 54;
	int* p = &i;	
	sizes('a', 54, p, true, 4.67, "string");
}
