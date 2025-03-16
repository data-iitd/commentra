
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#define MAX_N 200005

// Initialize arrays
long long a[MAX_N];
long long pre[MAX_N];
long long last[MAX_N];

int main(){
	// Read the number of elements in the array
	int n;
	scanf("%d",&n);

	// Read the elements of the array
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		// Initialize pre and last arrays
		pre[i] = pre[i-1] + a[i];
		last[i] = last[i+1] + a[i];
	}

	// Initialize sum of prefix and suffix arrays to zero
	long long sumpre = 0, sumlast = 0;

	// Calculate prefix sum
	for(int i = 1;i<n;i++){
		sumpre += a[i];
		pre[i] = sumpre;
	}

	// Calculate suffix sum
	for(int i = n;i>0;i--){
		sumlast += a[i];
		last[i] = sumlast;
	}

	// Initialize difference as maximum long long value
	long long d = (1LL << 60);

	// Find the minimum difference between prefix and suffix sums
	for(int i = 1;i<n;i++){
		d = min(d, abs(pre[i] - last[i+1]));
	}

	// Print the minimum difference
	printf("%lld\n",d);
}

