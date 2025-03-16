
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define rep(i,n) for(int i=0;i<n;i++) // A macro for looping through a range of indices
#define all(c) (c).begin(),(c).end() // A macro for getting a reference to the begin and end of a container
#define mp make_pair // A function to create a pair of values
#define pb push_back // A function to add an element to the end of a vector
#define rp(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) // A loop for iterating through the elements of a container
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) // A loop for iterating through the elements of a container, with the current element being referenced as 'i'
#define dbg(x) printf("%s = %d\n",#x,(x)) // A debugging macro for printing the value of a variable and its name

int main()
{
	int n,t; // Variables to store the number of test cases and the current test case
	bool st[7]; // A boolean array to store the current segment tree state

	while(scanf("%d",&n),~n){ // Reading the number of test cases and processing them while there are still test cases to be processed
		rep(i,7)st[i]=0; // Initializing the segment tree state to all zeros
		rep(i,n){ // Processing each test case
			scanf("%d",&t); // Reading the current test case
			char ans[8]={0}; // Initializing an array to store the answer as a string of 0s and 1s
			rep(i,7){ // Iterating through each bit position in the segment tree
				ans[i]=st[i]^seg[t][i]?'1':'0'; // Updating the answer based on the current segment tree state and the current test case
				st[i]=seg[t][i]; // Updating the segment tree state for the current bit position
			}
			printf("%s\n",ans); // Printing the answer for the current test case
		}
	}

	return 0; // Indicating successful termination of the program
}

