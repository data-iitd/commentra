#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int *l = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &l[i]);
	}

	qsort(l, n, sizeof(int), compare);

	int ans=0;
	for(int i = 0; i < k; i++){
		ans += l[n - 1 - i];
	}
	printf("%d\n", ans);
	free(l);
}

int compare(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

