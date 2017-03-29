#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data, Node* next = nullptr) { this->data = data; this->next = next;}
		~Node() {}
	};
	Node* first;
	int nrOfElements;
public:
	//Konstruktor med defaultarg.
	List(Node* first = nullptr);
	//Destruktor
	virtual ~List();
	//Copykonstruktor
	List(const List &origObj);
	//Tilldelningsoperator
	List operator=(const List &origObj);
	//Funktioner
	void insertAt(const T &data, int post);
	T get(int pos) const;
	void removeAt(int pos);
	void clear();
	int size() const;
};

//Konstruktor
template<typename T>
List<T>::List(Node* first)
{
	this->first = first;
	this->nrOfElements = 0;
}

#endif