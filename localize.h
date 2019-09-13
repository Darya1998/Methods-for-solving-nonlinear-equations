#ifndef _LOCALIZE_
#define _LOCALIZE_
#include "includes.h"
#include "func.h"


vector<pair<double,double>> Local(vector<pair<double,double>>table, double(*fn)(double), vector<double> &sol);
#endif