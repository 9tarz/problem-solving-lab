#include <cstdio>

main() {
	int n,m;
	scanf("%d %d", &n, &m);
	char buffer[n];
	char map[n][n];
	char cmd[2];
	int val;
	for(int i = 0; i< n ;i++) {
		scanf("%s", buffer);
		for (int j = 0; j <n; j++) {
			map[i][j] = buffer[j];
		}
	}
	for(int i =0; i < m ;i++) {

		scanf("%s",cmd);
		scanf("%d",&val);

		if (cmd[0] == 'L') {
			for(int j = 0; j < n ;j++) {
				if(map[val-1][j] == 'x') {
					map[val-1][j] = '.';
				}
				else if (map[val-1][j] == '.' || map[val-1][j] == '#') {
					break;
				}
			}
		}
		else if (cmd[0] == 'R') {
			for(int j = n-1; j >= 0 ;j--) {
				if(map[val-1][j] == 'x') {
					map[val-1][j] = '.';
				}
				else if (map[val-1][j] == '.' || map[val-1][j] == '#') {
					break;
				}
			}

		}
		else if (cmd[0] == 'U') {
			for(int i = 0; i < n ;i++) {
				if(map[i][val-1] == 'x') {
					map[i][val-1] = '.';
				}
				else if (map[i][val-1] == '.' || map[i][val-1] == '#') {
					break;
				}
			}

		}
		else if (cmd[0] == 'D') {
			for(int i = n-1; i >= 0 ;i--) {
				if(map[i][val-1] == 'x') {
					map[i][val-1] = '.';
				}
				else if (map[i][val-1] == '.' || map[i][val-1] == '#') {
					break;
				}
			}

		}
		else if (cmd[0] == 'A') {
			for(int j = 0; j < n ;j++) {
				if(map[val-1][j] == '.') {
					map[val-1][j] = 'x';
				}
				else if (map[val-1][j] == '#') {
					continue;
				}
			}
		}
		else if (cmd[0] == 'B') {
			for(int i = 0; i < n ;i++) {
				if(map[i][val-1] == '.') {
					map[i][val-1] = 'x';
				}
				else if (map[i][val-1] ==  '#') {
					continue;
				}
			}

		}

	}
	for (int i =0; i< n ;i++) {
		for (int j =0 ;j < n ; j++) {
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
