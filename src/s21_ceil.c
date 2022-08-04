#include "s21_math.h"

long double s21_ceil(double x) {
    long double res;
    if (x < 0) {
        res =  (long double)((int)x);
    } else {
        res = (long double)(x + 1 - ((x == (int)x) ? 1 : x - (int)x));
    }
    if (x != x)
        res = S21_NAN;
    if (x == 1.0/0.0)
        res = S21_PL_INFINITY;
    if (x == -1.0/0.0)
        res = S21_MIN_INFINITY;
    return res;
}
