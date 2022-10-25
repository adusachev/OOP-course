
#include<iostream>
#include "tests.h"
#include "doubly_linked_list.h"


void test_push() {

	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_front(7);
	list.push_front(-19);

	std::cout << "List: ";
	list.print();
	std::cout << "Reversed list: ";
	list.print_reverse();
}


void test_pop() {

	DoublyLinkedList list;

	list.push_back(1);
	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);
	list.push_back(23);
	list.push_back(54);

	std::cout << "Initial list: ";
	list.print();

	list.pop_front();
	list.pop_front();
	list.pop_back();
	list.pop_back();

	std::cout << std::endl;
	std::cout << "List after pops: ";
	list.print();
	std::cout << std::endl;

	std::cout << "First elem after pops: " << list.first->value << std::endl;
	std::cout << "Last elem after pops: " << list.last->value << std::endl;
}


void test_clear() {

	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	std::cout << "Initial list: ";
	list.print();
	std::cout << "Is empty: " << list.is_empty() << std::endl;
	std::cout << "Size: " << list.size() << std::endl;

	std::cout << std::endl;
	list.clear();
	std::cout << "List after clear: ";
	list.print();
	std::cout << "Size: " << list.size() << std::endl;
	std::cout << "Is empty: " << list.is_empty() << std::endl;;
}


void test_indexing() {

	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	std::cout << "Initial list: ";
	list.print();
	std::cout << "Size: " << list.size() << std::endl;

	std::cout << std::endl;
	std::cout << "list[0] = " << list[0] << std::endl;
	std::cout << "list[1] = " << list[1] << std::endl;
	//std::cout << "list[1] = " << list[0]->next->value << std::endl;

	//for (int i = 0; i < list.size(); i++) {
	//	cout << list[i] << ", ";
	//}
}


void test_insert() {

	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(-19);

	std::cout << "Initial list: ";
	list.print();
	std::cout << "Size: " << list.size() << std::endl << std::endl;

	int value = 7;
	//list.insert_after(2, value);
	list.insert_before(2, value);
	std::cout << "Inserted value: " << value << std::endl;
	std::cout << "New list: ";
	list.print();
	//list.print_reverse();
	std::cout << "Size: " << list.size() << std::endl;
}



void test_erase() {

	DoublyLinkedList list;

	list.clear();
	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	std::cout << "Initial list: ";
	list.print();
	std::cout << "Size: " << list.size() << std::endl << std::endl;

	int pos = 2;  // position of element to delete
	std::cout << "Deleted element: " << list[pos] << std::endl;
	list.erase(pos);
	std::cout << "New list: ";
	list.print();
	//list.print_reverse();
	std::cout << "Size: " << list.size() << std::endl;
}


void test_swap() {

	DoublyLinkedList list;

	list.push_back(10);
	list.push_back(5);
	list.push_back(7);
	list.push_back(-19);

	std::cout << "Initial list: ";
	list.print();
	std::cout << "Size: " << list.size() << std::endl << std::endl;

	int pos1 = 1;
	int pos2 = 3;
	std::cout << "Swap elements " << list[pos1] << " and " << list[pos2] << std::endl;
	list.swap(pos1, pos2);
	std::cout << "New list: ";
	list.print();
	//list.print_reverse();
	std::cout << "Size: " << list.size() << std::endl;
}
