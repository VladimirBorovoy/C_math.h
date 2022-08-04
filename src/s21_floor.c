#include "s21_math.h"

long double s21_floor(double x) {
    long double res;
    if (x < 0 && x != (int)x) {
        res = (long double)((int)x - 1);
    } else {
        res = (long double)((int)x);
    }
    if (x != x)
        res = S21_NAN;
    if (x == 1.0/0.0)
        res = S21_PL_INFINITY;
    if (x == -1.0/0.0)
        res = S21_MIN_INFINITY;
    return res;
}
