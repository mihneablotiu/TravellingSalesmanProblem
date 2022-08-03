#ifndef TSP_H
#define TSP_H
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class TSP
{
private:
	// Structură pentru coordonatele fiecărui oraș
	struct City {
		int x;
		int y;
	};

	string iFile;
	string oFile;

	/* Listă pentru nodurile impare */
	vector<int>odds;

	/* Matrice de costuri redusă pentru nodurile impare */
	int **cost;

	/* Lista de adiacentă */
	vector<int> *adjList;

	void findOdds();

public:
	/* Numărul de orașe și implicit numărul de noduri */
	int n;

	int **path_vals;
	int pathLength;

	/* Circuitul eulerian */
	vector<int> circuit;
	vector<City> cities;

	/* Matricea de adiacență realizată după 
	prelucrarea distanțelor dintre orașe */
	int **graph;

    vector<int>* adjlist;

	/* Semnătura metodelor explicate
	și dezvoltate în fișierul tsp_Christofides.cpp */
	TSP(string in, string out);
	~TSP();
	int get_distance(struct City c1, struct City c2);
	void perfectMatching();
	void euler_tour(int start, vector<int> &path);
	void make_hamiltonian(vector<int> &path, int &pathCost);
	void findMST();
	int getMinIndex(int key[], bool mst[]);
	void printResult();
	int get_size(){return n;};
	void fillMatrix();
	int findBestPath(int start);
};

#endif
