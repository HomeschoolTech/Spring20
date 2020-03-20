#include<iostream>
using namespace std;
char* strdup(char* ch){
	// char* c = ch; 
	char* a = new char [100];
	char* ap = a;
/*	char*ap2 = a;
	while(*c != 0){
		*ap = *c;
		++c;
		*ap = *ap2;
		++ap2;
	}
	//delete[] a;
*/
	while(*ch){
		*ap = *ch;
		ap++;
		ch++;
	}

	return a;
}
int main(){
	char* ch = "hel";
	char* a = strdup(ch);
	while(*a){
		cout << *a << endl;
		a++;
	}
}
