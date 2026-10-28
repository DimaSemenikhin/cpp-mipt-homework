#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

void clean(Dynarray* pd)
{
    for (size_t i = 0; i < pd->size; ++i)
        pd->data[i] = 0;
}

void init(Dynarray* pd, size_t initial_size) 
{
    pd->size = initial_size;
    pd->capacity = initial_size;
    if (pd->size == 0)
        pd->data = NULL;
    else
        pd->data = (int*)ecmalloc(pd->capacity * sizeof(int));
    clean(pd);
}

void reserve(Dynarray* pd, size_t new_capacity)
{
    if (new_capacity <= pd->capacity)
        return;

    int* new_data = (int*)ecmalloc(new_capacity * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        new_data[i] = pd->data[i];
    }

    free(pd->data);
    pd->data = new_data;
    pd->capacity = new_capacity;
}


void push_back(Dynarray* pd, int x) 
{
    static const double growth_factor = 2;
    if (pd->size == pd->capacity) 
    {
        size_t new_capacity = (size_t)(growth_factor * pd->capacity);
        
        if (new_capacity <= pd->size)
            new_capacity = pd->size + 1;

        reserve(pd, new_capacity);
    }
    pd->data[pd->size] = x;
    pd->size += 1;
}


int get(const Dynarray* pd, size_t index) 
{
    assert(index < pd->size);
    return pd->data[index];
}


void set(Dynarray* pd, size_t index, int value) 
{
    assert(index < pd->size);
    pd->data[index] = value;
}


void print(const Dynarray* pd) 
{
    printf("dynarray: ");
    for (size_t i = 0; i < pd->size; ++i) 
        printf("%i ", pd->data[i]);

    printf("\n");
}


int pop_back(Dynarray* pd){
    int cur = pd->data[pd->size - 1];
    pd->size -= 1;
    return cur;
}

void resize(Dynarray* pd, size_t new_size){
    int growth_factor = 2;
    while (pd->capacity < new_size){
        reserve(pd, (size_t)(growth_factor * pd->capacity));
    }
    for (size_t i = pd->size; i < new_size; i++){
        pd->data[i] = 0;

    }
    pd->size = new_size;
}

void shrink_to_fit(Dynarray* pd){
    size_t new_capacity = pd->size;
    int* new_data = (int*)ecmalloc(new_capacity * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        new_data[i] = pd->data[i];
    }

    free(pd->data);
    pd->data = new_data;
    pd->capacity = new_capacity;
}

Dynarray shallow_copy(Dynarray* pd){
    Dynarray copy;
    copy.data = pd->data;
    copy.size = pd->size;
    copy.capacity = pd->capacity;
    return copy;
}

Dynarray deep_copy(Dynarray* pd){
    Dynarray copy;
    Dynarray* pcopy = &copy;
    init(pcopy, pd->size);
    reserve(pcopy, pd->capacity);
    for (size_t i = 0; i < pd->size; i++){
        pcopy->data[i] = pd->data[i];
    }
    return copy;
}


void destroy(Dynarray* pd) 
{
    free(pd->data);
    pd->data = NULL;
}

