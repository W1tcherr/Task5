#include <iostream>
#include "func.h"

int main() {
    std::cout << "Enter number: ";
    unsigned num = getValue();
    if(num == 1 || num == 0)
        std::cout << "\nThere is no prime number less than entered." << std::endl;
    else
    {
        if(num % 2 == 0)
            printPairSimpleNumber(num-1);
        else
            printPairSimpleNumber(num-2);
    }
    return 0;
}