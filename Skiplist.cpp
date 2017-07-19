#include <iostream>

using namespace std;

const int max_h = 5;

struct SLnode {
	int value;
	SLnode ** next;
};
struct SkipList {
	SLnode *first;
	SLnode *last;
	int max_lvl;
};

int get_h() {
	int h = 1;
	int random = rand() % 10;
	while (h < max_h && random < 5) {
		h++;
	}
	return h;
}

void insert(int x, SkipList A) {
	int h = get_h();
	SLnode *inserted = new SLnode;
	inserted->next = new SLnode*[h];
	inserted->value = x;
	h--;
	for (int i = max_h - 1; i >= 0; i--) {
		while (A.first->next[i]->value < x) {
			A.first = A.first->next[i];
		}
		if (i <= h) {
			inserted->next[i] = A.first->next[i];
			A.first->next[i] = inserted;
		}
	}
}

SLnode *search(SkipList *S, int val) {
	int h = S->max_lvl;
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






int main() {

	return 0;
}