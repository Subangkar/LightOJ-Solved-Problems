//
// Created by Subangkar on 04-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1000
#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

void addEdge(list<int> adj[], int u, int v) {
	adj[u].push_back(v); // Add v to u’s list.
}

void DFSUtil(list<int> adj[], int u, bool visited[], int indepSetSize_inc[], int indepSetSize_exc[]) {
	visited[u] = true;
	indepSetSize_inc[u] = 1;
	indepSetSize_exc[u] = 0;

	for (auto &v:adj[u]) {
		if (!visited[v]) {
			DFSUtil(adj, v, visited, indepSetSize_inc, indepSetSize_exc);
			indepSetSize_inc[u] += indepSetSize_exc[v];
			indepSetSize_exc[u] += max(indepSetSize_inc[v], indepSetSize_exc[v]);
		}
	}
}

int DFS(list<int> adj[], int n) {
	int V = n + 1;
	bool visited[V];
	int indepSetSize_inc_this[V], indepSetSize_exc_this[V];
	memCLR(visited, V, false);

	int maxS = 0;
	for (int u = 1; u <= n; ++u) {
		if (!visited[u]) {
			DFSUtil(adj, u, visited, indepSetSize_inc_this, indepSetSize_exc_this);
			maxS += max(indepSetSize_inc_this[u], indepSetSize_exc_this[u]);
		}
	}
	return maxS;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc, x;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;
//		vector<int> adj[N_MAX + 1];
		list<int> adj[n + 1];
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			addEdge(adj, u, v);
			addEdge(adj, v, u);
		}

		cout << "Case " << t << ": " << DFS(adj, n) << endl;
	}
	return 0;
}
