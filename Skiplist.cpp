#include <iostream>

using namespace std;

struct SLnode {
	int value;
	SLnode **next;
};

struct SkipList {
	SLnode *first, *last;
	int maxH;
	SkipList(int lvl) {
		maxH = lvl;
		first = new SLnode[maxH];
		last = new SLnode[maxH];
		first->value = -1;
		last->value = 1000000;
		first->next = new SLnode*[maxH];
		last->next = new SLnode*[maxH];
		for (int i = 0; i < maxH; i++) {
			first->next[i] = last;
			last->next[i] = NULL;
		}
	}
	int getH();
};

int SkipList::getH() {
	int h = 1;
	int random = rand() % 10;
	while (h < this->maxH && random < 5) {
		h++;
	}
	return h;
}

void insert(SkipList * skip, int key) {
	SLnode * it = skip->first;
	int h = skip->getH();
	SLnode * newNode = new SLnode;
	newNode->value = key;
	newNode->next = new SLnode *[h];

	for (int i = skip->maxH - 1; i >= 0; i--) {
		while (it->next[i] != NULL && key > it->next[i]->value)
			it = it->next[i];
		if (i<h) {
			newNode->next[i] = it->next[i];
			it->next[i] = newNode;
		}
	}
}

void erase(int k,SkipList *A) {
	SLnode *current = A->first;
	SLnode **update = new SLnode*[A->maxH];
	for (int i = A->maxH - 1; i >= 0; i--) {
		while (current->next[i] != NULL && current->next[i]->value < k) {
			current = current->next[i];
		}
		update[i] = current;
	}
	current = current->next[0];
	if (current != NULL && current->value == k) {
		for (int i = 0; i < A->maxH; i++) {
			if (update[i]->next[i] != current) {
				break;
			}
			update[i]->next[i] = current->next[i];
		}
	}
}

SLnode *search(SkipList *S, int val) {
	int h = S->maxH;
	SLnode *tmp = S->first;
	while (h >= 0) {
		while (tmp->next[h]->value < val) {
			tmp = tmp->next[h];
		}
		h--;
	}
	tmp = tmp->next[0];
	if (tmp->value = val) {
		return tmp;
	}
	return NULL;
}

void _Skiplist() {
	SkipList *A = new SkipList(5);
	for (int i = 0; i < 10; i++) {
		int ins = rand() % 10 + 1;
		cout << ins << " ";
		insert(A,ins);
	}
	cout << endl;
	erase(10,A);
	for (SLnode *i = A->first->next[0]; i->next[0] != NULL; i = i->next[0]) {
		cout << i->value << " ";
	}
	cout << endl;
	erase(2, A);
	for (SLnode *i = A->first->next[0]; i->next[0] != NULL; i = i->next[0]) {
		cout << i->value << " ";
	}
	cout << endl;	
}


int main() {

	return 0;
}
