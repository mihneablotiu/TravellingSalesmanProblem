#include <bits/stdc++.h>
using namespace std;
 
/* Funcția găsește drumul cu cel
mai mic cost din toate drumurile */
int tsp_greedy(vector<vector<int>> tsp)
{
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;
 
    // Începem de la nodul cu indicele 0
    visitedRouteList[0] = 1;
    int route[tsp.size()];
 
    /* Traversăm matricea de adiacență TSP */
    while (i < (int)tsp.size() && j < (int)tsp[i].size()) {
        /* Dacă am depășit dimensiunile matricei */
        if (counter >= (int)tsp[i].size() - 1) {
            break;
        }

        /* Dacă această rută a fost nevizitată
        și dacă are costul mai mic decât minimul*/
        if (j != i && (visitedRouteList[j] == 0)) {
            if (tsp[i][j] < min) {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }

        j++;
 
        /* Verificarea tuturor traseelor
        din nodul i */
        if (j == (int)tsp[i].size()) {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }

    i = route[counter - 1] - 1;
 
    for (j = 0; j < (int)tsp.size(); j++) {
        if ((i != j) && tsp[i][j] < min) {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }

    sum += min;
    return sum;
}