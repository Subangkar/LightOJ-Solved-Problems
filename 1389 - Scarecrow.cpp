//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 10000


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int x;
		char text[N_MAX + 1];
		scanf("%d%s", &x, text);
		vector<int> seg;
		string s = text;
		int n = 0;
		int l = 0;
		for (int i = 0; i < s.size(); ++i) {
			auto c = s[i];
			if (c == '.') {
				++l;
				if (l == 2) { //]...^ | ]..#^
					++n;
					++i;
					l = 0;
				}
			} else {
				if (l) { // ].#.^ | ].##^
					++n;
					++i;
					l = 0;
				}
			}
		}
		if (l)++n;
		printf("Case %d: %d\n", t, n);
	}
	return 0;
}
