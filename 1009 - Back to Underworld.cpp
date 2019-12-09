//
// Created by Subangkar on 26-Nov-19.
//

// C++ implementation of modified BFS
#include<bits/stdc++.h>

using namespace std;

typedef int color_t;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
}

// A utility function to do BFS of graph
// from a given vertex u.
void BFSUtil(int u, vector<int> adj[],
             vector<bool> &visited, int &max_part_size) {
	vector<color_t> color = vector<color_t>(visited.size(), -1);
	int color_count[2] = {0, 0};
	// Create a queue for BFS
	list<int> q;

	// Mark the current node as visited and enqueue it
	visited[u] = true;
	color[u] = 0;
	++color_count[color[u]];
	q.push_back(u);

	// 'i' will be used to get all adjacent vertices 4
	// of a vertex list<int>::iterator i;

	while (!q.empty()) {
		// Dequeue a vertex from queue and print it
		u = q.front();
//		cout << u << " ";
		q.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int i = 0; i != adj[u].size(); ++i) {
			if (!visited[adj[u][i]]) {
				int v = adj[u][i];
				visited[v] = true;
				color[v] = !color[u];
				++color_count[color[v]];
				q.push_back(adj[u][i]);
			}
		}
	}
	max_part_size = max(color_count[0], color_count[1]);
}

// This function does BFSUtil() for all
// unvisited vertices.
int BFS(vector<int> adj[], int V, vector<bool> &is_present) {
	vector<bool> visited(V + 1, false);
	int max_comp_size = 0;
	for (int u = 1; u <= V; u++)
		if (visited[u] == false && is_present[u]) {
			int max_part_size = 0;
			BFSUtil(u, adj, visited, max_part_size);
//			cout << ">" << max_part_size << endl;
			max_comp_size += max_part_size;
		}
	return max_comp_size;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int t, tc, x;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int m;
		int V = 0;
		cin >> m;
		vector<int> adj[100000 + 1];
		vector<bool> is_present = vector<bool>(100000 + 1, false);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			is_present[u] = is_present[v] = true;
			V = max(V, max(u, v));
			addEdge(adj, u, v);
			addEdge(adj, v, u);
		}

		cout << "Case " << t << ": " << BFS(adj, V, is_present) << endl;
	}
	return 0;
}
