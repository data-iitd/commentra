
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef  pair<int,int> P;

     bool d[10]={0};
     int n,k;
     bool hantei=true;




int main(){
      scanf("%d %d",&n,&k);
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
