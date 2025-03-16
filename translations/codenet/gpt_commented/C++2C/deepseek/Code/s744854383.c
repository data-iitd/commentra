#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define INF						(int)2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846

typedef long long				ll;
typedef unsigned long long int	QWORD;

int main()
{
	// Read the number of elements
	int N;
	scanf("%d", &N);

	// Initialize a vector to store the elements
	int a[N];
	// Read the elements into the vector
	REP(i, N) scanf("%d", &a[i]);

	// Initialize index and answer counter
	int idx = 1;
	int ans = 0;

	// Iterate through the vector to count mismatches
	REP(i, N) {
		// If the current element matches the expected index
		if (a[i] == idx) {
			// Move to the next expected index
			idx++;
		} else {
			// Count the mismatch
			ans++;
		}
	}

	// If no elements matched the expected index
	if (idx == 1) {
		printf("-1\n"); // Output -1 to indicate no matches
	} else {
		// Output the count of mismatches
		printf("%d\n", ans);
	}

	return 0; // End of the program
}
