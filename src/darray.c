#include "darray.h"
#include <stdlib.h>

void darray_new(darray *a, int n, void *(*fn_new)(), void (*fn_free)(void *))
{
    a->p = malloc(n * sizeof(void *));
    if(!(a->p)) exit(-1);
    a->size = 0;
    a->alloc = n;
    a->fn_new = fn_new;
    a->fn_free = fn_free;
    for(void **i = a->p; i < a->p + a->alloc; i++)
        *i = NULL;
}

void darray_free(darray *a)
{
    for(void **i = a->p; i < a->p + a->size; i++)
        if(*i != NULL) a->fn_free(i);
    free(a->p);
    a = NULL;
}

void *darray_i(darray *a, int i)
{
    if(i >= a->alloc) exit(-1);
    if(a->p[i] == NULL) a->p[i] = a->fn_new();
    if(i > a->size - 1) a->size = i + 1;
    return a->p[i];
}

void darray_i_del(darray *a, int i)
{
    if(i >= a->alloc) exit(-1);
    if(a->p[i] == NULL) return;
    a->fn_free(a->p[i]);
    a->p[i] = NULL;
    if(i != a->size - 1) return;
    for(void **x = a->p + i - 1; x >= a->p; x--)
    {
        a->size--;
        if(*x != NULL) return;
    }
}

void *darray_end(darray *a)
{
    if(a->size == a->alloc)
    {
        a->p = (void **)realloc(a->p, a->alloc * 2);
        if(!(a->p)) exit(-1);
        a->alloc *= 2;
        for(void **i = a->p + a->size; i < a->p + a->alloc; i++)
            *i = NULL;
    }
    return a->p[a->size++];
}

void darray_end_del(darray *a)
{
    darray_i_del(a, a->size - 1);
}

void darray_compact(darray *a)
{
    if(a->size == a->alloc) return;
    a->p = (void **)realloc(a->p, a->size);
    a->alloc = a->size;
}

void darray_alloc(darray *a, int n)
{
    if(n <= a->size) return;
    if(n < a->alloc)
    {
        for(void **i = a->p + n; i < a->p + a->alloc; i++)
            if(*i != NULL) a->fn_free(i);
    }
    a->p = (void **)realloc(a->p, n);
    if(!(a->p)) exit(-1);
    for(void **i = a->p + a->alloc; i < a->p + n; i++)
        *i = NULL;
    a->alloc = n;
}