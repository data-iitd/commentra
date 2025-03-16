#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int N,M;
	scanf("%d %d",&N,&M);
	int Inf = 1 << 62;
	int *dist = (int *)malloc(sizeof(int)*N);
	for (int i= 0; i<N; i++) {
		dist[i] = Inf;
	}
	dist[0] = 0;
	int *a = (int *)malloc(sizeof(int)*M);
	int *b = (int *)malloc(sizeof(int)*M);
	int *c = (int *)malloc(sizeof(int)*M);
	for (int i= 0; i<M; i++) {
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		c[i] = -c[i];
	}
	int *navigate = (int *)malloc(sizeof(int)*N);
	for (int loop = 0; loop < N; loop++) {
		for (int i= 0; i<M; i++) {
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = 1;
			}
		}
	}
	int ans = dist[N-1];
	for (int loop = 0; loop < N; loop++) {
		for (int i= 0; i<M; i++) {
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = 1;
			}
			if (navigate[a[i]-1] == 1) {
				navigate[b[i]-1] = 1;
			}
		}
	}

	if (navigate[N-1]){
		printf("inf\n");
	} else {
		printf("%d\n",-ans);
	}
	return 0;
}
