#include "Pair.h"
#include "string"
#include <vector>
using std::vector;

int main(){
	Pair<int, std::string> x(21, "hello");
	Pair<char, double> y('g', 4.76);
	x.print_vals();
	y.print_vals();
	std::cout << x << std::endl;
	
	vector<int> v = {1, 2, 3, 4};
	std::cout << Pair(x, y) << std::endl;
}
