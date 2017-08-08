#include <iostream>
#include <vector>

using namespace std;
vector<int>res;

void DFS(int **G, bool *B, int size,int x){
	B[x]=true;
	for(int i=0;i<size;i++){
		if(!B[i] && G[x][i]==1 && i!=x){
			DFS(G,B,size,i);
		}
	}
	res.push_back(x);
}

void sort_topol(int **G, int size){	
	bool *B = new bool[size];
	for(int i=0;i<size;i++) B[i]=false;
	for(int i=0;i<size;i++){
		if(!B[i]){
			DFS(G,B,size,i);
		}
	}
	delete(B);
	for(int i=0;i<res.size();i++){
		cout << res[i] << " ";
	}
	cout << endl;
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
	sort_topol(tab,size);
	for (int i = 0; i < size; i++) delete(tab[i]);
	delete(tab);
}

int main(){
	G_run();
	return 0;
}
