#include <iostream>
#include <algorithm>

using namespace std;

int knapsack(int *value, int *weight, int size, int max_w) {
	int *A = new int[max_w + 1];
	for (int i = 0; i < max_w + 1; i++) A[i] = 0;
	for (int i = 0; i <= max_w; i++) {
		for (int j = 1; j < size; j++) {
			if (weight[j] <= i) A[i] = max(A[i], A[i - weight[j]] + value[j]);
		}
	}
	return A[max_w];
}

void _kapsnack() {
	int max_w = 26;
	int v[5] = { 24,13,23,15,16};
	int w[5] = { 12,7,11,8,9};
	int size = 5;
	cout << knapsack(v, w, size, max_w);
}

//Assuming, that activities are sorted by the ending time;
int activity_selection(int *s, int *f, int k, int size) {
	int m = k + 1;
	while (m < size && s[m] < f[k]) m++;
	if (m < size) {
		cout << "m= " << m << endl;
		return 1 + activity_selection(s, f, m, size);
	}
	return 0;
}

void _activity_selector() {
	int s[] = { 1, 3, 0, 5, 8, 5 };
	int f[] = { 2, 4, 6, 7, 9, 9 };
	cout << activity_selection(s, f, 0,6);
}


//Algoritm was taken from that video:
//https://www.youtube.com/watch?v=cr6Ip0J9izc

struct task {
	int s, f, c;
};

int activity_selection_w(task *activ, int n) {
	int *A = new int[n];
	for (int i = 0; i < n; i++) A[i] = 0;
	A[0] = activ[0].c;
	for (int i = 1; i < n; i++) {
		A[i] = max(activ[i].c, A[i - 1]);
		for (int j = i - 1; j >= 0; j--) {
			if (activ[j].f <= activ[i].s) {
				A[i] = max(A[i], activ[i].c + A[j]);
				break;
			}
		}
	}
	int max_v = 0;
	for (int i = 0; i < n; i++) {
		if (max_v < A[i]) max_v = A[i];
	}
	return max_v;
}

void activity_add(int s, int f, int c,task *arr, int n) {
	arr[n].s = s;
	arr[n].f = f;
	arr[n].c = c;
}

void _activity_selection_w() {
	task *arr = new task[6];
	activity_add(1,3,5,arr,0);
	activity_add(2,5,6,arr,1);
	activity_add(4,6,5,arr,2);
	activity_add(6,7,4,arr,3);
	activity_add(5,8,11,arr,4);
	activity_add(7,9,2,arr,5);
	cout << activity_selection_w(arr, 6);
}


int LCS(int n,int m,int *A, int *B) {
	int **tab = new int*[n+1];
	for(int i=0;i<n+1;i++) tab[i]=new int[m+1];
	for (int i = 0; i < n+1; i++) tab[i][0] = 0;
	for (int i = 0; i < m+1; i++) tab[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i] != B[j]) {
				tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
			}
			else {
				tab[i][j] = tab[i - 1][j - 1] + 1;
			}
		}
	}
	return tab[n][m];
}

void _LCS() {
	int n = 7;
	int A[] = { 0,1,2,3,4,5,6 };
	int B[] = { 0,1,2,3,7,8,9 };
	cout << LCS(n, n, A, B);
}

int main() {
	return 0;
}