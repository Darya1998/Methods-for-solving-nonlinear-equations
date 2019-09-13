#include "func.h"


//Массив x 
vector<double> mass_x(int n, pair<double,double> limits){
	vector<double> x(n);
	double h = fabs(limits.second- limits.first)/(n - 1);
	for (int i = 0; i < (n - 1); i ++){
		x[i] = limits.first + h * i;
	}

	x[n - 1] = limits.second;
	return x;
}


vector<pair<double,double>> func1(int div_count, vector<double> x, vector<pair<double,double>> &table){
	table.resize(div_count);
	for (int i = 0; i < x.size(); i++){
		table[i].first = x[i];
		table[i].second = (x[i] - 0.1) * (x[i] - 0.22) * (x[i] - 0.55) * (x[i] - 0.7) * (x[i] - 0.75);
	}

	return table;
}

vector<pair<double,double>> func2(int div_count, vector<double> x, vector<pair<double,double>> &table){
	table.resize(div_count);
	for (int i = 0; i < x.size(); i++){
		table[i].first = x[i];
		table[i].second = sqrt(x[i] + 1) - 1;
	}
	
	return table;
}

vector<pair<double,double>> func3(int div_count, vector<double> x, vector<pair<double,double>> &table){
	table.resize(div_count);
	for (int i = 0; i < x.size(); i++){
		table[i].first = x[i];
		table[i].second = 35 * pow(x[i],3) - 67 * pow(x[i],2) - 3 * x[i] + 3;
	}
	
	return table;
}

vector<pair<double,double>> func_new_sqr(int div_count, vector<double> x, vector<pair<double,double>> &table){
	table.resize(div_count);
	for (int i = 0; i < x.size(); i++){
		table[i].first = x[i];
		table[i].second = pow(x[i] - 1,2);
	}
	
	return table;
}

vector<pair<double,double>> func_new_cube(int div_count, vector<double> x, vector<pair<double,double>> &table){
	table.resize(div_count);
	for (int i = 0; i < x.size(); i++){
		table[i].first = x[i];
		table[i].second = pow(x[i] - 1,3);
	}
	
	return table;
}

//--------------------------------------------------------------------------------------------

double function1(double x){

	double y = (x - 0.1) * (x- 0.22) * (x - 0.55) * (x - 0.7) * (x - 0.75);

return y;
}

double function2(double x){

	double y = sqrt(x + 1) - 1;

	
	return y;
}

double function3(double x){

	double y = 35 * pow(x,3) - 67 * pow(x,2) - 3 * x + 3;

	
	return y;
}

double function_new_sqr(double x){
	double y = pow( x - 1, 2);
	return y;
}

double function_new_cube(double x){
	double y = pow(x - 1, 3);
	return y;
}
//----------------------------СИСТЕМЫ--------------------------------------------------------------------------
vector<double> function4(double x1, double x2){
	double y1 = pow(x1,2) - pow(x2,2) - 15;
	double y2 = x1 * x2 + 4;
	vector<double> znach;
	znach.push_back(y1);
	znach.push_back(y2);
	return znach;
}

vector<double> function5 (double x1, double x2){
	double y1 = pow(x1,2) + pow(x2,2) +x1 + x2 -8;
	double y2 = pow(x1,2) + pow(x2,2) +x1 * x2 -7;
	vector<double> znach;
	znach.push_back(y1);
	znach.push_back(y2);
	return znach;
}
//----------------------------------------------------------------------------------------------------------
//Невязка
double discrepancy_function4(pair<double, double> system_sol){
	double a = fabs(15 - (pow(system_sol.first,2)- pow(system_sol.second,2)));
	double b = fabs(- 4- (system_sol.first * system_sol.second));
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;

}

double discrepancy_function5(pair<double, double> system_sol){
	double a = fabs(8 - (pow(system_sol.first,2) + pow(system_sol.second,2) + system_sol.first + system_sol.second));
	double b = fabs(7 - (pow(system_sol.first,2) + pow(system_sol.second,2) + system_sol.first * system_sol.second));
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;

}


//Погрешность
double error_4_1(pair<double, double> system_sol){
	double a = fabs(4 - system_sol.first);
	double b = fabs(-1 - system_sol.second);
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;
}

double error_4_2(pair<double, double> system_sol){
	double a = fabs(-4 - system_sol.first);
	double b = fabs(1 - system_sol.second);
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;
}

double error_5_1(pair<double, double> system_sol){
	double a = fabs(-3 - system_sol.first);
	double b = fabs(1 - system_sol.second);
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;
}

double error_5_2(pair<double, double> system_sol){
	double a = fabs(1 - system_sol.first);
	double b = fabs(-3 - system_sol.second);
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;
}

double error_5_3(pair<double, double> system_sol){
	double a = fabs(1 - system_sol.first);
	double b = fabs(2 - system_sol.second);
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;
}

double error_5_4(pair<double, double> system_sol){
	double a = fabs(2 - system_sol.first);
	double b = fabs(1 - system_sol.second);
	double max;
	if (a > b){
		max = a;
	}
	else{
		max = b;

	}
	return max;
}