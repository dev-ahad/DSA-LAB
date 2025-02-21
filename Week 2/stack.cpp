#include <stdlib.h> 
#include "stack.h"

Stack::Stack(){
  top = -1;   
}

int Stack::IsEmpty() const
{
    return (top == -1);
}

int Stack::IsFull() const
{
    return (top == MAX_ITEMS-1);
}

void Stack::Push(ItemType newItem)
{
    if (IsFull())
    {
        cout << "Stack Overflow" << endl; 
        exit(1);
    }
    top++;
    items[top] = newItem;
}

void Stack::Pop (ItemType& item)
{
    if (IsEmpty())
    {
    cout<< "Stack Underflow" << endl;
    exit(1);
}
    item = items[top];
    top--;
}