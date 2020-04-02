#include "StringFactory.hpp"

Queue* StringFactory::split(string s, string delims)
{
    string delimHolder = "";
    string numHolder = "";
    int stringSize = s.length();
    Queue* returnQueue = new Queue;
    for(int i = 0; i < stringSize; i++) //cycles through given string s
    {
        for(int j = 0; j < delims.length(); j++) //cycles through given delims
        {
            if(s.at(i) == delims.at(j)) //if the char in s is a delim
            {
                delimHolder = s.at(i); //saves delim to a variable
                if(numHolder != "") //if nums have been building up in numHolder
                {
                    returnQueue->enqueue(numHolder); //enqueue numHolder string to returnQueue
                    numHolder = "";
                }
                returnQueue->enqueue(delimHolder);
                break; //prevents StringFactory from adding the same char multiple times
            }
        }
        if(delimHolder == "") //if the char in s did not match a delim (if it was a number)
        {
            numHolder = numHolder + s.at(i);
        }
        delimHolder = ""; //clears delimHolder for next round since only one delim is handled at a time 
    }
    returnQueue->enqueue(numHolder); //adds the last number caught in numHolder
    returnQueue->display();
    return returnQueue;
}
