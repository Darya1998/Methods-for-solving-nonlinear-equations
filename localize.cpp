#include "localize.h"

// vector<pair<double,double>> Local(vector<pair<double,double>>table, double(*fn)(double), vector<double> &sol){
// 	//ОБрабатываем случай, когда на концах отрезка значение функции = 0
// 	if (fabs(table[0].second) == 0.0000000){
// 		sol.push_back(table[0].first);
// 		table[0].first = table[0].first + 10 * EPSILON;
// 		table[0].second = fn(table[0].first);
// 	}

// 	int n = table.size()-1;
// 	if (fabs(table[n].second) == 0.0000000){
// 		sol.push_back(table[n].first);
// 		table[n].first = table[n].first - 10 * EPSILON;
//  		table[n].second = fn(table[n].first);
// 	}
	
// 	//Если нашелся корень
// 	for (int i = 1; i < n; i++){
// 		if(fabs(table[i].second) == 0.0000000){
// 			sol.push_back(table[i].first);
// 		}
// 	}

// 	vector<pair<double,double>> local_area;

// 	//поиск отрезков локализации
// 	for (int i = 0; i < n; i ++){
// 		if(table[i].second * table[i+1].second <= 0){
// 			pair<double,double> limits = make_pair(table[i].first, table[i+1].first);
// 			local_area.push_back(limits);
// 		}
// 	}


// 	return local_area;
// }



vector<pair<double,double>> Local(vector<pair<double,double>>table, double(*fn)(double), vector<double> &sol){
	//ОБрабатываем случай, когда на концах отрезка значение функции = 0
	if (fabs(table[0].second) < EPSILON){
		table[0].first = table[0].first - 10 * EPSILON;
		table[0].second = fn(table[0].first);

	}
	int n = table.size()-1;
	if (fabs(table[n].second) < EPSILON){
		table[n].first = table[n].first + 10 * EPSILON;
		table[n].second = fn(table[n].first);
	}
	
	//Если нашелся корень
	for (int i = 1; i < n; i++){
		if(fabs(table[i].second) < EPSILON){
			table[i].first -= 10 * EPSILON;
			table[i].second = fn(table[i].first);

		}
	}

	vector<pair<double,double>> local_area;

	//поиск отрезков локализации
	for (int i = 0; i < n; i ++){
		if(table[i].second * table[i+1].second < 0){
			pair<double,double> limits = make_pair(table[i].first, table[i+1].first);
			local_area.push_back(limits);
		}
	}

	return local_area;
}
