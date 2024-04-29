#include <iostream>
#include <vector>
using namespace std;

class Stack {
private: 
    vector<int> elements;
public:
    void push(int value) {
        elements.push_back(value);
    }
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }
    bool isEmpty() const {
        return elements.empty();
    }
    int top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout<<"Top element: "<<stack.top()<<endl;
    stack.pop();
    cout<<"Top element after pop: "<<stack.top()<<endl;
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}