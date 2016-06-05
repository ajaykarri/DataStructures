// A templated singly linked list
#include "LinkedList.h"

using namespace TLL;

LinkedList::~LinkedList()
{
	std::cout << "Destructor called  for @" << this << std::endl; 
	deleteList();
}

LinkedList::LinkedList(const LinkedList & ListToBeCopied)
{
	std::cout << "Copy constructor called for @ " << this <<  std::endl;

	ListElement *copy = ListToBeCopied._head;
	_head = new ListElement(copy->getValue());
	copy = copy->getNext();
	
	ListElement *curr = _head;

	// copy List Elements Until we reach the end of the 
	// List to be copied
	while (copy != nullptr) {
		curr->setNext(new ListElement(copy->getValue()));
		copy = copy->getNext();
		curr = curr->getNext();
	}
}

LinkedList& LinkedList::operator=(const LinkedList &ListToBeAssigned)
{
	std::cout << "Copy assignement operator called for @ " << this << std::endl;

	if (&ListToBeAssigned != this) {
		// Free The memory held by this
		deleteList();

		ListElement *copy = ListToBeAssigned._head;
		if (copy != nullptr) {
			_head = new ListElement(copy->getValue());
			ListElement *curr = _head;
			copy = copy->getNext();

			// copy List Elements Until we reach the end of the 
			// List to be copied
			while (copy != nullptr) {
				curr->setNext(new ListElement(copy->getValue()));
				copy = copy->getNext();
				curr = curr->getNext();
			}
		}

	} 

	return *this;
}


bool LinkedList::insertAtHead(int data)
{
	ListElement  *newElement = new ListElement(data);
	if (newElement == nullptr) return false;
	newElement->setNext(_head);
	_head = newElement;
	return true;
}

bool LinkedList::insertAtHead(ListElement * nodeToInsert)
{
	if (nodeToInsert == nullptr) return false;
	return insertAtHead(nodeToInsert->getValue());
}

bool LinkedList::insertAtEnd(int data)
{
	ListElement *nodeToInsert = new ListElement(data);
	if (nodeToInsert == nullptr) return false;

	// head is null
	if (isEmpty()) {
		_head = nodeToInsert;
		return true;
	}

	ListElement *curr = _head;
	// iterate to the end 
	while (curr != nullptr && curr->getNext() != nullptr) {
		curr = curr->getNext();
	}

	curr->setNext(nodeToInsert);
	return true;
}

bool LinkedList::insertAtEnd(ListElement *nodeToInsert)
{
	if (nodeToInsert == nullptr) return false;
	return insertAtEnd(nodeToInsert->getValue());
}

bool LinkedList::insertAtPos(int data, int pos)
{
	ListElement *nodeToInsert = new ListElement(data);
	if (nodeToInsert == nullptr) return false;

	// If list is empty and position is not the 
	// begining of the list return false. 
	if (isEmpty() && pos != 0) {
		return false;
	}

	ListElement *curr = _head;
	// iterate until we are at pos - 1
	while (curr != nullptr && pos != 1) {
		curr = curr->getNext();
		pos--;
	}

	// insert the ListElement
	if (pos == 1) {
		nodeToInsert->setNext(curr->getNext());
		curr->setNext(nodeToInsert);
		return true;
	}
	return false;
}

ListElement * LinkedList::find(const int data)
{
	ListElement *temp = _head;
	if (temp == nullptr) return temp;

	while (temp != nullptr && temp->getValue() != data) {
		temp = temp->getNext();
	}
	return temp;
}

ListElement * LinkedList::find(ListElement *le)
{
	if (le == nullptr) return nullptr;
	return find(le->getValue());
}

ListElement * LinkedList::getElementAtPos(int pos)
{
	if (isEmpty() && pos != 0) {
		return nullptr;
	}

	ListElement *curr = _head;
	// iterate until we are at pos = 0
	while (curr != nullptr && pos != 0) {
		curr = curr->getNext();
		pos--;
	}

	// pos != 0 mean's we reached end of the list
	return (pos ? curr : nullptr);
}

