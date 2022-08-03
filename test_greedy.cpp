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
    if (nodes != 0 && nodes != 1) {

         vector<vector<int>> graph;
         int cost;

         for (int i = 0; i < nodes; i++) {
             vector<int> line;

             for (int j = 0; j < nodes; j++) {
                 fin >> cost;
                 line.push_back(cost);
             }

             graph.push_back(line);
         }

        /* Calculăm timpul de execuție al algoritmului
        de backtracking pe graful curent prin diferența
        dintre valoarea timpului de după și înaintea
        aplicării algoritmului */
        t = clock();
        
        // Aplicarea efectivă a algoritmului
        fout << tsp_greedy(graph);

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        cout << endl << "TSP took: " << time_taken << " seconds" << endl;
        
    } else if (nodes == 1) {
        fout << "0";
        t = clock();
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        cout << endl << "TSP took: " << time_taken << " seconds" << endl;
    }
    return 0;
}
