#include "vector"
#include "string"
#include "iostream"
#include "typeinfo"
using namespace std;
template <typename T>
struct S{
	S(T value);
	void print();
	T& get();
	S operator=(const T& x);
private:
	T val;
};

template<typename T>
S<T>::S(T value): val(value) {}

template <typename T>
S<T> S<T>::operator=(const T& x){
	val = x;
    return *this;
}
template <typename T>
T& S<T>::get(){
	return val;
}
int main(){
	vector <int> v = {1,2,3};
	S <int> i(2);
	S <char> c('t');
	S <double> d(6.79);
	S <string> s("hello world");
	S <vector<int>> vs(v);
	cout << i.get() << endl;
	cout << c.get() << endl;
	cout << d.get() << endl;
	cout << s.get() << endl;
//	cout << vs.get() << endl;	
}
