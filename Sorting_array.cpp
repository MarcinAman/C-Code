#include <iostream>
#include <stdlib.h>

using namespace std;

//Bubble sort

void swap_positions(int a, int b, int *&arr) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void bubble_sort(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap_positions(j, j + 1, arr);
			}
		}
	}
}

//Insertion sort

void insertion_sort(int *arr, int n) {
	for (int i = 2; i < n; i++) {
		int A = arr[i];
		int j = i - 1;
		while (j > 0 && arr[j] > A) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+ 1] = A;
	}
}

//Quick sort:

int partition(int *&tab, int l, int r) {
	int pivot = tab[r];
	int i = l;
	int current = l;
	for (int k = l; k<r; k++) {
		if (tab[k]<pivot) {
			swap(tab[k], tab[current]);
			current++;
		}
	}
	swap(tab[current], tab[r]);
	return current;
}

void QuickSort(int *&tab, int p, int r)
{
	while (p<r)
	{
		int q = partition(tab, p, r);
		QuickSort(tab, p, q - 1);
		p = q + 1;
	}
}

//Merge sort:

void mergetwo(int a, int b, int *&tab, int *&tab_d) {
	int middle = (b + a) / 2;
	int pointer = a;
	int current_a = a;
	int current_mid = middle;
	while (pointer != b) {
		if (current_a == middle) {
			while (current_mid != b) {
				tab_d[pointer] = tab[current_mid];
				current_mid++;
				pointer++;
			}
		}
		else if (current_mid == b) {
			while (current_a != middle) {
				tab_d[pointer] = tab[current_a];
				pointer++;
				current_a++;
			}
		}
		else {
			if (tab[current_a]>tab[current_mid]) {
				tab_d[pointer] = tab[current_mid];
				pointer++;
				current_mid++;
			}
			else {
				tab_d[pointer] = tab[current_a];
				pointer++;
				current_a++;
			}
		}
	}
	for (int j = a; j<b; j++) {
		tab[j] = tab_d[j];
	}
}


void mergesort(int a, int b, int *&tab, int *&tab_d) {
	if (a + 1<b) {
		int sr = (b + a) / 2;
		mergesort(a, sr, tab, tab_d);
		mergesort(sr, b, tab, tab_d);
		mergetwo(a, b, tab, tab_d);
	}
}

//Count sort:
//Effective only on short ranges of data. In this implementation it is from 0 to range

void count_sort(int *arr, int n, int range) {
	int *range_arr = new int[range];
	for (int i = 0; i < range; i++) {
		range_arr[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		range_arr[arr[i]]++;
	}
	int arr_ind = 0;
	for (int i = 0; i < range; i++) {
		while (range_arr[i] != 0) {
			arr[arr_ind++] = i;
			range_arr[i]--;
		}
	}
}

//Shell sort;

void shell_sort(int *arr, int n) {
	for (int gap = n / 2; gap > 0; gap /=2) {
		for (int i = gap; i < n; i++) {
			int first = arr[i], j;
			for (j = i; j >= gap && arr[j - gap] > first; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = first;
		}
	}
}

void print_arr(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void prepare_array(int n) {
	int *arr = new int[n];
	cout << "Unsorted data:" << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10+1;
		cout << arr[i] << " ";
	}
	cout << endl << "After sorting: " << endl;
	shell_sort(arr, n);
	print_arr(arr, n);
}

int main() {
	prepare_array(10);
	getchar();
	return 0;
}
