#include <stdio.h>
#include <stdlib.h>

#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define INF						(int)2e9
#define Ceil(x, n)				(((((x))+((n)-1))/n))
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)
#define FloorN(x, n)			((x)-(x)%(n))
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)
#define IsEven(x)				(!IsOdd((x)))
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef unsigned long long int	QWORD;
typedef struct {
	ll first;
	ll second;
} P;

int main() {
	int N;

	scanf("%d", &N);

	int a[N];
	REP(i, N) scanf("%d", &a[i]);

	int idx = 1;
	int ans = 0;

	REP(i, N) {
		if (a[i] == idx) {
			idx++;
		} else {
			ans++;
		}
	}

	if (idx == 1) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}
