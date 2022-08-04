#include "s21_math.h"

long double s21_cos(double x) {
    if (x > 0 && x > 2*S21_PI) {
        double temp = x / (2 * S21_PI);
        x = x - (int)temp * 2 * S21_PI;
    } else if (x < 0 && x < -2* S21_PI) {
        double temp = x / (2 * S21_PI);
        x = x - (int)temp * 2 * S21_PI;
    }
    double t = 1.0, sum = 1.0;
    int p = 0;
    while (s21_fabs(t/sum) > S21_EPS) {
        p++;
        t = (-t * x * x) / ((2 * p - 1) * (2 * p));
        sum += t;
    }
    if (x == 1.0/0.0) sum = S21_NAN;
    if (x == -1.0/0.0) sum = S21_NAN;
    return sum;
}
