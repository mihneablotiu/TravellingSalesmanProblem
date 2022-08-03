#ifndef ALGO_H
#define ALGO_H
int tsp_naive(int **graph, int s, int nodes);

void tsp_back(int **graph, std::vector<bool>& v, int currPos,
         int n, int count, int cost, int& ans);

int tsp_greedy(std::vector<std::vector<int>> tsp);
         
#endif