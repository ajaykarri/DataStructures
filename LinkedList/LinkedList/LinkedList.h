#pragma once
namespace TLL {
	int testLinkedList();
	template <class T>
	class ListElement {
	public:
		ListElement<T>(const T &data) : _data(data), _next(nullptr) {}
		ListElement<T>(const ListElement<T> & copyNode) : _data(copyNode.data), _next(nullptr) {}

		~ListElement() {}

		ListElement getNext() { return _next; }
		void		setNext(ListElement next) { _next = next; }
		void	    setValue(const T &data) { _data = data; }
		T			getValue() { return _data; }

	private:
		//ListElement<T>& operator=(const ListElement<T>&);
		ListElement<T> *_next;
		T			   _data;
	};

	template<class T>
	class LinkedList
	{
	public:
		LinkedList() : _head(nullptr) {}
		LinkedList(ListElement<T> *newElement) : _head(newElement) {}
		~LinkedList() { deleteList() };
		LinkedList(const LinkedList& LL);
		//LinkedList& operator=(LinkedList byValList);

		// List Operations
		bool		insertAtHead(T data);
		bool		insertAtHead(ListElement<T> *nodeToInsert);
		bool		insertAtEnd(T data);
		bool		insertAtEnd(ListElement<T> *nodeToInsert);
		//bool		insertAtPos(ListElement **head, int data, int pos);

		ListElement<T> *find(T data);
		ListElement<T> *find(const ListElement<T> &le);
		bool		deleteElement(ListElement<T> *deleteMe);
		bool		deleteElement(T data);
		void		deleteList();
		void		display();
		int			getSize();
		int		    isEmpty() { return _head == nullptr };
		bool		compareList(const LinkedList<T> *list1, const LinkedList<T> *list2);

	private:
		ListElement<T> *_head;

	};
};
