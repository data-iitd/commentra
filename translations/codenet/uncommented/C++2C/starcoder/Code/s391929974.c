#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  int sq[10000],fr[5000];
  int com[10000];
  int tmp;

  while(1){
    scanf("%d",&n);
    if(!n)break;

    for(int i=1;i<n;i++)sq[i] = (i*i)%n;
    int c = 0;

    for(int i=1;i<n;i++){
      int f = 1;
      for(int j=0;j<c;j++){
	if(com[j]==sq[i]){
	  f = 0;
	  break;
	}
      }
      if(f)com[c++] = sq[i];
    }
 
    for(int i=0;i<=(n-1)/2;i++)fr[i] = 0;

    for(int i=0;i<c;i++){
      for(int j=0;j<c;j++){
	if(i!=j){
	  tmp = com[i]-com[j];
	  if(tmp<0)tmp+=n;
	  if(tmp>(n-1)/2)tmp = n - tmp;
	  fr[tmp]++;
	}
      }
    }

    for(int i=1;i<=(n-1)/2;i++)printf("%d\n",fr[i]);
  }
}
