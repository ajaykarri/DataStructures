#pragma once
#include<iostream>
namespace TLL {
	class ListElement {
	public:
		ListElement(const int data) : _data(data), _next(nullptr) {}
		ListElement(const ListElement & copyNode) : _data(copyNode._data), _next(nullptr) {}

		~ListElement() {}

		ListElement* getNext() { return _next; }
		void		setNext(ListElement *next) { _next = next; }
		void	    setValue(const int &data) { _data = data; }
		int			getValue() { return _data; }

	private:
		//ListElement<T>& operator=(const ListElement<T>&);
		ListElement *_next;
		int			 _data;
	};

	class LinkedList
	{
	public:
		LinkedList() : _head(nullptr) { std::cout << "Default Constructor called  for @" << this << std::endl; }
		LinkedList(ListElement *newElement) : _head(newElement) { std::cout << "Constructor called  for @" << this << std::endl; }
		~LinkedList();
		LinkedList(const LinkedList& LL);
		LinkedList& operator=(const LinkedList &LL);

		// Insert Operations
		bool		insertAtHead(int data);
		bool		insertAtHead(ListElement *nodeToInsert);
		bool		insertAtEnd(int data);
		bool		insertAtEnd(ListElement *nodeToInsert);
		bool		insertAtPos(int data, int pos);

		// Search operations
		ListElement *find(const int data);
		ListElement *find(ListElement *le);
		ListElement *getElementAtPos(int pos);

		// Delete Operations
		bool		deleteElement(ListElement *deleteMe);
		bool		deleteElement(int data);
		void		deleteList();

		// Misc Operations
		void		display();
		int			getSize();
		void		setHead(ListElement *le) { _head = le; };
		int		    isEmpty() const { return _head == nullptr; };
		static bool		compareList(const LinkedList *list1, const LinkedList *list2);

		void		reverseList();
		ListElement* recursiveReverseList() { return recursiveReverseList(_head, nullptr); };
		


		// test
		static	int testLinkedList();
	private:
		ListElement* recursiveReverseList(ListElement *currElement, ListElement *nextElement);
		ListElement *_head;

	};
};
