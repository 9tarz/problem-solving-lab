#include <cstdio>

struct ListNode {
	ListNode* next;
	int value;
	ListNode (int v, ListNode* n = 0)
		:value(v), next(n)
  	{}
};

void print_list(ListNode* list) {
  while(list != 0) {
    printf("%d\n", list->value);
    list = list->next;
  }
}

main() {
	int n,val,count;
	char cmd[2];
	ListNode* header = new ListNode(0);
	scanf("%d", &n);
	count = 0;
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		scanf("%d", &val);
		if (cmd[0] == 'I') {
			ListNode* new_node = new ListNode(val);
			new_node->next = header->next;
			header->next = new_node;
			count++;
		}
		else if (cmd[0] == 'D') {

			ListNode* current_node = header;
			ListNode* next_node;
			if (val <= count) {
				for(int j = 0; j < val; j++) {
					if(j == val - 1)
						next_node = current_node->next;
					else if(j != val - 1)
						current_node = current_node->next;
				}
				current_node->next = next_node->next;
				delete next_node;
				count--;
			}
		}

	}

	print_list(header->next);
}