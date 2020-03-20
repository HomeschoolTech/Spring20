const char* findx(const char* s, const char* x){
	while(*s != 0){
		if(*s == *x) return s; 
		else {
			++s;
		}
	}
	return nullptr;
}
int main(){
	char* sp = "abcde"; 
	char* x = "b";
	char* xp = x;
	findx(sp, x);
}
