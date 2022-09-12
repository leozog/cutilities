#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "darray.h"

typedef struct dstr_s
{
    char *p;
    int len;
} dstr;

void *dstr_new()
{
    dstr *o = malloc(sizeof(dstr));
    o->p = malloc(256 * sizeof(char));
    if(!(o->p)) exit(-1);
    o->len = 256;
    return o;
}

void dstr_free(void *a)
{
    free(((dstr *)a)->p);
    free((dstr *)a);
}

int main(int argc, const char **argv)
{
    darray tab;
    darray_new(&tab, 100, dstr_new, dstr_free);
    dstr *x = darray_i(&tab, 5);
    dstr *y = darray_i(&tab, 0);
    strcpy(x->p, "testy");
    strcpy(y->p, "abc");
    printf("s: %d, %s\n", tab.size, x->p);
    darray_i_del(&tab, 5);
    printf("s: %d, %s\n", tab.size, y->p);
    darray_i_del(&tab, 5);

    darray_free(&tab);

    return 0;
}