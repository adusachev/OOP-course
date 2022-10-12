#pragma once


struct Node {
	int value = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};


struct DoublyLinkedList {
	Node* first = nullptr;
	Node* last = nullptr;
	int size_ = 0;

	/**
	* Вставка в начало списка
	**/
	void push_front(const int value);

	/**
	* Вставка в конец списка
	**/
	void push_back(const int value);

	/**
	* Вывод значений списка
	**/
	void print();

	/**
	* Вывод значений списка в обратном порядке
	**/
	void print_reverse();

	/**
	* Удаление первого элемента списка
	**/
	void pop_front();

	/**
	* Удаление последнего элемента списка
	**/
	void pop_back();

	/**
	* Очистка списка
	**/
	void clear();

	/**
	* Проверка, является ли список пустым
	**/
	bool is_empty();


	Node* operator[] (const int index);

	/**
	* Вставка перед элементом
	* param pos: индекс элемента, перед которым хотим произвести вставку
	* param val: значение вставляемого элемента
	**/
	void insert_before(const int pos, int val);

	/**
	* Вставка после элемента
	* param pos: индекс элемента, после которого хотим произвести вставку
	* param val: значение вставляемого элемента
	**/
	void insert_after(const int pos, int val);

	/**
	* Удаление элемента с индексом pos
	**/
	void erase(int pos);

	/**
	* Меняет местми два элемента списка
	* param pos1: индекс первого элемента
	* param pos2: индекс второго элемента
	**/
	void swap(int pos1, int pos2);

	/**
	* Размер списка
	**/
	int size();
};