#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=200000+10; // maximum size of the input array 'n'
const int INF=int(1e8); // a large constant value used as INF

// Initialize arrays 'maps' and 'num' with given size 'maxn'
int maps[maxn];
int num[maxn];

// Main function starts here
int main() {
	// Initialize variable 'n' to read input from standard input
	int n;
	// Start an infinite loop to read multiple test cases
	while(~scanf("%d",&n)) {
		// Initialize 'maps' and 'num' arrays with input values
		for(int i=1; i<=n; i++) {
			scanf("%d",&maps[i]);
			num[i]=maps[i]; // copy input values to 'num' array
		}
		// Sort 'maps' array in ascending order
		sort(maps+1,maps+n+1);
		// Calculate the middle index 'm' of sorted 'maps' array
		int m=n/2;
		// Process each element in 'num' array based on the middle index 'm'
		for(int i=1; i<=n; i++) {
			// If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
			if(num[i]<=maps[m]) {
				// Print the next element in sorted 'maps' array
				printf("%d\n",maps[m+1]);
			}
			// Otherwise print the current middle element 'maps[m]'
			else {
				printf("%d\n",maps[m]);
			}
		}
	}
	// Return 0 to indicate successful execution of the program
	return 0;
}
