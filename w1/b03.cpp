/*
LANG: C++
TASK: buythemall
*/

#include <stdio.h>
#include <math.h>

main() {
	int p[3],n,t[1000],s[3];
	s[0] = s[1] = s[2] = 0;
	for(int i = 0; i < 3 ;i++){
		scanf("%d", &p[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < n ;i++){
		scanf("%d", &t[i]);
	}
	for(int i = 0; i < n ;i++){
		if(t[i] == 1)
			s[0]++;
		else if(t[i] == 2)
			s[1]++;
		else if(t[i] == 3)
			s[2]++;
	}
	s[0] = s[0]*p[0];
	s[1] = s[1]*p[1];
	s[2] = s[2]*p[2];
	int temp = fmin(s[0],s[1]);
	temp = fmin(temp,s[2]);
	printf("%d", temp);
}