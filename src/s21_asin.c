#include "s21_math.h"

long double s21_asin(double x) {
    long double y = (long double)x;
    if (y >= - 1.0 && y <= 1.0) {
        x = (long double) s21_fabs(x);
        long double mn = (long double)x;
        long double  asin = (long double)x;
        if (x < 1) {
            for (long double i = 1.0; mn > S21_EPS / 10000; i++) {
                // taylor series: (2 * i - 1) ^ 2 * x ^ 2 / (2 * i * (2 * i + 1))
                mn *= (((2 * i - 1) * x * (2 * i - 1) * x) / ((2 * (2 * i + 1) * i)));
                asin += mn;
            }
        }
        if (y > 0 && y < 1)
            y = asin;
        if (y < 0 && y > - 1)
           y = - asin;
        if (y == 1.0)
            y = S21_PI / 2;
        if (y == - 1.0)
            y = - S21_PI / 2;
    } else {
        y = S21_NAN;
    }
    return y;
}
