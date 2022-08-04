#include "s21_math.h"

long double s21_acos(double x) {
    x = S21_PI / 2 - s21_asin(x);
    return x;
}
