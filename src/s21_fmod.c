#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double res;
    if (x < S21_PL_INFINITY && x > S21_MIN_INFINITY) {
        if ((x == 0.0 && y == 0.0) || y == 0.0) {
            res = S21_NAN;
        } else if (y == S21_PL_INFINITY || y == S21_MIN_INFINITY) {
            res = x;
        } else {
            res = x - ((int)(x / y)) * y;
        }
    } else {
        res = S21_NAN;
    }
    return res;
}
