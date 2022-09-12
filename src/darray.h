#pragma once

typedef struct darray_s
{
    void **p;
    int size; //number of elements
    int alloc; //size of allocated memory
    void *(*fn_new)();
    void (*fn_free)(void *);
} darray;

void darray_new(darray *a, int size, void *(*fn_new)(), void (*fn_free)(void *));
void darray_free(darray *a);
void *darray_i(darray *a, int i);
void darray_i_del(darray *a, int i);
void *darray_end(darray *);
void darray_end_del(darray *a);
void darray_compact(darray *a);
void darray_alloc(darray *a, int n);