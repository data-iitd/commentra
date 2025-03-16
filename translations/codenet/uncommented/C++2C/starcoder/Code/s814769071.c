#pragma region
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int n, k; scanf("%d %d", &n, &k);
	int MOD = 1e9 + 7;
	int mx = n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2;
	int mn = k * (k - 1) / 2;
	int res = 0;
	for (int i = k; i <= n + 1; ++i)
	{
		res += mx - mn + 1;
		mx += n - i;
		mn += i;
		res %= MOD;
	}
	printf("%d\n", res);
}

#pragma endregion

