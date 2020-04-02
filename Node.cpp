#include "Node.hpp"
#include <string.h>
using namespace std;

Node::Node(string payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

string Node::getPayload()
{
    return this->payload;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}
