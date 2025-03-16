
#include <stdio.h>

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i)) // Macro for repetition
#define INF						(int)2e9 // Constant for infinity
#define Ceil(x, n)				(((((x))+((n)-1))/n)) // Ceiling function
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n) // Ceiling and round up to nearest multiple of n
#define FloorN(x, n)			((x)-(x)%(n)) // Floor function and round down to nearest multiple of n
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL) // Check if a number is odd
#define IsEven(x)				(!IsOdd((x))) // Check if a number is even
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ])) // Get the size of an array
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF) // Constant for maximum QWORD value
#define M_PI					3.14159265358979323846 // Constant for pi
typedef long long				ll; // Typedef for long long int
typedef unsigned long long int	QWORD; // Typedef for unsigned long long int
typedef pair<ll, ll>			P; // Typedef for pair of long long int

/*-----------------------------------------------------------------------------
　入力
 -------------------------------------------------------------------------------*/
int main() {
	int N; // Variable to store the number of elements in the array

	// Read the number of elements from the standard input
	scanf("%d", &N);

	// Allocate memory for the array and read its elements
	int a[N];
	REP(i, N) scanf("%d", &a[i]);

	// Initialize variables
	int idx = 1; // Index for checking the current element in the array
	int ans = 0; // Variable to store the answer

	// Process the array
	REP(i, N) {
		// Check if the current element matches the index
		if (a[i] == idx) {
			// Increment the index
			idx++;
		} else {
			// Increment the answer
			ans++;
		}
	}

	// Output the result
	if (idx == 1) {
		printf("-1\n"); // Output -1 if all elements are the same
	} else {
		printf("%d\n", ans); // Output the answer otherwise
	}

	// Terminate the program
	return 0;
}


