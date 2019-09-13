#include "method_newton.h"
#include "method_chords.h"

vector<double> product(vector<vector<double>> &jacoby_matrix, vector<double> &y){
	vector<double> product_y(jacoby_matrix.size());
	for (int i = 0; i < jacoby_matrix.size(); i++){
		for (int j = 0; j < jacoby_matrix.size(); j++){
			product_y[i] += y[j] * jacoby_matrix[i][j];

		}

	}
	return product_y;
}


double random(double min, double max)
{
    return (double)(rand())/RAND_MAX*(max - min) + min;
}
double det(vector<vector<double>>matrix){
	double det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return det;
}
// //Выбор точки
// double choice_point_x(vector<double>(*fn)(double,double), double x, double y){
// 	double a1 = 10;
// 	vector<double> y1 = fn(x,y);
// 	vector<double> y2 = fn(a1,y);
// 	while(y1 * y2 >= 0){
// 		a1 -= 1;
// 		y2 = fn(a1,y);
// 	}
// 	return a1;

// }

// double choice_point_y(vector<double>(*fn)(double,double), double x, double y){
// 	double a2 = 10;
// 	vector<double> y1 = fn(x,y);
// 	vector<double> y2 = fn(x,a2);
// 	while(y1 * y2 >= 0){
// 		a2 -= 1;
// 		y2 = fn(x,a2);
// 	}
// 	return a2;

// }

pair<double,double> newton(pair<double,double> x, vector<double>(*fn)(double,double), vector<vector<double>>(*fn_jacoby)(double,double), int &counter, double limit){
	double delta = 1;
	pair<double,double> x_new;
	vector<vector<double>> jacoby_matrix(2,vector<double>(2));
	while (delta >= EPSILON){
		vector<double> f_vector = fn(x.first, x.second);//значение функции в текущей точке
		jacoby_matrix = fn_jacoby(x.first, x.second);//значение матрицы якоби в текущей точке
		double det_jacobian = det(jacoby_matrix);
		if(det_jacobian != det_jacobian) counter = 30;
		vector<double> vector_y_product = product(jacoby_matrix, f_vector);
		//находим новое приближение
		x_new.first = x.first - vector_y_product[0];
		x_new.second = x.second - vector_y_product[1];
		// cout << "x new =  " << x_new.first << "\t" << "y new =  " << x_new.second << endl;
		//Если вышло за пределы области локализации
		if(fabs(x_new.first) > limit){
			if (x_new.first < 0){
				x_new.first = -limit;
			}
			else{
				x_new.first = limit;
			}

		}
		if(fabs(x_new.second) > limit){
			if (x_new.second < 0){
				x_new.second = -limit;
			}
			else{
				x_new.second = limit;
			}

		}

		// cout << "x newest =  " << x_new.first << "\t" << "y newest =  " << x_new.second << endl;
		delta = sqrt(pow(x_new.first - x.first,2) + pow(x_new.second - x.second,2));//разность приближений
		//присваиваем текцщей точке найденное значение
		x.first = x_new.first;
		x.second = x_new.second ;
		counter++;
		if (counter >= 30)break;

	}
	
	return x;
}

vector<double> newton_equation(vector<pair<double, double>> &area, double(*fn)(double), double (*derivative_y)(double)){
	vector<double> x_sol;
	for (int i = 0; i < area.size(); i ++){
		double delta = 1;
		double a = area[i].first;
		double b = area[i].second;

		double x = random(a,b);
		//double x = (fn(a) * b - fn(b)*a)/(fn(a) - fn(b)); //Нашли начальное приближение методом хорд.
		x = 0;
		cout << "Начальное приближение = " << x << endl;
		double x_new;
		//Специально даем неточное приближение
		int counter = 0;
		double delta1;
		while(delta >= EPSILON){
			double y = fn(x);
			double derivat = derivative_y(x);
			x_new = x - y/derivat;
			//cout << "Новое приближение =  " << x_new << endl;
			//Если приближение вышло за пределы отрезка локализации
			// if (x_new < a || x_new > b){
			// 	x_new = chords_interval(a,b,x, fn);
			// }
			if (fabs(fabs(x) - fabs(x_new)) == delta1){
				cout << "Bad init pointer" << endl;
				x_new = chords_interval(a,b,x, fn);
			}
			delta1 = fabs(fabs(x) - fabs(x_new));

			delta = fabs(x - x_new);
			x = x_new;
			counter ++;
		}
		cout << "Кол-во итераций/Метод Ньютона =  " << counter << endl;
		x_sol.push_back(x);
	}

	return x_sol;

}