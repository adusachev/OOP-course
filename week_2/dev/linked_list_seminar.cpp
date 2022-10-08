#include <iostream>
#include <forward_list>



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
    int size = 0;

    void push_front(const int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = first;
        first = newNode;
        size++;

    }

    void print() {
        Node* curNode = first;  // current node
        while (!(curNode == nullptr)) {
            cout << curNode->value << endl;
            curNode = curNode->next;
        }
    }

    void clear() {
        //for (Node* node = first; node != nullptr; node = node->next) {
        //    Node* tmpNode = node->next;  // сохр указатель на сдел ноду
        //    delete node;  // удаляем текущую
        //    first = tmpNode;  
        //}
        while (first != nullptr) {
            Node* tmpNode = first->next;
            delete first;
            first = tmpNode;
        }
        size = 0;
    }

    void pop_front() {
        if (first != nullptr) {
            Node* tmpNode = first->next;
            delete first;
            first = tmpNode;
        }
        size--;
    }

    bool is_empty() {
        if (first != nullptr) {
            return true;
        }
        return false;
    }


    void insert_after(int position, int value) {
        Node* curNode = first;  // current node
        int pos = 0;
        while (!(curNode == nullptr)) {

            if (position == pos) {
                Node* tmpNode = new Node;
                tmpNode->value = value;

                tmpNode->next = curNode->next;
                curNode->next = tmpNode;

                /* if (pos == 0) {
                     first = tmpNode;
                 }*/
                size++;
                return;
            }

            pos++;
            curNode = curNode->next;
        }
    }

    // refresh [index]
    int operator[] (const int index) {
        Node* curNode = first;  // current node
        int pos = 0;
        while (!(curNode == nullptr)) {

            if (index == pos) {
                return curNode->value;
            }
            pos++;
            curNode = curNode->next;
        }

        cout << "Out of range" << endl;
    }

    //int size() {  // ругается, можно сделать через цикл
    //    return size;
    //}
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













