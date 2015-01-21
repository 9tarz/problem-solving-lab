/*
LANG: C++
TASK: wordrev
*/

#include <cstdio>

main() {
	char buff[1001],out[1001];
	scanf("%s", buff);
	for (int i = 0; i < 1000 ; i++){
		out[i] = '*';
	}
	int c = 0,stlen = 0 ;
	for (int i =0; buff[i] != '\0' ;i++){
		stlen++;
	}
	for(int i = 0 ; i <= stlen ;i++) {
		if(buff[i] == '_' || buff[i] == '\0'){
			for (int j = 0 ; j < c ; j++){
				out[i - c + j] = buff[i - j - 1];
			}
			out[i] = '_';
			i++;
			c = 0;
		}
		c++;
	}
	for (int i = 0; i < stlen  ; i++){
		printf("%c", out[i]);
	}
}