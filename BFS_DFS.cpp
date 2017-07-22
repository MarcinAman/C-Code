#include <iostream>
#include <queue>

using namespace std;

//O(V+E)

void VisitedNode(int **tab,bool *tab_b,int x,int size) {
	char s = 'A'+x;
	tab_b[x] = true;
	cout << "Processed by DFS: " << s << endl;
	for (int i = 0; i < size; i++) {
		if (tab[x][i] != 0 && x != i && !tab_b[i]) {
			VisitedNode(tab, tab_b, i, size);
		}
	}
}
void DFS(int **tab, int size) {
	bool  *tab_b = new bool[size];
	for (int i = 0; i < size; i++) tab_b[i] = false;
	for (int i = 0; i < size; i++) {
		if (!tab_b[i]) VisitedNode(tab, tab_b, i, size);
	}
	delete(tab_b);
}

//O(V+E)

void BFS(int **tab, int vertex, int size) {
	queue<int> Q;
	bool *visited = new bool[size];
	int *parent = new int[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
		parent[i] = -1;
	}
	visited[vertex] = true;
	Q.push(vertex);
	while (!Q.empty()) {
		int a = Q.front();
		char c = 'A' + a;
		cout << "Processed by BFS: " << c << endl;
		Q.pop();
		for (int i = 0; i < size; i++) {
			if (tab[a][i] == 1 && !visited[i]) {
				visited[i] = true;
				parent[i] = a;
				Q.push(i);
			}
		}
	}
	delete(visited);
	delete(parent);
}

void G_run() {
	int size = 7;
	int **tab = new int*[size];
	for (int i = 0; i < size; i++) {
		tab[i] = new int[size];
		for (int j = 0; j < size; j++) {
			tab[i][j] = 0;
		}
	}
	tab[0][1] = 1, tab[0][2] = 1, tab[0][4] = 1;
	tab[1][3] = 1, tab[1][5] = 1;
	tab[2][6] = 1;
	tab[4][5] = 1;
	//BFS(tab, 0, size);
	DFS(tab, size);
	for (int i = 0; i < size; i++) delete(tab[i]);
	delete(tab);
}

int main() {
	G_run();
	getchar();
	return 0;
}