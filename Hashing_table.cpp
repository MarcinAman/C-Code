#include <iostream>
#include <string>

using namespace std;

struct node {
	node *next;
	string data;
};

int hash_f(string data,int size) {
	return (data.length()%size);
}

void insert_into_HT(node **HT,string A,int size) {
	int position = hash_f(A,size);
	node *inserted = new node;
	inserted->data = A;
	node *tmp = HT[position];
	HT[position] = inserted;
	inserted->next = tmp;
}

bool is_in_HT(node **HT, string A, int size) {
	int position = hash_f(A, size);
	node *tmp = HT[position];
	while (tmp != NULL) {
		if (tmp->data == A) return true;
	}
	return false;
}

void delete_from_hash(node **HT, string A, int size) {
	//Functions assumes, that A is in array!
	int pos = hash_f(A, size);
	if (A == HT[pos]->data) {
		node *removed = HT[pos];
		HT[pos] = HT[pos]->next;
		delete removed;
		return;
	}
	node *tmp = HT[pos];
	while (tmp->next->data!=A) {
		tmp = tmp->next;
	}
	node *removed = tmp->next;
	tmp->next = tmp->next->next;
	delete removed;
}

void print_HT(node **HT, int size) {
	for (int i = 0; i < size; i++) {
		node *tmp = HT[i];
		cout << "Position: " << i << " : ";
		while (tmp != NULL) {
			cout << tmp->data << "";
			tmp = tmp->next;
		}
		cout << endl;
	}
}


void delete_HT(node **HT, int size) {
	for (int i = 0; i < size; i++) {
		node *tmp = HT[i];
		while (tmp != NULL) {
			node *prev = tmp;
			tmp = tmp->next;
			delete(prev);
		}
	}
	delete(HT);
}

void create_HT(int n) {
	string A;
	node **HT = new node*[n];
	for (int i = 0; i < n; i++) {
		HT[i] = NULL;
	}
	insert_into_HT(HT, "ala", n);
	insert_into_HT(HT, "ma", n);
	insert_into_HT(HT, "koty", n);
	insert_into_HT(HT, "dwaaa", n);
	insert_into_HT(HT, "i", n);
	print_HT(HT, n);
	cout << "Check if i is in the HT: " << is_in_HT(HT, "i", n) << endl;
	cout << "Delete i" << endl;
	delete_from_hash(HT, "i", n);
	cout << "Again check if i is in the HT: " << is_in_HT(HT, "i", n) << endl;
	cout << "After deleting i" << endl;
	print_HT(HT, n);
	delete_HT(HT,n);
}

int main() {
	create_HT(5);
	getchar();
	return 0;
}