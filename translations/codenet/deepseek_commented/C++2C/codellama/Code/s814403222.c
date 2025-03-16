#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  int first;
  char *second;
} P;

P v[22];

int main(void){
  int n;
  while(scanf("%d", &n) == 1 && n){
    int m;
    for(int i = 0; i < 33; i++){
      v[i].first = 0;
      v[i].second = NULL;
    }
    for(int i = 0; i < n; i++){
      v[i].first = 0;
      v[i].second = NULL;
      scanf("%s %d", v[i].second, &m);
      for(int j = 0; j < m; j++){
	int a;
	scanf("%d", &a);
	v[i].first += n - (int)d[a].size;
	for(int k = 0; k < (int)d[a].size; k++){
	  v[d[a][k]].first--;
	}
	d[a].push_back(i);
      }
    }
    sort(v,v+n);
    printf("%d %s\n", v[0].first, v[0].second);
  }
}

