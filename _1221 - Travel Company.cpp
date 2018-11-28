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







/* Define Infinite as a large enough value. This value will be used
for vertices not connected to each other */
#define INFINITY 999999999

// Input a graph Matrix  && 0 indexed @ O(V^3)
class AllPairShortest
{

public:

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



	int** dist = NULL;
	int** p = NULL;
	int** graph = NULL;

	int V = 0;

	/* dist[][] will be the output matrix that will finally have the shortest
	distances between every pair of vertices */
	void floydWarshall()
	{
		dist = new2D<int>(V, V, INFINITY);
		p = new2D<int>(V, V, INFINITY);

		copy2D(dist, graph, V, V);

		int u, v, k;
		for (k = 0; k < V; k++)
		{
			for (u = 0; u < V; u++)
			{
				for (v = 0; v < V; v++)
				{
					if (dist[u][k] + dist[k][v] < dist[u][v]) {
						dist[u][v] = dist[u][k] + dist[k][v];
						p[u][v] = p[k][v];
					}
				}
			}
		}

	}

	bool hasNegCycle() {
		for (int u = 0; u < V; u++)
		{
			if (dist[u][u] < 0)
				return true;
		}
		return false;
	}


	void printSolution()
	{
		printf("Following matrix shows the shortest distances"
			" between every pair of vertices \n");
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][j] == INFINITY)
					printf("%7s", "INF");
				else
					printf("%7d", dist[i][j]);
			}
			printf("\n");
		}
	}


	AllPairShortest(int** g, int n)
	{
		graph = g;
		V = n;
	}

	~AllPairShortest()
	{
		delete2D<int>(dist, V);
		delete2D<int>(p, V);
	}
};




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
		int pr = 0;
		cin >> V >> E >> pr;


		int** g = new2D<int>(V, V, INFINITY);
		//print2D(g, V, V);

		for (int i = 0; i < E; i++)
		{
			int u, v, w, p, c;
			cin >> u >> v >> p >> c;

			w = pr*c - p;
			g[u][v] = w;
		}

		AllPairShortest alp(g, V);
		alp.floydWarshall();
		//alp.printSolution();
		cout << "Case " << cs << ": " << (alp.hasNegCycle() ? "YES" : "NO") << endl;

		delete2D<int>(g, V);
	}

	return 0;
}
