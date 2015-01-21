/*
LANG: C++
TASK: plusminus
*/

#include <stdio.h>
main(){
	int n,sum,b;
	scanf("%d", &n);
	char a[5];
	scanf("%d", &sum);
	for (int i = 0; i < n - 1 ; i++){
		scanf("%s%d",a,&b);
		if (a[0] == '+'){
			sum += b;
		}
		else if (a[0] == '-'){
			sum -= b;
		}
	}
	printf("%d", sum);
}