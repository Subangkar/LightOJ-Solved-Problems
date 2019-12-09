//
// Created by Subangkar on 25-Nov-19.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int t, tc, x;
	int i;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int total = 0;
		int plus = 0;
		cin >> N;
		for (i = 0; i < N; ++i) {
			cin >> x;
			total += abs(x);
			plus += (x > 0);
		}

		printf("Case %d: ", t);
		if (!plus) cout << "inf" << endl;
		else {
			int g = __gcd(total, plus);
			plus /= g;
			total /= g;
			printf("%d/%d\n", total, plus);
		}
	}

	return 0;
}