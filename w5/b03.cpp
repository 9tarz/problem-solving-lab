#include <cstdio>
#include <map>

using namespace std;

main () {
	int n, cmd, a, b;
	map<int, int> stock;

	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++) {
		scanf("%d",&cmd);
		if (cmd == 1) {
			scanf("%d %d", &a, &b);
			stock[a] += b;

		}
		else if (cmd == 2) {
			scanf("%d", &a);
			printf("%d\n",stock.find(a)->second);

		}
		else if (cmd == 3) {
			scanf("%d %d", &a, &b);
			if ( b <= stock.find(a)->second ){
				printf("%d\n", b);
				stock.find(a)->second -= b ;
      		}
			else {
				printf("%d\n",stock.find(a)->second);
				stock.find(a)->second = 0 ;
			}

		}
		else {
			printf("command error\n");
		}

	}
}