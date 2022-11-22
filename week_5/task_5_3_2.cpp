
#include<string>



struct Expression {
    Expression(std::string expr) {
        expr_ = expr;
    }

    std::string expr_;
};

struct Number;
struct BinaryOperation;


struct Storage {
    Storage(Expression* ptr) {
        this->ptr = ptr;
        counter++;
    }
    ~Storage() {
        delete ptr;
    }

    int counter = 0;
    Expression* ptr = 0;
};


struct SharedPtr {
    
    Storage* storage;
    
    
    explicit SharedPtr(Expression *ptr = 0) {
        if (ptr != 0) {
            storage = new Storage(ptr);
        }
        else {
            storage = 0;
        }
    }

    ~SharedPtr() {
        if (storage != 0) {
            (storage->counter)--;
            if (storage->counter == 0) {
                delete storage;
                storage = 0;
            }
        }
    }
    
    SharedPtr(const SharedPtr & obj) {
        this->storage = obj.storage;
        if((this->storage != 0) && (this->storage->counter))
            (this->storage->counter)++;
    }

    SharedPtr& operator=(const SharedPtr & obj) {
        if (this != &obj) {
            this->~SharedPtr();
            this->storage = obj.storage;
            if (this->storage != 0) {
                this->storage->counter++;
            }
        }
        return *this;
    }
    
    void reset(Expression *ptr = 0) {
        this->~SharedPtr();

        if (ptr != 0) {
            storage = new Storage(ptr);
        }
        else {
            storage = 0;
        }
    }

    Expression* get() const {
        return this->storage->ptr;
    }
    
    Expression& operator*() const {
        return *this->storage->ptr;
    }
    
    Expression* operator->() const{
        return this->storage->ptr;
    }
    

};





int main() {

    SharedPtr p1;

    {
        SharedPtr p2(new Expression("expr1"));
        SharedPtr p3(new Expression("expr2"));
        SharedPtr p4(p2);
        SharedPtr p5;
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(0);
        p3 = p5;
        p5.reset(0);
        SharedPtr p6;
        SharedPtr p7;
        p7 = p7;
        p7.reset(0);
        p7.reset(new Expression("expr3"));
        SharedPtr p8(new Expression("expr4"));
        p8.reset(0);
    }
    p1 = p1;


    return 0;
}


