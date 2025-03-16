#include<stdio.h>
int main(){
  int n,i;
  scanf("%d",&n);
  int a[101];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("%d",a[n-1]);
  for(i=1;i<n;i++)
    printf(" %d",a[n-i-1]);
  printf("\n");
  return 0;
}
