#include <bits/stdc++.h>
using namespace std;

int tsp_naive(int **graph, int s, int nodes)
{
    /* Vector pentru monitorizarea tuturor nodurilor
    în afară de cel curent */
    vector<int> vertex;
    for (int i = 0; i < nodes; i++)
        if (i != s)
            vertex.push_back(i);
 
    /* Variabilă pentru a ține minte drumul minim*/
    int min_path = INT_MAX;

    do {
 
        // Costul curent
        int current_pathweight = 0;
 
        // Calculăm costul curent
        int k = s;
        for (int i = 0; i < (int)vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // Actualizăm minimul
        min_path = min(min_path, current_pathweight);
 
    // Trecem la următoarea permutare posibilă
    } while (next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}