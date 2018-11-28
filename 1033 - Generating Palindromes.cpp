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


#define FILE_INP freopen("in.txt","r",stdin)
#define FILE_OUT freopen("out.txt","w",stdout)



using namespace std;


// A utility function to get max of two integers
int max(int x, int y) { return (x > y) ? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(const char *str)
{
	int n = strlen(str);
	int i, j, cl;
	int L[n][n];

	for (i = 0; i < n; i++)
		L[i][i] = 1;

	for (cl = 2; cl <= n; cl++)
	{
		for (i = 0; i<n - cl + 1; i++)
		{
			j = i + cl - 1;
			if (str[i] == str[j] && cl == 2)
				L[i][j] = 2;
			else if (str[i] == str[j])
				L[i][j] = L[i + 1][j - 1] + 2;
			else
				L[i][j] = max(L[i][j - 1], L[i + 1][j]);
		}
	}

	return L[0][n - 1];
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
		string str;
		cin >> str;
		cout << "Case " << cs << ": " << (str.length() - lps(str.data())) << endl;

	}

	return 0;
}
