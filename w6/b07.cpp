#include <cstdio>

main() {
	int n, x, y, r, delta, min;
	min = 10000000;
	scanf("%d", &n);
	for(int i = 0; i < n ;i++) {
		scanf("%d %d %d", &x, &y, &r);
		if (y >= 0) delta = y - r;
		else if (y < 0) delta = -(y + r);

		if (delta <= 0) delta = -1;
		if (delta < min) min = delta;
	}
	printf ("%d\n", min);
}