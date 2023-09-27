#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
#include "int-set.h"

using std::size_t;
using std::string;
using std::vector;

index_offset IntSet::get_vector_index(int val)
{
    long unsigned int bval = 0;
    ;
    if (val < 0)
    {
        bval += 1;
        val *= -1;
        val -= 1;
    }
    bval += val * 2;

    return index_offset{
        int(bval / 32),
        OCCUPIED << (bval % 32)};
}

IntSet::IntSet()
{
    nums = {};
    occupied_indices = {};
}

bool IntSet::insert(int val)
{
    index_offset io = get_vector_index(val);
    if (io.index >= (int)nums.size())
    {
        nums.resize(io.index + 1, 0);
    }
    int original = nums[io.index];
    if ((original & io.offset) != 0)
    {
        return false;
    }
    else
    {
        nums[io.index] |= io.offset;
        if (original == 0)
        {
            occupied_indices.push_back(io.index);
        }
    }
    return true;
}

bool IntSet::remove(int val)
{
    index_offset io = get_vector_index(val);
    if (io.index >= (int)nums.size())
    {
        return false;
    }
    if ((nums[io.index] & io.offset) != 0)
    {
        nums[io.index] &= ~(io.offset | io.offset);
        if (nums[io.index] == 0)
        {
            auto it = std::find(occupied_indices.begin(), occupied_indices.end(), io.index);
            occupied_indices.erase(it);
        }

        return true;
    }
    return false;
}

int IntSet::getRandom()
{
    int rand_index = occupied_indices[rand() % occupied_indices.size()];

    vector<int> nums_at_index;
    for (size_t i = 0; i < 32; i++)
    {
        int occupied = nums[rand_index] & (OCCUPIED << i);
        if (occupied == 0)
        {
            continue;
        }

        int val = (rand_index * 32 + (int)i);
        if (val % 2)
        {
            val *= -1;
            val -= 1;
        }

        val /= 2;
        nums_at_index.push_back(val);
    }

    return nums_at_index[rand() % nums_at_index.size()];
}

