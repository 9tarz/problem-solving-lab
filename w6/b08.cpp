#include <cstdio>

main() {
	int n, r, s, t, j;
	scanf("%d %d %d", &r, &s, &t);
	scanf("%d", &n);
	for(int i = 0; i < n ;i++) {
		scanf("%d", &j);
		if (j <= r) printf("no\n");
		else {
			j -= r;
			j = j % (s + t);
			if (j <= s)
				printf("yes\n");
			else if ( j > s && j <= s+t )
				printf("no\n");
		}
	}
}