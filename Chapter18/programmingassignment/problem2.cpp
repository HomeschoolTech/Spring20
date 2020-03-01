const char* findx(const char* s, const char* x){
	const char* sp = s;
	while(*sp != 0){
		if(*sp == *x) return sp; 
		else ++sp;
	}
}
int main(){
	char* sp = "abcde"; 
	char* x = "b";
	char* xp = x;
	findx(sp, x);
}
