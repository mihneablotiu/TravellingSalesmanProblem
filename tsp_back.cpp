#include <bits/stdc++.h>

using namespace std;

void tsp_back(int **graph, vector<bool>& visited, int curr_pos,
         int nodes, int count, int cost, int& answer)
{
 
    /* Dacă s-a ajuns la ultimul nod și acesta
    are o legătură cu nodul inițial (ceea ce se
    întâmplă mereu în cadrul acestei probleme
    deoarece graful trebuie să fie complet) atunci
    păstrăm valoarea minimă dintre costul total
    de până atunci și „answer”. Apoi, ne întoarcem
    din apelul recursiv și căutăm alte variante posibile */
    if (count == nodes) {
        answer = min(answer, cost + graph[curr_pos][0]);
        return;
    }
 
    /* Partea de backtracking - traversăm toți vecinii
    nevizitați ai nodului de pe poziția curentă, creștem
    numărătoarea cu 1 și costul total cu cel corespunzător
    acestui pas */
    for (int i = 0; i < nodes; i++) {
        if (visited[i] == 0 && graph[curr_pos][i] != 0) {
 
            // Dacă nodul nu a fost vizitat, îl marcăm ca vizitat
            visited[i] = true;
            tsp_back(graph, visited, i, nodes, count + 1,
                cost + graph[curr_pos][i], answer);
 
            // Când ne întoarcem din apelul recursiv îl marcăm ca nevizitat
            visited[i] = false;
        }
    }
};