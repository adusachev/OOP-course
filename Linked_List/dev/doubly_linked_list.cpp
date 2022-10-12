#include <iostream>
#include "doubly_linked_list.h"



void DoublyLinkedList::push_front(const int value) {

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


void DoublyLinkedList::push_back(const int value) {
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

void DoublyLinkedList::print() {
	Node* curNode = first;
	while (curNode != nullptr)
	{
		std::cout << curNode->value << " ";
		curNode = curNode->next;
	}
	std::cout << std::endl;
};

void DoublyLinkedList::print_reverse() {
	Node* curNode = last;
	while (curNode != nullptr)
	{
		std::cout << curNode->value << " ";
		curNode = curNode->prev;
	}
	std::cout << std::endl;
};


void DoublyLinkedList::pop_front() {
	if (first != nullptr) {
		Node* tmpNode = first->next;
		delete first;
		first = tmpNode;
		first->prev = nullptr;
		size_--;
	}
}

void DoublyLinkedList::pop_back() {
	if (last != nullptr) {
		Node* tmpNode = last->prev;
		delete last;
		last = tmpNode;
		last->next = nullptr;
		size_--;
	}
}


void DoublyLinkedList::clear() {

	while (first != nullptr) {
		Node* tmpNode = first->next;
		delete first;
		first = tmpNode;
	}
	last = nullptr;
	size_ = 0;

}

bool DoublyLinkedList::is_empty() {
	if (first != nullptr) {
		return false;
	}
	return true;
}


Node* DoublyLinkedList::operator[] (const int index) {
	Node* curNode = first;
	int pos = 0;
	while (curNode != nullptr)
	{
		if (index == pos) {
			return curNode;
		}
		pos++;
		curNode = curNode->next;
	}
	std::cout << "Out of range";
}



void DoublyLinkedList::insert_before(const int pos, int val) {
	int tmp_pos = 0;
	Node* tmpNode = first;
	while (tmp_pos != pos) {
		tmpNode = tmpNode->next;
		tmp_pos++;
	}
	Node* prevNode = tmpNode->prev;
	Node* nextNode = tmpNode;

	Node* newNode = new Node;
	newNode->value = val;

	if (tmpNode == first) {
		newNode->prev = prevNode;
		newNode->next = nextNode;
		nextNode->prev = newNode;
		first = newNode;
	}
	else {
		prevNode->next = newNode;
		newNode->prev = prevNode;
		newNode->next = nextNode;
		nextNode->prev = newNode;
	}
	size_++;
}

void DoublyLinkedList::insert_after(const int pos, int val) {
	int tmp_pos = 0;
	Node* tmpNode = first;
	while (tmp_pos != pos) {
		tmpNode = tmpNode->next;
		tmp_pos++;
	}
	Node* prevNode = tmpNode;
	Node* nextNode = tmpNode->next;

	Node* newNode = new Node;
	newNode->value = val;

	if (tmpNode == last) {
		newNode->prev = prevNode;
		prevNode->next = newNode;
		last = newNode;
	}
	else {
		prevNode->next = newNode;
		newNode->prev = prevNode;
		newNode->next = nextNode;
		nextNode->prev = newNode;
	}
	size_++;
}


void DoublyLinkedList::erase(int pos) {
	int cur_pos = 0;
	Node* curNode = first;
	while (cur_pos != pos) {
		curNode = curNode->next;
		cur_pos++;
	}

	if (curNode == first) {
		pop_front();
	}
	else if (curNode == last) {
		pop_back();
	}
	else {
		Node* prevNode = curNode->prev;
		Node* nextNode = curNode->next;
		delete curNode;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		size_--;
	}
}


void DoublyLinkedList::swap(int pos1, int pos2) {
	int cur_pos = 0;
	int val1, val2;
	Node* curNode = first;
	while (curNode != nullptr) {
		if (cur_pos == pos1) {
			val1 = curNode->value;
		}
		if (cur_pos == pos2) {
			val2 = curNode->value;
		}
		curNode = curNode->next;
		cur_pos++;
	}
	insert_after(pos1, val2);
	erase(pos1);
	insert_after(pos2, val1);
	erase(pos2);
}


int DoublyLinkedList::size() {
	return size_;
}

