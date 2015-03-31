#include <cstdio>
#include <algorithm>
using namespace std;

main() {
	int dest, buffer;
	int i = 0;
	int list_war[1000];
	scanf("%d", &dest);
	scanf("%d", &buffer);
	list_war[i] = buffer;
	while(buffer != 0) {
		i++;
		scanf("%d", &buffer);
		list_war[i] = buffer;
	}
	char out[1000];
	int k = 0;
	int chk = 0;
	sort(list_war, list_war + i);
	for (int j = 2558; j < 3000; j++) {
		if (list_war[k] == j) {
			k++;
			continue;
		}
		else if (chk == 0) {
			out[3000-j] = 'K';
			chk = 1;
		}
		else if (chk == 1) {
			out[3000-j] = 'C';
			chk = 0;
		}

	}
	printf("%c\n", out[3000-dest]);
}
