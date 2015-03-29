#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

main() {

	map<int, int> status;
	int n, result, like;	
	int max = -1;

	scanf("%d",&n);

	for (int i = 0 ; i < n ; i++) {

		scanf("%d",&like);

		status[like] += 1 ;
		if (status[like] > max) {
			max = status[like];
			result = like ;
		}
		else if (status[like] == max) {
			result = like ;
		}

		printf("%d\n",result);
	}
}