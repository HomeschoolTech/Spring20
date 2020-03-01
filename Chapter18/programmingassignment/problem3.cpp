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

int main(){
	char* s1 = "acbd";
	char* s2 = "abcd";
	int result = strcmp(s1,s2);
	std::cout << result << std::endl;
}
