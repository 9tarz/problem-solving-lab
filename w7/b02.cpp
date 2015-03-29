#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100000

vector<int> adj[MAX_N];
int deg[MAX_N], particion[MAX_N];
bool visited[MAX_N];

bool bfs(int u) {
	queue<int> Q;
	Q.push(u);
	visited[u] = true;
	particion[u] = 1;

	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int i = 0;i < deg[u];i++) {
			int v = adj[u][i];
			if (particion[u] == particion[v]) {
				return false;
			}
			if(!visited[v]) {
				visited[v] = true;
				particion[v] = 3 - particion[u];
				Q.push(v);
			}
		}
	}
	return true;
}


main () {
	int k;
	scanf("%d", &k);
	for (int j =0 ;j < k ;j++) {

		int n,m;
		bool chk = false;

		scanf("%d %d", &n, &m);
		for (int i = 0 ;i < m ; i++) {
			int u, v;
			scanf("%d %d", &u, &v); u--; v--;
			adj[u].push_back(v); adj[v].push_back(u);
			deg[u]++; deg[v]++;
		}
		for (int i =0;i<n;i++)
			visited[i] = false;

		for(int i = 0; i < n; i++ ) {
			if ( visited[i] == false && !bfs(i)) {
				printf("no\n");
				chk = true;
				break;
			}
		}
		if (chk == false)
			printf("yes\n");

		for (int i =0; i<n;i++) {
			deg[i] = 0;
			particion[i] = 0;
			adj[i].clear();
		}
	}
}