bool LinkedList::deleteElement(ListElement *deleteMe)
{
	if (deleteMe == nullptr) return false;


	ListElement *temp = _head;

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

bool LinkedList::deleteElement(int data)
{
	return deleteElement(new ListElement(data));
}

void LinkedList::deleteList()
{
	if (_head == nullptr) return;

	ListElement *elementToDel = _head;
	ListElement	*next = nullptr;
	while (elementToDel != nullptr) {
		next = elementToDel->getNext();
		delete elementToDel;
		elementToDel = next;
	}
	_head = nullptr;
}

void LinkedList::display()
{
	if (_head == nullptr) return;
	ListElement *temp = _head;
	while (temp != nullptr) {
		std::cout << temp->getValue();
		temp = temp->getNext();
		if (temp != nullptr) {
			std::cout << "->";
		}
	}
	std::cout << std::endl << std::endl;
}

int LinkedList::getSize()
{
	int size = 0;
	if (!isEmpty()) {
		ListElement *curr = _head;
		while (curr != nullptr) {
			size++;
			curr = curr->getNext();
		}
	}

	return size;
}

bool LinkedList::compareList(const LinkedList *list1, const LinkedList * list2)
{
	if (list1 == nullptr || list2 == nullptr) return false;

	ListElement *temp1 = list1->_head;;
	ListElement *temp2 = list2->_head;

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

void LinkedList::reverseList()
{
	if (isEmpty()) return;

	ListElement *curr = _head;
	ListElement *prev = curr->getNext();
	ListElement *next = nullptr;

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

ListElement* LinkedList::recursiveReverseList(ListElement *currElement, ListElement *nextElement)
{
	if (currElement->getNext() == nullptr) {
		currElement->setNext(nextElement);
		_head = currElement;
		return currElement;
	} else {
		ListElement* temp = currElement->getNext();
		currElement->setNext(nextElement);
		return recursiveReverseList(temp, currElement);
	}
}


int LinkedList::testLinkedList() {
	using namespace std;
	{
		LinkedList LL1(new ListElement(7));
		LL1.insertAtEnd(1);
		LL1.insertAtEnd(6);
		LL1.insertAtEnd(5);
		LL1.insertAtEnd(4);
		cout << "L1 is empty :: "<< LL1.isEmpty()<< "L1 size : " << LL1.getSize() << endl;
		LL1.display();
		LL1.insertAtHead(10);
		cout << "After insert 10 at head L1 size : " << LL1.getSize() << endl;
		LL1.display();

		LL1.insertAtEnd(20);
		cout << "After insert at end L1 size : " << LL1.getSize() << endl;
		LL1.display();

		LL1.deleteElement(new ListElement(6));
		cout << "after delete 6 L1 size : " << LL1.getSize() << endl;
		LL1.display();
	
		ListElement *le = LL1.find(6);
		if (le) {
			cout << "L1 find :" << le->getValue() << endl;
		} else {
			cout << "not found " << endl;
		}

		LL1.recursiveReverseList();
		cout << "L1 after recursive reverse : size:  " << LL1.getSize() << endl;
		LL1.display();

		LL1.reverseList();
		cout << "L1 after  reverse : size:  " << LL1.getSize() << endl;
		LL1.display();

		LinkedList LL2(new ListElement(5));
		LL2.insertAtEnd(9);
		LL2.insertAtEnd(2);

		cout << "L2 size : " << LL2.getSize() << endl;
		//LinkedList<int> LL = LL1.sumLists(LL1, LL2);
		LL2.display();
		LL1 = LL2;

		cout << "are list same: " << LinkedList::compareList(&LL1, &LL2) << endl;
		cout << "L1 size : " << LL1.getSize() << endl;
		cout << "L2 size : " << LL1.getSize() << endl;
		LL1.display();
		LL2.display();

		LinkedList LL3 = LL2;
		LL3.display();
		cout << "are LL2 & LL3 same: " << LinkedList::compareList(&LL2, &LL3) << endl;

		LL3.reverseList();
		cout << "L3 after reverse : size:  " << LL3.getSize() <<  endl;
		LL3.display();

	}
	getchar();

	return 0;
}