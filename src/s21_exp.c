#include "s21_math.h"

long double s21_exp(double x) {
    long double result = 1.0;
    int flag = 0;
    if (x == S21_MIN_INFINITY) {
        result = 0.0;
    } else {
        if (x < 0.0) {
            x = -x;
            flag = 1;
        }
        long double k = 1.0, t = 1.0;
        while (s21_fabs(t) > 1e-12) {
            t = (t * x) / k;
            result = result + t;
            if (result >= DBL_MAX) {
                result = S21_PL_INFINITY;
                break;
            }
            k += 1;
        }
        if (flag) {
        if (result > DBL_MAX)
            result = 0;
        else
            result = 1. / result;
        }
    }
    return result;
}
