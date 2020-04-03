#include "vector"
#include "iostream"
#include "fstream"
#include "algorithm"
#include "numeric"
using namespace std;

int main(){
	vector<double> vd;
	cout << "enter filename ";
	string iname;
	cin >> iname;
	ifstream ifs(iname);
	if(!ifs){
	       	cout << "file " << iname << " not found" << endl;
		return 1;
	}
	double val;
	while(ifs){
		ifs >> val;
		vd.push_back(val);
	}
	for(int i = 0; i < vd.size(); ++i){
		cout << vd[i] << ',';
	}
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	int sumd = 0;
	int sumi = 0;
	for(int i = 0; i < vd.size(); ++i){
		cout << '(' << vd[i] << ", " << vi[i] << ')' << endl;
	}
	sumd = accumulate(vd.begin(), vd.end(), sumd);
	sumi = accumulate(vi.begin(), vi.end(), sumi);
	sumd-=sumi;
	cout << sumd << endl;
	reverse(vd.begin(), vd.end());
	for(int i = 0; i < vd.size(); ++i){
		cout << vd[i] << ", ";
	}
	cout << endl << sumd/2 << endl;
	vector<double> vd2;
	sort(vd.begin(), vd.end());
	for(int i = 0; i < vd.size(); ++i){
		if(vd[i] < sumd/2) vd2.push_back(vd[i]);
	}
	for(int i = 0; i < vd.size(); ++i){
		cout << vd[i] << ", ";
	}

}

