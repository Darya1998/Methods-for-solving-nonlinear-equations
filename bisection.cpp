#include "bisection.h"

vector<double> search_bisec(vector<pair<double,double>> &area, double(*fn)(double)){
	vector<double> roots;
	double x;
for (int i = 0; i < area.size(); i ++){
		double delta = 1;
		double a = area[i].first;
		double b = area[i].second;
		int counter = 0;
		while(delta >= 2 * EPSILON){

			x = (a + b)/2;

			if(fn(x) == 0.0) break;

			else if ((fn(a) * fn(x)) <= 0){
				b = x;
			}

			else
				a =x;

			delta = fabs(b-a);
			counter++;
		}
		cout << "Кол-во итераций/Метод бисекций  =  " << counter << endl;
		x = (a + b)/2;
		roots.push_back(x);
	}
	
	return roots;
}








// for (int i = 0; i < area.size(); i ++){
// 		double delta = 1;
// 		double a = area[i].first;
// 		double b = area[i].second;
// 		while(delta >= 2 * EPSILON){
// 			x = (a + b)/2;
// 			if ((fn(a) * fn(x)) <= 0){
// 				b = x;
// 			}
// 			if ((fn(b) * fn(x)) <= 0){
// 				a = x;
// 			}
// 			delta = fabs(b-a);
// 		}
// 		x = (a + b)/2;
// 		roots.push_back(x);


// 	}