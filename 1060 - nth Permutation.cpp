//
// Created by Subangkar on 01-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 20u
#define memCLR(a, n, v) for(int i=0;i<n;++i) a[i]=v;

uint64_t fact[N_MAX + 1];
size_t freq[26];


void calc_fact() {
	fact[0] = 1;
	for (uint64_t n = 1; n <= N_MAX; ++n) {
		fact[n] = n * fact[n - 1];
	}
}

uint64_t perm(uint64_t n, const set<char> &chars) {
	uint64_t perm = fact[n];
	for (char c:chars) {
		perm /= fact[freq[c - 'a']];
	}
	return perm;
}

string nth_perm(const string &str, uint64_t N) {
	if (!N) return "Impossible";

	string nth_str;

	memCLR(freq, 'z' - 'a' + 1, 0);
	set<char> chars;
	for (auto c:str) {
		chars.insert(c);
		++freq[c - 'a'];
	}

	uint64_t n = N;
	while (nth_str.size() < str.size()) {
		uint64_t num_perm_passed = 0;
		for (auto c:chars) {
			if (!freq[c - 'a']) continue;
			--freq[c - 'a'];
			uint64_t perm_val = perm(str.size() - nth_str.size() - 1, chars);
			num_perm_passed += perm_val;
			if (num_perm_passed < n) {
				++freq[c - 'a'];
			} else {
				nth_str += c;
				n = n - (num_perm_passed - perm_val);
				break;
			}
		}
		if (nth_str.empty()) return "Impossible";
	}
	return nth_str;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	calc_fact();
	int t, tc = 0;
//	cout << nth_perm("aabbcaabbcaabbcaabbc", 2) << endl;
//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		uint64_t N;
		string s;
		cin >> s >> N;
//		scanf("%lld", &N);
		printf("Case %d: %s\n", t, nth_perm(s, N).data());
	}
	return 0;
}
