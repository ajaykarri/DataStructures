#pragma once
#pragma once
#include<iostream>
namespace SLLT {
	template <class T>
	class ListElement {
	public:
		ListElement(const T data) : _data(data), _next(nullptr) {}
		ListElement(const ListElement & copyNode) : _data(copyNode._data), _next(nullptr) {}

		~ListElement() {}

		ListElement* getNext() { return _next; }
		void		setNext(ListElement *next) { _next = next; }
		void	    setValue(const T &data) { _data = data; }
		T			getValue() { return _data; }

	private:
		//ListElement<T>& operator=(const ListElement<T>&);
		ListElement *_next;
		T			 _data;
	};

	template <class T>
	class LinkedList
	{
	public:
		LinkedList() : _head(nullptr) { std::cout << "Default Constructor called  for @" << this << std::endl; }
		LinkedList(ListElement<T>* newElement) : _head(newElement) { std::cout << "Constructor called  for @" << this << std::endl; }
		~LinkedList();
		LinkedList(const LinkedList<T> &LL);
		LinkedList& operator=(const LinkedList<T> &LL);

		// Insert Operations
		bool		insertAtHead(T data);
		bool		insertAtHead(ListElement<T> *nodeToInsert);
		bool		insertAtEnd(T data);
		bool		insertAtEnd(ListElement<T> *nodeToInsert);
		bool		insertAtPos(T data, int pos);

		// Search operations
		ListElement<T> *find(const T data);
		ListElement<T> *find(ListElement<T> *le);
		ListElement<T> *getElementAtPos(int pos);

		// Delete Operations
		bool		deleteElement(ListElement<T> *deleteMe);
		bool		deleteElement(T data);
		void		deleteList();

		// Misc Operations
		void		display();
		int			getSize();
		int		    isEmpty() const { return _head == nullptr; };
		static bool		compareList(const LinkedList<T> *list1, const LinkedList<T> *list2);

		void		reverseList();
		ListElement<T>* recursiveReverseList() { return recursiveReverseList(_head, nullptr); };
		void		sort();

	private:
		ListElement<T>* recursiveReverseList(ListElement<T> *currElement, ListElement<T> *nextElement);
		ListElement<T> *_head;

	};
	// test
	int testLinkedList();
	int testLinkedList2();
};
