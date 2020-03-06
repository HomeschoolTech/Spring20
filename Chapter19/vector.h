#include <memory>

using namespace std;

template<typename T, typename A>
struct vector_base {
	A alloc; // allocator
	T* elem; // start of allocation
	int sz; // number of elements
	int space; // amount of allocated space
	vector_base(const A& a, int n)
		: alloc{a}, elem{alloc.allocate(n)}, sz{n}, space{n}{ }
	~vector_base() { alloc.deallocate(elem,space); }
};

template <typename T, typename A = allocator<T>>
class vector : private vector_base<T,A> {
	/*
	invariant:
	if 0<=n<sz, elem[n] is element n
	sz<=space;
	if sz<space there is space for (space–sz) doubles after elem[sz–1]
	*/
	int sz; // the size
	T* elem; // pointer to the elements (or 0)
	int space; // number of elements plus number of free slots
  public:
	vector() : sz{0}, elem{nullptr}, space{0} { }
	explicit vector(int s) :sz{s}, elem{new T[s]}, space{s}
	{
		for (int i=0; i<sz; ++i) elem[i]=0; // elements are initialized
	}

	vector(const vector&); // copy constructor
	vector& operator=(const vector&); // copy assignment
	
	vector(vector&&); // move constructor
	vector& operator=(vector&&); // move assignment
	
	~vector() { delete[] elem; } // destructor
	
	T& operator[ ](int n) { return elem[n]; } // access: return reference
	const T& operator[](int n) const { return elem[n]; }
	
	int size() const { return sz; }
	int capacity() const { return space; }
	
	void resize(int newsize, T val = T()); // growth
	void push_back(const T& val);
	void reserve(int newalloc);
};
template <typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
	if (newalloc<=(this->space)) return; // never decrease allocation
	vector_base<T,A> b(this->alloc,newalloc); // allocate new space
	uninitialized_copy(b.elem,&b.elem[this->sz],this->elem); // copy
	for (int i=0; i<(this->sz); ++i)
		this->alloc.destroy(&this->elem[i]); // destroy old
	swap<vector_base<T,A>>(*this,b); // swap representations
}
template <typename T, typename A>
void vector<T,A>::resize(int newsize, T val = T()){
	// make the vector have newsize elements
	// // initialize each new element with the default value 0.0
	reserve(newsize);
	for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val); // construct
	for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]); // destroy
	sz = newsize;
}
template <typename T, typename A>
void vector<T,A>::push_back(const T& val){
	// increase vector size by one; initialize the new element with d
	if (space==0) reserve(8); 	// start with space for 8 elements
	else if (sz==space) reserve(2*space); 	// get more space
	alloc.construct(&elem[sz],val); 		// add val at end
	++sz; 			// increase the size (sz is the number of elements)
}
template <typename T> 
vector& vector::operator=(const vector& a){
	// like copy constructor, but we must deal with old elements
	T* p = new T[a.sz]; 			// allocate new space
	for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i]; 	// copy elements
	delete[] elem; 		// deallocate old space
	space = sz = a.sz; 	// set new size
	elem = p; 		// set new elements
	return *this;		// return self-reference
}
