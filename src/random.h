#pragma once

void rand_SEED(int a);
int rand_int(int a, int b);
double rand_float(double a, double b);
int rand_chance(double a);
double perlin_get2d(double x, double y, int seed_offset, double freq, int depth);