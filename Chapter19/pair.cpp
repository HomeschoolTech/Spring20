#include "Pair.h"
#include "string"

int main(){
	Pair<int, std::string> x(21, "hello");
	Pair<char, double> y('g', 4.76);
	x.print_vals();
	y.print_vals();
}
