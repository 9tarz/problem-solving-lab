/*
LANG: C++
TASK: strrev
*/

#include <stdio.h>

main() {
	char st[1001],out[1001];
	int count;
	count = 0;
	char tmp;
	scanf("%s", st);
	for (int i =0; st[i] != '\0' ;i++){
		count++;
	}
	for (int i = 1; i <= count ; i++){
		tmp = st[count - i];
		out[i] = tmp;
	}
	for (int i = 1; i <= count ; i++){
		printf("%c", out[i]);
	}
}