
template<typename T>
struct Link {
	T elem;
	Link<T>* prev;
	Link<T>* next;
};

template<typename T>
class Iterator {
public:
	T& operator*();
	bool operator==(const Iterator<T>& p) const;
	bool operator!=(const Iterator<T>& p) const;
	Iterator<T>& operator++();
	Iterator<T>& operator--();
	friend class LinkedList;
private:
	Link<T>* current;
	Iterator(Link<T>* u);
};


template<typename T>
class List{
	List(): sz(0), tail(new Link<T>()), head(new Link<T>())
	{
		head->next = tail;
		tail->prev = head;
	}
	
	Iterator<T> begin() const{ return Iterator(head->next); }
	Iterator<T> end() const{ return Iterator(tail); }

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

	int size() const { return sz; }
	bool empty() const{ return sz == 0; }

private:
	int sz;
	Link<T>* head;
	Link<T>* tail;
};





