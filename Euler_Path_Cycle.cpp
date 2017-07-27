#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Alg assumes that there is an Euler cycle and it req an undirected graph

void euler_cycle(int x, int **G, stack<int>&path,int size) {
	for (int i = 0; i < size; i++) {
		if (G[i][x] != 0) {
			G[i][x] = 0;
			G[x][i] = 0;
			euler_cycle(i, G, path, size);
		}
	}
	path.push(x);
}

//For a DAG:

void EulerDFS(int **G, int x, stack<int>&path, int size) {
	for (int i = 0; i < size; i++) {
		if (G[x][i] != 0) {
			G[x][i] = 0;						//diffrence!
			EulerDFS(G, x, path, size);
		}
	}
	path.push(x);
}

//checking for an Eulerian graph: (undirected)

void DFS(int **G, bool *visited, int x, int size,int &c) {
	visited[x] = true;
	int a = 0;
	for (int i = 0; i < size; i++) {
		if (G[x][i] != 0 && x != i && !visited[i]) {
			DFS(G, visited, i, size, c);
		}
		if (G[x][i] != 0 && x != i) a++;
	}
	if (a % 2 == 1) {
		c++;
	}
}

string Euler() {
	int size, edges;
	cin >> size >> edges;
	bool *visited = new bool[size];
	int c = 0;
	int **G = new int*[size];
	for (int i = 0; i < size; i++) {
		G[i] = new int[size];
		visited[i] = false;
		for (int j = 0; j < size; j++) {
			G[i][j] = 0;
		}
	}
	int a, b;
	for (int i = 0; i < edges; i++) {
		cin >> a >> b;
		G[a][b] = 1, G[b][a] = 1;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (G[i][j] != 0) {
				DFS(G, visited, i, size, c);
				i = size;
				j = size;
			}
		}
	}
	for (int m = 0; m < size; m++) {
		cout << visited[m] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (visited[i] == false) {
			for (int j = 0; j < size; j++) {
				if (G[i][j] != 0) {
					return "Not an Eulerian graph";
				}
			}
		}
	}
	if (c == 0) {
		return "Graph has an Euler cycle";
	}
	if (c == 2) {
		return "Graph has an Euler path";
	}
	return "Not an Eulerian graph";
}


int main() {
	getchar();
	return 0;
}