#include "iostream"

template <typename T, typename P>

class Pair{
	T val1;
	P val2;
    public:
	Pair(T val1, P val2) : val1{val1}, val2{val2}{}
	void print_vals();
};
template <typename T, typename P>
void Pair<T, P>::print_vals(){
	std::cout << '(' << this->val1 << ", "
		<< this->val2 << ')' << std::endl;
}
