
#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  int sq[10000],fr[5000];
  int *com;
  int tmp;

  while(1){
    scanf("%d",&n);
    if(!n)break;

    for(int i=1;i<n;i++)sq[i] = (i*i)%n;
    com = (int *)malloc(sizeof(int)*(n-1));

    int j=0;
    for(int i=1;i<n;i++){
      bool f = true;
      for(int k=0;k<j;k++){
	if(com[k]==sq[i]){
	  f = false;
	  break;
	}
      }
      if(f){
	com[j] = sq[i];
	j++;
      }
    }
 
    for(int i=0;i<=(n-1)/2;i++)fr[i] = 0;

    for(int i=0;i<j;i++){
      for(int k=0;k<j;k++){
	if(i!=k){
	  tmp = com[i]-com[k];
	  if(tmp<0)tmp+=n;
	  if(tmp>(n-1)/2)tmp = n - tmp;
	  fr[tmp]++;
	}
      }
    }

    for(int i=1;i<=(n-1)/2;i++)printf("%d\n",fr[i]);
    free(com);
  }
}

