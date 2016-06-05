// A templated singly linked list
#include "SinglyLinkeListTemplate.h"

using namespace SLLT;

template <class T>
LinkedList<T>::~LinkedList()
{
	std::cout << "Destructor called  for @" << this << std::endl;
	deleteList();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & ListToBeCopied)
{
	std::cout << "Copy constructor called for @ " << this << std::endl;

	ListElement<T> *copy = ListToBeCopied._head;
	_head = new ListElement<T>(copy->getValue());
	copy = copy->getNext();

	ListElement<T> *curr = _head;

	// copy List Elements Until we reach the end of the 
	// List to be copied
	while (copy != nullptr) {
		curr->setNext(new ListElement<T>(copy->getValue()));
		copy = copy->getNext();
		curr = curr->getNext();
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &ListToBeAssigned)
{
	std::cout << "Copy assignement operator called for @ " << this << std::endl;

	if (&ListToBeAssigned != this) {
		// Free The memory held by this
		deleteList();

		ListElement<T> *copy = ListToBeAssigned._head;
		if (copy != nullptr) {
			_head = new ListElement<T>(copy->getValue());
			ListElement<T> *curr = _head;
			copy = copy->getNext();

			// copy List Elements Until we reach the end of the 
			// List to be copied
			while (copy != nullptr) {
				curr->setNext(new ListElement<T>(copy->getValue()));
				copy = copy->getNext();
				curr = curr->getNext();
			}
		}

	}

	return *this;
}

template <class T>
bool LinkedList<T>::insertAtHead(T data)
{
	ListElement<T>  *newElement = new ListElement<T>(data);
	if (newElement == nullptr) return false;
	newElement->setNext(_head);
	_head = newElement;
	return true;
}

template <class T>
bool LinkedList<T>::insertAtHead(ListElement<T> * nodeToInsert)
{
	if (nodeToInsert == nullptr) return false;
	return insertAtHead(nodeToInsert->getValue());
}

template <class T>
bool LinkedList<T>::insertAtEnd(T data)
{
	ListElement<T> *nodeToInsert = new ListElement<T>(data);
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
	return true;
}

template <class T>
bool LinkedList<T>::insertAtEnd(ListElement<T> *nodeToInsert)
{
	if (nodeToInsert == nullptr) return false;
	return insertAtEnd(nodeToInsert->getValue());
}

template <class T>
bool LinkedList<T>::insertAtPos(T data, int pos)
{
	ListElement<T> *nodeToInsert = new ListElement<T>(data);
	if (nodeToInsert == nullptr) return false;

	// If list is empty and position is not the 
	// begining of the list return false. 
	if (isEmpty() && pos != 0) {
		return false;
	}

	ListElement<T> *curr = _head;
	// iterate until we are at pos - 1
	while (curr != nullptr && pos != 1) {
		curr = curr->getNext();
		pos--;
	}

	// insert the ListElement<T>
	if (pos == 1) {
		nodeToInsert->setNext(curr->getNext());
		curr->setNext(nodeToInsert);
		return true;
	}
	return false;
}

template <class T>
ListElement<T> * LinkedList<T>::find(const T data)
{
	ListElement<T> *temp = _head;
	if (temp == nullptr) return temp;

	while (temp != nullptr && temp->getValue() != data) {
		temp = temp->getNext();
	}
	return temp;
}

template <class T>
ListElement<T> * LinkedList<T>::find(ListElement<T> *le)
{
	if (le == nullptr) return nullptr;
	return find(le->getValue());
}

template <class T>
ListElement<T> * LinkedList<T>::getElementAtPos(int pos)
{
	if (isEmpty() && pos != 0) {
		return nullptr;
	}

	ListElement<T> *curr = _head;
	// iterate until we are at pos = 0
	while (curr != nullptr && pos != 0) {
		curr = curr->getNext();
		pos--;
	}

	// pos != 0 mean's we reached end of the list
	return (pos ? curr : nullptr);
}

template <class T>
bool LinkedList<T>::deleteElement(ListElement<T> *deleteMe)
{
	if (deleteMe == nullptr) return false;


	ListElement<T> *temp = _head;

	// check if the element is the head
	if (deleteMe == _head) {
		_head = temp->getNext();
		delete temp;
		temp = nullptr;
		return true;
	}

	while (temp != nullptr) {
		if (temp->getNext() != nullptr &&
			temp->getNext()->getValue() == deleteMe->getValue()) {
			temp->setNext(temp->getNext()->getNext());
			delete deleteMe;
			deleteMe = nullptr;
			return true;
		}
		temp = temp->getNext();
	}
	// deleteMe not found
	return false;
}

template <class T>
bool LinkedList<T>::deleteElement(T data)
{
	return deleteElement(new ListElement<T>(data));
}

template <class T>
void LinkedList<T>::deleteList()
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

template <class T>
void LinkedList<T>::display()
{
	if (_head == nullptr) return;
	ListElement<T> *temp = _head;
	while (temp != nullptr) {
		std::cout << temp->getValue();
		temp = temp->getNext();
		if (temp != nullptr) {
			std::cout << "->";
		}
	}
	std::cout << std::endl << std::endl;
}

template <class T>
int LinkedList<T>::getSize()
{
	int size = 0;
	if (!isEmpty()) {
		ListElement<T> *curr = _head;
		while (curr != nullptr) {
			size++;
			curr = curr->getNext();
		}
	}

	return size;
}

template <class T>
bool LinkedList<T>::compareList(const LinkedList<T> *list1, const LinkedList<T> * list2)
{
	if (list1 == nullptr || list2 == nullptr) return false;

	ListElement<T> *temp1 = list1->_head;;
	ListElement<T> *temp2 = list2->_head;

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

template <class T>
void LinkedList<T>::reverseList()
{
	if (isEmpty()) return;

	ListElement<T> *curr = _head;
	ListElement<T> *prev = curr->getNext();
	ListElement<T> *next = nullptr;

	// Iterate until we reach to the end of the list
	while (prev != nullptr) {
		curr->setNext(next);
		next = curr;
		curr = prev;
		prev = prev->getNext();
	}
	curr->setNext(next);

	// Set head to the current element
	_head = curr;
}

template <class T>
ListElement<T>* LinkedList<T>::recursiveReverseList(ListElement<T> *currElement, ListElement<T> *nextElement)
{
	if (currElement->getNext() == nullptr) {
		currElement->setNext(nextElement);
		_head = currElement;
		return currElement;
	}
	else {
		ListElement<T>* temp = currElement->getNext();
		currElement->setNext(nextElement);
		return recursiveReverseList(temp, currElement);
	}
}

template<class T>
void LinkedList<T>::sort()
{

}

int SLLT::testLinkedList()
{
	using namespace std;
	{
		LinkedList<int> LL1(new ListElement<int>(7));
		LL1.insertAtEnd(1);
		LL1.insertAtEnd(6);
		LL1.insertAtEnd(5);
		LL1.insertAtEnd(4);
		cout << "L1 is empty :: " << LL1.isEmpty() << "L1 size : " << LL1.getSize() << endl;
		LL1.display();
		LL1.insertAtHead(10);
		cout << "After insert 10 at head L1 size : " << LL1.getSize() << endl;
		LL1.display();

		LL1.insertAtEnd(20);
		cout << "After insert at end L1 size : " << LL1.getSize() << endl;
		LL1.display();

		LL1.deleteElement(new ListElement<int>(6));
		cout << "after delete 6 L1 size : " << LL1.getSize() << endl;
		LL1.display();

		ListElement<int> *le = LL1.find(6);
		if (le) {
			cout << "L1 find :" << le->getValue() << endl;
		}
		else {
			cout << "not found " << endl;
		}

		LL1.recursiveReverseList();
		cout << "L1 after recursive reverse : size:  " << LL1.getSize() << endl;
		LL1.display();

		LL1.reverseList();
		cout << "L1 after  reverse : size:  " << LL1.getSize() << endl;
		LL1.display();

		LinkedList<int> LL2(new ListElement<int>(5));
		LL2.insertAtEnd(9);
		LL2.insertAtEnd(2);

		cout << "L2 size : " << LL2.getSize() << endl;
		//LinkedList<T><int> LL = LL1.sumLists(LL1, LL2);
		LL2.display();
		LL1 = LL2;

		cout << "are list same: " << LinkedList<int>::compareList(&LL1, &LL2) << endl;
		cout << "L1 size : " << LL1.getSize() << endl;
		cout << "L2 size : " << LL1.getSize() << endl;
		LL1.display();
		LL2.display();

		LinkedList<int> LL3 = LL2;
		LL3.display();
		cout << "are LL2 & LL3 same: " << LinkedList<int>::compareList(&LL2, &LL3) << endl;

		LL3.reverseList();
		cout << "L3 after reverse : size:  " << LL3.getSize() << endl;
		LL3.display();

	}
	getchar();

	return 0;
}

int SLLT::testLinkedList2()
{
	using namespace std;
	{
		LinkedList<char> LL1(new ListElement<char>('a'));
		LL1.insertAtEnd('b');
		LL1.insertAtEnd('c');
		LL1.insertAtEnd('d');
		LL1.insertAtEnd('e');
		cout << "L1 is empty :: " << LL1.isEmpty() << "L1 size : " << LL1.getSize() << endl;
		LL1.display();
		LL1.insertAtHead('f');
		cout << "After insert 10 at head L1 size : " << LL1.getSize() << endl;
		LL1.display();

		LL1.insertAtEnd('g');
		cout << "After insert at end L1 size : " << LL1.getSize() << endl;
		LL1.display();

		LL1.deleteElement(new ListElement<char>('c'));
		cout << "after delete 6 L1 size : " << LL1.getSize() << endl;
		LL1.display();

		ListElement<char> *le = LL1.find('c');
		if (le) {
			cout << "L1 find :" << le->getValue() << endl;
		}
		else {
			cout << "not found " << endl;
		}

		LL1.recursiveReverseList();
		cout << "L1 after recursive reverse : size:  " << LL1.getSize() << endl;
		LL1.display();

		LL1.reverseList();
		cout << "L1 after  reverse : size:  " << LL1.getSize() << endl;
		LL1.display();

		LinkedList<char> LL2(new ListElement<char>('c'));
		LL2.insertAtEnd('a');
		LL2.insertAtEnd('b');

		cout << "L2 size : " << LL2.getSize() << endl;
		//LinkedList<T><int> LL = LL1.sumLists(LL1, LL2);
		LL2.display();
		LL1 = LL2;

		cout << "are list same: " << LinkedList<char>::compareList(&LL1, &LL2) << endl;
		cout << "L1 size : " << LL1.getSize() << endl;
		cout << "L2 size : " << LL1.getSize() << endl;
		LL1.display();
		LL2.display();

		LinkedList<char> LL3 = LL2;
		LL3.display();
		cout << "are LL2 & LL3 same: " << LinkedList<char>::compareList(&LL2, &LL3) << endl;

		LL3.reverseList();
		cout << "L3 after reverse : size:  " << LL3.getSize() << endl;
		LL3.display();

	}
	getchar();

	return 0;
}