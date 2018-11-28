#define ACTIVE
#define _CRT_SECURE_NO_WARNINGS
#ifdef ACTIVE


#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<cstring>
#include<cstdio>


using namespace std;



template<typename T>
T ** new2D(size_t max_r, size_t max_c, T initVal)
{
	T** mat = new T*[max_r];
	for (size_t i = 0; i < max_r; i++)
	{
		mat[i] = new T[max_c];
		memset(mat[i], initVal, max_c * sizeof(T));
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


int bfs(bool** Graph, pair<int, int> src)
{
	pair<int, int> u = src;
	queue<pair<int, int> > Q;
	int nDis = 0;

	Q.push(u);

	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		nDis++;

		if (Graph[u.first - 1][u.second]) {
			Q.push(make_pair(u.first - 1, u.second));
			Graph[u.first - 1][u.second] = false;
		}
		if (Graph[u.first][u.second - 1]) {
			Q.push(make_pair(u.first, u.second - 1));
			Graph[u.first][u.second - 1] = false;
		}
		if (Graph[u.first + 1][u.second]) {
			Q.push(make_pair(u.first + 1, u.second));
			Graph[u.first + 1][u.second] = false;
		}
		if (Graph[u.first][u.second + 1]) {
			Q.push(make_pair(u.first, u.second + 1));
			Graph[u.first][u.second + 1] = false;
		}
	}

	return nDis;
}


int main()
{
	int t = 0;
	scanf("%d", &t);
	int cs = 0;
	while (cs < t)
	{
		cs++;

		pair<int, int> src;
		int n, m;
		n = m = 0;


		scanf("%d %d", &n, &m);

		bool** g = new2D<bool>(m + 2, n + 2, false);
		//bool** vis = new2D<bool>(n, m, false);

		char c;
		for (size_t i = 1; i <= m; i++)
		{
			for (size_t j = 1; j <= n; j++)
			{
				cin >> c;
				if (c == '.')g[i][j] = true;
				else if (c == '@') {
					//vis[i][j] = true;
					src = make_pair(i, j);
				}
			}
		}

		int cnt = bfs(g, src);

		printf("Case %d: %d\n", cs, cnt);

		delete2D<bool>(g, m + 2);
	}


	return 0;
}



#endif // ACTIVE

