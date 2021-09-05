#include "func.h"

unsigned getValue()
{
    while(true)
    {
        unsigned value;
        std::cin >> value;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nWrong size, please re-enter.\n";
        }
        else
        {
            return value;
        }
    }
}

void printPairSimpleNumber(unsigned number)
{
    unsigned simple1 = 0;
    unsigned simple2 = 0;
    unsigned simple3 = 0;
    unsigned pairCount = 1;
    for(long i = number; i > 0; i-=2)
    {
        if(i % 3 == 0)
            continue;
        if(searchSimpleNumber(i))
        {
            simple3 = simple2;
            simple2 = simple1;
            simple1 = i;
        }
        else
            continue;
        if(simple2 - simple1 == 6)
        {
            std::cout << "\nPair " << pairCount << ": " << simple1 << '\t' << simple2;
            ++pairCount;
        }
        else if(simple3 - simple1 == 6)
        {
            std::cout << "\nPair " << pairCount << ": " << simple1 << '\t' << simple3;
            ++pairCount;
        }
    }
    if(pairCount == 1)
        std::cout << "In the given range, there are no pairs of primes differing by 6." << std::endl;
}

bool searchSimpleNumber(unsigned number)
{
    unsigned limit = sqrt(number);
    for(unsigned i = 5; i <= limit; i+=6)
        if(number % i == 0 || number % (i + 2) == 0)
            return false;
    return true;
}