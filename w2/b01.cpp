/*
LANG: C++
TASK: cyclingchars
*/

#include <cstdio>
main(){
	char st[101];
	scanf("%s", st);
	for (int i =0; st[i] != '\0' ;i++){
		st[i] += 4;
		if(st[i] > 'z')
			st[i] -= 26;
	}
	printf("%s", st);
}