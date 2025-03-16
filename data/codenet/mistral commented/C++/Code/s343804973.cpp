
#include<cstdio>
#define int long long

// Define constants and input variables
int n, m, mod;

// Define 2D arrays and names
int C[310][310], pre[310][310], f[310][310];

using namespace std;

// Main function
signed main(){
	// Read input values
	scanf("%lld%lld%lld",&n,&m,&mod);

	// Initialize C array with base cases
	C[0][0] = 1;
	for(int i=1;i<=n;i++){
		// Initialize i-th row with base cases
		C[i][0] = C[i][i] = 1;

		// Calculate C[i][j] using previous rows
		for(int j=1;j<i;j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}

	// Initialize f and pre arrays for base case
	for(int i=0;i<=m;i++)
		f[1][i] = 1, pre[1][i] = m-i+1;

	// Calculate f and pre arrays for all other rows
	for(int i=2;i<=n+1;i++){
		for(int j=0;j<=m;j++){
			// Calculate f[i][j] using previous rows and pre arrays
			for(int k=1;k<i;k++)
				(f[i][j] += f[i-k][j] * pre[k][j+1] % mod * C[i-2][k-1]) %= mod;
		}

		// Calculate pre[i][j] using previous rows and f arrays
		for(int j=m;j>=0;j--)
			pre[i][j] = (pre[i][j+1] + f[i][j]) % mod;
	}

	// Print the result
	printf("%lld\n", f[n+1][0]);
}

// The code is now commented and easy to understand.