#ifndef _METHOD_NEWTON_
#define _METHOD_NEWTON_

#include "includes.h"
vector<double> product(vector<vector<double>> &jacoby_matrix, vector<double> &y);
double random(double min, double max);
pair<double,double> newton(pair<double,double> x, vector<double>(*fn)(double,double), vector<vector<double>>(*fn_jacoby)(double,double), int &counter, double limit);
double det(vector<vector<double>>matrix);
vector<double> newton_equation(vector<pair<double, double>> &area, double(*fn)(double), double (*derivative_y)(double));
#endif