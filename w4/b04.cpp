#include <cstdio>

struct Node {
	int val,sl,sr;
	Node* left;
	Node* right;

	Node(int v, int sl=0, int sr=0, Node* l=0, Node* r=0)
	: val(v), left(l), right(r), sl(sl), sr(sr)
	{}
};

void insert(Node*& root, int x) {

	if(root == 0) {
		root = new Node(x);
		return;
	}
	if(x > root->val) {
		root->sr += 1;
		insert(root->right, x);
	}
	else if(x < root->val) {
		root->sl += 1;
		insert(root->left, x);
	}
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

int searchMore(Node*& root, int x, int count) {

	if(root == 0) {
		return count;
	}
	else {
		if(x == root->val) {
			//if (root->right != 0)
			//	count++;
			return (searchMore(root->right, x, count));
		}
		else {

			if(x >= root->val){
				return (searchMore(root->right, x,count));
			}
			else if(x < root->val) {
				count++;
				count += root->sr;
				return searchMore(root->left, x,count);
			}
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
		scanf("%d %d", &cmd, &val);
		int count = -1;
		if (cmd == 1) {
			insert(r,val);
			result[i] = -1;
		}
		else if (cmd == 2) {
			result[i] = searchMore(r,val,count)+ 1;
		}
	}
	for (int i = 0 ;i < n; i++) {
		if (result[i] >= 0)
			printf("%d\n", result[i]);
	}
	//int count = -1;
	//print_bst(r, count);
}