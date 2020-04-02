#ifndef Queue_hpp
#define Queue_hpp
#include "Node.hpp"

class Queue
{
private:
    Node* head;
    int count;
    Node* runToEndOfList();
    
public:
    Queue();
    void enqueue(string payload);
    string dequeue();
    void display();
};
#endif
