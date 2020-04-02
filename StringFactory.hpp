#ifndef StringFactory_hpp
#define StringFactory_hpp
#include "Queue.hpp"
#include <string.h>
#include <iostream>

using namespace std;

class StringFactory
{
    public:
        static Queue* split(string s, string delims);
};
#endif
