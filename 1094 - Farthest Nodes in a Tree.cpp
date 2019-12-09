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
	int DFSUtil(int v, bool visited[], int cost_from_root, int cost_to_leaf[][2]);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	int DFS(int v);

	~Graph() {
		delete[] adj;
//		delete[] cost;
	}
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<pair<int, int>>[V];
//	cost = new vector<int>[V];
//	for (int i = 0; i < V; ++i) {
//		cost[i] = vector<int>(V, 0);
//	}
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w)); // Add u to v’s list.
//	cost[u][v] = cost[v][u] = w;
}

int Graph::DFSUtil(int v, bool visited[], int cost_from_root, int cost_to_leaf[][2]) {
	// Mark the current node as visited and
	// print it
	visited[v] = true;
//	cout << v << " ";

	cost_to_leaf[v][0] = cost_from_root;

	// Recur for all the vertices adjacent
	// to this vertex
//	list<int>::iterator i;
	int max_cost_from_leaf = 0;
//	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	for (auto i:adj[v])
		if (!visited[i.first]) {
			int cost_from_leaf = DFSUtil(i.first, visited, cost_from_root + i.second, cost_to_leaf) + i.second;
			if (cost_from_leaf > cost_to_leaf[v][1]) {
				if (cost_from_leaf > cost_to_leaf[v][0]) {
					cost_to_leaf[v][1] = cost_to_leaf[v][0];
					cost_to_leaf[v][0] = cost_from_leaf;
				} else {
					cost_to_leaf[v][1] = cost_from_leaf;
				}
			}
			max_cost_from_leaf = max(max_cost_from_leaf, cost_from_leaf);
		}
	return max_cost_from_leaf;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
int Graph::DFS(int v) {
	// Mark all the vertices as not visited
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
//	auto cost_to_leaf = vector<vector<int>>(V, vector<int>(2, 0));// 2max of cost_from_root & cost_to_leaves_not_thru_root
	int cost_to_leaf[V][2];
	for (int i = 0; i < V; i++)
		cost_to_leaf[i][0] = cost_to_leaf[i][1] = 0;
	// Call the recursive helper function
	// to print DFS traversal
	int max_cost = 0;
	DFSUtil(v, visited, 0, cost_to_leaf);
	for (int i = 0; i < V; i++)
		max_cost = max(max_cost, cost_to_leaf[i][0] + cost_to_leaf[i][1]);
	return max_cost;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc, x;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		Graph g(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			g.addEdge(u, v, w);
			g.addEdge(v, u, w);
		}
		cout << "Case " << t << ": " << g.DFS(0) << endl;
	}
	return 0;
}

