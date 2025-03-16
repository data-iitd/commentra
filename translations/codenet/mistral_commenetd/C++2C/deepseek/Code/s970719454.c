#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining macros for for loops
#define reps(i,f,n) for(int i=f;i<n;i++)
#define rep(i,n) reps(i,0,n)

int main(){
	// Initializing arrays
	int here[100001];
	int dp1[100001];
	int dp2[100001];

	// Initializing all elements of the arrays to zero
	rep(i,100001) here[i]=dp1[i]=dp2[i]=0;

	// Reading input
	while(1){
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0) break;

		// Resetting the arrays for new input
		rep(i,100001) here[i]=dp1[i]=dp2[i]=0;

		// Reading queries
		int a;
		rep(i,m){
			scanf("%d",&a);
			// Setting the corresponding element of 'here' array to 1
			here[a]=1;
		}

		// Calculating the maximum length of a subsequence without any house
		int maxi1 = 0;
		reps(i,1,n+1){
			if(here[i]==1) dp1[i] = dp1[i-1]+1;
			if(dp1[i] > maxi1) maxi1 = dp1[i];
		}

		// Calculating the maximum length of a subsequence with at least one house
		int maxi2 = 0;
		reps(i,1,n+1){
			if(here[i]==1) dp2[i] = dp2[i-1]+1;
			else dp2[i] = dp1[i-1]+1;
			if(dp2[i] > maxi2) maxi2 = dp2[i];
		}

		// Printing the result
		if(m==0){
			printf("%d\n",maxi1);
		}else{
			printf("%d\n",maxi2);
		}
	}
}
