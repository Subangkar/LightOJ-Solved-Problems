#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

typedef long long ll;




using namespace std;


#define pb push_back
#define pp pop
#define ins insert
#define rmv remove


#define FILE_INP freopen("in.txt","r",stdin)
#define FILE_OUT freopen("out.txt","w",stdout)

#define forL(i,start,end) for(i=start;i<end;i++)





template<typename T>
T ** new2D(size_t max_r, size_t max_c, T initVal)
{
	T** mat = new T*[max_r];
	for (size_t i = 0; i < max_r; i++)
	{
		mat[i] = new T[max_c];
		//memset(mat[i], (T)initVal, max_c * sizeof(T));
		for (int j = 0; j < max_c; j++)
		{
			mat[i][j] = initVal;
		}
	}
	return mat;
}

template<typename T>
void delete2D(T ** mat, size_t max_r)
{
	for (size_t i = 0; i < max_r; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}



template<typename T>
void print2D(T ** mat, size_t max_r, size_t max_c)
{
	for (size_t i = 0; i < max_r; i++)
	{
		for (int j = 0; j < max_c; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


template<typename T>
void set2D(T ** mat, size_t max_r, size_t max_c, T Val)
{
	for (size_t i = 0; i < max_r; i++)
	{
		for (int j = 0; j < max_c; j++)
		{
			mat[i][j] = Val;
		}
	}
}







#define INFINITY 9999999

struct Edge
{
	int u = EOF, v = EOF, w = NULL;
};


struct Graph
{
	int V = 0, E = 0;
	struct Edge* edge = NULL;
	void addEdge(int u, int v, int w) {
		edge[curEdges].u = u;
		edge[curEdges].v = v;
		edge[curEdges].w = w;

		curEdges++;
	}

private:
	int curEdges = 0;
};


// Graph with 0 indexing
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void deleteGraph(Graph* g)
{
	delete[] g->edge;
	delete g;
}


// need to initialize dist with size=V & dist[u] represents min_dist(src,u)
bool BellmanFord(Graph* graph, int src, int dist[])
{
	int V = graph->V;
	int E = graph->E;

	for (int i = 0; i < V; i++)
		dist[i] = INFINITY;
	dist[src] = 0;

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].u;
			int v = graph->edge[j].v;
			int w = graph->edge[j].w;
			if (dist[u] != INFINITY && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].u;
		int v = graph->edge[i].v;
		int w = graph->edge[i].w;
		if (dist[u] != INFINITY && dist[u] + w < dist[v])
			return false;
	}
	return true;
}



int main()
{
	//FILE_INP;
	//FILE_OUT;



	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;

		int V = 5;  // Number of vertices in graph
		int E = 8;  // Number of edges in graph
		cin >> V >> E;

		Graph* g = createGraph(V, 2*E);
		for (int i = 0; i < E; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u -= 1; v -= 1;
			g->addEdge(u, v, w);
			g->addEdge(v, u, w);
		}
		int* dist = new int[V];
		int s = 0, d = V-1;

		BellmanFord(g, s, dist);
		if (dist[d] < INFINITY) {
			cout << "Case " << cs << ": " << dist[d] << endl;
		}
		else
		{
			cout << "Case " << cs << ": " << "Impossible" << endl;
		}
		delete[] dist;
		deleteGraph(g);
	}

	return 0;
}
