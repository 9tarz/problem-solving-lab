#include <cstdio>

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int v, Node* l=0, Node* r=0)
	: val(v), left(l), right(r)
	{}
};

void insert(Node*& root, int x) {

	if(root == 0) {
		root = new Node(x);
		return;
	}
	if(x > root->val)
		insert(root->right, x);
	else if(x < root->val)
		insert(root->left, x);
}

int search(Node*& root, int x) {

	if(root == 0) {
		return 0;
	}
	else {
		if(x == root->val) {
			return 1;
		}
		else {

			if(x > root->val)
				return (search(root->right, x));
			else if(x < root->val)
				return (search(root->left, x));
		}
	}
}

void print_bst(Node*& root, int count) {
	
	count++;

	if(root->right != 0) 
		print_bst(root->right, count); 

	for(int i = 0; i < count ; i++) {
		printf("...");
	}
	printf("* %d\n", root->val); 

	if(root->left != 0) 
		print_bst(root->left, count);

}

main() {

	int n, cmd, val;
	scanf("%d", &n);
	int result[n];
	Node* r = 0;
	for (int i = 0 ; i < n ; i++) {
		scanf("%d",&val);
		insert(r,val);
	}
	int count = -1;
	print_bst(r, count);
}