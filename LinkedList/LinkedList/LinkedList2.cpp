// A templated singly linked list
#include "LinkedList.h"

template<class T>
TLL::LinkedList<T>::LinkedList(const LinkedList & LL)
{
	const ListElement<T> *curr = LL._head;

	// If Linked List is empty
	if (isEmpty() && temp != nullptr) {
		_head = new ListElement<T>(curr->getValue());
		curr = curr->getNext();
	}

	ListElement<T> *newNode = nullptr;
	while (curr) {
		newNode = new ListElement<T>(curr->getValue());
		curr = curr->getNext();
	}
}

/*
template<class T>
LinkedList& TLL::LinkedList<T>::operator=(LinkedList<T> byValList)
{
	std::swap(_head, byValList.head);
	return *this;
}
*/

template<class T>
bool TLL::LinkedList<T>::insertAtHead(T data)
{
	ListElement <T> *newElement = new ListElement<T>(data);
	if (newElement == nullptr) return false;
	newElement->setNext(_head);
	_head = newElement;
	return true;
}

template<class T>
bool TLL::LinkedList<T>::insertAtHead(ListElement<T>* nodeToInsert)
{
	if (nodeToInsert == nullptr) return false;
	return insertAtHead(nodeToInsert->getValue());
}

template<class T>
bool TLL::LinkedList<T>::insertAtEnd(T data)
{
	ListElement<T> *nodeToInsert (data);
	if (nodeToInsert == nullptr) return false;

	// head is null
	if (isEmpty()) {
		_head = nodeToInsert;
		return true;
	}

	ListElement<T> *curr = _head;
	// iterate to the end 
	while (curr != nullptr && curr->getNext() != nullptr) {
		curr = curr->getNext();
	}

	curr->setNext(nodeToInsert);
	return true;;
}

template<class T>
bool TLL::LinkedList<T>::insertAtEnd(ListElement<T>* nodeToInsert)
{
	if (nodeToInsert == nullptr) return false;
	return insertAtEnd(nodeToInsert->getValue());
}

template<class T>
ListElement<T>* TLL::LinkedList<T>::find(T data)
{
	const ListElement<T> *temp = head;
	if (temp == nullptr) return temp;

	while (temp != nullptr && temp->getValue() != data) {
		temp = temp->getNext();
	}
	return temp;
}

template<class T>
ListElement<T>* TLL::LinkedList<T>::find(T data)
{
	return nullptr;
}

template<class T>
ListElement * TLL::LinkedList<T>::find(const ListElement<T> &le)
{
	return find(new ListElement<T>(le.getValue());
}

template<class T>
bool TLL::LinkedList<T>::deleteElement(ListElement<T> *deleteMe)
{
	if (deleteMe) return false;


	ListElement<T> *temp = _head;

	// check if the element is the head
	if (deleteMe == _head) {
		_head = temp->getNext();
		delte temp;
		temp = nullptr;
		return true;
	}

	while (temp != nullptr) {
		if (temp->getNext() == deleteMe) {
			temp->setNext(deleteMe->getNext());
			delete deleteMe;
			deleteMe = nullptr;
			return true;
		}
		temp = temp->getNext();
	}
	// deleteMe not found
	return false;
}

template<class T>
bool TLL::LinkedList<T>::deleteElement(T data)
{
	return deleteElement(new ListElement<T>(data));
}

template<class T>
void TLL::LinkedList<T>::deleteList()
{
	if (_head == nullptr) return;

	ListElement<T> *elementToDel = _head;
	ListElement<T>	*next = nullptr;
	while (elementToDel != nullptr) {
		next = elementToDel->getNext();
		delete elementToDel;
		elementToDel = next;
	}
	_head = nullptr;
}

template<class T>
void TLL::LinkedList<T>::display()
{
	if (_head == nullptr) return;
	const ListElement<T> *temp = _head;
	while (temp != nullptr) {
		cout << temp->getValue() << "->";
	}
	cout << endl << < endl;
}

template<class T>
int TLL::LinkedList<T>::getSize()
{
	int size = 0;
	if (!isEmpty()) {
		const ListElement<T> *curr = _head;
		while (curr->getNext() != nullptr) {
			size++;
			curr = curr->getNext();
		}
	}

	return size;
}

template<class T>
bool TLL::LinkedList<T>::compareList(const LinkedList<T> *list1, const LinkedList<T> * list2)
{
	if (head1 == nullptr || head2 == nullptr) return false;

	const ListElement<T> *temp1 = list1._head;;
	const ListElement<T> *temp2 = list2._head;

	// compare the data of each element
	while (temp1 != nullptr && temp2 != nullptr) {
		if (temp1->getValue() != temp2->getValue()) return false;
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
	}

	// If one of the linked list is not null, it means one list is larger than the
	// the other. 
	if (temp1 != nullptr || temp2 != nullptr) return false;
	return true;
}

static int TLL::testLinkedList() {
	using namespace std;
	LinkedList<int> LL1(new ListElement<int>(7));
	LL1.insertAtEnd(1);
	LL1.insertAtEnd(6);
	LL1.insertAtEnd(5);
	LL1.insertAtEnd(4);

	LinkedList<int> LL2(new ListElement<int>(5));
	LL2.insertAtEnd(9);
	LL2.insertAtEnd(2);

	//LinkedList<int> LL = LL1.sumLists(LL1, LL2);
	LL1.display();
	LL2.display();
	LL1 = LL2;
	LL1.display();
	LL2.display();


	return 0;
}