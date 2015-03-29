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

void leftRotate(LinkedList*& linkedlist){
	ListNode* pointerNode = linkedlist->header;
	ListNode* newFirstNode = linkedlist->header->next->next;
	for(int i = 0; i < linkedlist->size  ;i++) {
		pointerNode = pointerNode->next;
	}
	pointerNode->next = linkedlist->header->next;
	linkedlist->header->next->next = 0;
	linkedlist->header->next = newFirstNode;
}

void rightRotate(LinkedList*& linkedlist) {
	ListNode* pointerNode = linkedlist->header;
	ListNode* prevLastNode;
	for(int i = 0; i < linkedlist->size  ;i++) {
		if (i == linkedlist->size - 1)
			prevLastNode = pointerNode;
		pointerNode = pointerNode->next;
	}
	pointerNode->next = linkedlist->header->next;
	linkedlist->header->next = pointerNode;
	prevLastNode->next = 0;

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
	int n,val, count;
	count = 0;
	char cmd[3];
	LinkedList* list = new LinkedList();
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		if (cmd[0] == 'r' && cmd[1] == 'i') 
			scanf("%d", &val);
		else if (cmd[0] == 'l' && cmd[1] == 'i')
			scanf("%d", &val);

		//printf("%c %c %d\n",cmd[0],cmd[1],val);
		if (cmd[0] == 'r' && cmd[1] == 'i') {
			insertLast(list, val);
			//print_list(list);
			//printf("----------------------------\n");
		}
		else if (cmd[0] == 'l' && cmd[1] == 'i') {
			insertFirst(list, val);
			//print_list(list);
			//printf("----------------------------\n");
		}
		else if (cmd[0] == 'l' && cmd[1] == 'r') {
			if (list->size <= 1){
				continue;
			}
			leftRotate(list);
			//print_list(list);
			//printf("----------------------------\n");
		}
		else if (cmd[0] == 'r' && cmd[1] == 'r') {
			if (list->size <= 1){
				continue;
			}
			rightRotate(list);
			//print_list(list);
			//printf("----------------------------\n");
		}
		val = 0;

	}
	print_list(list);
}