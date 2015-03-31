#include <cstdio>
#include <algorithm>
using namespace std;

main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int table[n], dice[m];
	int pointer = 0;
	for (int i =0 ; i < n; i++) {
		scanf("%d", &table[i]);
	}
	for (int i =0 ; i < m; i++) {
		scanf("%d", &dice[i]);
		pointer += dice[i];
		if(table[pointer -1 ] > 0) {
			pointer += table[pointer -1];
		}
		else if ((table[pointer -1] < 0)) {
			pointer += table[pointer - 1];
		}
	}
	if (pointer >= n)
		printf("%d\n", n);
	else if (pointer <= 0)
		printf("0\n");
	else 
		printf("%d\n", pointer);

}