#include "iostream"
#include <ostream>
using std::ostream;

template <typename T, typename P>

class Pair{ 
	T val1;
	P val2;
    public:
	Pair(T val1, P val2) : val1{val1}, val2{val2}{}
	void print_vals();
	friend ostream& operator<< (ostream& out, Pair<T, P>& p);
};
template <typename T, typename P>
void Pair<T, P>::print_vals(){
	std::cout << '(' << val1 << ", "
		<< val2 << ')' << std::endl;
}

template<typename T, typename P>
ostream& Pair<T, P>::operator<< (ostream& out, Pair<T, P>& p){

	out << '(' << val1 << ", " << val2 << ')';
	return out;
}
