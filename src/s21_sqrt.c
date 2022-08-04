#include "s21_math.h"

long double s21_sqrt(double x) {
    long double mid;
    if (x != x) {
        mid = S21_NAN;
    } else if (x == S21_PL_INFINITY) {
        mid = S21_PL_INFINITY;
    } else if (x < 0.0) {
        mid = S21_NAN;
    } else {
        long double left = 0.0;
        long double right;
        if (x > 1.0) {
            right = x;
        } else {
            right = 1.0;
        }
        mid = (left + right) / 2;
        while ((mid - left) > S21_EPS) {
            if (mid * mid > x) {
                right = mid;
            } else {
                left = mid;
            }
            mid = (left + right) / 2;
        }
    }
    return mid;
}
