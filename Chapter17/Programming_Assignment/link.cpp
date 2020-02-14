#include "Link.h"
#include "iostream"

void print_all(Link* p)
{
	std::cout << "{ ";
	while (p) {
		std::cout << p->value;
		if (p=p->next()) std::cout << ", ";
	}
	std::cout << " }";
}

int main(){
	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->insert(new Link{"Odin"});
	norse_gods = norse_gods->insert(new Link{"Zeus"});
	norse_gods = norse_gods->insert(new Link{"Freia"});
	Link* greek_gods = new Link{"Hera"};
	greek_gods = greek_gods->insert(new Link{"Athena"});
	greek_gods = greek_gods->insert(new Link{"Mars"});
	greek_gods = greek_gods->insert(new Link{"Poseidon"});
	Link* p = greek_gods->find("Mars");
	if (p) p->value = "Ares";
	Link* p2 = norse_gods->find("Zeus");
	if (p2) {
		if (p2==norse_gods) norse_gods = p2->next();
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}
	print_all(norse_gods);
	std::cout<<std::endl;
	print_all(greek_gods);
	std::cout<<std::endl;
}
