#include <stdio.h>
int main(void){
  int n,r,p,c;
  int i,j,k,l;
  int a[51],b[51];

  while( 1 ){
    scanf("%d %d ",&n,&r);
    if( !n && !r )
      break;

    for( i=0;i<n;i++)
      a[i]=i+1;

    for( i=0;i<r;i++){
      scanf("%d %d ",&p,&c );

      # <START-OF-CODE>
      # 