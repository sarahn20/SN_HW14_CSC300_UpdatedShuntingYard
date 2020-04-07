#include "ShuntingYard.hpp"

bool ShuntingYard::isInString(string numOrNot, string searchDictionary)
{
    for(int i = 0; i < searchDictionary.length(); i++)
    {
        if(searchDictionary[i] == numOrNot[0])
        {
            return true;
        }
    }
    return false;
}

Queue* ShuntingYard::process(Queue* inputQ)
{
    Queue* outputQ = new Queue();
    string allDelims = "-+*/()";
    string greaterDelims = "*/";
    string lesserDelims = "-+";
    Stack* operatorStack = new Stack();

    while(inputQ->getCount() > 0)
    {
        Node* currNode = inputQ->getHead();
        if(isInString(currNode->getPayload(),allDelims)) //is a delim
        {
            if(operatorStack->getCount() == 0) //if the OP is empty
            {
                operatorStack->push(inputQ->dequeue());
            }
            else if(isInString(operatorStack->peek(),lesserDelims))
            {
                if(isInString(currNode->getPayload(),lesserDelims))
                {
                    outputQ->enqueue(operatorStack->pop());
                }
                else if(isInString(currNode->getPayload(),greaterDelims))
                {
                    operatorStack->push(inputQ->dequeue());
                }
                else if(isInString(currNode->getPayload(),"("))
                {
                    operatorStack->push(inputQ->dequeue());
                }
                else if(isInString(currNode->getPayload(),")")) //call to action
                {
                    
                    while(operatorStack->peek() != "(")
                    {
                        outputQ->enqueue(operatorStack->pop());
                    }
                    operatorStack->pop();
                    inputQ->dequeue();
                    
                    operatorStack->push(inputQ->dequeue());
                }
                
            }
            else if(isInString(operatorStack->peek(),greaterDelims))
            {
                if(isInString(currNode->getPayload(),greaterDelims))
                {
                    outputQ->enqueue(operatorStack->pop());
                }
                else if(isInString(currNode->getPayload(),")")) //call to action
                {
                    
                    while(operatorStack->peek() != "(")
                    {
                        outputQ->enqueue(operatorStack->pop());
                    }
                    operatorStack->pop();
                    inputQ->dequeue();
                    
                    operatorStack->push(inputQ->dequeue());
                }
                else
                {
                    operatorStack->push(inputQ->dequeue());
                }

            }
            else if(isInString(operatorStack->peek(),"("))
            {
                operatorStack->push(inputQ->dequeue());
            }
        }
        else if(currNode->getPayload() != " ")
        {
            outputQ->enqueue(inputQ->dequeue());
        }
        currNode = currNode->getNextNode();
    }
    while(operatorStack->getCount() > 0)
    {
        outputQ->enqueue(operatorStack->pop());
    }
    
    return outputQ;
}
