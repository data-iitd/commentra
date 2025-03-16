#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

#define N 1000
#define INF 0x3f3f3f3f

int time2min(int month,int day,int hour,int min){
  const int total_day_of_month[]
    = {31,28,31,30,31,30,31,31,30,31,30,31};
  int total = 0;
  for(int i=1;i<month;i++){
    total += total_day_of_month[i]*24*60;
  }
  for(int i=1;i<day;i++){
    total += 24*60;
  }
  total += hour * 60 + min;

  return total;
}

int main(){
  int N;
  while(~scanf("%d",&N)){
    if(N==0) break;

    int log[N][2];
    for(int i=0;i<N;i++){
      int month,day,hour,min,id;
      char action[2];
      scanf("%d/%d %d:%d %s %d",
	    &month,&day,&hour,&min,action,
	    &id);
      
      int t = time2min(month,day,hour,min);
      log[id][0] = t;
      log[id][1] = t;
    }

    int total[1000];
    memset(total,0,sizeof(total));
    
    for(int i=0;i+1<log[0][1];i+=2){
      int god_start = log[0][0];
      int god_end = log[0][1];

      for(int j=1;j<N;j++){
	int ppl_start = log[j][0];
	int ppl_end = log[j][1];
	int start = max(god_start,ppl_start);
	int end = min(god_end,ppl_end);
	total[j] += max(0,end-start);
      }
    }

    int max_v = 0;
    for(int id=0;id<1000;id++){
      max_v = max(total[id],max_v);
    }
    printf("%d\n",max_v);
  }
}

