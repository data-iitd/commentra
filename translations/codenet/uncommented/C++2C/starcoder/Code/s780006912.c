#include<stdio.h>
int main(){
  int n;
  int array[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  
  int sum=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      sum+=array[i]*array[j];
    }
  }
  
  printf("%d\n",sum);
  return(0);
}
