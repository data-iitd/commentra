#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the constant for modular arithmetic.
#define mod 1000000007

// Function to perform modular exponentiation.
int modpow(int a,int n) {
	int res = 1;
	for(;n>0;n>>=1) {
		if(n&1 == 1) {
			res = res*a%mod;
		}
		a = a*a%mod;
	}
	return res;
}

// The main function of the program.
int main() {
	// Read the number of elements.
	int n = 0;
	scanf("%d",&n);

	// Read n integers into a slice.
	int c[n];
	for(int i = 0;i<n;i++) {
		scanf("%d",&c[i]);
	}

	// Initialize the answer variable.
	int ans = 0;

	// Sort the slice of integers.
	qsort(c,n,sizeof(int),compare);

	// Calculate the answer based on the sorted slice.
	for(int i = 0;i<n;i++) {
		ans = (ans+(n+1-i)*c[i]%mod)%mod;
	}

	// Print the final answer, multiplied by 4^(n-1) modulo mod.
	printf("%d\n",ans*modpow(4,n-1)%mod);
	return 0;
}

// Function to compare two integers.
int compare(const void *a,const void *b) {
	return *(int*)a - *(int*)b;
}

