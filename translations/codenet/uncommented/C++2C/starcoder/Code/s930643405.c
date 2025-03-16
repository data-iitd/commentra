#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

typedef  pair<int,int> P;

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

