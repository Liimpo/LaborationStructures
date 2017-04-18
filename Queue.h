#ifndef QUEUE_H
#define QUEUE_H
#include "IQueue.h"

template <typename T>
class Queue : public IQueue<T>
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data, Node* next = nullptr) { this->data = data; this->next = next; }
		~Node() {}
	};
	int nrOfElements;
	Node* first;
	void copy(const Queue<T> &origObj);
public:
	Queue(Node* first = nullptr);
	virtual ~Queue();
	Queue(const Queue<T> &origObj);
	Queue<T> operator=(const Queue<T> &origObj);

	void enqueue(const T& element);
	void dequeue();
	T front()const;
	bool isEmpty()const;
};

template <typename T>
void Queue<T>::copy(const Queue<T> &origObj)
{
	this->nrOfElements = 0;
	//Walkern vill åt adressen i "this objektet"
	Node* walkerOrig = origObj.first;

	for (int i = 0; i < origObj.nrOfElements; i++)
	{
		this->enqueue(walkerOrig->data);
		walkerOrig = walkerOrig->next;
	}
}

template <typename T>
Queue<T>::Queue(Node* first)
{
	this->first = first;
	this->nrOfElements = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	while (this->nrOfElements > 0)
		this->dequeue();
}

template <typename T>
Queue<T>::Queue(const Queue<T> &origObj)
{
	this->copy(origObj);
}

template <typename T>
Queue<T> Queue<T>::operator=(const Queue<T> &origObj)
{
	if (this != &origObj)
	{
		this->copy(origObj);
	}
	return *this;
}

template <typename T>
void Queue<T>::enqueue(const T& element)
{
	if (this->nrOfElements == 0)
	{
		this->first = new Node(element, this->first);
		this->first->next = nullptr;
		this->nrOfElements++;
	}
	else
	{
		Node* walker = this->first;
		for (int i = 0; i < this->nrOfElements-1; i++)
			walker = walker->next;

		walker->next = new Node(element, nullptr);
		this->nrOfElements++;
	}
}

template <typename T>
void Queue<T>::dequeue()
{
	if (this->nrOfElements == 0)
		throw "You cannot remove anything.";
	Node* toRemove = this->first;
	if (this->nrOfElements == 1)
	{
		delete toRemove;
		this->nrOfElements--;
	}
	else
	{
		Node* walker = this->first;
		//flytta fram walker ett steg.

		walker = walker->next;

		delete toRemove;
		this->first = walker;
		this->nrOfElements--;
	}
}

template <typename T>
T Queue<T>::front()const
{
	if (this->nrOfElements == 0)
		throw "You dont have any elements in your queue.";
	return this->first->data;
}

template <typename T>
bool Queue<T>::isEmpty()const
{
	bool elementsExists = false;
	if (this->nrOfElements == 0)
		elementsExists = true;
	return elementsExists;
}
#endif
