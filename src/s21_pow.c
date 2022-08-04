#include "s21_math.h"

long double s21_pow(double base, double exp) {
    long double res;
    if (exp == S21_MIN_INFINITY && base == S21_MIN_INFINITY) {
        res = 0.0;
    } else if (exp == S21_PL_INFINITY && (base == S21_PL_INFINITY || base == S21_MIN_INFINITY)) {
        res = S21_PL_INFINITY;
    } else if (base == S21_PL_INFINITY && exp == S21_PL_INFINITY) {
        res = S21_PL_INFINITY;
    } else if ((base == 0.0 && exp == 0.0) || (base != 0.0 && exp == 0.0)) {
        res = 1;
    } else if (exp < 0.0 && base == 0.0) {
        res = S21_PL_INFINITY;
    } else if (base == S21_MIN_INFINITY && exp < 0.0 && s21_fabs(exp - (int)exp) > 0.0) {
        res = 0.0;
    } else if (base == S21_MIN_INFINITY && exp > 0 && exp - (int)exp > 0.0) {
        res = S21_PL_INFINITY;
    } else if (base < 0.0 && s21_fabs((exp - (int)exp)) > 0.0) {
        res = S21_NAN;
    } else {
        if (base - (int)base == 0.0 && exp - (int)exp == 0.0 && exp > 0) {
            res = 1.0;
            for (int i = 0; i < exp; i++) {
                res *= base;
            }
        } else {
            if (base < 0.0) {
                base = -base;
                res = s21_exp(exp * s21_log(base));
                if (s21_fmod(exp, 2) != 0) {
                    res = -res;
                }
            } else {
                res = s21_exp(exp * s21_log(base));
            }
        }
    }
    return res;
}
