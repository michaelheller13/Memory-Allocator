//Michael Heller
//allocator.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allocator.h"
#include "dlist.h"
#include "dnode.h"


int allocator_init (size_t size) {
    allocated_list = dlist_create();
    free_list = dlist_create();
    void *mem = malloc(size);
    if (mem == NULL) {
        printf("error: allocation failed");
        exit(-1);
    }
    struct dnode *init_node = dnode_create();
    dnode_setdata(init_node, mem, size);
    dlist_add_front(free_list, init_node, size);
    return 0;
}

void *allocate (size_t size, char *method) {
    void *mem_alloc = NULL;
    if (strcmp(method, "ff") == 0)
        mem_alloc = first_fit(size);
    if (strcmp(method, "bf") == 0)
        mem_alloc = best_fit(size);
    if (strcmp(method, "wf") == 0)
        mem_alloc = worst_fit(size);
    void *iter = dlist_iter_begin(free_list);
    int i = 0;
    while ((mem_alloc != iter) && (i < free_list->counter)) {
        iter = dlist_iter_next(free_list);
        i++;
    }
    free_list->iter->size -= size;
    free_list->iter->data += size;
    dlist_add_back(allocated_list, mem_alloc, size);
    return mem_alloc;
}

int deallocate (void *ptr) {
    void *iter = dlist_iter_begin(allocated_list);
    int i = 0;
    while (i < allocated_list->counter) {
        if (ptr == iter) {
            dlist_add_back(free_list, iter, allocated_list->iter->size);
            iter = dlist_find_remove(allocated_list, ptr);
            return 0;
        }
        iter = dlist_iter_next(allocated_list);
        i++;
    }
    printf("error: deallocation failed\n");
    return -1;
}

void *first_fit (size_t size) {
    void *iter = dlist_iter_begin(free_list);
    void *ff_ptr = NULL;
    int i = 0;
    while (i < free_list->counter) {
        if (free_list->iter->size >= size) {
           ff_ptr = iter;
           return ff_ptr;
        }
        iter = dlist_iter_next(free_list);
        i++;
    }
    return ff_ptr;   
}

void *worst_fit (size_t size) {
    void *iter = dlist_iter_begin(free_list);
    void *worst_ptr = NULL;
    int big_size = (int) free_list->iter->size;
    int i = 0;
    while (i < free_list->counter) {
        if (size <= free_list->iter->size) {
            if (worst_ptr == NULL)
                worst_ptr = iter;
            if ((int) free_list->iter->size > big_size) {
                big_size = (int) free_list->iter->size;
                worst_ptr = iter;
            }
        }
        iter = dlist_iter_next(free_list);
        i++;
    }   
    return worst_ptr;
}

void *best_fit (size_t size) {
    void *iter = dlist_iter_begin(free_list);
    void *best_ptr = NULL;
    int small_size = (int) free_list->iter->size;
    int i = 0;
    while (i < free_list->counter) {
        if (size <= free_list->iter->size) {
            if (best_ptr == NULL)
                best_ptr = iter;
            if ((int) free_list->iter->size < small_size) {
                small_size = (int) free_list->iter->size;
                best_ptr = iter;
            }
        }
        iter = dlist_iter_next(free_list);
        i++;
    }
    return best_ptr;
}

