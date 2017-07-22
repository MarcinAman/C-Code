#include <iostream>

using namespace std;
//Simple, array-based implementation

void make_set_arr(int i, int *R) {
	R[i] = i;
}

int findArr(int i, int *R) {
	return R[i];
}

void unionArr(int x, int y, int *R,int size) {
	//We find sets and if they are diffrent union them by running through the whole arr and comparing 
	int set_x = findArr(x, R);
	int set_y = findArr(y, R);
	if (set_x != set_y) {
		for (int i = 0; i < size; i++) {
			if (R[i] == set_y) R[i] = set_x;
		}
	}
}

bool compare_sets(int x, int y, int *R) {
	if (findArr(x, R) == findArr(y, R)) return true;
	return false;
}

int *makeArr(int size) {
	int *R = new int[size];
	for (int i = 0; i < size; i++) {
		make_set_arr(i, R);
	}
	return R;
}

void delete_arr(int *R) {
	delete(R);
}

//Implementation based on pointers:

struct set;
struct setNode {
	set *set_p;
	setNode *next;
	int val;
};

struct set {
	setNode *head;
	setNode *tail;
	int l;
};

//So the set has 2 pointers: on the first element of the list and on the last one. Also we hava an int value that is representing a lenght of a set. For quicker unioning
//The setNode has 2 pointers: one to the next element in set and another for the find set operation, also some data which is in this case an int

set *findSet(setNode *A) {
	return A->set_p;
}

setNode *makeSet(int x) {
	setNode *node = new setNode;
	set *s = new set;
	node->val = x;
	s->head = node;
	s->tail = node;
	s->l = 1;
	node->next = NULL;
	node->set_p = s;
	return node;
}

bool compare_sets(setNode *x, setNode *y) {
	if (x->set_p == y->set_p) return true;
	return false;
}

void union_sets(setNode *x, setNode *y) {
	set *A = x->set_p;
	set *B = y->set_p;
	if (A != B) {
		if (A->l > B->l) {
			A->tail->next = B->head;
			A->tail = B->tail;
			A->l += B->l;
			while (B->head != NULL) {
				B->head->set_p = A;
				B->head = B->head->next;
			}
			delete(B);
		}
		else {
			//same operations, just the other way around due to lenght
			B->tail->next = B->head;
			B->tail = A->tail;
			B->l += A->l;
			while (A->head != NULL) {
				A->head->set_p = B;
				A->head = A->head->next;
			}
			delete(A);
		}
	}
}

void init(int size, setNode **tab) {
	for (int i = 0; i < size; i++) {
		tab[i] = makeSet(rand() % 20 + 1);
	}
}

int main() {
	return 0;
}