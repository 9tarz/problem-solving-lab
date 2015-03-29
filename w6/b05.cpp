#include <cstdio>

main() {

	int n,m,id,val,sum;
	sum = 0;
	int score[100];

	scanf("%d %d", &n, &m);
	for (int i =0; i < n; i++) {
		score[i] = 501;
	}
	for (int i = 0; i < m;i++) {
		scanf("%d %d", &id, &val);
		if (val < score[id-1]) 
			score[id-1] = val;
	}
	for (int i =0; i < n; i++) {
		sum += score[i];
	}
	printf("%d\n",sum);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n",i+1,score[i]);
	}

}