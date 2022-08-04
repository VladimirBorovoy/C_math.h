#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_PL_INFINITY 1.0 / 0.0
#define S21_MIN_INFINITY -1.0/0.0

#define S21_NMAX 10000

#define S21_EPS 1e-9

#define EXP_D 1.00e-19

#define S21_PI 3.14159265359
#define EPSILON 0.000001

#define S21_NAN 0.0 / 0.0

#define S21_E 2.71828182845904523536

#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int s21_abs(int x);
long double s21_fabs(double x);

long double s21_pow(double base, double exp1);  //  мб для инта
long double s21_exp(double x);
long double s21_sqrt(double x);
long double s21_log(double x);

long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_cos(double x);

long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

#endif  // SRC_S21_MATH_H_
