#include <vector>
#include <cassert>
#include <iostream>
#include "int-set.h"

int main()
{
    IntSet r;
    bool success = false;
    for (int i = 0; i < 100; i++)
    {
        success = r.insert(1000000000 + i);
        assert(success);
        success = r.insert(-1000000000 - i);
        assert(success);
    }
    for (int i = 0; i < 100; i++)
    {
        success = r.remove(1000000000 + i);
        assert(success);
        success = r.remove(-1000000000 - i);
        assert(success);
    }
    std::cout << "passed." << std::endl;
    return 0;
}
