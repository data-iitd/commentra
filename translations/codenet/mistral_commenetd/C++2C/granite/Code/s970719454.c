

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

// Defining macros for for loops
#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

int main(){
	// Including necessary headers
	//...

	// Defining macros for for loops
	//...

	// Initializing arrays
	int here[100001];
	int dp1[100001];
	int dp2[100001];

	// Initializing all elements of the arrays to zero
	rep(i,100001)here[i]=dp1[i]=dp2[i]=0;

	// Reading input
	while(1){
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0)break;

		// Resetting the arrays for new input
		rep(i,100001)here[i]=dp1[i]=dp2[i]=0;

		// Reading number of houses and queries
		bool dpflg = false;
		
		// Reading queries
		rep(i,m){
			int a;
			scanf("%d",&a);
			// Setting the corresponding element of 'here' array to 1
			here[a]=1;
			// If a query is to find the maximum length of a subsequence without any house, then setting 'dpflg' to true
			if(a==0) dpflg=true;
		}

		// Calculating the maximum length of a subsequence without any house
		int maxi1 = 0;
		reps(i,1,n+1){
			if(here[i]==1)dp1[i] = dp1[i-1]+1;
			maxi1 = max(dp1[i], maxi1);
		}

		// Calculating the maximum length of a subsequence with at least one house
		int maxi2 = 0;
		reps(i,1,n+1){
			if(here[i]==1)dp2[i] = dp2[i-1]+1;
			else dp2[i] = dp1[i-1]+1;
			maxi2 = max(dp2[i], maxi2);
		}

		// Printing the result
		if(!dpflg){
			printf("%d\n",maxi1);
		}else{
			printf("%d\n",maxi2);
		}
	}
}

