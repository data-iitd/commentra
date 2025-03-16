#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>
#include<stdarg.h>
#include<float.h>
#include<ctype.h>
#include<setjmp.h>
#include<signal.h>
#include<errno.h>
#include<fenv.h>
#include<inttypes.h>
#include<locale.h>
#include<monetary.h>
#include<regex.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdio_ext.h>
#include<wchar.h>
#include<wctype.h>

// Initialize arrays'maps' and 'num' with given size'maxn'
int maps[maxn];
int num[maxn];

// Main function starts here
int main() {
	// Initialize variable 'n' to read input from standard input
	int n;
	// Start an infinite loop to read multiple test cases
	while(~scanf("%d",&n)) {
		// Initialize'maps' and 'num' arrays with input values
		for(int i=1; i<=n; i++) {
			scanf("%d",&maps[i]);
			num[i]=maps[i]; // copy input values to 'num' array
		}
		// Sort'maps' array in ascending order
		sort(maps+1,maps+n+1);
		// Calculate the middle index'm' of sorted'maps' array
		int m=n/2;
		// Process each element in 'num' array based on the middle index'm'
		for(int i=1; i<=n; i++) {
			// If current element 'num[i]' is smaller than or equal to middle element'maps[m]'
			if(num[i]<=maps[m]) {
				// Print the next element in sorted'maps' array
				printf("%d\n",maps[m+1]);
			}
			// Otherwise print the current middle element'maps[m]'
			else {
				printf("%d\n",maps[m]);
			}
		}
	}
	// Return 0 to indicate successful execution of the program
	return 0;
}

