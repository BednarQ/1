#include <iostream>
#include "Graph.h"
#include <deque>

using namespace std;

int **g, **p, npow, city;
vector< vector<int> > vec_g;
vector< vector<int> > vec_p;
int **graph;

int tsp(int start, int set) {
	int masked, mask, result = -1, temp;
	if (vec_g[start][set] != -1) {
		return vec_g[start][set];
	}
	else {
		for (int x = 0; x < city; x++) {
			mask = npow - 1 - (int)pow(2, x);
			masked = set & mask;
			if (masked != set) {
				temp = graph[start][x] + tsp(x, masked);
				if (result == -1 || result > temp)
					result = temp;
				vec_p[start][set] = x;
			}
		}
	}
	vec_g[start][set] = result;
	return result;
}

int tsphelper() {
	for (int i = 0; i < city; i++) {
		for (int j = 0; j < npow; j++) {
			vec_g[i][j] = -1;
			vec_p[i][j] = -1;
		}
	}
	// init matrix g ,from distance matrix graph
	for (int i = 0; i < city; i++) {
		vec_g[i][0] = graph[i][0];
	}
	return tsp(0, npow - 2);
}


int main() {
	string fileName;
	cout << "Provide file name to load graph:" << endl;
	cin >> fileName;

	Graph *gr = new Graph(fileName);
	gr->printGraph();
	graph = gr->getCostMatrix();
	city = gr->getNumberOfCities();
	npow = 0;
	npow = pow(2, city);

	vec_g.resize(city, vector<int>(npow));
	vec_p.resize(city, vector<int>(npow));

	/*vec_g = new int *[city];
	for (int i = 0; i < city; i++)
		vec_g[i] = new int[npow];

	vec_p = new int *[city];
	for (int i = 0; i < city; i++)
		vec_p[i] = new int[npow];*/


	cout << "The min cost is :";
	cout << tsphelper();
	cout << endl;


	cin.get();
	cin.ignore();

	return 0;
}