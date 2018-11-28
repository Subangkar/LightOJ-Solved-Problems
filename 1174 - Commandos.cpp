#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
#include <cstdio>



using namespace std;

#define NULL_VALUE -999999999
#define INFINITY 999999999

#define NIL -1

int min(int x, int y)
{
	return x <= y ? x : y;
}

int max(int x, int y)
{
	return x >= y ? x : y;
}

void PrintTable(int T[][101], int r, int c)
{
	cout << "     ";
	for (int j = 0; j < c; j++)
	{
		//cout << " " << j << " " << "--";
		printf("%10d", j);
	}
	cout << endl << endl;
	for (int i = 0; i < r; i++)
	{
		cout << i << " :  ";
		for (int j = 0; j < c; j++)
		{
			if (T[i][j] != INFINITY && T[i][j] != NIL)
				printf("%10d", T[i][j]);
			else
				printf("%10s", "INF");
		}
		cout << endl;
	}

}


int g[101][101];

void set2D(size_t max_r, size_t max_c, int initVal)
{
	for (size_t i = 0; i < max_r; i++)
	{
		for (int j = 0; j < max_c; j++)
		{
			g[i][j] = initVal;
		}
	}
}

void AllPairShortestPath(int OPT[][101], int nVertices)
{
	for (int u = 0; u < nVertices; u++)
	{
		OPT[u][u] = 0;
	}

	// Distance
	for (int w = 0; w < nVertices; w++) // All Shortest Path passing through w
	{
		for (int u = 0; u < nVertices; u++)
		{
			for (int v = 0; v < nVertices; v++)
			{
				OPT[u][v] = min(OPT[u][v], OPT[u][w] + OPT[w][v]);
			}
		}
	}

}




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int u, v;
	int t = 0;
	cin >> t;
	int cs = 0;
	while (cs<t)
	{
		cs++;
		int n = 0;
		int m = 0;
		cin >> n >> m;
		set2D(n, n, INFINITY);

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			g[u][v] = 1;
			g[v][u] = 1;
		}
		int s, d;
		cin >> s >> d;


		AllPairShortestPath(g, n);
		//PrintTable(g,n,n);
		/*int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (g[i][j] != INFINITY && g[i][j] != 0) {
					sum += g[i][j];
				}
			}
		}*/
		int dmax = 0;
		for (int i = 0; i < n; i++)
		{
			dmax = max(dmax, g[s][i] + g[i][d]);
		}

		printf("Case %d: %d\n", cs, dmax);
	}

	return 0;
}

