#include <iostream>

using namespace std;


struct Node {
	int value = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};


struct DoublyLinkedList {
	Node* first = nullptr;
	Node* last = nullptr;
	int size_ = 0;


	void push_front(const int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = first;

		if (size_ == 0) {
			last = newNode;
		}
		else {
			first->prev = newNode;
		}
		first = newNode;
		size_++;
	}


	void push_back(const int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->prev = last;

		if (size_ == 0) {
			first = newNode;
		}
		else {
			last->next = newNode;
		}
		last = newNode;
		size_++;

	}

	void print() {
		Node* curNode = first;
		while (!(curNode == nullptr))
		{
			std::cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	};

	void print_reverse() {
		Node* curNode = last;
		while (!(curNode == nullptr))
		{
			std::cout << curNode->value << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	};



};

