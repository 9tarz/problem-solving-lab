#include <cstdio>

struct Node {
	int val;
	int height;
	Node* left;
	Node* right;

	Node(int v, Node* l=0, Node* r=0, int h=0)
	: val(v), left(l), right(r), height(h)
	{}
};

int getHeight(Node* root) {

	if (root == 0) {
		return 0;
	}
	else {
		return root->height;
	}
}

int max(int v1, int v2) {
	return ((v1 > v2) ? v1 : v2);
}

void singleRotateRight(Node*& root) {

	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root = temp;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	temp->height = max(root->height, getHeight(temp->right)) + 1;
}

void singleRotateLeft(Node*& root) {

	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root = temp;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	temp->height = max(getHeight(temp->left), root->height) + 1;
}

void doubleRotateRight(Node*& root) {
	singleRotateLeft(root->right);
	singleRotateRight(root);
}

void doubleRotateLeft(Node*& root) {
	singleRotateRight(root->left);
	singleRotateLeft(root);
}



void insert(Node*& root, int x) {

	if(root == 0) {
		root = new Node(x);
		return;
	}
	if(x > root->val) {

		insert(root->right, x);
		//printf("H right: %d , H left: %d\n",getHeight(root->right), getHeight(root->left));
		if (getHeight(root->right) - getHeight(root->left) ==  2 ) {

			//printf("Right");
			if ( x > root->right->val)
				singleRotateRight(root);
			else
				doubleRotateRight(root);
		}

	}

	else if(x < root->val) {

		insert(root->left, x);
		//printf("H right: %d , H left: %d, diff: %d \n",getHeight(root->right), getHeight(root->left), getHeight(root->right) - getHeight(root->left));
		if (getHeight(root->right) - getHeight(root->left) == -2) {
			//printf("Left");
			if ( x < root-> left->val)
				singleRotateLeft(root);
			else
				doubleRotateLeft(root);
		}

	}
    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;

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
		//print_bst(r, -1);
	}

	for (int i = 0 ;i < n; i++) {
		if (result[i] == 0)
			printf("%d\n", result[i]);
		else if (result[i] == 1)
			printf("%d\n", result[i]);
	}
}