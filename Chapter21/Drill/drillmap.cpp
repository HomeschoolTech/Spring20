#include "map"
using std::map;
#include "string"
using std::string;
#include "iostream"
using std::cout, std::endl, std::cin;

map<string, int> get_vals(map<string, int> msi){
	cout << "input name/value pairs(! 0 to finish): ";
	string str;
	int i;
	cin >> str >> i;
	while(str != "!"){
		msi[str] = i;
		cin >> str >> i;
	}
	return msi;
}


int main(){
	map<string, int> msi;
	msi["hello"] = 2;
	msi["world"] = 5;
	msi["goodbye"] = 0;
	msi["code"] = 12;
	msi["array"] = 34;
	msi["vector"] = -6;
	msi["cpp"] = 123;
	msi["program"] = 54;
	msi["drill"] = -23;
	msi["map"] = 93;
	map<string, int>::iterator iter;
	for(iter = msi.begin(); iter != msi.end(); iter++){
		cout << '(' << (*iter).first << ", " << (*iter).second << ')' << endl;
		msi.erase(iter);
	}
	cout << "msi.size() = " << msi.size() << endl;
	msi = get_vals(msi);
	int sum = 0;
	for(iter = msi.begin(); iter != msi.end(); iter++){
		sum += (*iter).second;
		cout << '(' << (*iter).first << ", " << (*iter).second << ')' << endl;
	}
	cout << sum << endl;
	map <int, string> mis;
	for(iter = msi.begin(); iter != msi.end(); iter++){
		mis[(*iter).second] = (*iter).first;
	}
	map <int, string>::iterator iter2;	
	for(iter2 = mis.begin(); iter2 != mis.end(); iter2++){
		cout << '(' << (*iter2).first << ", " << (*iter2).second << ')' << endl;
	}
}
