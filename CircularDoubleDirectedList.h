#ifndef CDDLIST_H
#define CDDLIST_H
#include "ICircularDoubleDirectedList.h"
#include "iostream"

template <typename T>
class CircularDoubleDirectedList : public ICircularDoubleDirectedList<T>
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
		Node(T data, Node* next = nullptr, Node* prev = nullptr) { this->data = data; this->next = next; this->prev = prev; }
		~Node() {}
	};
	Node* current;
	int nrOfElements;
	direction currentDirection;
public:
	CircularDoubleDirectedList(Node* current = nullptr);
	virtual ~CircularDoubleDirectedList();
	void addAtCurrent(const T &element);
	T getElementAtCurrent()const;
	void removeAtCurrent();
	int size()const;
	void changeDirection();
	void moveCurrent();
	direction getCurrentDirection()const;
};

template <typename T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList(Node* current)
{
	this->current = current;
	this->nrOfElements = 0;
	this->currentDirection = FORWARD;
}

template <typename T>
CircularDoubleDirectedList<T>::~CircularDoubleDirectedList()
{
	while (this->nrOfElements > 0)
	{
		this->removeAtCurrent();
	}
}

template <typename T>
void CircularDoubleDirectedList<T>::addAtCurrent(const T &element)
{
	if (this->nrOfElements == 0)
	{
		cout << "tja" << endl;
		this->current = new Node(element, nullptr, nullptr);
		this->nrOfElements++;
	}

	//Lägger till framför eller bakom.
	else if (this->nrOfElements == 1)
	{
			this->current->next = new Node(element, this->current, this->current);
			this->nrOfElements++;
			this->current->prev = this->current->next;
			this->current = this->current->next;
	}

	else if (this->nrOfElements > 1 && this->getCurrentDirection() == FORWARD)
	{
		Node* behind = this->current->next;
		behind->prev = new Node(element, this->current->next, this->current);
		this->current->next = behind->prev;
		this->current = this->current->next;
		this->nrOfElements++;
	}

	else if (this->nrOfElements > 1 && this->getCurrentDirection() == BACKWARD)
	{
		Node* ahead = this->current->prev;
		ahead->next = new Node(element, this->current, this->current->prev);
		this->current->prev = ahead->next;
		this->current = this->current->prev;
		this->nrOfElements++;
	}
}

template <typename T>
T CircularDoubleDirectedList<T>::getElementAtCurrent()const
{
	if (this->nrOfElements == 0)
		throw "Exception: call of getElementAtCurrent on empty list";
	else
		return this->current->data;
}

template <typename T>
void CircularDoubleDirectedList<T>::removeAtCurrent()
{
	if (this->nrOfElements == 0)
		throw "Exception: call of removeAtCurrent on empty list";

	else if (this->nrOfElements == 1)
		delete this->current;

	else if (this->nrOfElements > 1 && this->getCurrentDirection() == FORWARD)
	{
		Node* behind = this->current->prev;
		this->current = this->current->next;
		delete this->current->prev;
		behind->next = this->current;
		this->current->prev = behind;
	}

	else if (this->nrOfElements > 1 && this->getCurrentDirection() == BACKWARD)
	{
		Node* ahead = this->current->next;
		this->current = this->current->prev;
		delete this->current->next;
		ahead->prev = this->current;
		this->current->next = ahead;
	}
	this->nrOfElements--;
}

template <typename T>
int CircularDoubleDirectedList<T>::size()const
{
	return this->nrOfElements;
}

template <typename T>
void CircularDoubleDirectedList<T>::changeDirection()
{
	if (this->currentDirection = FORWARD)
		this->currentDirection = BACKWARD;
	else
		this->currentDirection = FORWARD;
}

template <typename T>
void CircularDoubleDirectedList<T>::moveCurrent()
{
	if (this->nrOfElements == 0)
		throw "Exception: call of moveCurrent on empty list";

	else if (this->currentDirection == FORWARD)
			this->current = this->current->next;

	else if (this->currentDirection == BACKWARD)
			this->current = this->current->prev;
}

template <typename T>
direction CircularDoubleDirectedList<T>::getCurrentDirection()const
{
	return this->currentDirection;
}

#endif
