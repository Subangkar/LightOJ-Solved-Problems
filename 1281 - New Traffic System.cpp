//
// Created by Subangkar on 06-Dec-19.
//

// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>

struct edge_t {
	int v;
	int w;
	bool proposed;

	edge_t(int v, int w, bool proposed) : v(v), w(w), proposed(proposed) {}
};

using namespace std;

#define INF INT32_MAX
#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

#define N_MAX 100
#define M_MAX 100

class Graph {

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list<edge_t> *adj;

public:
	int V; // No. of vertices
//	vector<vector<int>> cost;

	Graph(int V);

	~Graph();

	void addEdge(int u, int v, int w, int p = false);

	// prints shortest path from s
	int dijkstra(int src, int d);

};

// Allocates memory for adjacency list
Graph::Graph(int V) {
	this->V = V;
	adj = new list<edge_t>[V];
//	cost = vector<vector<int>>(V, vector<int>(V, INF));
}

Graph::~Graph() {
	delete[] adj;
}

void Graph::addEdge(int u, int v, int w, int p) {
	adj[u].emplace_back(v, w, p);
}

int Graph::dijkstra(int src, int d) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<> > pq; // min heap // dist, v ,n_used

	vector<vector<int>> dist(d + 1, vector<int>(V, INF));

	pq.push(make_pair(0, make_pair(src, 0)));
	dist[0][src] = 0;

	while (!pq.empty()) {
		int u = pq.top().second.first;
		int nused_u = pq.top().second.second;
//		cout << " > [" << u << "] " << nused_u << "   " << pq.top().first << endl;
		pq.pop();
		if (u == V - 1) return dist[nused_u][u];
		for (const auto &e:adj[u]) {
			auto v = e.v;
			auto w = e.w;
			auto nused_v = nused_u + (e.proposed ? 1 : 0);
			if (nused_v <= d && dist[nused_v][v] > dist[nused_u][u] + w) {// && dist[v] > dist[u] + w
				dist[nused_v][v] = dist[nused_u][u] + w;
//				cout << "      [" << v << "] " << nused_v << "   " << dist[nused_v][v] << endl;
				pq.push(make_pair(dist[nused_v][v], make_pair(v, nused_v)));
			}
		}
	}
//	// Print shortest distances stored in dist[]
//	printf("Vertex Distance from Source\n");
//	for (int i = 0; i < V; ++i)
//		printf("%d \t\t %d\n", i, dist[i]);
	return INF;
}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int64_t n, m, k, d;
		int64_t u, v, w;
//		cin >> n >> k >> s;
		scanf("%lld %lld %lld %lld", &n, &m, &k, &d);

		Graph g(n);
		for (int i = 0; i < m; ++i) {
			scanf("%lld%lld%lld", &u, &v, &w);
			g.addEdge(u, v, w, false);
		}
		for (int i = 0; i < k; ++i) {
			scanf("%lld%lld%lld", &u, &v, &w);
			g.addEdge(u, v, w, true);
		}
		int cost = g.dijkstra(0, d);
		if (cost == INF)
			printf("Case %d: %s\n", t, "Impossible");
		else
			printf("Case %d: %d\n", t, cost);
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
