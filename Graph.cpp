#include "Graph.h"
#include <vector>


int numOfCities;
Graph::Graph(string fileName)
{
	ifstream file;
	string temp;
	file.open(fileName.c_str());

	if (file.is_open()) {

		do {
			file >> temp;
		} while (strcmp(temp.c_str(), "DIMENSION:") && strcmp(temp.c_str(), "DIMENSION"));
		file >> temp;
		if (!strcmp(temp.c_str(), ":"))
			file >> this->numOfCities;
		else {
			this->numOfCities = stoi(temp);
		}

		do {
			file >> temp;
		} while (strcmp(temp.c_str(), "EDGE_WEIGHT_SECTION"));

		this->matrix = new int*[numOfCities];
		for (int i = 0; i < numOfCities; i++) {
			matrix[i] = new int[numOfCities];
		}
		for (int i = 0; i < numOfCities; i++) {
			for (int j = 0; j < numOfCities; j++) {
				file >> matrix[i][j];

				if (i == j) matrix[i][j] = 0;
				if (matrix[i][j] >= 9999 || matrix[i][j] == 0) matrix[i][j] = 0;
			}
		}
	}
	else {
		cout << "Error occured during loading from file\nFile was probably not found.";
	}
	//cout << "File loaded to matrix" << endl;
}


Graph::~Graph() {
	for (int i = 0; i < numOfCities; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Graph::printGraph() {

	for (int i = 0; i < numOfCities; i++) {
		for (int j = 0; j < numOfCities; j++) {
			cout.width(4);
			cout.fill(' ');
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int Graph::getNumberOfCities() {
	return numOfCities;
}

int **Graph::getCostMatrix() {
	return matrix;
}



