#pragma once

typedef struct ivec3_s
{
    int x, y, z;
} ivec3;

typedef struct fvec3_s
{
    double x, y, z;
} fvec3;

//ivec3
ivec3 ivec3_set(int x, int y, int z);
ivec3 ivec3_add(ivec3 a, ivec3 b);
ivec3 ivec3_sub(ivec3 a, ivec3 b);
ivec3 ivec3_mul(ivec3 a, double b);
double ivec3_len(ivec3 a);
int ivec3_dot(ivec3 a, ivec3 b);
ivec3 ivec3_cross(ivec3 a, ivec3 b);
fvec3 ivec3_float(ivec3 a);

//fvec3
fvec3 fvec3_set(double x, double y, double z);
fvec3 fvec3_add(fvec3 a, fvec3 b);
fvec3 fvec3_sub(fvec3 a, fvec3 b);
fvec3 fvec3_mul(fvec3 a, double b);
double fvec3_len(fvec3 a);
double fvec3_dot(fvec3 a, fvec3 b);
fvec3 fvec3_cross(fvec3 a, fvec3 b);
ivec3 fvec3_int(fvec3 a);