char* strdup(const char* ch){
	const char* c = ch; 
	char* a = new char [100];
	char* ap = a;
	char*ap2 = a;
	while(*c != 0){
		*ap = *c;
		++c;
		*ap = *ap2;
		++ap2;
	}
	delete[] a;
}
int main(){
	char* ch = "hello world";
	strdup(ch);
}
