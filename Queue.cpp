#include "Queue.hpp"
#include <string.h>

using namespace std;

Queue::Queue()
{
    this->count = 0;
}

string Queue::dequeue()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    string val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

Node* Queue::runToEndOfList()
{
    Node* currNode = this->head;
    while(currNode->getNextNode())
    {
        currNode = currNode->getNextNode();
    }
    return currNode;
    
}

void Queue::enqueue(string payload) //add to end of queue
{
    Node* n = new Node(payload);
    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        Node* currNode = this->runToEndOfList();
        currNode->setNextNode(n);
    }
    this->count++;
}
void Queue::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        cout << currNode->getPayload() << ",";
        currNode = currNode->getNextNode();
    }
    cout << "\n";
}
