#include "includes.h"
#include "func.h"
#include "localize.h"
#include "bisection.h"
#include "derivative.h"
#include "method_newton.h"
#include "method_chords.h"
int main() {
		
	Function f1;
	f1.f = func3;
	//f1.f = func_new_sqr;
	//f1.f = func_new_cube;
	f1.limits = make_pair(0, 1);//границы
	f1.table_init = f1.f(f1.div_count, mass_x(f1.div_count, f1.limits), f1.table_init);
	cout << "--------------------------------Разбили на отрезки--------------" << endl;
	for (const auto &v:f1.table_init){
		cout << v.first << "   "<< v.second << endl;
	}
	cout << "---------------------Локализовали корни---------------------------------" << endl;
	//найдем отрезки локализации
	//double (*fn)(double) = function_new_cube;
	//double (*fn)(double) = function_new_sqr;
	double (*fn)(double) = function3;
	vector<double> sol;//вектор, содержащий корнеь
	vector<pair<double,double>> area = Local(f1.table_init, fn, sol);
	if (area.size() == 0){
		cout << "На всей области определения функция >= 0" << endl;
		area.push_back(f1.limits);
	}

	else{
		for (const auto &v:area){
			cout << v.first << "   "<< v.second << endl;
		}
	}


	//найдем корни
	cout << "---------------------Корни уравнения---------------------------------" << endl;
	vector<double> roots = search_bisec(area, fn);
	for (const auto &n : roots){
		cout << n << "  ";
	}
	cout << endl;

	cout << "Погрешность  = " << fabs(1 - roots[0]) << endl;

	cout << "----------------------Решение уравнения методом Ньютона-----------------------" << endl;
	//double (*f_derivative)(double) = analytic_func_cube;
	//double (*f_derivative)(double) = analytic_func_sqr;
	double (*f_derivative)(double) = analytic_func3;

	area[0].first = 0;
	area[0].second = 1;
	vector<double> solution = newton_equation(area,fn, f_derivative);
	for (const auto &n : solution){
			cout << n << "  ";
		}
	cout << endl;

	cout << "Погрешность  = " << fabs(1 - solution[0]) << endl;



	cout << "-----------------------Решение систем---------------------------------" << endl;
	vector<double> (*func_system)(double, double) = function4;
	vector<vector<double>>(*func_jacoby)(double,double) = numeric_func_jacoby4;
	pair<double, double> point;
	//Выбераем рандомную точку из заданной области
	double limit = 10;
	point.first = random(-limit,limit);
	point.second = random(-limit,limit);

	point.first = 3;
	point.second = 0;

	cout<< "Начальная точка =  " << point.first << "  " << point.second << endl;
	int i = 0;
	pair<double, double> system_sol = newton(point, func_system, func_jacoby,i, limit);
	cout << "Кол-во итераций =  " << i << endl;
	cout << left << setw(15) << setprecision(6) << fixed << system_sol.first << "  " << left << setw(40) << setprecision(40) << fixed <<system_sol.second << endl;
	cout << "--------------------------------Невязка---------------------------------------"<< endl;
	double nevyazka = discrepancy_function4(system_sol);
	cout << nevyazka << endl;
	cout << "-------------------------------Погрешность-------------------------------------" << endl;
	double error = error_4_1(system_sol);
	cout << error << endl;


	//Сетка
	// double L1 = 10;
	// double L2 = 10;
	// int N = 21;//число ячеек секти
	// double h = 1;//шаг
	// vector<vector<pair<double,double>>> mesh(N, vector<pair<double,double>>(N));
	// // for (int i = 0; i < N; i ++){
	// // 	for (int j = 0; j < N; j ++){
	// // 		mesh[N-1 - i][j].first = -L1 + j * h;
	// // 		mesh[N - 1- i][j].second = -L2 + i * h;
	// // 	}
	// // }
	// for (int i = 0; i < N; i ++){
	// 	for (int j = 0; j < N; j ++){
	// 		mesh[i][j].first = -L1 + j * h;
	// 		mesh[i][j].second = -L2 + i * h;
	// 	}
	// }

	// //Матрица кол-ва итераций
	// vector<vector<int>> matrix_iter(N, vector<int>(N));
	// for (int i = 0; i < N; i++){
	// 	for (int j = 0; j < N; j++){
	// 		point.first = mesh[i][j].first;
	// 		point.second = mesh[i][j].second;
	// 		cout<< "Начальная точка =  " << point.first << "  " << point.second << endl;
	// 		int counter = 0;// Счетчик кол-ва итераций
	// 		pair<double, double> system_sol = newton(point, func_system, func_jacoby, counter, limit);
	// 		cout << "Решение"<< system_sol.first << "  " << system_sol.second << endl;
	// 		matrix_iter[i][j] = counter;
	// 	}
	// }

	// //Записываем в файл кол-во итераций
	// string name = "matr.dat";
	// ofstream fout(name);
	// for (int i = 0; i < N; i ++){
	// 	for (int j = 0; j < N; j++){
	// 		fout << matrix_iter[i][j] << "\t" ;
	// 	}

	// 	fout << endl;
		
	// }
	// fout.close();

	// //Записываем в файл координатную сетку
	// name = "coord.dat";
	// ofstream fout_coord(name);
	// for (int i = 0; i < N; i ++){
	// 	for (int j = 0; j < N; j++){
	// 		fout_coord << mesh[i][j].first << "  " << mesh[i][j].second << "\t" ;
	// 	}

	// 	fout_coord << endl;
		
	// }
	// fout_coord.close();



	return 0;
}