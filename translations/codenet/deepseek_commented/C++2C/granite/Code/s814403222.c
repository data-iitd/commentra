
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct{
  int first;
  char second[22];
}P;
P v[22]; // Array to store n pairs
int d[33][22]; // Array of arrays to store indices

int main(void){
  int n;
  while(scanf("%d",&n) && n){ // Read n until it is zero
    int m;
    for(int i = 0; i < 33; i++){ // Clear all arrays in d
      for(int j = 0; j < 22; j++){
	d[i][j] = 0;
      }
    }
    for(int i = 0; i < n; i++){ // Read m for each element
      v[i].first = 0; // Initialize the first element of v to 0
      scanf("%s %d",v[i].second,&m); // Read the string and m
      for(int j = 0; j < m; j++){ // For each m, read an integer and update v and d
	int a;
	scanf("%d",&a);
	v[i].first += n - d[a][0]; // Update the first element of v
	for(int k = 1; k <= d[a][0]; k++){ // Update the first elements of other v elements
	  v[d[a][k]].first--;
	}
	d[a][++d[a][0]] = i; // Store the index of the current element in d
      }
    }
    qsort(v,n,sizeof(P),cmp); // Sort the array v based on the first element of P
    printf("%d %s\n",v[0].first,v[0].second); // Output the first element of v
  }
  return 0;
}

