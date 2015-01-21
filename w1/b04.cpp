/*
LANG: C++
TASK: darts
*/

#include <stdio.h>
#include <math.h>

main() {
	int n,score;
	float x,y;
	score = 0;
	double sum;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%f %f", &x , &y);
		sum = sqrt(x*x + y*y);
		if (sum <= 2)
			score += 5;
		else if (sum <= 4)
			score += 4;
		else if (sum <= 6)
			score += 3;
		else if (sum <= 8)
			score += 2;
		else if (sum <= 10)
			score += 1;
	}
	printf("%d", score);
}