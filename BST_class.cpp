#include <iostream>
#include <stdlib.h>

using namespace std;

struct BST_node {
	BST_node *parent;
	BST_node *left;
	BST_node *right;
	int val;
};

class BST {
public: 
	BST();
	~BST();
	void insert(int);
	BST_node *search(int);
	void print();
	void BST_delete(BST_node*);
	BST_node *min();
	BST_node *max();
	BST_node *find_succesor(BST_node*);
	BST_node *find_predecesor(BST_node*);
private:
	BST_node *root;
	void delete_tree(BST_node*);
	void print_post(BST_node*);
	BST_node *find_min_in_subtree(BST_node*);
	void transplant(BST_node*, BST_node*);
	BST_node *max_in_subtree(BST_node*);
};

BST::BST() {
	root = NULL;
}

BST::~BST() {
	delete_tree(root);
}

void BST::insert(int val) {
	BST_node *current = new BST_node;
	current->val = val;
	current->left = NULL, current->right = NULL, current->parent = NULL;
	if (root == NULL) {
		root = current;
	}
	else {
		BST_node *root_c = root;
		while (true) {
			if (root_c->val > val) {
				if (root_c->left != NULL) {
					root_c = root_c->left;
				}
				else {
					root_c->left = current;
					current->parent = root_c;
					return;
				}
			}
			else {
				if (root_c->right != NULL) {
					root_c = root_c->right;
				}
				else {
					root_c->right = current;
					current->parent = root_c;
					return;
				}
			}
		}
	}
}

void BST::delete_tree(BST_node *node) {
	if (node != NULL) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete(node);
	}
}

BST_node* BST::search(int val) {
	BST_node *root2 = root;
	while (root2 != NULL) {
		if (root2->val == val) {
			return root2;
		}
		else if (root2->val > val) {
			root2 = root2->left;
		}
		else {
			root2 = root2->right;
		}
	}
	return NULL;
}

void BST::print() {
	cout << "Printing in post order: " << endl;
	print_post(root);
	cout << endl;
}

void BST::print_post(BST_node *node) {
	if (node != NULL) {
		print_post(node->left);
		print_post(node->right);
		cout << node->val << " ";
	}
}

BST_node* BST::find_min_in_subtree(BST_node *node) {
	BST_node *node2 = node;
	if (node2 == NULL) return NULL;
	while (node2->left != NULL) {
		node2 = node2->left;
	}
	return node2;
}

BST_node* BST::find_succesor(BST_node *node) {
	if (node == NULL) return NULL;
	if (node->right != NULL) {
		return find_min_in_subtree(node->right);
	}
	else {
		BST_node *tmp = node->parent;
		BST_node *node2 = node;
		while (tmp != NULL && node2 == tmp->right) {
			node2 = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
}

BST_node* BST::find_predecesor(BST_node *node) {	
	if (node->left != NULL) {
		return max_in_subtree(node->left);
	}
	BST_node *tmp = node->parent;
	while (tmp != NULL && tmp->right != node) {
		node = tmp;
		tmp = tmp->parent;			
	}
	return tmp;
}

BST_node* BST::min() {
	return find_min_in_subtree(root);
}
BST_node* BST::max() {
	return max_in_subtree(root);
}

BST_node* BST::max_in_subtree(BST_node* root2) {
	while (root2 != NULL && root2->right != NULL) {
		root2 = root2->right;
	}
	return root2;
}

void BST::transplant(BST_node *u, BST_node *v){
	if (u->parent == NULL) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	if (v != NULL) {
		v->parent = u->parent;
	}
}

void BST::BST_delete(BST_node *z) {
	if (z->left == NULL) {
		transplant(z, z->right);
	}
	else if (z->right == NULL) {
		transplant(z, z->left);
	}
	else {
		BST_node *y = find_min_in_subtree(z->right);
		if (y->parent != z) {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}
int main() {
	return 0;
}