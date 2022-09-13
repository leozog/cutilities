#include "vec.h"
#include <math.h>

//ivec3
ivec3 ivec3_set(int x, int y, int z)
{
    ivec3 a;
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}

ivec3 ivec3_add(ivec3 a, ivec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

ivec3 ivec3_sub(ivec3 a, ivec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

ivec3 ivec3_mul(ivec3 a, double b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

double ivec3_len(ivec3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int ivec3_dot(ivec3 a, ivec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

ivec3 ivec3_cross(ivec3 a, ivec3 b)
{
    ivec3 c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}

fvec3 ivec3_float(ivec3 a)
{
    return fvec3_set((double)a.x, (double)a.y, (double)a.z);
}

//fvec3
fvec3 fvec3_set(double x, double y, double z)
{
    fvec3 a;
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}

fvec3 fvec3_add(fvec3 a, fvec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

fvec3 fvec3_sub(fvec3 a, fvec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

fvec3 fvec3_mul(fvec3 a, double b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

double fvec3_len(fvec3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double fvec3_dot(fvec3 a, fvec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

fvec3 fvec3_cross(fvec3 a, fvec3 b)
{
    fvec3 c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}

ivec3 fvec3_int(fvec3 a)
{
    return ivec3_set((int)a.x, (int)a.y, (int)a.z);
}