#include "iostream"
using std::cout, std::endl;
#include "vector"
using std::vector;
#include "numeric"
using std::accumulate;

int main(){
	vector<int> sum_of_squares;	//initialize
	vector<int> square_of_sum;
	for(int i = 0; i < 101; ++i){		//fill vectors with necessary values
		sum_of_squares.push_back(i*i);	//square each input into sum_of_squares
		square_of_sum.push_back(i);
	}							//add all the values in each vector together
	auto val_of_squares = accumulate(sum_of_squares.begin(), sum_of_squares.end(), 0);
	auto val_of_sum = accumulate(square_of_sum.begin(), square_of_sum.end(), 0);
	val_of_sum *= val_of_sum;	//square val_of_sum
	long long result = val_of_sum - val_of_squares;
	cout << result << endl;
}
