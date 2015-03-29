#include <cstdio>

struct Node {
	int val,sl,sr;
	Node* left;
	Node* right;
	Node* parent;

	Node(int v, int sl=0, int sr=0, Node* l=0, Node* r=0,Node* parent=0)
	: val(v), left(l), right(r), sl(sl), sr(sr), parent(parent)
	{}
};

void insert(Node*& root, int x, Node* parent) {


	if(root == 0) {
		root = new Node(x);
		root->parent = parent;
		//printf("%d\n", parent->val);
		return;
	}
	if(x > root->val) {
		root->sr += 1;
		insert(root->right, x, root);
	}
	else if(x < root->val) {
		root->sl += 1;
		insert(root->left, x,root );
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


int minFind(Node*& root) {

	if (root->left == 0)
		return root->val;

	else
		return minFind(root->left);
}


void remove(Node*& root, int x) {
	//Node*& parent = root ;

	if(root == 0) {
		return;
	}
	else {
		if(x == root->val) {

			if (root->parent == 0) {

				if(root->left == 0 && root->right == 0) {
					delete root;
					root = 0;
				}
				else if (root->left == 0 && root->right != 0) {
					root = root->right;
					root->parent = 0;
				}
				else if (root->left != 0 && root->right == 0 ) {
					root = root->left;
					root->parent = 0;
				}
				else if (root->left != 0 && root->right != 0) {
				
					root->val = minFind(root->right);
					remove(root->right, root->val);

				}	

			}
			else {

				if(root->left == 0 && root->right == 0) {
					if (root->parent->left == root)
						root->parent->left = 0;
					else
						root->parent->right = 0;
					//delete root;
					//root = 0;
				}
				else if (root->left == 0 && root->right != 0) {
					root->right->parent = root->parent;
					if (root->parent->left == root)
					{
						root->parent->left = root->right;
					}
					else
					{
						root->parent->right = root->right;
					}
					//delete root;
					//root = 0;
				}
				else if (root->left != 0 && root->right == 0 ) {

					root->left->parent = root->parent;
					if (root->parent->left == root)
						root->parent->left = root->left;
					else
					{
						root->parent->right = root->left;
					}
					//delete root;
					//root = 0;
				}

				else if (root->left != 0 && root->right != 0) {
				
					root->val = minFind(root->right);
					remove(root->right, root->val);

				}
			}

			//Node*& min = minFind(root->right);
			//root->val = min->val;
			//delete min;
		}
		else {

			//parent = root;

			if(x > root->val)
				return (remove(root->right, x));
			else if(x < root->val)
				return (remove(root->left, x));
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
			insert(r,val,r);
			result[i] = -1;
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
		else if (cmd == 3) {
			remove(r,val);
			result[i] = -1;
		}
		print_bst(r, -1);
	}
	for (int i = 0 ;i < n; i++) {
		if (result[i] == 0)
			printf("%d\n", result[i]);
		else if (result[i] == 1)
			printf("%d\n", result[i]);
	}
}