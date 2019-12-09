//
// Created by Subangkar on 29-Nov-19.
//
#include<bits/stdc++.h>

using namespace std;


#define N_MAX 100
#define DICE 6

#define M (N_MAX+1)

// Function to print the matrix
void PrintMatrix(double a[][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++)
//			cout << a[i][j] << " ";
			printf("%2.8f ", a[i][j]);
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
	int t, tc;

	double a[N_MAX][M];
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int m;
		cin >> m;
		int R[N_MAX];
		for (int l = 0; l < N_MAX; ++l) {
			R[l] = l;
		}
		for (int k = 0; k < m; ++k) {
			int x, y;
			cin >> x >> y;
			R[x - 1] = y - 1;
		}
		// Order of Matrix(n)
		int n = N_MAX, flag = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= n; ++j) {
				a[i][j] = 0.0;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (R[i] != i) {
				a[i][i] = 1;
				a[i][n] = 1;
				continue;
			}
			int miss = max(i + 1 + 6 - N_MAX, 0);
			a[i][i] = (1.0 - miss / 6.0);
			for (int j = i + 1; j <= min(i + 6, n - 1); ++j) {
				int x = R[j];
				a[i][x] += -1.0 / 6;
			}
			a[i][n] = 1;
		}
		a[n - 1][n - 1] = 1;
		a[n - 1][n] = 0;
//		PrintMatrix(a, n);

		// Performing Matrix transformation
		flag = PerformOperation(a, n);

		if (flag == 1)
			flag = CheckConsistency(a, n, flag);

		// Printing Final Matrix
//		cout << "Final Augumented Matrix is : " << endl;
//		PrintMatrix(a, n);
//		cout << endl;

		// Printing Solutions(if exist)
		PrintResult(a, n, flag);


//		double E[N_MAX + 1], E_sum[N_MAX + 1];
//		E_sum[N_MAX] = E[N_MAX] = 0;
//		for (int i = N_MAX - 1; i; --i) {
//			int miss = max(i + 6 - N_MAX, 0);
//			double j = 6.0 / (6 - miss);
//			double next = 0.0;
//			for (int k = 1; k <= 6; ++k) {
//				next += E[min(i + k, N_MAX)];
//			}
//			E[i] = j * (1 + (1.0 / 6) * next);
//		}
		printf("Case %d: %lf\n", t, a[0][n]);
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
