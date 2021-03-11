//Michael Heller
//memory-test-1.c


#include <stdlib.h>
#include <stdio.h>
#include "dnode.h"
#include "dlist.h"
#include "allocator.h"

int main () {
    printf("----------TESTING FIRST FIT ALLOCATION----------\n");
    printf("allocate 1000 bytes for the algorithm\n");
    allocator_init(1000);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 300 byte block\n");
    void *alloc1 = allocate(300, "ff");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 400 byte block\n");
    void *alloc2 = allocate(400, "ff");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 200 byte block\n");
    void *alloc3 = allocate(200, "ff");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("deallocate the 300 byte block\n");
    deallocate(alloc1);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list); 

    printf("allocate 290 bytes\n");
    alloc1 = allocate(290, "ff");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 10 bytes that should take from the FIRST available block in free_list\n");
    void *alloc4 = allocate(10, "ff");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("deallocating rest of memory\n");
    deallocate(alloc2);
    deallocate(alloc3);
    deallocate(alloc1);
    deallocate(alloc4);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("----------TESTING BEST FIT ALLOCATION----------\n");
    printf("allocate 1000 bytes for the algorithm\n");
    allocator_init(1000);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 300 byte block\n");
    alloc1 = allocate(300, "bf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 400 byte block\n");
    alloc2 = allocate(400, "bf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 200 byte block\n");
    alloc3 = allocate(200, "bf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("deallocate 300 byte block\n");
    deallocate(alloc1);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 290 bytes\n");
    alloc1 = allocate(290, "bf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 10 bytes to go back into the best fit block of 10 bytes from the free_list\n");
    alloc4 = allocate(10, "bf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("deallocating rest of memory\n");
    deallocate(alloc2);
    deallocate(alloc3);
    deallocate(alloc1);
    deallocate(alloc4);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);


    printf("----------TESTING WORST FIT ALLOCATION----------\n");
    printf("allocate 1000 bytes for the algorithm\n");
    allocator_init(1000);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 300 byte block\n");
    alloc1 = allocate(300, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 400 byte block\n");
    alloc2 = allocate(400, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 100 byte block\n");
    alloc3 = allocate(100, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 200 byte block\n");
    alloc4 = allocate(200, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("deallocating all blocks of memory so that free_list has different sized, available blocks\n");
    deallocate(alloc1);
    deallocate(alloc2);
    deallocate(alloc3);
    deallocate(alloc4);
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 210 bytes, should take from the 400 block\n");
    alloc4 = allocate(210, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 90 bytes, should take from the 300 block\n");
    alloc4 = allocate(90, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);

    printf("allocate 10 bytes, should take from the remaining 210 in the 300 block\n");
    alloc4 = allocate(10, "wf");
    printf("free list:  ");
    dlist_print(free_list);
    printf("allocated list:  ");
    dlist_print(allocated_list);     

    printf("----------END OF TESTS----------\n");
return 0;
}
