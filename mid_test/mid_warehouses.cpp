#include <cstdio>
#include <algorithm>
using namespace std;

main() {
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	int a[n], b[n];
	int s[n], t[n];
	for(int i = 0; i < m;i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for(int i = 0; i < k;i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
}