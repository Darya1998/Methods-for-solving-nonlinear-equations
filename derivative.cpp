#include "derivative.h"
#include "func.h"
#include "method_newton.h"

vector<vector<double>> analytic_func4_jacoby(double x1, double x2){
	vector<vector<double>> jacoby_matrix(2, vector<double>(2));
	jacoby_matrix[0][0] = 2 * x1;
	jacoby_matrix[0][1] = -2 * x2;
	jacoby_matrix[1][0] = x2;
	jacoby_matrix[1][1] = x1;

	//Сразу найдем обратную
	double det_matr = det(jacoby_matrix);
	jacoby_matrix[0][0] = (x1)/det_matr;
	jacoby_matrix[0][1] = -(-2 * x2)/det_matr;
	jacoby_matrix[1][0] = -(x2)/det_matr;
	jacoby_matrix[1][1] = (2 * x1)/det_matr;

	return jacoby_matrix;

}

vector<vector<double>> analytic_func5_jacoby(double x1, double x2){
	vector<vector<double>> jacoby_matrix(2, vector<double>(2));
	jacoby_matrix[0][0] = 2 * x1 + 1;
	jacoby_matrix[0][1] = 2 * x2 + 1;
	jacoby_matrix[1][0] = 2 * x1 + x2;
	jacoby_matrix[1][1] = 2 * x2 + x1;

	//Сразу найдем обратную
	double det_matr = det(jacoby_matrix);
	jacoby_matrix[0][0] = (2 * x2 + x1)/det_matr;
	jacoby_matrix[0][1] = -(2 * x2 + 1)/det_matr;
	jacoby_matrix[1][0] = -(2 * x1 + x2)/det_matr;
	jacoby_matrix[1][1] = (2 * x1 + 1)/det_matr;

	return jacoby_matrix;
}

vector<vector<double>> numeric_func_jacoby4(double x1, double x2){
	vector<vector<double>> jacoby_matrix(2, vector<double>(2));
	double a = 1e-8;
	vector<double> f_x(2); 
	vector<double> f_y(2);
	for (int i = 0; i < 2; i ++){
		f_x[i]= (function4(x1 + a, x2)[i] - function4(x1, x2)[i]);
		f_y[i] = (function4(x1, x2 + a)[i] - function4(x1, x2)[i]);
	}
	jacoby_matrix[0][0] = f_x[0]/a;
	jacoby_matrix[0][1] = f_y[0]/a;
	jacoby_matrix[1][0] = f_x[1]/a;
	jacoby_matrix[1][1] = f_y[1]/a;

	//Сразу найдем обратную матрицу
	double det_matr = det(jacoby_matrix);
	jacoby_matrix[0][0] = f_y[1]/(a*det_matr);
	jacoby_matrix[1][0] = -f_y[0]/(a*det_matr);
	jacoby_matrix[0][1] = -f_x[1]/(a*det_matr);
	jacoby_matrix[1][1] = f_x[0]/(a*det_matr);

	return jacoby_matrix;
}

vector<vector<double>> numeric_func_jacoby5(double x1, double x2){
	vector<vector<double>> jacoby_matrix(2, vector<double>(2));
	double a = 1e-8;
	vector<double> f_x(2); 
	vector<double> f_y(2);
	for (int i = 0; i < 2; i ++){
		f_x[i]= (function5(x1 + a, x2)[i] - function5(x1, x2)[i]);
		f_y[i] = (function5(x1, x2 + a)[i] - function5(x1, x2)[i]);
	}
	jacoby_matrix[0][0] = f_x[0]/a;
	jacoby_matrix[0][1] = f_y[0]/a;
	jacoby_matrix[1][0] = f_x[1]/a;
	jacoby_matrix[1][1] = f_y[1]/a;

	//Сразу найдем обратную матрицу
	double det_matr = det(jacoby_matrix);
	jacoby_matrix[0][0] = f_y[1]/(a*det_matr);
	jacoby_matrix[0][1] = -f_y[0]/(a*det_matr);
	jacoby_matrix[1][0] = -f_x[1]/(a*det_matr);
	jacoby_matrix[1][1] = f_x[0]/(a*det_matr);

	return jacoby_matrix;
}









//----------------------------------------------------------------------------------------------------------
double analytic_func1(double x){
	double y = 0.121495 - 1.5119 * x + 5.9535 * pow(x,2) - 9.28 * pow(x,3) + 5 * pow(x,4);
    return y;
}

double analytic_func2(double x){
	double y = 1/(2 * sqrt(1 + x));
	return y;
}

double analytic_func3(double x){
	double y =-3 - 134 * x + 105 * pow(x,2);
	return y;
}

double analytic_func_sqr(double x){
	double y = 2 * (x - 1);
	return y;
}

double analytic_func_cube(double x){
	double y = 3 * pow(x - 1,2);
	return y;
}

double numeric_func1(double x){
	double a = 1e-8;
	double y = (function1(x + a) - function1(x))/a;
	return y;
}

double numeric_func2(double x){
	double a = 1e-8;
	double y = (function2(x + a) - function2(x))/a;
	return y;
}

double numeric_func3(double x){
	double a = 1e-8;
	double y = (function3(x + a) - function3(x))/a;
	return y;
}