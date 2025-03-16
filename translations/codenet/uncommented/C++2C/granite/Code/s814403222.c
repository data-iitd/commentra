
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct{
  int first;
  char second[22];
}P;
P v[22];
vector<int> d[33];
int main(void){
  int n;
  while(scanf("%d",&n) && n){
    int m;
    for(int i = 0; i < 33; i++) d[i].clear();
    for(int i = 0; i < n; i++){
      v[i].first = 0;
      scanf("%s %d",v[i].second,&m);
      for(int j = 0; j < m; j++){
	int a;
	scanf("%d",&a);
	v[i].first += n - (int)d[a].size();
	for(int k = 0; k < (int)d[a].size(); k++){
	  v[d[a][k]].first--;
	}
	d[a].push_back(i);
      }
    }
    sort(v,v+n);
    printf("%d %s\n",v[0].first,v[0].second);
  }
}
