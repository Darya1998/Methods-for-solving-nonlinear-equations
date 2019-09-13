#ifndef _FUNC_
#define _FUNC_


#include "includes.h"

struct Function{
	Function(){};
	vector<pair<double,double>> (*f)(int n, vector<double> x, vector<pair<double,double>> &table_init) = nullptr;
	pair<double,double> limits;
	int div_count = 21;
	vector<pair<double,double>> table_init;
};


vector<double> mass_x(int n, pair<double,double> limits);
vector<pair<double,double>> func1(int div_count, vector<double> x, vector<pair<double,double>> &table);
vector<pair<double,double>> func2(int div_count, vector<double> x, vector<pair<double,double>> &table);
vector<pair<double,double>> func3(int div_count, vector<double> x, vector<pair<double,double>> &table);
vector<pair<double,double>> func_new_sqr(int div_count, vector<double> x, vector<pair<double,double>> &table);
vector<pair<double,double>> func_new_cube(int div_count, vector<double> x, vector<pair<double,double>> &table);
double function1(double x);
double function2(double x);
double function3(double x);
double function_new_sqr(double x);
double function_new_cube(double x);
vector<double> function4(double  x1, double x2);
vector<double> function5(double x1, double x2);
double discrepancy_function4(pair<double, double> system_sol);
double discrepancy_function5(pair<double, double> system_sol);

//Погрешность
double error_4_1(pair<double, double> system_sol);
double error_4_2(pair<double, double> system_sol);
double error_5_1(pair<double, double> system_sol);
double error_5_2(pair<double, double> system_sol);
double error_5_3(pair<double, double> system_sol);
double error_5_4(pair<double, double> system_sol);

#endif