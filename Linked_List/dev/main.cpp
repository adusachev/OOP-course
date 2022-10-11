#include <iostream>
#include <cassert>

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
		while (curNode != nullptr)
		{
			std::cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << endl;
	};

	void print_reverse() {
		Node* curNode = last;
		while (curNode != nullptr)
		{
			std::cout << curNode->value << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	};


	void pop_front() {
		if (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
			first->prev = nullptr;
			size_--;
		}
	}

	void pop_back() {
		if (last != nullptr) {
			Node* tmpNode = last->prev;
			delete last;
			last = tmpNode;
			last->next = nullptr;
			size_--;
		}
	}

	void clear() {
		while (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
			//first->prev = nullptr;
		}
		last = nullptr;
		size_ = 0;

		//// second variant (?)
		//first = nullptr;
		//last = nullptr;
		//size_ = 0;
	}

	bool is_empty() {
		if (first != nullptr) {
			return false;
		}
		assert(last == nullptr);
		return true;
	}


	Node* operator[] (const int index) {
		Node* curNode = first;
		int pos = 0;
		while (curNode != nullptr)
		{
			if (index == pos) {
				//return curNode->value;
				return curNode;
			}
			pos++;
			curNode = curNode->next;
		}
		std::cout << "Out of range";
	}



	void insert_before(const int pos, int val) {
		/// <summary>
		/// 
		/// Производит вставку элемента со значением val перед 
		/// элементом с индексом pos в исходном списке
		int tmp_pos = 0;
		Node* tmpNode = first;
		while (tmp_pos != pos) {
			tmpNode = tmpNode->next;
			tmp_pos++;
		}
		Node* prevNode = tmpNode->prev;
		Node* nextNode= tmpNode;

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

	void insert_after(const int pos, int val) {
		/// <summary>
		/// 
		/// Производит вставку элемента со значением val после 
		/// элемента с индексом pos в исходном списке
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


	void insert(const int pos, int val) {
		/// <summary>
		/// 
		/// Производит вставку элемента со значением val на место pos в новом списке (нужно ли?)
		if (pos == size_) {
			insert_after(pos-1, val);
		}
		else {
			insert_before(pos, val);
		}
	}



	void erase(int pos) {
		/// <summary>
		/// 
		/// Удаление элемента с индексом pos
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


	void swap(int pos1, int pos2) {
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
		erase(pos1);
		insert(pos1, val2);
		erase(pos2);
		insert(pos2, val1);
	}




	int size() {
		return size_;
	}
};









void test1() {
	/// <summary>
	/// 
	/// Test for push_back() and push_front()
	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_front(7);
	list.push_front(-19);

	cout << "List: ";
	list.print();
	cout << "Reversed list: ";
	list.print_reverse();
}


void test2() {
	/// <summary>
	/// 
	/// Test for pop_front() and pop_back()
	DoublyLinkedList list;

	list.push_back(1);
	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);
	list.push_back(23);
	list.push_back(54);

	cout << "Initial list: ";
	list.print();

	list.pop_front();
	list.pop_front();
	list.pop_back();
	list.pop_back();

	cout << endl;
	cout << "List after pops: ";
	list.print();
	cout << endl;

	cout << "First elem after pops: " << list.first->value << endl;
	cout << "Last elem after pops: " << list.last->value << endl;
}


void test3() {
	/// <summary>
	/// 
	/// Test for clear() and is_empty()
	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	cout << "Initial list: ";
	list.print();
	cout << "Is empty: " << list.is_empty() << endl;
	cout << "Size: " << list.size() << endl;

	cout << endl;
	list.clear();
	cout << "List after clear: ";
	list.print();
	cout << "Size: " << list.size() << endl;
	cout << "Is empty: " << list.is_empty() << endl;;	
}


void test4() {
	/// <summary>
	/// 
	/// Test for indexing
	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	cout << "Initial list: ";
	list.print();
	cout << "Size: " << list.size() << endl;

	cout << endl;
	cout << list[0]->value << endl;
	cout << list[0]->next->value << endl;


	//for (int i = 0; i < list.size(); i++) {
	//	cout << list[i] << ", ";
	//}
}


void test5() {
	/// <summary>
	/// 
	/// Test for insert()
	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(-19);

	cout << "Initial list: ";
	list.print();
	cout << "Size: " << list.size() << endl << endl;

	int value = 7;
	//list.insert_after(2, value);
	//list.insert_before(0, value);
	list.insert(3, value);
	cout << "Inserted value: " << value << endl;
	cout << "New list: ";
	list.print();
	list.print_reverse();
	cout << "Size: " << list.size() << endl;

	// вставка в пустой список (?)
}



void test6() {
	/// <summary>
	/// 
	/// Test for erase()
	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	cout << "Initial list: ";
	list.print();
	cout << "Size: " << list.size() << endl << endl;

	list.erase(2);
	cout << "New list: ";
	list.print();
	list.print_reverse();
	cout << "Size: " << list.size() << endl;
}


void test7() {
	/// <summary>
	/// 
	/// Test for swap()
	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	cout << "Initial list: ";
	list.print();
	cout << "Size: " << list.size() << endl << endl;

	list.swap(3, 0);
	cout << "New list: ";
	list.print();
	list.print_reverse();
	cout << "Size: " << list.size() << endl;
}





int main() {


	test7();



                                                                                
    return 0;
}

