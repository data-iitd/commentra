#include<stdio.h>
int main(){
  int n,a[101],i;
  scanf("%d", &n);
  for(i=0; i<n;i++)
  scanf("%d", &a[i]);
  printf("%d", a[n-1]);
  for(i=1;i<n;i++)
  printf(" %d", a[n-i-1]);
  printf("\n");
  return 0;
}

