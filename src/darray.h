#pragma once
#include <stdlib.h>

void darray_new(darray *a, int size, void *(*fn_new)(), void (*fn_free)(void *));
void darray_free(darray *a);
void darray_add_end(darray *a, void *e);
#define darray_i(a, i) (a->p[i])
void darray_compact(darray *a);
void darray_alloc(darray *a, int n);

typedef struct darray_s
{
    void **p;
    int size; //number of elements
    int alloc; //size of allocated memory
    void *(*fn_new)();
    void (*fn_free)(void *);
} darray;

void darray_new(darray *a, int size, void *(*fn_new)(), void (*fn_free)(void *))
{
    *(a->p) = malloc(size * sizeof(void *));
    if(!*(a->p)) exit(-1);
    a->size = size;
    a->alloc = size;
    a->fn_new = fn_new;
    a->fn_free = fn_free;
    for(void **i = a->p; i < a->p + a->size; i++)
        *i = a->fn_new();
}

void darray_free(darray *a)
{
    for(void **i = a->p; i < a->p + a->alloc; i++)
        a->fn_free(i);
    free(a->p);
    a = NULL;
}

void darray_add_end(darray *a, void *e)
{
    if(a->size == a->alloc)
    {
        a->p = (void **)realloc(a->p, a->alloc * 2);
        if(!*(a->p)) exit(-1);
        a->alloc *= 2;
        for(void **i = a->p + a->size; i < a->p + a->alloc; i++)
            *i = a->fn_new();
    }
    darray_i(a, a->size) = e;
    a->size++;
}