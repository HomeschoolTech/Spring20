#include "iostream"

#include <ostream>
using std::ostream;

#include<type_traits>
using std::is_same;

#include<utility>
using std::declval;



template<typename T>
concept Printable = 
	is_same<decltype( declval<ostream&>() << declval<T>() ), ostream&>::value;
  
template <Printable T, Printable P>
class Pair{ 
	T val1;
	P val2;
public:
	Pair(T val1, P val2) : val1{val1}, val2{val2}{}
	void print_vals();

	friend ostream& operator << (ostream& out, const Pair<T, P>& p){
		out << '(' << p.val1 << ", " << p.val2 << ')';
		return out;
	}
};
template <Printable T, Printable P>
void Pair<T, P>::print_vals(){
	std::cout << '(' << val1 << ", "
		<< val2 << ')' << std::endl;
}

