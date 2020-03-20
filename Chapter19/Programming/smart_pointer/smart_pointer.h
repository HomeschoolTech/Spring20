
template<typename T> 
class shared_pointer;

template<typename T>
shared_pointer<T> make_shared(T obj);

// This file implements a smart_pointer. This is an object that holds a pointer to 
// an object, but keeps track of how many other objects point to the same thing.
//
// There are two data members pointer, and counter. Pointer is obviously a pointer to
// the object inquestion. Note that counter is also a pointer, so that differenct objects
// can share access to the current number of things point to the object.
//
// Whenever a new object points to *pointer, *counter should increment. Whenever an 
// object that points to *pointer is destroyed either counter should decrease by 1, 
// or delete pointter and counter when *counter is <= 1 (i.e. the last thing pointing
// to *pointer deletes, last one out closes the door)
//
// This makes shart_pointer much safer to work with rather than working with raw pointers
// and having to remember to delete them.
//
// A note on constructors, you will need to implement the constructors, but I have created
// a helpber function that calls the private constructor. This way there are only two options
// on how to create a smart pointer
//
//    shared_pointer<int> myptr1 = make_shared<int>(5); // creates smartpointer to value 5
//    shared_pointer<int> myptr2; // Initializes pointer to nullptr, *counter to 0
//
// This guarentees that there is no way we could forget to delete a pointer.
template <typename T>
class shared_pointer{
public:

    friend shared_pointer<T> make_shared<T>(T obj);
    
    shared_pointer(): counter{nullptr}, pointer{nullptr}{
        // Initialize pointer to nullptr and *counter to 0
    }

    shared_pointer(shared_pointer<T>& p): pointer{p.pointer}, counter{p.counter}{
        // New object created, increase counter by 1
	   ++*counter;
    }
    
    shared_pointer(shared_pointer<T>&& p): pointer{p.pointer}, counter{p.counter}{
        // Object moved, set p.ptr and p.count to nullptr for safe destruction
    	p.pointer = nullptr;
	p.counter = nullptr;
    }
    
    shared_pointer<T>& operator=(shared_pointer<T>& p){
        // clear current values (make sure to decrement counter first)
        // Assign new values
        // increase  new counter
        // return *this;
	if(counter == nullptr);
	else --*counter;	
	pointer = nullptr;
	pointer = p.pointer;
	counter = p.counter;
	++*counter;
	return *this;

    }
    
    shared_pointer<T>& operator=(shared_pointer<T>&& p){
        // clear current values (make sure to decrement counter)
        // Assign new values
        // increase  new counter (depending how you implement, may not need)
        // return *this;
	pointer = nullptr;
	if(counter == nullptr);
	else --*counter;	
	pointer = p.pointer;
	counter = p.counter;
	return *this;
    }
    
    ~shared_pointer(){
        // If counter > 1, decrease *counter
        // If counter = 1, delete pointer and counter
        // Set pointer and counter to nullptr for safe delete of object
	//if(*counter > 1) --*counter;
       	//if(*counter == 1){
	//	delete pointer;
	//	delete counter;
    }

        
    T& operator*() const {
        // return *pointer, make sure you don't dereference the nullptr
	//if(pointer == nullptr) throw; 
	return *pointer;
    }
    
    int ref_count() const{ 
        // return current count, make sure you dont dereference the nullptr
    	if(counter == nullptr) return 0;
	else return *counter;
    }

private:
    T* pointer;
    int* counter;
   
    shared_pointer(T* p): pointer{p}, counter{new int (1)}{
        // Initialize pointer to p, and initialize counter to 1
    }
            
};


template<typename T>
shared_pointer<T> make_shared(T obj){
    return shared_pointer<T>(new T(obj));
};



























