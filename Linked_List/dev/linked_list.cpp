#include <iostream>
//#include <forward_list>



using namespace std;



//void print_array(int n, int array[]) {
//
//    for (int i = 0; i < n; i++) {
//        std::cout << array[i] << " ";
//    }
//    std::cout << std::endl;
//}



// (необязательно)
// можно добавить шаблон, чтоб не работать только с  int
//template<typename Type> поставить перед struct Node
// тогда надо менять Node на Node<Type>


struct Node {
	int value = 0;
	Node* next = nullptr;
};

struct List {
	Node* first = nullptr;
	int size_ = 0;

	void push_front(const int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = first;
		first = newNode;
		size_++;
	}

	void print() {
		Node* curNode = first;
		while (!(curNode == nullptr))
		{
			std::cout << curNode->value << "\n";
			curNode = curNode->next;
		}
	};

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




int main1() {


    {
        cout << "Own list" << endl;

        List list;

        list.push_front(10);
        list.push_front(5);
        list.push_front(-19);

        list.insert_after(0, 20);

        cout << endl;
        for (int i = 0; i < 4; i++) {
            cout << list[i] << endl;
        }

        list.print();

        cout << "List after clear:" << endl;
        list.clear();
        list.print();
    }


    //{
    //    // Library linked list

    //    cout << endl;
    //    forward_list<int> list;


    //    list.push_front(10);
    //    list.push_front(5);
    //    list.push_front(-19);

    //    list.pop_front();

    //    for (auto i : list) {
    //        cout << i << " ";
    //    }

    //}





    return 0;
}













