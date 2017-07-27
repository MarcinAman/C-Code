#include <iostream>
#include <string>
const int _INF = 100000;
#define M 100000

using namespace std;

int Dijkstra(int **G, int n, int start, int e){
	int *costs = new int[n];
	bool *visited = new bool[n];
	int *p=new int[n];
	for(int i=0;i<n;i++){
		costs[i]=_INF;
		visited[i]=false;
	}
	costs[start]=0;
	for(int m=0;m<n;m++){
		int c = 0;
		while(c<n){
			if(!visited[c]) break;
			c++;
		}
		for(int i=0;i<n;i++){
			if(!visited[i] && costs[i]<costs[c]) c=i;
		}
		visited[c]=true;
		for(int i=0;i<n;i++){
			if(!visited[i] && costs[i]>costs[c]+G[c][i]){
				p[i]=c;
				costs[i]=costs[c]+G[c][i];
			}
		}
	}
	int i=e;
	cout<<i+1<<" - ";
    while (i!=start) {
        i=p[i];
        cout<<i+1<<" - ";
    }
    delete(costs);
    delete(visited);
    delete(p);
}

void _Dijkstra () {
    int** G = new int*[10];
    for (int i=0; i<10; i++) {
        G[i]=new int[10];
    }

    int K[10][10] = {
            {M,37,2,M,M,M,M,M,M,M},
            {37,M,M,1,M,M,M,M,12,M},
            {2,M,M,7,M,M,M,2,M,M},
            {M,1,7,M,M,10,M,M,M,M},
            {M,M,M,M,M,M,41,14,M,M},
            {M,M,M,10,M,M,2,20,M,8},
            {M,M,M,M,41,2,M,M,M,1},
            {M,M,2,M,14,20,M,M,M,M},
            {M,12,M,M,M,M,M,M,M,21},
            {M,M,M,M,M,8,1,M,21,M} };

    for (int i=0; i<100; i++) {
        G[i/10][i%10]=K[i/10][i%10];
    }
    Dijkstra(G, 10, 0, 9);
}

int main(){
	_Dijkstra();
	return 0;
}
