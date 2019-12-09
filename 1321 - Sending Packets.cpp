//
// Created by Subangkar on 29-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, double> edge;

void addEdge(vector<edge> adj[], int u, int v, double wt) {
	adj[u].emplace_back(v, wt);
	adj[v].emplace_back(u, wt);
}


void shortestPath(vector<edge> adj[], int V, int src, double dist[]) {
	priority_queue<pair<double, int>> pq;

	for (int i = 0; i < V; ++i) dist[i] = 0.0;

	pq.push(make_pair(1.0, src));
	dist[src] = 1.0;

	while (!pq.empty()) {
		// sorted distance (distance must be first item
		// in pair)
		auto u = pq.top().second;
		pq.pop();

		for (auto x : adj[u]) {
			auto v = x.first;
			auto weight = x.second;

			if (dist[v] < dist[u] * weight) {
				dist[v] = dist[u] * weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

//	// Print shortest distances stored in dist[]
//	printf("Vertex Distance from Source\n");
//	for (int i = 0; i < V; ++i)
//		printf("%d \t\t %lf\n", i, dist[i]);
}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

	double dist[100];
//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n, m, s, k;
		scanf("%d %d %d %d", &n, &m, &s, &k);
		vector<edge> adj[n];
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			addEdge(adj, u, v, w / 100.0);
		}

		shortestPath(adj, n, 0, dist);
		double e = 2 * k / dist[n - 1];// E = p*2K + (1-p)*(2K+E)
		printf("Case %d: %lf\n", t, s * e);
	}
	return 0;
}
