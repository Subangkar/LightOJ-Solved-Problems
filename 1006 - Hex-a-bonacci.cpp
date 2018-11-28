#include <cstdio>
#include <cstring>

unsigned int val[10000 + 1];
int t[10000 + 1];


unsigned int fn(int n) {
	if (t[n]!=0) return val[n];
	val[n] = 0;
	for (int i = 1; i <= 6; i++)
	{
		val[n] = (val[n] % 10000007 + fn(n - i) % 10000007) % 10000007;
	}
	t[n] = 1;
	return val[n];
}




#define FILE_INP freopen("in.txt","r",stdin)
#define FILE_OUT freopen("out.txt","w",stdout)


int main() {
	

	//FILE_INP;
	//FILE_OUT;

	int n, caseno = 0, cases;
	scanf("%d", &cases);
	while (cases--) {
		memset(t, 0, 10001 * sizeof(int));
		for (int i = 0; i < 6; i++)
		{
			scanf("%u", &val[i]);
			val[i] %= 10000007;
			t[i] = 1;
		}
		scanf("%d", &n);
		printf("Case %d: %u\n", ++caseno, fn(n));
	}
	return 0;
}