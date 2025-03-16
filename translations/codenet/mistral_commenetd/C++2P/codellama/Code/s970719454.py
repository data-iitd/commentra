
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

def main():
	# Including necessary headers
	# ...

	# Defining macros for for loops
	# ...

	# Initializing arrays
	here = [0]*100001
	dp1 = [0]*100001
	dp2 = [0]*100001

	# Initializing all elements of the arrays to zero
	rep(i,100001)here[i]=dp1[i]=dp2[i]=0

	# Reading input
	while(1):
		n,m = map(int,input().split())
		if(n==0)break

		# Resetting the arrays for new input
		rep(i,100001)here[i]=dp1[i]=dp2[i]=0

		# Reading number of houses and queries
		dpflg = False
		
		# Reading queries
		rep(i,m):
			a = int(input())
			# Setting the corresponding element of 'here' array to 1
			here[a]=1
			# If a query is to find the maximum length of a subsequence without any house, then setting 'dpflg' to true
			if(a==0) dpflg=True

		# Calculating the maximum length of a subsequence without any house
		maxi1 = 0
		reps(i,1,n+1):
			if(here[i]==1)dp1[i] = dp1[i-1]+1
			maxi1 = max(dp1[i], maxi1)

		# Calculating the maximum length of a subsequence with at least one house
		maxi2 = 0
		reps(i,1,n+1):
			if(here[i]==1)dp2[i] = dp2[i-1]+1
			else dp2[i] = dp1[i-1]+1
			maxi2 = max(dp2[i], maxi2)

		# Printing the result
		if(!dpflg):
			print(maxi1)
		else:
			print(maxi2)

# 