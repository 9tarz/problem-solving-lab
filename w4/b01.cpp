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

main() {

	int n, cmd, val;
	scanf("%d", &n);
	int result[n];
	Node* r = 0;
	for (int i = 0 ; i < n ; i++) {
		scanf("%d %d", &cmd, &val);
		if(cmd == 1) {
			insert(r,val);
			result[i] = 2;
		}
		else if (cmd == 2) {
			if (search(r,val) == 1 ) {
				//printf("1\n");
				result[i] = 1;

			}
			else if (search(r,val) == 0) {
				//printf("0\n");
				result[i] = 0;
			} 
		}
	}
	for (int i = 0 ;i < n; i++) {
		if (result[i] == 0)
			printf("%d\n", result[i]);
		else if (result[i] == 1)
			printf("%d\n", result[i]);
	}
}