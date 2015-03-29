#include <list>
#include <cstdio>
#include <string>

using namespace std;
 
list<string> lst;
 
void print_list(list<string>& lst) {
	list<string>::const_iterator i = lst.begin();
	while(i != lst.end()) {
		printf("%s ", i->c_str());
		i++;
	}
}

main() {

	int n;
	scanf("%d",&n);
	char buffer[11],cmd[2];
	list<string>::iterator pointer = lst.begin();

	for(int i = 0; i <n ;i++) {
		scanf("%s",cmd);
		if(cmd[0] == 'i') {
			scanf("%s",buffer);
			lst.insert(pointer, buffer);
		}
		else if (cmd[0] == 'l') {
			if (pointer != lst.begin())
				pointer--;
		}
		else if (cmd[0] == 'r') {
			if (pointer != lst.end())
				pointer++;
		}
		else if (cmd[0] == 'b') {
			if (pointer != lst.begin())
				pointer = lst.erase(--pointer);
		}
		else if (cmd[0] == 'd') {
			if (pointer != lst.end())
				pointer = lst.erase(pointer);
		}
	}	
	print_list(lst);
}