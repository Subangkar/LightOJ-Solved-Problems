//
// Created by Subangkar on 03-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 10000

// Structure to store information of a suffix
struct suffix {
	int index; // To store original index
	int rank[2]; // To store ranks and next rank pair
};

// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
int cmp(struct suffix a, struct suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
	       (a.rank[0] < b.rank[0] ? 1 : 0);
}

// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string : O(nlogn)
void buildSuffixArray(const char *text, int n, int suffixArr[]) {
	// A structure to store suffixes and their indexes
	struct suffix suffixes[n];

	// Store suffixes and their indexes in an array of structures.
	// The structure is needed to sort the suffixes alphabatically
	// and maintain their old indexes while sorting
	for (int i = 0; i < n; i++) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = text[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (text[i + 1] - 'a') : -1;
	}

	// Sort the suffixes using the comparison function
	// defined above.
	sort(suffixes, suffixes + n, cmp);

	// At this point, all suffixes are sorted according to first
	// 2 characters. Let us sort suffixes according to first 4
	// characters, then first 8 and so on
	int ind[n]; // This array is needed to get the index in suffixes[]
	// from original index. This mapping is needed to get
	// next suffix.
	for (int k = 4; k < 2 * n; k = k * 2) {
		// Assigning rank and index values to first suffix
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		// Assigning rank to suffixes
		for (int i = 1; i < n; i++) {
			// If first rank and next ranks are same as that of previous
			// suffix in array, assign the same new rank to this suffix
			if (suffixes[i].rank[0] == prev_rank &&
			    suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			} else // Otherwise increment rank and assign
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}

		// Assign next rank to every suffix
		for (int i = 0; i < n; i++) {
			int nextindex = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = (nextindex < n) ?
			                      suffixes[ind[nextindex]].rank[0] : -1;
		}

		// Sort the suffixes according to first k characters
		sort(suffixes, suffixes + n, cmp);
	}

	// Store indexes of all sorted suffixes in the suffix array
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;
}

// Kasai Algorithm lcp[i] = lcp of suffix i,i+1
void buildLcpArray(const char *text, int suffixArr[], int n, int lcp[]) {
	memCLR(lcp, n, 0);

	// An auxiliary array to store inverse of suffix array
	// elements. For example if suffixArr[0] is 5, the
	// invSuffixArray[5] would store 0.  This is used to get next
	// suffix string from suffix array.
	vector<int> invSuffixArray(n, 0);

	// Fill values in invSuffixArray[]
	for (int i = 0; i < n; i++)
		invSuffixArray[suffixArr[i]] = i;

	// Initialize length of previous LCP
	int k = 0;

	// Process all suffixes one by one starting from
	// first suffix in text[]
	for (int i = 0; i < n; i++) {
		/* If the current suffix is at n-1, then we don’t
		   have next substring to consider. So lcp is not
		   defined for this substring, we put zero. */
		if (invSuffixArray[i] == n - 1) {
			k = 0;
			continue;
		}

		/* j contains index of the next substring to
		   be considered  to compare with the present
		   substring, i.e., next string in suffix array */
		int j = suffixArr[invSuffixArray[i] + 1];

		// Directly start matching from k'th index as
		// at-least k-1 characters will match
		while (i + k < n && j + k < n && text[i + k] == text[j + k])
			k++;

		lcp[invSuffixArray[i]] = k; // lcp for the present suffix.

		// Deleting the starting character from the string.
		if (k > 0)
			k--;
	}
}


int suffixArr[N_MAX + 1], lcp[N_MAX + 1];//, uniq_start_suffix[n]
// bounds of indices of unique substrings in O(nlogn)
int unique_substrings_count(const string &text, int l_min, int l_max) {
	int n = text.length();

	buildSuffixArray(text.data(), n, suffixArr);
	buildLcpArray(text.data(), suffixArr, n, lcp);

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int uniq_final_suffix = min(n - 1, suffixArr[i] + l_max - 1);
		int uniq_start_suffix = max(suffixArr[i] + lcp[i], suffixArr[i] + l_min - 1);
		cnt += max(uniq_final_suffix - uniq_start_suffix + 1, 0);
	}
	return cnt;
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
		int p, q;
		scanf("%s", text);
		scanf("%d%d", &p, &q);
		printf("Case %d: %d\n", t, unique_substrings_count(text, p, q));
	}
	return 0;
}
