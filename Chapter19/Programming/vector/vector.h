#include <memory>
using std::allocator;

// TODO: Write tests for each function, be as thourough as you can
// TODO: Find and fix the memory leak.
// TODO: Implement an iterator, write test for it. 

template <typename T, typename A = allocator<T>>
class vector;

template <typename T>
class iterator{
	T* iter;
	public:
	iterator(vector<T>* v): iter{v}{}
	bool operator==(const iterator& p);
	bool operator!=(const iterator& p);
	T& operator*();
	iterator& operator++();
};

template <typename T, typename A>
class vector {
	A alloc; 
	T* elem; 
	int sz; 
	int space; 
	friend class iterator<T>;

public:
	vector() : alloc(), elem{nullptr}, sz{3}, space{0}{}
	
	explicit vector(int s) 
		: alloc{A()}, elem{alloc.allocate(s)}, sz{s}, space{s}
	{
		for (int i=0; i<s; ++i) 
			elem[i]=0; 
	}

	vector(const vector<T, A>& v)
		: alloc{A()}, elem{alloc.allocate(v.size())}, sz{v.size()}, space{v.size()}
	{
		for (int i = 0; i < v.size(); i++)
			elem[i] = v[i];
	}	
	
	vector& operator=(const vector<T, A>& v)
	{
		if(space < v.size()){
			alloc.deallocate(space); 
			elem = alloc.allocate(v.size());
		}

		for(int i = 0; i < v.size(); ++i)
			elem[i] = v[i];
		
		sz = v.size();
		space = v.size();
	}
	
	vector(vector<T, A>&& v)
	{
		elem = v.elem;
		sz = v.size();
		space = v.capacity();
		alloc = v.alloc;

		v.elem = nullptr;
		v.space = 0;		
	}

	vector& operator=(vector<T, A>&& v)
	{
		alloc.deallocate(elem, space);
		
		elem = v.elem;
		sz = v.size();
		space = v.capacity();		
		alloc = v.alloc;

		v.elem = nullptr;
		v.space = 0;
	}
	//added destructor
	~vector(){
		delete[] elem;
	}	
	iterator<T> begin(){
		return elem[0];
	}	
	iterator<T> end(){
		return elem[size() + 1];
	}
	T& operator[](int n)
	{ 
		return elem[n]; 
	}
	
	const T& operator[](int n) const
	{
		return elem[n]; 
	}
	
	int size() const
	{ 
		return sz; 
	}
	
	int capacity() const 
	{ 
		return space; 
	}
	
	void resize(int newsize, T val = T())
	{
		reserve(newsize);
		for (int i = sz; i < newsize; ++i)
			elem[i] = 0;
		sz = newsize;
	} 

	void push_back(const T& val)
	{
		if( space == 0) 
			reserve(4);
		else if(space == sz)
			reserve(2*space);
		
		elem[sz] = val;
		++sz;
	}

	void reserve(int newalloc)
	{
		if(newalloc <= space) return;

		T* v = alloc.allocate(newalloc);
		for(int i = 0; i < sz; ++i){
			alloc.construct(&v[i], elem[i]);
			alloc.destroy(&elem[i]);
		}		

		alloc.deallocate(elem, space);
		
		elem = v;
		space = newalloc;
	}
	/*
	using vector<T,A>::iterator T*;
	iterator begin(){return elem;}
	iterator end(){return this[this.size()];}
	iterator insert(iterator p, const T& val);
	iterator erase(iterator p);
	*/
};
template <typename T>				
bool iterator<T>::operator==(const iterator& p){
	return iter == p.iter;
}
template <typename T>
bool iterator<T>::operator!=(const iterator& p){
	return iter != p.iter;
}
template <typename T>
T& iterator<T>::operator*(){
	return *iter;
}
template <typename T>
iterator<T>& iterator<T>::operator++(){
	++iter;	
	return *this;
}
/*
template <typename T, typename A = allocator<T>>
vector<T, A>::iterator vector<T,A>::erase(iterator p){
	if(p == end()) return p;
	for(auto pos = p + 1; pos != end(); ++pos){
		*(pos-1) = *pos;
		alloc.destroy(&*(end()-1));
		--sz;
		return p;
	}	
}
template <typename T, typename A = allocator<T>>
vector<T, A>::iterator vector<T, A>::insert(iterator p, const T& val){
	int index = p-begin();
	if(size() == capacity()) reserve(size()==0?8:2*size());
	alloc.construct(elem+sz,*back());
	++sz;
	iterator pp = begin()+index;
	for(auto pos = end()-1; pos != pp; --pos){
		*pos = *(pos-1);
	}
	*(begin()+index) = val;
	return pp;
}
*/

