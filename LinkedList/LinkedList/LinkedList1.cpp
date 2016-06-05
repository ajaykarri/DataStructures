#include <iostream>
namespace LL1 {
	struct Node
	{
		int data;
		Node* next;
	};

	typedef struct Node* NODE;
	// only for the first node
	void initNode(NODE head, int n) {
		head->data = n;
		head->next = nullptr;
	}

	// Create Node
	NODE createNode(int n) {
		NODE newNode = new Node;
		newNode->data = n;
		newNode->next = nullptr;

		return newNode;
	}

	NODE createNode(int n, NODE *node) {
		NODE newNode = new Node;
		newNode->data = n;
		newNode->next = *node;

		return newNode;
	}

	// apending 
	void addNode(NODE head, int n) {
		NODE curr = head;
		while (curr != nullptr && curr->next != nullptr) {
			curr = curr->next;
		}

		curr->next = createNode(n);
	}

	//insert at front
	void insertAtFront(NODE *head, int n) {
		NODE newNode = createNode(n, &*head);
		*head = newNode;
	}

	// Search Node
	NODE searchNode(NODE head, int n) {
		NODE curr = head;
		while (curr && curr->data != n) {
			curr = curr->next;
		}
		if (curr != nullptr) {
			return curr;
		}
		else {
			std::cout << "No Node in the list " << std::endl;
		}
	}

	// delete the node, given the node
	bool deleteNode(NODE *head, NODE ptrDel) {
		NODE curr = *head;
		// If head is the node to delete
		if (ptrDel == *head) {
			*head = curr->next;
			delete ptrDel;
			ptrDel = nullptr;
			return true;
		}

		while (curr != nullptr) {
			if (curr->next && curr->next == ptrDel) {
				curr = curr->next;
				delete ptrDel;
				ptrDel = nullptr;
				return true;
			}
 		}

		std::cout << "Coudn't find the node" << std::endl;
		return false;
	}

	// reverse the list
	NODE reverseList(NODE *head) {
		NODE parent = *head;
		NODE me = parent->next;
		NODE child = me->next;

		// Make parent as tail
		parent->next = nullptr;

		while (child) {
			me->next = parent;
			parent = me;
			me = child;
			child = child->next;
		}
		me->next = parent;
		*head = me;
		return *head;
	}

	// Create copy of the list
	void copyLinkedList(NODE node, NODE *pNewNode) {
		if (node == nullptr) {
			*pNewNode = nullptr;
			return;
		}
	#if 0
		while (node) {
			*pNewNode = createNode(node->data)
			node = node->next;
		}
	#endif
	}

	// Compare two linke list 
	// Return value: same (true), different (false)
	bool compareLinkedList(NODE node1, NODE node2) {
		// check if the nodes are valid
		if (node1 == nullptr || node2 == nullptr) {
			return false;
		}

		while (node1 && node2) {
			if (node1->data == node2->data) {
				node1 = node1->next;
				node2 = node2->next;
			} else {
				return false;
			}
		}
	
		if (node1 == nullptr && node2 == nullptr) {
			return true;
		} 

		return false;
	}

	// delete linked list
	void deleteLinkedList(NODE *node) {
		NODE tmpNode = nullptr;
		while (*node) {
			tmpNode = *node;
			*node = tmpNode->next;
			delete tmpNode;
			tmpNode = nullptr;
		}
	}

	// Display 
	void display(NODE head) {
		NODE tmpNode = head;
		while (tmpNode) {
			std::cout << tmpNode->data << "->";
			tmpNode = tmpNode->next;
		}
		std::cout << std::endl << std::endl;
	}


	int main()
	{
		using namespace std;
		struct Node *newHead;
		struct Node *head = new Node;

		initNode(head, 10);
		display(head);

		addNode(head, 20);
		display(head);

		addNode(head, 30);
		display(head);

		addNode(head, 35);
		display(head);

		addNode(head, 40);
		display(head);

		insertAtFront(&head, 5);
		display(head);

		int numDel = 5;
		Node *ptrDelete = searchNode(head, numDel);
		if (deleteNode(&head, ptrDelete))
			cout << "Node " << numDel << " deleted!\n";
		display(head);

		cout << "The list is reversed\n";
		reverseList(&head);
		display(head);

		cout << "The list is copied\n";
		copyLinkedList(head, &newHead);
		display(newHead);

		cout << "Comparing the two lists...\n";
		cout << "Are the two lists same?\n";
		if (compareLinkedList(head, newHead))
			cout << "Yes, they are same!\n";
		else
			cout << "No, they are different!\n";
		cout << endl;

		numDel = 35;
		ptrDelete = searchNode(newHead, numDel);
		if (deleteNode(&newHead, ptrDelete)) {
			cout << "Node " << numDel << " deleted!\n";
			cout << "The new list after the delete is\n";
			display(newHead);
		}
		cout << "Comparing the two lists again...\n";
		cout << "Are the two lists same?\n";
		if (compareLinkedList(head, newHead))
			cout << "Yes, they are same!\n";
		else
			cout << "No, they are different!\n";

		cout << endl;
		cout << "Deleting the copied list\n";
		deleteLinkedList(&newHead);
		display(newHead);

		getchar();
		return 0;
	}
}