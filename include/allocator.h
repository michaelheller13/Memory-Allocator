//Michael Heller
//allocator.h


#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

//define the free and allocated dlinked lists
struct dlist *free_list;
struct dlist *allocated_list;

//initialize the two above lists
int allocator_init(size_t size);

//malloc the space for each allocation of memory
void *allocate(size_t size, char *method);

//free the allocated memory space
int deallocate(void *ptr);

//function for the first-fit allocation algorithm
void *first_fit(size_t size);

//function for the best-fit allocation algorithm
void *best_fit(size_t size);

//function for the worst-fit allocation algorithm
void *worst_fit(size_t size);

#endif /* _ALLOCATOR_H_ */

