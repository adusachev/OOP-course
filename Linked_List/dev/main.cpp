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
			last->next= newNode;
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

	////////////////////////////////////////////////////////





	void clear() {
		while (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
		}
		size_ = 0;
	}

	void pop_front() {
		if (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
			size_--;
		}
	}

	bool is_empty() {
		if (first != nullptr) {
			return true;
		}
		return false;
	}

	void insert_after(int position, int value) {
		Node* curNode = first;
		int pos = 0;
		while (!(curNode == nullptr))
		{
			if (position == pos) {
				Node* tmpNode = new Node;
				tmpNode->value = value;

				tmpNode->next = curNode->next;

				curNode->next = tmpNode;

				size_++;
				return;
			}
			pos++;
			curNode = curNode->next;
		}
	}

	int operator[] (const int index) {
		Node* curNode = first;
		int pos = 0;
		while (!(curNode == nullptr))
		{
			if (index == pos) {
				return curNode->value;
			}
			pos++;
			curNode = curNode->next;
		}
		std::cout << "Out of range";
	}

	int size() {
		return size_;
	}
};








int main() {
   
    DoublyLinkedList list;

    list.push_back(10);
	list.push_back(5);
    list.push_back(7);
    list.push_back(-19);

	//list.push_front(10);
	//list.push_front(5);
	//list.push_front(7);
	//list.push_front(-19);

	list.print();
	list.print_reverse();



    //list.insert_after(0, 20);

    //list.print();
	//cout << "Size: " << list.size();

	//list.print_reverse();
                                                                                
    return 0;
}

