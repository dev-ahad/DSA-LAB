#include <iostream>
#include <cstdlib> 
#include <string>

using namespace std;

#define MAX_ITEMS 100

template <typename T>
class Stack {
public:
    Stack();
    int IsEmpty() const;
    int IsFull() const;
    void Push(T newItem);
    void Pop(T& item);
    T Peek() const;

private:
    int top;
    T items[MAX_ITEMS];
};

template <typename T>
Stack<T>::Stack() {
    top = -1;
}

template <typename T>
int Stack<T>::IsEmpty() const {
    return (top == -1);
}

template <typename T>
int Stack<T>::IsFull() const {
    return (top == MAX_ITEMS - 1);
}

template <typename T>
void Stack<T>::Push(T newItem) {
    if (IsFull()) {
        cout << "Stack Overflow" << endl;
        exit(1);
    }
    top++;
    items[top] = newItem;
}

template <typename T>
void Stack<T>::Pop(T& item) {
    if (IsEmpty()) {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    item = items[top];
    top--;
}

template <typename T>
T Stack<T>::Peek() const {
    if (IsEmpty()) {
        cout << "Stack is Empty!" << endl;
        exit(1);
    }
    return items[top];
}

void ReverseString(string& str) {
    Stack<char> s; 

    // Push all characters onto the stack
    for (size_t i = 0; i < str.length(); i++) {
        s.Push(str[i]);
    }

    // Pop characters from stack to reverse the string
    for (size_t i = 0; i < str.length(); i++) {
        char ch;
        s.Pop(ch);
        str[i] = ch;
    }
}

// Main function to test stack operations and string reversal
int main() {
    Stack<int> s; // Stack for integers
    int item;

    // Push and Pop demonstration
    cout << "Pushing numbers onto stack: ";
    for (int i = 0; i < 10; i++) {
        s.Push(i);
        cout << i << " ";
    }
    cout << endl;

    cout << "Popping numbers from stack (LIFO): ";
    for (int i = 0; i < 10; i++) {
        s.Pop(item);
        cout << item << " ";
    }
    cout << endl;

    s.Push(99);
    cout << "Peek top element: " << s.Peek() << endl;
    
    // Test string reversal
    string str = "Hello, World!";
    cout << "Original String: " << str << endl;

    ReverseString(str);

    cout << "Reversed String: " << str << endl;

    return 0;
}
