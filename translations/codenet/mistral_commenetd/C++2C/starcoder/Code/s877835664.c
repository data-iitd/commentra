#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Include necessary headers for the program

#define rep(i,s,e) for(int i=s;i<e;i++)
#define repeq(i,s,e) for(int i=s;i<=e;i++)

// Macros for for loops

int main() {
	int N, K;
	// Declare variables for input

	scanf("%d %d", &N, &K);
	// Read input for 'N' and 'K'

	int A[N + 1];
	// Initialize an array 'A' of size 'N+1'

	repeq(i, 1, N) {
		scanf("%d", &A[i]);
		// Read input for each element of the array 'A'
	}

	int cur = 1;
	// Initialize a variable 'cur' to keep track of the current position in the array

	int dic[N + 1] = { -1 };
	// Initialize an array 'dic' of size 'N+1' to store the distance from the start for each position

	bool flg = false;
	// Initialize a boolean variable 'flg' to check if we need to reverse the direction of traversal

	repeq(i, 1, K) {
		if (dic[cur] < 0 || flg) {
			dic[cur] = i;
			// If the distance from the start for the current position is not yet determined or we need to reverse the direction, update the distance

			cur = A[cur];
			// Move to the next position
		}
		else if(!flg) {
			int tmp = K - (dic[cur] - 1);
			tmp %= i - dic[cur];
			// Calculate the number of steps we need to take to reach the position 'i' from the current position

			i = K - tmp ;
			// Update 'i' to the position we need to reach

			flg = true;
		}
	}

	printf("%d\n", cur);
	// Print the final answer, which is the position of the last visited node

	return 0;
}
// Main function to solve the problem

