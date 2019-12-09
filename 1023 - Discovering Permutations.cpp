//
// Created by Subangkar on 25-Nov-19.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int N;
	int t, tc, x;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int n, k;
		cin >> n >> k;
		char arr[n + 1];
		for (char i = 'A'; i <= 'A' + n; ++i) {
			arr[i - 'A'] = i;
		}
		arr[n] = '\0';
		cout << "Case " << t << ":" << endl;
		do {
			cout << arr << endl;
			--k;
		} while (k && next_permutation(arr, arr + n));
	}
	return 0;
}

