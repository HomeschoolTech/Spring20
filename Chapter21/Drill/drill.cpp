#include "string"
#include "vector"
#include "iostream"
#include "algorithm"
#include "fstream"
#include "list"

using namespace std;

struct Item{
	string name;
	int iid;
	double value;
	public:
	Item(string name, int iid, double value) : name{name}, iid{iid}, value{value}{}
	friend ostream& operator<<(ostream &os, const Item &obj){
		os << obj.name << ',' << obj.iid << ',' << obj.value << endl;
		return os;
	}
	friend bool operator<(const Item& i1, const Item& i2){
		return i1.name < i2.name;
	}
	friend bool operator>(const Item& i1, const Item& i2){
		return i1.value > i2.value;
	}
	
};
bool compareItemi(Item i1, Item i2){
	return i1.iid < i2.iid;
}
bool compareItemn(Item i1, Item i2){
	return i1.name < i2.name;
}
bool compareItemv(Item i1, Item i2){
	return i1.value > i2.value;
}
int main(){
	//open file
	cout << "enter name of file: ";
	string iname;
	cin >> iname;
	ifstream ifs {iname};
	if(!ifs){
		cout << "file " << iname << " not found" << endl;
	  	return 1;	
	}
	//initialize
	string str;
	int iid;
	double value;
	vector <Item> vi;
	//input file into vector
	while(vi.size() < 10){
		ifs >> str;
		ifs >> iid;
		ifs >> value;
		Item it(str, iid, value);
		vi.push_back(it);
	}
	//close file
	ifs.close();
	//sort vi by name
	sort(vi.begin(), vi.end(), compareItemn);
	//print vi
	for(auto& i : vi){
		cout << i;
	}
	//sort vi by value
	sort(vi.begin(), vi.end(), compareItemi);
	//print vi
	for(auto& i : vi){
		cout << i;
	}
	sort(vi.begin(), vi.end(), compareItemv);
	//add 2 items to vi
	vi.push_back(Item("horse shoe",99,12.34));
	vi.push_back(Item("Canon S400",9988,499.95));
	//erase items from vi on condition
	for(int i = 0; i < vi.size(); ++i){
		if(vi[i].name == "hello") vi.erase(vi.begin()+i);
		if(vi[i].name == "cpp") vi.erase(vi.begin()+i);
		if(vi[i].iid == 12) vi.erase(vi.begin()+i);
		if(vi[i].iid == 0) vi.erase(vi.begin()+i); 
	}
	//create list
	list<Item> li;
	//open file for reading
	ifstream ist(iname);
	if(!ist){
		cout << "file " << iname << " not found";
		return 1;
	}
	//put Items in list
	while(li.size() < 10){
		ist >> str;
		ist >> iid;
		ist >> value;
		Item il(str, iid, value);
		li.push_back(il);
	}
	//sort list by name
	sort(li.begin(), li.end(), compareItemn);
	//print sorted list
	for(auto& i : li){
		cout << i;
	}
	//sort list by iid
	sort(li.begin(), li.end(), compareItemi);
	//sort list by value
	sort(li.begin(), li.end(), compareItemv);
	//print sorted list
	for(auto& i : li){
		cout << i;
	}
	//add 2 ITems to list
	li.push_back(Item("horse shoe", 99, 12.34));
	li.push_back(Item("Canon S400", 9988, 499.95));
	//erase Items from list by condition
	list<Item>::iterator it;
	for(it = li.begin(); it != li.end(); ++it){
		if(it->name == "hello") li.erase(it);
		if(it->name == "cpp") li.erase(it);
		if(it->iid == 12) li.erase(it);
		if(it->iid == 0) li.erase(it);	
	}

}

