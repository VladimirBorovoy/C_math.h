#include "s21_math.h"

long double s21_log(double x) {
    double res = 0.0;
    int k = 0;
    if (x == 0) {
        res = S21_MIN_INFINITY;
    } else if (x == S21_PL_INFINITY) {
        res = S21_PL_INFINITY;
    } else if (x < 0) {
        res = S21_NAN;
    } else {
        for (; x >= S21_E; x /= S21_E, k++)
            continue;

        for (int i = 0; i < 200; i++) {
            double tmp = res;
            res = tmp + 2 * (x - s21_exp(tmp)) / (x + s21_exp(tmp));
        }
    }
    return (res+k);
}
