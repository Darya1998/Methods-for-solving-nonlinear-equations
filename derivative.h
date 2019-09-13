#ifndef _DERIVATIVE_
#define _DERIVATIVE_

#include "includes.h"
vector<vector<double>> analytic_func4_jacoby(double x1, double x2);
vector<vector<double>> analytic_func5_jacoby(double x1, double x2);
vector<vector<double>> numeric_func_jacoby4(double x1, double x2);
vector<vector<double>> numeric_func_jacoby5(double x1, double x2);
double analytic_func1(double x);
double analytic_func2(double x);
double analytic_func3(double x);
double analytic_func_sqr(double x);
double analytic_func_cube(double x);
double numeric_func1(double x);
double numeric_func2(double x);
double numeric_func3(double x);
#endif