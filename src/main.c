#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "darray.h"
#include "vec.h"
#include "random.h"

/*typedef struct dstr_s
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
}*/

void *v3_new()
{
    ivec3 *a = malloc(sizeof(ivec3));
    a->x = 1;
    a->y = 1;
    a->z = 1;
    return a;
}

void v3_free(void *a)
{
    free(a);
}

void print(darray *a)
{
    printf("print:\n");
    for(int i = 0; i < a->size; i++)
    {
        ivec3 *e = darray_i(a, i);
        printf("  %2d:  %2d, %2d, %2d\n", i, e->x, e->y, e->z);
    }
    
}


int main(int argc, const char **argv)
{
    rand_SEED(time(NULL));
    //printf("random: %d\n", time(NULL));
    printf("random f: %lf\n", rand_float(0.0, 5.0));
    printf("random c: %d\n", rand_chance(0.7));
    int a = 0;
    for(int i = 0; i < 10000; i++)
    {
        a += rand_chance(0.7);
    }
    printf("random 10000: %lf\n", (double)a/10000);

    darray tab;
    darray_new(&tab, 16, v3_new, v3_free);
    ivec3 *x = darray_i(&tab, 5);
    *x = ivec3_set(54, 16, 64);
    print(&tab);
    darray_i_del(&tab, 5);
    print(&tab);
    darray_free(&tab);

    

    return 0;
}