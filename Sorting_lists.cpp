//Implementation of Insertion sort and selection sort

#include <iostream>

using namespace std;

struct node {
	node *next;
	int val;
};

void insert(node *root, node *inserted) {
	if (root == NULL) {
		root = inserted;
	}
	else {
		node *root_c = root, *next_n = root->next;
		while (next_n != NULL && next_n->val < inserted->val) {
			root_c = next_n;
			next_n = next_n->next;
		}
		root_c->next = inserted;
		inserted->next = next_n;
	}
}

node * insertion_sort(node * first) {
	node * sorted = new node;
	sorted->next = NULL;
	while (first->next != NULL) {
		node * tmp = first->next;
		first->next = tmp->next;
		tmp->next = NULL;
		insert(sorted, tmp);
	}
	sorted = sorted->next;
	delete first;
	return sorted;
}

node *removemax(node *root) {
	if (root == NULL) return NULL;
	node *root_c = root, *max_p = root;
	while (root_c->next != NULL) {
		if (root_c->next->val > max_p->next->val) {
			max_p = root_c;
		}
		root_c = root_c->next;
	}
	node *max = max_p->next;
	max_p->next = max_p->next->next;
	max->next = NULL;
	return max;
}

node * selection_sort(node * root) { 
	//sorted in reverse order!
	if (root == NULL) return NULL;
	node *new_list = removemax(root), *new_list_c = new_list;
	while (root->next != NULL) {
		new_list-> next = removemax(root);
		new_list = new_list->next;
		new_list->next = NULL;
	}
	delete root;
	return new_list_c;
}


void create_list(int n) {
	node *begining = new node;
	node *second = new node,*current;
	second->val = rand() % 10 + 1;
	begining->next = second;
	while (n--) {
		current = new node;
		current->val = rand() % 10 + 1;
		cout << current->val << " ";
		second->next = current;
		second = current;
	}
	second->next = NULL;
	cout << endl;
	node *sorted_list = selection_sort(begining->next);
	while (sorted_list != NULL) {
		cout << sorted_list->val << " ";
		sorted_list=sorted_list->next;
	}
	cout << endl;
}

int main() {
	create_list(10);
	getchar();
	return 0;
}
