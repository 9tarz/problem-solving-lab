#include <cstdio>

struct ListNode {
	ListNode* next;
	int value;
	ListNode (int v=0, ListNode* n = 0)
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
		header = NULL;
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
	if(linkedlist->header == 0) {
		linkedlist->header = linkedlist->tail = newNode;
	} else {
		linkedlist->tail->next = newNode;
		linkedlist->tail = linkedlist->tail->next;
	}
	linkedlist->size++;

}

void move(LinkedList*& linkedlist_child ,LinkedList*& linkedlist_parent) {
	if(linkedlist_child->size == 0)
		return;

	if(linkedlist_parent->header == 0){

		linkedlist_parent->header = linkedlist_child->header;
		linkedlist_parent->tail = linkedlist_child->tail;
	}
	else if (linkedlist_child->header == linkedlist_parent->header) {
		return;
	}
	else {
		linkedlist_parent->tail->next = linkedlist_child->header;
		linkedlist_parent->tail = linkedlist_child->tail;
	}
	linkedlist_child->header = linkedlist_child->tail = 0;
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
	ListNode* pointerNode = linkedlist->header;
	if (pointerNode == 0) {
		return;
	}
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
	arrayOfLinkedList = new LinkedList* [200000];
	for(int i = 0; i < 200000; i++) {
    	arrayOfLinkedList[i] = new LinkedList();
    	//arrayOfLinkedList[i]->header = arrayOfLinkedList[i]->tail = new ListNode();
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		scanf("%d %d", &vali, &valj);
		if (cmd[0] == 'N') {
			insertLast(arrayOfLinkedList[valj-1], vali);
			print_list(arrayOfLinkedList[valj-1]);
			printf("-------------\n");
		}
		else if (cmd[0] == 'M') {
			move(arrayOfLinkedList[vali-1],arrayOfLinkedList[valj-1]);
			print_list(arrayOfLinkedList[valj-1]);
			printf("-------------\n");
		}

	}
	for(int i = 0; i < 200000; i++) {
		print_list(arrayOfLinkedList[i]);
	}

	//print_list(list);
}