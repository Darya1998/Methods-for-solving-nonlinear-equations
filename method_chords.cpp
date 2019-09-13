#include "method_chords.h"


//Для одного уравнения
double chords_interval(double left, double right, double x, double(*fn)(double)){
	double a,b;
	if (fn(x) * fn(left) <= 0){
		a = left;
		b = x;
	}

	if(fn(x) * fn(right) <= 0){
		a = x;
		b = right;
	}

	double x_new = (fn(a) * b - fn(b)*a)/(fn(a) - fn(b));
    return x_new;
}

//Для системы
// pair<double> chords_system(vector<double>(*fn)(double,double), double a1,a2, pair<double> x){
// 	pair<double> x_new;
// 	vector<double> y = fn(x.first, x.second);
// 	if(a1 > x.first){
// 		x_new.first = x.first - (a1 - x.first) * y[0] /(fn(a1,x.second) - y[0]);

// 	}
	

// }
