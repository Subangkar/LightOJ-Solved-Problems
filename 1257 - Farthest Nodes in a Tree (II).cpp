//
// Created by Subangkar on 26-Nov-19.
//

//
// Created by Subangkar on 26-Nov-19.
//

// C++ program to print DFS traversal from
// a given vertex in a given graph
#include<bits/stdc++.h>

using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
	int V; // No. of vertices

	// Pointer to an array containing
	// adjacency lists
	list<pair<int, int>> *adj;
//	vector<int> *cost;

	// A recursive function used by DFS
	int DFSUtil(int v, bool visited[], int cost_from_root, int cost[], int &max_cost_from_root, int &farthest_node);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	int DFS(int v, int maxCost[]);

	~Graph() {
		delete[] adj;
//		delete[] cost;
	}
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w)); // Add u to v’s list.
	adj[v].push_back(make_pair(u, w)); // Add u to v’s list.
//	cost[u][v] = cost[v][u] = w;
}

int Graph::DFSUtil(int v, bool visited[], int cost_from_root, int cost[], int &max_cost_from_root, int &farthest_node) {
	visited[v] = true;
//	cout << v << " ";
	if (cost_from_root > max_cost_from_root) {
		max_cost_from_root = cost_from_root;
		farthest_node = v;
	}

	for (auto i:adj[v])
		if (!visited[i.first]) {
			cost[i.first] = cost_from_root + i.second;
			DFSUtil(i.first, visited, cost_from_root + i.second, cost, max_cost_from_root, farthest_node) + i.second;
		}
	return 0;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
int Graph::DFS(int v, int maxCost[]) {
	int cost1[V], cost2[V], tmp[V], t = -1;
	bool visited[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		cost1[i] = cost2[i] = 0;
	}
	int max_cost_from_root = 0, max_cost_from_far1 = 0, max_cost_from_far2 = 0;
	int far1 = -1, far2 = -1;
	DFSUtil(v, visited, 0, tmp, max_cost_from_root, far1);// src->far1
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	DFSUtil(far1, visited, 0, cost1, max_cost_from_far1, far2);// far1->far2
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	DFSUtil(far2, visited, 0, cost2, max_cost_from_far2, t);// far2->far1
//	cout << far1 << " " << far2 << " " << t;
	for (int i = 0; i < V; i++)
		maxCost[i] = max(cost1[i], cost2[i]);
	return 0;
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
		int n;
//		cin >> n;
		scanf("%d", &n);
		Graph g(n);
		int maxCost[n];
		for (int i = 0; i < n - 1; ++i) {
			int u, v, w;
//			cin >> u >> v >> w;
			scanf("%d %d %d", &u, &v, &w);
			g.addEdge(u, v, w);
//			g.addEdge(v, u, w);
		}
		g.DFS(0, maxCost);
//		cout << "Case " << t << ":" << endl;
		printf("Case %d:\n", t);
		for (int j = 0; j < n; ++j) {
//			cout << maxCost[j] << endl;
			printf("%d\n", maxCost[j]);
		}
	}
	return 0;
}

