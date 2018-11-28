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


// M is number of applicants and N is number of jobs
//#define M 6
//#define N 6

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



struct Crit
{
	int h;
	int a;
	int div;
};


int main()
{
	//FILE_INP;
	//FILE_OUT;




	int t = 0, cs = 0;
	cin >> t;

	while (cs < t)
	{
		cs++;

		int n, m;
		cin >> m >> n;
		int n_str = 0;
		int** brd = new2D<int>(m + 2, n + 2, EOF);
		for (size_t i = 1; i <= m; i++)
		{
			for (size_t j = 1; j <= n; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '*')
					brd[i][j] = n_str++;
			}
		}
		int** st = new2D<int>(m + 2, n + 2, 0);

		for (size_t i = 0; i <= m; i += 2)
		{
			for (size_t j = 0; j <= n; j += 2)
			{
				st[i][j] = 1;
				st[i + 1][j] = 0;
				st[i][j + 1] = 0;
				st[i + 1][j + 1] = 1;
			}
		}

		bool** bpGraph = new2D<bool>(n_str, n_str, false);


		for (size_t i = 1; i <= m; i++)
		{
			for (size_t j = 1; j <= n; j++)
			{
				if (brd[i][j] == EOF) continue;

				if (brd[i - 1][j] != EOF && st[i][j] == 0 && st[i - 1][j] == 1)
				{
					bpGraph[brd[i][j]][brd[i - 1][j]] = true;
				}
				if (brd[i + 1][j] != EOF && st[i][j] == 0 && st[i + 1][j] == 1)
				{
					bpGraph[brd[i][j]][brd[i + 1][j]] = true;
				}
				if (brd[i][j - 1] != EOF && st[i][j] == 0 && st[i][j - 1] == 1)
				{
					bpGraph[brd[i][j]][brd[i][j - 1]] = true;
				}
				if (brd[i][j + 1] != EOF && st[i][j] == 0 && st[i][j + 1] == 1)
				{
					bpGraph[brd[i][j]][brd[i][j + 1]] = true;
				}
			}
		}

		//print2D<bool>(bpGraph, n_str, n_str);

		cout << "Case " << cs << ": " << (n_str-maxBPM(bpGraph, n_str, n_str)) << endl;

		delete2D<int>(st, m + 2);
		delete2D<bool>(bpGraph, n_str);
		delete2D<int>(brd, m + 2);
	}

	return 0;
}
