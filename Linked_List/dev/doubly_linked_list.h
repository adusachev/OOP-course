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
	* ������� � ������ ������
	**/
	void push_front(const int value);

	/**
	* ������� � ����� ������
	**/
	void push_back(const int value);

	/**
	* ����� �������� ������
	**/
	void print();

	/**
	* ����� �������� ������ � �������� �������
	**/
	void print_reverse();

	/**
	* �������� ������� �������� ������
	**/
	void pop_front();

	/**
	* �������� ���������� �������� ������
	**/
	void pop_back();

	/**
	* ������� ������
	**/
	void clear();

	/**
	* ��������, �������� �� ������ ������
	**/
	bool is_empty();


	Node* operator[] (const int index);

	/**
	* ������� ����� ���������
	* param pos: ������ ��������, ����� ������� ����� ���������� �������
	* param val: �������� ������������ ��������
	**/
	void insert_before(const int pos, int val);

	/**
	* ������� ����� ��������
	* param pos: ������ ��������, ����� �������� ����� ���������� �������
	* param val: �������� ������������ ��������
	**/
	void insert_after(const int pos, int val);

	/**
	* �������� �������� � �������� pos
	**/
	void erase(int pos);

	/**
	* ������ ������ ��� �������� ������
	* param pos1: ������ ������� ��������
	* param pos2: ������ ������� ��������
	**/
	void swap(int pos1, int pos2);

	/**
	* ������ ������
	**/
	int size();
};