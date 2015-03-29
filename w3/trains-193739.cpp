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
	ListNode* tail;
	int size;
	LinkedList (int v = 0)
	:size(v)
	{
		header = new ListNode(0);
		tail = header;
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

void move(LinkedList*& linkedlist_parent, LinkedList*& linkedlist_child) {
	ListNode* newNode = linkedlist_child->header->next;
	ListNode* pointerNode = linkedlist_parent->header;
	while(pointerNode->next != 0) {
		pointerNode = pointerNode->next;
	}
	pointerNode->next = newNode;
	linkedlist_parent->size++;

	linkedlist_child->tail->next = 0;
	linkedlist_child->size = 0;
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
	int n,vali, valj, count;
	count = 0;
	char cmd[2];
	LinkedList* list;
	LinkedList** arrayOfLinkedList;
	arrayOfLinkedList = new LinkedList* [100000];
	for(int i = 0; i < 100000; i++) {
    	arrayOfLinkedList[i] = new LinkedList();
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		scanf("%d %d", &vali, &valj);
		if (cmd[0] == 'N') {
			insertLast(arrayOfLinkedList[valj-1], vali);
		}
		else if (cmd[0] == 'M') {
			move(arrayOfLinkedList[valj-1],arrayOfLinkedList[vali-1]);
		}

	}
	for(int i = 0; i < 100000; i++) {
		print_list(arrayOfLinkedList[i]);
	}

	//print_list(list);
}