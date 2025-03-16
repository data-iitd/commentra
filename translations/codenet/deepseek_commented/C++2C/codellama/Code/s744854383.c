#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						(int)2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef unsigned long long int	QWORD;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
int main()
{
	// Read the number of elements N
	int N;
	scanf("%d", &N);
	
	// Read N integers into a vector `a`
	int *a = (int *)malloc(sizeof(int) * N);
	REP(i, N) scanf("%d", &a[i]);

	// Initialize idx to 1 and ans to 0
	int idx = 1;
	int ans = 0;

	// Iterate through the vector `a`
	REP(i, N) {
		// If the current element is equal to `idx`, increment `idx`
		if (a[i] == idx) {
			idx++;
		} else {
			// If not, increment `ans`
			ans++;
		}
	}

	// If `idx` is still 1, it means no elements matched, so print `-1`
	if (idx == 1) {
		printf("%d\n", -1);
	} else {
		// Otherwise, print `ans`
		printf("%d\n", ans);
	}

	return 0;
}

