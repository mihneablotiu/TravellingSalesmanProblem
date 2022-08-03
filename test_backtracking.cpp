#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <time.h>

#include "algo.h"

using namespace std;

// Citirea datelor din fișiere
ifstream fin ("./test.in");
ofstream fout ("./test.out");

int main ()
{
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

        /* Vector pentru a verifica dacă un
        anumit nod a fost vizitat sau nu */
        vector<bool> visited(nodes);
        for (int i = 0; i < nodes; i++)
            visited[i] = false;
 
        /* Considerăm primul nod din graf 
        ca fiind vizitat deoarece cu acesta
        începem algoritmul */
        visited[0] = true;
        int answer = INT_MAX;
        if (nodes == 1) {
            answer = 0;
        }

        /* Calculăm timpul de execuție al algoritmului
        de backtracking pe graful curent prin diferența
        dintre valoarea timpului de după și înaintea
        aplicării algoritmului */
        clock_t t;
        t = clock();

        // Aplicarea efectivă a algoritmului
        tsp_back(graph, visited, 0, nodes, 1, 0, answer);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        cout << endl << "TSP took: " << time_taken << " Seconds" << endl;
 
        /* Afișarea în fișier a drumului minim exact, întors
        de către algoritm */
        fout << answer;

        /* Eliberarea memoriei pentru graful asociat*/
        for (int i = 0; i < nodes; i++) {
            free(graph[i]);
        }

        free(graph);
    }

    return 0;
}
