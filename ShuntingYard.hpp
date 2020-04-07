#ifndef ShuntingYard_hpp
#define ShuntingYard_hpp
#include "StringFactory.hpp"
#include "Stack.hpp"
#include <iostream>

using namespace std;

class ShuntingYard
{
    public:
        static Queue* process(Queue* inputQ);
    private:
        static bool isInString(string numOrNot, string searchDictionary);
};
#endif
