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
T ** new2D(size_t max_r, size_t max_c, T** initMat)
{
	T** mat = new T*[max_r];
	for (size_t i = 0; i < max_r; i++)
	{
		mat[i] = new T[max_c];
		//memset(mat[i], (T)initVal, max_c * sizeof(T));
		for (int j = 0; j < max_c; j++)
		{
			mat[i][j] = initMat[i][j];
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


template<typename T>
void copy2D(T ** dest, T** src, size_t max_r, size_t max_c)
{
	for (size_t i = 0; i < max_r; i++)
	{
		for (int j = 0; j < max_c; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}



#define INFINITY 99999999



class Ford_Fulkerson
{
public:

	/* Returns true if there is a path from source 's' to sink 't' in
	residual graph. Also fills parent[] to store the path */
	static int bfs(int** rGraph, int V, int s, int t, int parent[])
	{
		// Create a visited array and mark all vertices as not visited
		bool visited[V];
		memset(visited, 0, sizeof(visited));

		queue <int> q;
		q.push(s);
		visited[s] = true;
		parent[s] = -1;

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int v = 0; v < V; v++)
			{
				if (visited[v] == false && rGraph[u][v] > 0)
				{
					q.push(v);
					parent[v] = u;
					visited[v] = true;
				}
			}
		}

		// If we reached sink in BFS starting from source, then return
		// true, else false
		return (visited[t] == true);
	}

	// A DFS based function to find all reachable vertices from s.  The function
	// marks visited[i] as true if i is reachable from s.  The initial values in
	// visited[] must be false. We can also use BFS to find reachable vertices
	static void dfs(int** rGraph, int V, int s, bool visited[])
	{
		visited[s] = true;
		for (int i = 0; i < V; i++)
			if (rGraph[s][i] && !visited[i])
				dfs(rGraph, V, i, visited);
	}

	// Returns the maximum flow from s to t in the given graph
	// with main Input Graph having no antiparallel edges
	// if (u,v) is not an edge then g[u][v]=0
	static int maxFlowValue(int** graph, int V, int s, int t)
	{

		// Create a residual graph and fill the residual graph with
		// given capacities in the original graph as residual capacities
		// in residual graph
		int** rGraph = new2D<int>(V, V, graph); // Residual graph where rGraph[i][j] indicates 
												// residual capacity of edge from i to j (if there
												// is an edge. If rGraph[i][j] is 0, then there is not)  

		int parent[V];  // This array is filled by BFS and to store path

		int max_flow = 0;  // There is no flow initially

						   // Augment the flow while tere is path from source to sink
		while (bfs(rGraph, V, s, t, parent))
		{
			int u, v;
			// Find minimum residual capacity of the edges along the
			// path filled by BFS. Or we can say find the maximum flow
			// through the path found.
			int path_flow = INFINITY;
			for (v = t; v != s; v = parent[v])
			{
				u = parent[v];
				path_flow = min(path_flow, rGraph[u][v]);
			}

			// update residual capacities of the edges and reverse edges
			// along the path
			for (v = t; v != s; v = parent[v])
			{
				u = parent[v];
				rGraph[u][v] -= path_flow;
				rGraph[v][u] += path_flow;
			}

			// Add path flow to overall flow
			max_flow += path_flow;
		}

		delete2D<int>(rGraph, V);
		// Return the overall flow
		return max_flow;
	}


private:
	template<typename T>
	static void copy2D(T ** dest, T** src, size_t max_r, size_t max_c)
	{
		for (size_t i = 0; i < max_r; i++)
		{
			for (int j = 0; j < max_c; j++)
			{
				dest[i][j] = src[i][j];
			}
		}
	}

	template<typename T>
	static T ** new2D(size_t max_r, size_t max_c, T initVal)
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
	static T ** new2D(size_t max_r, size_t max_c, T** initMat)
	{
		T** mat = new T*[max_r];

		for (size_t i = 0; i < max_r; i++)
		{
			mat[i] = new T[max_c];
			//memset(mat[i], (T)initVal, max_c * sizeof(T));
			for (int j = 0; j < max_c; j++)
			{
				mat[i][j] = initMat[i][j];
			}
		}
		return mat;
	}

	template<typename T>
	static void delete2D(T ** mat, size_t max_r)
	{
		for (size_t i = 0; i < max_r; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}

};








// Prob with antiparrallel edge
int main()
{
	//FILE_INP;
	//FILE_OUT;

	//Ford_Fulkerson::mainDemo_maxFlow();

	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;
		int s, t;
		int V,E;
		cin >> V >> s >> t >> E;
		s -= 1; t -= 1;
		int** g = new2D<int>(V, V, (int)0);

		for (int i = 0; i < E; i++)
		{
			int u, v, f;
			cin >> u >> v >> f;
			u -= 1; v -= 1;
			//if(!g[v][u])g[u][v] += f;
			//else g[v][u] += f;
			g[u][v] += f;
			g[v][u] += f;
		}
		//print2D<int>(g, V, V);
		printf("Case %d: %d\n", cs, Ford_Fulkerson::maxFlowValue(g, V, s, t));
		delete2D<int>(g, V);
	}

	return 0;
}
