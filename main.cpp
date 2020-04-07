#include<iostream>
#include "StringFactory.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "ShuntingYard.hpp"

using namespace std;

int main()
{
    string s = "123+42-8*2";
    string ops = "+-*/()";
    Queue* inputQ = StringFactory::split(s,ops); 
    inputQ->display();

    Queue* outputQ = ShuntingYard::process(inputQ);
    outputQ->display();

}
