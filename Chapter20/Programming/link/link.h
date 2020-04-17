
template<typename T>
struct Link {
	T elem;
	Link<T>* prev;
	Link<T>* next;
};

template<typename T>
class Iterator {
public:
	T& operator*(){return current -> elem;}
	bool operator==(const Iterator<T>& p) const{return current == current.p;}
	bool operator!=(const Iterator<T>& p) const{return current != current.p;}
	Iterator<T>& operator++(){current = current -> next; return *this;}
	Iterator<T>& operator--(){current = current -> prev; return *this;}
	friend class LinkedList;
private:
	Link<T>* current;
	Iterator(Link<T>* u);
};


template<typename T>
class List{
	friend class Iterator<T>
	List(): sz(0), tail(new Link<T>()), head(new Link<T>())
	{
		head->next = tail;
		tail->prev = head;
	}
	
	Iterator<T> begin() const{ return Iterator<T>(head->next); }
	Iterator<T> end() const{ return Iterator<T>(tail); }

	void insert(const Iterator<T>& p, const T& e)
	{
		auto* next_node = p.current;
		auto* prev_node = next_node->prev;
		auto* new_node = new Link<T>;
	
		new_node->elem = e;

		new_node->next = next_node;
		next_node->prev = new_node;

		new_node->prev = prev_node;
		prev_node->next = new_node;

		sz++;
	}
	
	void insert_front(const Iterator<T>& p)
	{
		insert(p, begin());
	}

	void insert_back(const Iterator<T>& p)
	{
		insert(p, end());
	}

	void erase(const Iterator<T>& p)
	{
		auto* old_node = p.current;
		auto* next_node = old_node->next;
		auto* prev_node = old_node->prev;

		prev_node->next = next_node;
		next_node->prev = prev_node;

		delete old_node;
		sz--;
	}

	void erase_front()
	{
		erase(begin());
	}

	void erase_back()
	{
		erase(--end());
	}

	int size() const { return sz; }
	bool empty() const{ return sz == 0; }

private:
	int sz;
	Link<T>* head;
	Link<T>* tail;
};





