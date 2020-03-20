#include "iostream"

int strcmp(const char* s1, const char* s2){
	const char* sp1 = s1;
	const char* sp2 = s2;
	int si1 = 0;
	int si2 = 0;
	int i = 0;
	char* al = "abcdefghijklmnopqrstuvwxyz0";
	char* alp = al;
	while(*sp1 != 0){
		if(*sp1 != *sp2){
			while(*alp != '0'){
				if(*sp1 == *alp) si1 = i;
				if(*sp2 == *alp) si2 = i;
				++i;
				++alp;
			}
		i = 0;	
		alp - 26;
		if(si1 < si2) return -1;
		if(si2 < si1) return 1;
		if(si1 == si2){
			si1 = 0;
			si2 = 0;
		}
		}
		++sp1;
		++sp2;
	}
	return 0;
}
char* strdup(const char* ch){
	const char* c = ch;
	char* a = new char [100];
	char* ap = a;
	char* ap2 = a;
	while(*c != 0){
		*ap = *c;
	 	++c;
		*ap = *ap2;
		++ap2;
	}
	delete[] a;
}
const char* findx(const char* s, const char* x){
	const char* sp = s;
	while(*sp != 0){
		if(*sp == *x) return sp;
		else ++sp;
	}
}
int main(){
/*
  	char* ch = "hello world";	//problem1
	char* chp = &ch[10];
	*chp = 'f';
	strdup(ch);
	
	char* sp2 = "abcde";	//problem2
	char* x = "b";
	char* xp = x;
	findx(sp2, x);
*/
	char* s1 = "acbd";	//problem3
	char* sp3 = &s1[4];
	*sp3 = 'd';
	++sp3;
	*sp3 = 'e';
	char* s2 = "abcd";
	int result = strcmp(s1,s2);
	std::cout << result << std::endl;

}
