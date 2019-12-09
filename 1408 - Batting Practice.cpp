//
// Created by Subangkar on 09-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;


#define N_MAX 100

#define M (N_MAX+1)

// Function to print the matrix
void PrintMatrix(double a[][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++)
//			cout << a[i][j] << " ";
			printf("%2.3f ", a[i][j]);
		cout << endl;
	}
}

// function to reduce matrix to reduced
// row echelon form.
int PerformOperation(double a[][M], int n) {
	int i, j, k = 0, c, flag = 0, m = 0;
	double pro = 0;

	// Performing elementary operations
	for (i = 0; i < n; i++) {
		if (a[i][i] == 0) {
			c = 1;
			while (a[i + c][i] == 0 && (i + c) < n)
				c++;
			if ((i + c) == n) {
				flag = 1;
				break;
			}
			for (j = i, k = 0; k <= n; k++)
				swap(a[j][k], a[j + c][k]);
		}

		for (j = 0; j < n; j++) {

			// Excluding all i == j
			if (i != j) {

				// Converting Matrix to reduced row
				// echelon form(diagonal matrix)
				double pro = a[j][i] / a[i][i];

				for (k = 0; k <= n; k++)
					a[j][k] = a[j][k] - (a[i][k]) * pro;
			}
		}
	}
	return flag;
}

// Function to print the desired result
// if unique solutions exists, otherwise
// prints no solution or infinite solutions
// depending upon the input given.
void PrintResult(double a[][M], int n, int flag) {
//	cout << "Result is : ";

	if (flag == 2)
		cout << "Infinite Solutions Exists" << endl;
	else if (flag == 3)
		cout << "No Solution Exists" << endl;


		// Printing the solution by dividing constants by
		// their respective diagonal elements
	else
		for (int i = 0; i < n; i++) {
			a[i][n] /= a[i][i];
//			cout << a[i][n] << " ";
		}
}

// To check whether infinite solutions
// exists or no solution exists
int CheckConsistency(double a[][M], int n, int flag) {
	int i, j;
	double sum;

	// flag == 2 for infinite solution
	// flag == 3 for No solution
	flag = 3;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++)
			sum = sum + a[i][j];
		if (sum == a[i][j])
			flag = 2;
	}
	return flag;
}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int t, tc;

	double a[N_MAX][M];
	scanf("%d", &tc);
//	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int k1, k2;
		double p;
//		cin >> p >> k1 >> k2;
		scanf("%lf %d %d", &p, &k1, &k2);
		double q = 1.0 - p;
		// Gauss Jordan giving most accurate but getting WA must be precision error
//		int n = 1 + k1 + k2;
//		int m = n;
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j <= n; ++j) {
//				a[i][j] = 0.0;
//			}
//		}
//		for (int i = 0; i < k1; ++i) {
//			a[i][i] = 1;
//			a[i][i + 1] = -q;
//			a[i][k1 + 1] = -p;
//			a[i][m] = 1;
//		}
//		a[k1][k1] = 1;
//		a[k1][m] = 0;
//		for (int j = 1 + k1; j < k1 + k2; ++j) {
//			a[j][j] = 1;
//			a[j][j + 1] = -p;
//			a[j][1] = -q;
//			a[j][m] = 1;
//		}
//		a[k1 + k2][k1 + k2] = 1;
//		a[k1 + k2][m] = 0;
//		PrintMatrix(a, n);

		// Performing Matrix transformation
//		auto flag = PerformOperation(a, n);
//
//		if (flag == 1)
//			flag = CheckConsistency(a, n, flag);

		// Printing Final Matrix
//		cout << "Final Augumented Matrix is : " << endl;
//		PrintMatrix(a, n);
//		cout << endl;

		// Printing Solutions(if exist)
//		PrintResult(a, n, flag);
//		printf("Case %d: %lf\n", t, a[0][n]);

		double E = 0;
		if (p < 1E-10) {
			E = k1;
		} else if (q < 1E-10) {
			E = k2;
		} else {
			auto P = (1 - pow(p, k2 - 1)) / (1 - p);
			auto Q = (1 - pow(q, k1 - 1)) / (1 - q);
			auto E1 = (Q + p * P * Q) / (1 - p * q * P * Q);
			auto E1_ = (P + q * P * Q) / (1 - p * q * P * Q);
			E = 1 + q * E1 + p * E1_;
		}
		printf("Case %d: %lf\n", t, E);
//		cout << "Case " << t << ": " << a[0][n] << endl;
	}
	return 0;
}
