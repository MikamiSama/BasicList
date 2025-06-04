#include <iostream>
#include <vector>
#include <string>

template <typename T>
class List {
protected:
    std::vector<T> elements;

public:
    List() {
    }

    virtual ~List() {
    }

    virtual void insert(const T& value) = 0;
    virtual T remove() = 0;

    bool isEmpty() const {
        return elements.empty();
    }

    size_t getSize() const {
        return elements.size();
    }

    void display() const {
        std::cout << "Elements: ";
        if (isEmpty()) {
            std::cout << "[empty]";
        }
        else {
            for (const T& elem : elements) {
                std::cout << elem << " ";
            }
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Stack : public List<T> {
public:
    void insert(const T& value) override {
        this->elements.push_back(value);
        std::cout << "Pushed: " << value << std::endl;
    }

    T remove() override {
        if (this->isEmpty()) {
            std::cout << "Error: Stack is empty! Cannot pop." << std::endl;
            return T();
        }
        T value = this->elements.back();
        this->elements.pop_back();
        std::cout << "Popped: " << value << std::endl;
        return value;
    }
};

template <typename T>
class Queue : public List<T> {
public:
    void insert(const T& value) override {
        this->elements.push_back(value);
        std::cout << "Enqueued: " << value << std::endl;
    }

    T remove() override {
        if (this->isEmpty()) {
            std::cout << "Error: Queue is empty! Cannot dequeue." << std::endl;
            return T();
        }
        T value = this->elements.front();
        this->elements.erase(this->elements.begin());
        std::cout << "Dequeued: " << value << std::endl;
        return value;
    }
};

int main() {
    std::cout << "--- Завдання 1: Список, Стек, Черга ---" << std::endl;

    std::cout << "\nОперації зі Стеком (Stack<int>):" << std::endl;
    Stack<int> myStack;
    myStack.insert(10);
    myStack.insert(20);
    myStack.insert(30);
    myStack.display();
    myStack.remove();
    myStack.display();
    myStack.remove();
    myStack.display();
    myStack.remove();
    myStack.display();
    myStack.remove();

    std::cout << "\nОперації з Чергою (Queue<std::string>):" << std::endl;
    Queue<std::string> myQueue;
    myQueue.insert("Apple");
    myQueue.insert("Banana");
    myQueue.insert("Cherry");
    myQueue.display();
    myQueue.remove();
    myQueue.display();
    myQueue.remove();
    myQueue.display();
    myQueue.remove();
    myQueue.display();
    myQueue.remove();

    return 0;
}