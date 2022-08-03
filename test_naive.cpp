#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include "algo.h"

using namespace std;

ifstream fin ("./test.in");
ofstream fout ("./test.out");

int main ()
{
    clock_t t;
    int nodes;

    // Citim numărul de noduri ale grafului
    fin >> nodes;


    /* Citim costul dintre oricare două laturi, 
    deoarece în cadrul acestei probleme, graful
    trebuie să fie complet */
    if (nodes != 0) {

        int **graph = (int **)malloc(nodes * sizeof(int *));
        for (int i = 0; i < nodes; i++) {
            graph[i] = (int *)calloc(nodes, sizeof(int));
        }

        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                fin >> graph[i][j];
            }
        } 

        int s = 0;

        /* Calculăm timpul de execuție al algoritmului
        de backtracking pe graful curent prin diferența
        dintre valoarea timpului de după și înaintea
        aplicării algoritmului */
        t = clock();

        // Aplicarea efectivă a algoritmului
        fout << tsp_naive(graph, s, nodes);

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        cout << endl << "TSP took: " << time_taken << " seconds" << endl;

        /* Eliberarea memoriei pentru graful asociat*/
        for (int i = 0; i < nodes; i++) {
            free(graph[i]);
        }
        free(graph);
    }

    return 0;
}
