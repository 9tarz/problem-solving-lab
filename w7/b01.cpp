#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 100000

int n,m;

vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input();
void init();
void dfs(int u);


void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0 ;i < m ; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
}

bool visited[MAX_N];

void init() {
	for (int i =0;i<n;i++)
		visited[i] = false;
}

void dfs(int u) {
	visited[u] = true;
	for(int i = 0;i < deg[u];i++) {
		int v = adj[u][i];
		if(!visited[v]) {
			dfs(v);
		}
	}
}

main () {
	read_input();
	init();
	int connected_component = 0;
	for(int i = 0; i < n; i++ ) {
		if ( visited[i] == false) {
			dfs(i);
			connected_component += 1;
		}
	}
	printf("%d", connected_component);
}

