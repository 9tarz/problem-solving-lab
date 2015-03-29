#include <cstdio>

struct ListNode {
	ListNode* next;
	int value;
	ListNode (int v, ListNode* n = 0)
		:value(v), next(n)
  	{}
};

void insertFirst(ListNode*& header, int val) {
	ListNode* newNode = new ListNode(val);
	newNode->next = header->next;
	header->next = newNode;
}

void insertLast(ListNode*& header, int val) {
	ListNode* newNode = new ListNode(val);
	ListNode* pointerNode = header;
	while(pointerNode->next != 0) {
		pointerNode = pointerNode->next;
	}
	pointerNode->next = newNode; 
}

void deleteNode(ListNode*& header, int n, int count) {
	ListNode* pointerNode = header;
	ListNode* pointerDeleteNode;
	if (n <= count) {
		for(int i = 0; i < n; i++){
			if(i == n - 1)
				pointerDeleteNode = pointerNode->next;
			else if (i != n - 1)
				pointerNode = pointerNode->next;
		}
		pointerNode->next = pointerDeleteNode->next;
		delete pointerDeleteNode;
	}
}

void print_list(ListNode*& header) {
	ListNode* pointerNode = header;
 	while( pointerNode != 0) {
	    printf("%d\n", pointerNode->value);
	    pointerNode = pointerNode->next;
  	}
}

main() {
	int n,val,count;
	count = 0;
	char cmd[2];
	ListNode* header = new ListNode(0);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		scanf("%d", &val);
		if (cmd[0] == 'I') {
			insertFirst(header, val);
			count++;
		}
		else if (cmd[0] == 'A') {
			insertLast(header, val);
			count++;
		}
		else if (cmd[0] == 'D') {
			if (val <= count) {
				deleteNode(header, val, count);
				count--;
			}
		}

	}
	print_list(header->next);
}