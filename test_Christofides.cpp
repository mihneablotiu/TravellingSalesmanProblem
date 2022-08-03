#include <iostream>
#include <bits/stdc++.h>
#include "Christofides.h"


int main(int argc, char** argv) {
	if(argc < 2){
		exit(-1);
	}

	/* Citirea numelui fișierului de
	inpus și crearea celui de output */
	string input, output;
	input = output = argv[1];
	output.append(".out");

	clock_t t;
    t = clock();

	/* Crearea unui nou obiect TSP
	unde TSP = Travelling Salesman Problem*/
	TSP tsp(input, output);
	
	// Dimensiunea obiectului TSP
	int tsp_size = tsp.get_size();

	/* Umplerea matricei de adiacență de dimensiune
	N x N unde N este numărul de noduri */
	tsp.fillMatrix();

	/* Găsirea unui MST unde MST = Minimum 
	Spannig Tree pentru obiectul curent */
	tsp.findMST();
	tsp.perfectMatching();

	/* Iterăm prin toți indexii pentru a
	găsii cel mai scurt drum*/
	int best = INT_MAX;
	int bestIndex = 0;
	for (long t = 0; t < tsp_size; t++) {
		int result = tsp.findBestPath(t);

		tsp.path_vals[t][0] = t;
		tsp.path_vals[t][1] = result;

		if (tsp.path_vals[t][1] < best) {
			bestIndex = tsp.path_vals[t][0];
			best = tsp.path_vals[t][1];
		}
	}

	// Cearea traseului pentru cel mai bun tur.
	tsp.euler_tour(bestIndex, tsp.circuit);
	tsp.make_hamiltonian(tsp.circuit, tsp.pathLength);


	cout << tsp.pathLength << endl;

	/* Calcularea efectivă a duratei de execuție
	pentru întreg algoritmul */
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << endl << "TSP took: " << time_taken << " Seconds" << endl;

	// Afișarea în fișier
	tsp.printResult();
}
