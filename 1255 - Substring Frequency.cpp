//
// Created by Subangkar on 02-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 1000000

// Fills lps[] for given patttern pat[0..M-1] : O(n) : lps from geeksforgeeks.com
void computeLPSArray(const string &pat, int *lps) {
	int M = pat.length();
	int len = 0;// length of the previous longest prefix suffix

	lps[0] = 0; // lps[0] is always 0

	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int knuth_morris_pattern_search(const string &text, const string &pattern) {
	int nindices = 0;
	if (text.empty() || pattern.empty() || pattern.size() > text.size()) return 0;

	int lps[pattern.length()];
	computeLPSArray(pattern, lps);

	for (int i = 0, j = 0; i < text.length();) {
		if (text[i] == pattern[j]) {
			++i;
			++j;
			if (j == pattern.length()) {
				++nindices;
				j = lps[j - 1];
			}
		}
		if (text[i] != pattern[j]) {
			if (!j) ++i;
			else j = lps[j - 1];
		}
	}
	return nindices;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		char text[N_MAX + 1];
		char pattern[N_MAX + 1];
		scanf("%s", text);
		scanf("%s", pattern);
		auto indices = knuth_morris_pattern_search(text, pattern);
//		cout << pattern << endl;
//		for (auto i :indices) {
//			cout << indices.size() << endl;
//		}
		printf("Case %d: %d\n", t, indices);
	}
	return 0;
}
