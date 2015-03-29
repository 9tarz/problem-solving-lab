#include <cstdio>

struct ListNode {
	ListNode* next;
	int value;
	ListNode (int v, ListNode* n = 0)
		:value(v), next(n)
  	{}
};

struct LinkedList {
	ListNode* header;
	int size;
	LinkedList (int v = 0)
	:size(v)
	{
		header = new ListNode(0);
	}
};


void insertFirst(LinkedList*& linkedlist, int val) {
	ListNode* newNode = new ListNode(val);
	ListNode* headNode = linkedlist->header;
	newNode->next = headNode->next;
	headNode->next = newNode;
	linkedlist->size++;
}

void insertLast(LinkedList*& linkedlist, int val) {
	ListNode* newNode = new ListNode(val);
	ListNode* pointerNode = linkedlist->header;
	while(pointerNode->next != 0) {
		pointerNode = pointerNode->next;
	}
	pointerNode->next = newNode;
	linkedlist->size++;
}

void deleteNode(LinkedList*& linkedlist, int n) {
	ListNode* pointerNode = linkedlist->header;
	ListNode* pointerDeleteNode;
	if (n <= linkedlist->size) {
		for(int i = 0; i < n; i++){
			if(i == n - 1)
				pointerDeleteNode = pointerNode->next;
			else if (i != n - 1)
				pointerNode = pointerNode->next;
		}
		pointerNode->next = pointerDeleteNode->next;
		delete pointerDeleteNode;
		linkedlist->size--;
	}
}

void print_list(LinkedList*& linkedlist) {
	ListNode* pointerNode = linkedlist->header->next;
 	while( pointerNode != 0) {
	    printf("%d\n", pointerNode->value);
	    pointerNode = pointerNode->next;
  	}
}

main() {
	int n,val,count;
	//count = 0;
	char cmd[2];
	LinkedList* list = new LinkedList();
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		scanf("%d", &val);
		if (cmd[0] == 'I') {
			insertFirst(list, val);
			//count++;
		}
		else if (cmd[0] == 'A') {
			insertLast(list, val);
			//count++;
		}
		else if (cmd[0] == 'D') {
			//if (val <= count) {
				deleteNode(list, val);
				//count--;
			//}
		}

	}
	print_list(list);
}


/*main() {
	int n,vali, valj, count;
	count = 0;
	char cmd[2];

	ListNode* header = new ListNode(0);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		scanf("%d %d", &vali, &valj);
		if (cmd[0] == 'N') {
		}

	}
	print_list(header->next);
}*/