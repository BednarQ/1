#pragma once
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <Windows.h>
#include <vector>
#include<limits.h>
#include<cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <limits>
#include <vector>
#include <list>

using namespace std;

class Graph
{
private:

	int numOfCities;
	int **matrix;
	int cost;

public:

	Graph(string fileName);
	~Graph();
	void printGraph();
	void dynamicProgramming();
	int getNumberOfCities();
	int** getCostMatrix();

};

