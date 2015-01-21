/*
LANG: C++
TASK: gifts
*/

#include <stdio.h>
main() {
	int x[1000],n;
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	for(int i = 0; i < n; i++){
		if (x[i] > 0 )
			sum += x[i];
		else 
			sum += 0;
	}
	printf("%d", sum);
}