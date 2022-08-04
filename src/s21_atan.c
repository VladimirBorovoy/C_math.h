#include "s21_math.h"

long double s21_atan(double x) {
    long double result = 0.0;
    if (x == 1.0) {
        result = 0.785398;
    } else if (x == -1.0) {
        result = -0.785398;
    } else if (x != x) {
        result = S21_NAN;
    } else if (x == 1.0/0.0) {
        result = S21_PI / 2;
    } else if (x == -1.0/0.0) {
        result = -S21_PI / 2;
    } else {
        if (s21_fabs(x) < 1) {
            for (int i = 0; i < S21_NMAX / 100; i++) {
                // if |x| < 1 taylor series: (-1)^i * x ^ (1 + 2 * i) / (1 + 2 * i)
                result += ((s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i));
            }
        } else if (s21_fabs(x) > 1) {
            long double temp_result = 0.0;
            for (int i = 0; i < S21_NMAX / 100; i++) {
                // if |x| > 1 taylor series: (-1)^i * x ^ (-1 - 2 * i) / (1 + 2 * i)
                temp_result += ((s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i));
            }
            result = (S21_PI * s21_sqrt(x*x)) / (2 * x) - temp_result;
            // if |x| > 1 then (PI * sqrt (x^2) / 2 * x) - temp_result
        }
    }
    return result;
}
