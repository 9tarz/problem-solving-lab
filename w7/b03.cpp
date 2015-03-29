#include <cstdio>
#include <queue>
#include <math.h>   
using namespace std;

struct Point {
	int X;
	int Y;
	Point (int x, int y)
		:X(x), Y(y)
  	{}
};

main() {

	int n,m,chk = 0;
	scanf("%d %d", &n, &m);
	char map[n][m], new_map[n][m], buffer[m], visited[n][m];
	for(int i = 0; i < n; i++) {
		scanf("%s",buffer);
		for (int j = 0; j < m; j++) {
			map[i][j] = buffer[j];
		}
	}
	for(int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			if (map[i][j] == '.' && map[i][j+1] == '.' && map[i+1][j] == '.' && map[i+1][j+1] == '.')
				new_map[i][j] = '.';
			else 
				new_map[i][j] = 'x';
		}
	}

	for(int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			visited[i][j] = new_map[i][j];
		}
	}

	for (int j = 0; j < m-1; j++) {
		if (visited[0][j] == 'x')
			continue; 
		queue<Point*> Q;
		Point* u = new Point (0,j);
		Point* v;
		Q.push(u);
		visited[0][j] = 'x';
		while(!Q.empty()) {
			u = Q.front();
			if (u->X == n - 2) {
				chk = 1;
				break;
			}
			Q.pop();
			if(visited[u->X][u->Y -1] == '.') {
				//printf("u = %d ", u);
				//printf("%d %d \n",u/10 %10, u%10 -1);
				visited[u->X][u->Y -1] = 'x';
				v = new Point (u->X, u->Y - 1);
				Q.push(v);
			}
			if(visited[u->X][u->Y  + 1] == '.') {
				//printf("u = %d ", u);
				//printf("%d %d\n",u/10 %10 , u%10 + 1);
				visited[u->X][u->Y +1] = 'x';
				v = new Point (u->X, u->Y + 1);
				Q.push(v);
			}
			if(visited[u->X - 1][u->Y] == '.') {
				//printf("u = %d ", u);
				//printf("%d %d\n",u/10 %10 - 1, u%10 );
				visited[u->X - 1][u->Y] = 'x';
				v = new Point (u->X - 1, u->Y);
				Q.push(v);
			}
			if(visited[u->X + 1][u->Y] == '.') {
				//printf("u = %d ", u);
				//printf("%d %d\n", u/10 %10 + 1, u%10);
				visited[u->X + 1][u->Y] = 'x';
				v = new Point (u->X + 1, u->Y);
				Q.push(v);
			}
			
		}
		for(int i = 1; i < n-1; i++) {
			for (int j = 0; j < m-1; j++) {
				visited[i][j] = new_map[i][j];
			}
		}
	}
	if (chk == 0) 
		printf("no\n");
	else
		printf("yes\n");

}