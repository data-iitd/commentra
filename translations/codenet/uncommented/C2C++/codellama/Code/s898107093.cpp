#include<string.h>
#include<stdlib.h>
#include<stdio.h>


int main(){
  char **t,**h;
  int n,taro=0,hanako=0,i;
  scanf("%d",&n);
  t=new char*[n];
  h=new char*[n];
  for(i=0;i<n;i++){
    t[i]=new char[100];
    h[i]=new char[100];
    scanf("%s",t[i]);
    scanf("%s",h[i]);
    if(strcmp(t[i],h[i])<0) hanako+=3;
    if(strcmp(t[i],h[i])>0) taro+=3;
    if(strcmp(t[i],h[i])==0){
      taro+=1;
      hanako+=1;
    }
    delete[] t[i];
    delete[] h[i];
  }
  delete[] t;
  delete[] h;
  printf("%d %d\n",taro,hanako);
  return 0;
}

