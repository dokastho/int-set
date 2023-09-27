# int-set

## Synapsis

O(1) time and ~O(n) space complexity set for integers

## Intended Usecase

This data type is best used when minimum time complexity is required and space is limited. It can be used to record the contents of a set of integers

## Design

This data type works by keeping record of a vector of 32 bit integers and uses a mapping function to map integer values to bits in that vector of integers. Negative numbers are stored alternate their positive counterparts.

For example:
- 0 maps to vector index 0, bit 0
- -1 maps to vector index 0, bit 1
- 10 maps to vector index 0, bit 20
- 32 maps to vector index 2, bit 0

When an integer value is inserted into the set, each bit is set to 1. When an integer is in the set and insert is called with that value insert will return false, true if that value is not present

Delete will return true if that value is in the set, false otherwise.

Getrandom will return a random integer from the set

All functions operate in O(1) time complexity. Each function maintains a cache of vector indices that contain values. This enables getrandom to operate within the O(1) time complexity constraint for choosing a non-empty index at random.

## Constraints

- 2^31 <= val <= 2^31 - 1
- At most 2 * 10^5 calls will be made to insert, remove, and getRandom
- There will be at least one element in the data structure when getRandom is called

## Problem Link

This code is a ground-up solution to Leetcode Daily Problem on Nov 28, 2022. [link](https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150)

## Misc Attributes

- Single-threaded
- Free of leaks:
```Valgrind
==1189451== Memcheck, a memory error detector
==1189451== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1189451== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1189451== Command: ./test_main
==1189451== 
==1189451== Warning: set address range perms: large range [0x1403f040, 0x31d15548) (undefined)
==1189451== Warning: set address range perms: large range [0x1403f028, 0x31d15560) (noaccess)
==1189451== 
==1189451== HEAP SUMMARY:
==1189451==     in use at exit: 0 bytes in 0 blocks
==1189451==   total heap usage: 8 allocs, 8 frees, 750,076,872 bytes allocated
==1189451== 
==1189451== All heap blocks were freed -- no leaks are possible
==1189451== 
==1189451== For lists of detected and suppressed errors, rerun with: -s
==1189451== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
