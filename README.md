# int-set
O(1) time and ~O(n) space complexity set for integers 

# Misc Attributes

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
- Single-threaded
