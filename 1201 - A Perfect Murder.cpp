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






// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool** bpGraph, int M, int N, int u, bool seen[], int matchR[])
{
	// Try every job one by one
	for (int v = 0; v < N; v++)
	{
		// If applicant u is interested in job v and v is
		// not visited
		if (bpGraph[u][v] && !seen[v])
		{
			seen[v] = true; // Mark v as visited

							// If job 'v' is not assigned to an applicant OR
							// previously assigned applicant for job v (which is matchR[v])
							// has an alternate job available.
							// Since v is marked as visited in the above line, matchR[v]
							// in the following recursive call will not get job 'v' again
			if (matchR[v] < 0 || bpm(bpGraph, M, N, matchR[v], seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Returns maximum number of matching from M to N
// bpGraph[u][v] is true if edge false otherwise
int maxBPM(bool** bpGraph, int M, int N)
{
	int matchR[N];
	bool seen[N];

	// Initially all jobs are available
	memset(matchR, -1, sizeof(matchR));

	int result = 0; // Count of jobs assigned to applicants
	for (int u = 0; u < M; u++)
	{
		// Mark all jobs as not seen for next applicant.
		memset(seen, 0, sizeof(seen));

		// Find if the applicant 'u' can get a job
		if (bpm(bpGraph, M, N, u, seen, matchR))
			result++;
	}
	return result;
}






// Prob in set assign
int main()
{
	//FILE_INP;
	//FILE_OUT;



	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;
		int V, E;
		cin >> V >> E;
		int st[V];
		memset(st, -1, V * sizeof(int));
		//int m = 0, n = 0;
		bool** g = new2D<bool>(V, V, false);
		int u, v;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			u -= 1;
			v -= 1;
			if (st[u] == -1) st[u] = !st[v];
			if (st[v] == -1) st[v] = !st[u];
			
			if (st[u] == 0) {
				g[u][v] = true;
				//++m;
			}
			else {
				g[v][u] = true;
				//++n;
			}
		}
		//for (int i = 0; i < V; i++)
		//{
		//	if (st[i] == 0) ++m;
		//}
		//n = V - m;
		//cout << m << "  " << n << endl;
		//print2D<bool>(g, V, V);
		printf("Case %d: %d\n", cs, V - maxBPM(g, V, V));
		delete2D<bool>(g, V);
	}

	return 0;
}


/*
16 5
2 6
1 3
3 5
4 2
1 2
*/