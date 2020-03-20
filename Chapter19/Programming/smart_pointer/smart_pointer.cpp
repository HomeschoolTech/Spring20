#include <iostream>
#include <smart_pointer.h>

// Above each line we have (var : *ptr : *counter)
// // 
// // I recommend commenting these out and getting them to 
// // work one by one. 

int main(){
	// test move constructor: 
	//(ptr : 9 : 1)
	shared_pointer<int> ptr(make_shared<int>(9));

	// test copy constructor: 
	//(ptr2 : 9 : 2), (ptr : 9 : 2)
	shared_pointer<int> ptr2 = ptr;

	// test copy constructor 
	//(ptr3 : 9 : 3), (ptr2 : 9 : 3), (ptr : 9 : 3)
	shared_pointer<int> ptr3(ptr2);

	// test default constructor 
	//(null : NULL : NULL), (ptr3 : 9 : 3), (ptr2 : 9 : 3), (ptr : 9 : 3)
	shared_pointer<int> null;                                                                 
	
	// test copy assignment : 
	//(null : NULL : NULL), (ptr3 : 9 : 3), (ptr2 : 9 : 3), (ptr : 9 : 3)
	ptr3 = ptr;
	
	// test move assignment 
	//(null : NULL : NULL), (ptr3 : 9 : 2), (ptr2 : 3 : 1), (ptr : 9 : 2)
	ptr2 = make_shared<int>(3);

	// test copy assignment 
	//(null : 3 : 2), (ptr3 : 9 : 2), (ptr2 : 3 : 2), (ptr : 9 : 2)
	null = ptr2;      
	std::cout << &(*ptr)  << " : " << *ptr  << " : " << ptr.ref_count()  << std::endl;
	std::cout << &(*ptr2) << " : " << *ptr2 << " : " << ptr2.ref_count() << std::endl;
	std::cout << &(*ptr3) << " : " << *ptr3 << " : " << ptr3.ref_count() << std::endl;
	std::cout << &(*null) << " : " << *null << " : " << null.ref_count() << std::endl;
}
