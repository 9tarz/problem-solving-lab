/*
LANG: C++
TASK: upperall
*/

#include <cstdio>
main(){
	char st[101];
	scanf("%s", st);
	for (int i =0; st[i] != '\0' ;i++){
		if(st[i] >= 96)
			st[i] -= 32;
		if(st[i] > 'z')
			st[i] -= 26;
	}
	printf("%s", st);
}