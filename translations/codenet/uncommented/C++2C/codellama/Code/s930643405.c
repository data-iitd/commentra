#include <stdio.h>
#include <stdbool.h>

typedef  struct{
     int a;
     int b;
}P;

     bool d[10]={0};
     int n,k;
     bool hantei=true;




int main(){
      scanf("%d%d",&n,&k);
     for(int i=0;i<k;++i){
          int a;
          scanf("%d",&a);
          d[a]=1;
     }
     while(1){
          int x=n;
          hantei=1;
          while(x){
               if(d[x%10]){
                    hantei=0;
                    break;
               }
               x/=10;
          }
          if(hantei){
               printf("%d\n",n);
               break;
          }
          n++;
     }
}

