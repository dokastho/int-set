#ifndef INT_SET
#define INT_SET

#include <vector>

#define OCCUPIED 0b1
#define EMPTY 0b0

struct index_offset
{
    int index;
    int offset;
};

class IntSet
{
    std::vector<int> nums;
    std::vector<int> occupied_indices;

    index_offset get_vector_index(int val);

public:
    IntSet();

    bool insert(int val);

    bool remove(int val);

    int getRandom();
};

#endif
