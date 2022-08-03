#include "Christofides.h"

// Constructor pentru obiectul de tip TSP
TSP::TSP(string in, string out)
{
	iFile = in;
	oFile = out;

	// Deschiderea fișierului de intrare
	ifstream inStream;
	inStream.open(iFile.c_str(), ios::in);

	// Verificăm dacă fișierul a fost deschis corect
	if (!inStream) {
		cerr << "Can't open input file " << iFile << endl;
		exit(1);
	}

	/* Citirea datelor de intrare făcută 
	sub formă de numărul orașului și coordonatele 
	la care se află acel oraș */
	int c, x, y;
	int count = 0;
	while (!inStream.eof()) {
		inStream >> c >> x >> y;
		count++;
		struct City newCity = {x, y};
		cities.push_back(newCity);
	}

	// Închiderea fișierului de intrare
	inStream.close();

	// Inițializarea membrilor acestui obiect
	n = count;
	graph = new int *[n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}

	cost = new int *[n];
	for (int i = 0; i < n; i++) {
		cost[i] = new int[n];
	}

	path_vals = new int *[n];
	for (int i = 0; i < n; i++) {
		path_vals[i] = new int[n];
	}

	adjlist = new vector<int>[n];
}

// Destructor pentru obiectul de tip TSP
TSP::~TSP()
{
	for (int i = 0; i < n; i++) {
		delete[] graph[i];
		delete[] cost[i];
		delete[] path_vals[i];
	}

	delete[] path_vals;
	delete[] graph;
	delete[] cost;
	delete[] adjlist;
}

/* Metodă pentru aflarea distanței matematice dintre două orașe
în format 2D folosind coordonatele acestora */
int TSP::get_distance(struct TSP::City c1, struct TSP::City c2)
{
	int dx = pow((float)(c1.x - c2.x), 2);
	int dy = pow((float)(c1.y - c2.y), 2);
	return floor((float)(sqrt(dx + dy) + .5));
}

/* Umplerea matricei de adiacență cu distanțele calculate de metoda
anterioară */
void TSP::fillMatrix()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = graph[j][i] = get_distance(cities[i], cities[j]);
		}
	}
}

/* Găsirea unui MST folosind algoritmul lui Prim */
void TSP::findMST()
{

	int *key = new int[n];
	bool *included = new bool[n];
	int *parent = new int[n];

	for (int i = 0; i < n; i++) {
		key[i] = std::numeric_limits<int>::max();
		included[i] = false;
	}

	/* Rădăcina arborelui are distanța 0 și niciun părinte */
	key[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < n - 1; i++) {
		/* Găsirea celui mai apropiat vârf care încă nu
		este în arbore */
		int k = getMinIndex(key, included);
		included[k] = true;

		/* Verificarea fiecărui vârf adiacent cu cel curent */
		for (int j = 0; j < n; j++) {
			if (graph[k][j] && included[j] == false && graph[k][j] < key[j]) {
				parent[j] = k;
				key[j] = graph[k][j];
			}
		}
	}

	// Construim arborele prin matrice de adiacență
	for (int i = 0; i < n; i++) {
		int j = parent[i];
		if (j != -1) {
			adjlist[i].push_back(j);
			adjlist[j].push_back(i);
		}
	}
}

/* Metodă pentru găsirea indexului celui mai apropiat
nod nevizitat */
int TSP::getMinIndex(int key[], bool mst[])
{
	int min = std::numeric_limits<int>::max();
	int min_index = 0;

	/* Iterăm prin toate vârfurile */
	for (int i = 0; i < n; i++) {
		/* Verificăm dacă vârful încă nu a fost
		parcurs si comparăm distanța cu cea minimă */
		if (mst[i] == false && key[i] < min) {
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

/* Metodă pentru găsirea tuturor nodurilor cu indice impar
și stocarea acestora într-un subgraf 0 */
void TSP::findOdds()
{
	for (int i = 0; i < n; i++) {
		if ((adjlist[i].size() % 2) != 0) {
			odds.push_back(i);
		}
	}
}

/* Găsirea unei corespondențe perfecte în subgraful M folosind
Greedy */
void TSP::perfectMatching()
{
	int closest, length;
	std::vector<int>::iterator tmp, first;

	findOdds();

	while (!odds.empty()) {
		first = odds.begin();
		vector<int>::iterator it = odds.begin() + 1;
		vector<int>::iterator end = odds.end();
		length = std::numeric_limits<int>::max();
		for (; it != end; ++it) {
			if (graph[*first][*it] < length) {
				length = graph[*first][*it];
				closest = *it;
				tmp = it;
			}
		}

		adjlist[*first].push_back(closest);
		adjlist[closest].push_back(*first);
		odds.erase(tmp);
		odds.erase(first);
	}
}

/* Metodă pentru găsirea unui circuit eulerian */
void TSP::euler_tour(int start, vector<int> &path)
{
	// Crearea unei copii a listei de adiacență
	vector<int> *tempList = new vector<int>[n];
	for (int i = 0; i < n; i++) {
		tempList[i].resize(adjlist[i].size());
		tempList[i] = adjlist[i];
	}

	stack<int> stack;
	int pos = start;
	path.push_back(start);
	while (!stack.empty() || tempList[pos].size() > 0) {
		if (tempList[pos].empty()) {
			path.push_back(pos);
			pos = stack.top();
			stack.pop();
		} else {
			stack.push(pos);
			int neighbor = tempList[pos].back();
			tempList[pos].pop_back();
			for (int i = 0; i < (int)tempList[neighbor].size(); i++) {
				if (tempList[neighbor][i] == pos) {
					tempList[neighbor].erase(tempList[neighbor].begin() + i);
				}
			}
			pos = neighbor;
		}
	}
	path.push_back(pos);
}

/* Metodă pentru transformarea circuitului eulerian
în circuit hamiltonian */
void TSP::make_hamiltonian(vector<int> &path, int &pathCost)
{

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}

	pathCost = 0;
	int root = path.front();
	vector<int>::iterator cur = path.begin();
	vector<int>::iterator iter = path.begin() + 1;
	visited[root] = 1;

	while (iter != path.end()) {
		if (!visited[*iter]) {
			pathCost += graph[*cur][*iter];
			cur = iter;
			visited[*cur] = 1;
			iter = cur + 1;
		} else {
			iter = path.erase(iter);
		}
	}

	if (iter != path.end()) {
		pathCost += graph[*cur][*iter];
	}
}

int TSP::findBestPath(int start)
{
	vector<int> path;
	euler_tour(start, path);
	int length;

	make_hamiltonian(path, length);
	return length;
}

void TSP::printResult()
{
	ofstream outputStream;
	outputStream.open(oFile.c_str(), ios::out);
	outputStream << pathLength << endl;
	for (vector<int>::iterator it = circuit.begin(); it != circuit.end(); ++it)
	{
		outputStream << *it << endl;
	}
	outputStream.close();
};
