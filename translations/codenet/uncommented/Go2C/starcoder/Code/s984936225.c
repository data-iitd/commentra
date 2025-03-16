#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000000000

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	int Inf = 1 << 62;
	int a[M],b[M],c[M];
	for(int i = 0; i<M; i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		c[i] = -c[i];
	}
	int dist[N];
	for(int i = 0; i<N; i++){
		dist[i] = Inf;
	}
	dist[0] = 0;
	for(int loop = 0; loop < N; loop++){
		for(int i = 0; i<M; i++){
			if(dist[a[i]-1] == Inf){
				continue;
			}
			if(dist[b[i]-1] > dist[a[i]-1] + c[i]){
				dist[b[i]-1] = dist[a[i]-1] + c[i];
			}
		}
	}
	int ans = dist[N-1];
	bool navigate[N];
	for(int loop = 0; loop < N; loop++){
		for(int i = 0; i<M; i++){
			if(dist[a[i]-1] == Inf){
				continue;
			}
			if(dist[b[i]-1] > dist[a[i]-1] + c[i]){
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = true;
			}
			if(navigate[a[i]-1] == true){
				navigate[b[i]-1] = true;
			}
		}
	}
	if(navigate[N-1]){
		printf("inf\n");
	}else{
		printf("%d\n",-ans);
	}
	return 0;
}
