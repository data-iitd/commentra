#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>
 
using namespace std;
 
typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P > PP;

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

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N;
    while(~sc.nextInt()){
      if(N==0) break;

      Map<Integer,List<Integer> > log = new HashMap<Integer,List<Integer> >();
      for(int i=0;i<N;i++){
	int month,day,hour,min,id;
	char action[2];
	sc.nextInt();
	sc.nextInt();
	sc.nextInt();
	sc.nextInt();
	sc.next();
	sc.nextInt();
	
	int t = time2min(month,day,hour,min);
	log.put(id,new ArrayList<Integer>());
      }

      int total[] = new int[1000];
      for(int i=0;i<1000;i++){
	total[i] = 0;
      }
      
      for(int i=0;i+1<log.get(0).size();i+=2){
	int god_start = log.get(0).get(i);
	int god_end = log.get(0).get(i+1);

	for(Map.Entry<Integer,List<Integer> > it : log.entrySet()){
	  int id = it.getKey();
	  if(id == 0) continue;
	  List<Integer> schedule = it.getValue();
	  for(int j=0;j<schedule.size();j+=2){
	    int ppl_start = schedule.get(j);
	    int ppl_end = schedule.get(j+1);
	    int start = Math.max(god_start,ppl_start);
	    int end = Math.min(god_end,ppl_end);
	    total[id] += Math.max(0,end-start);
	  }
	}
      }

      int max_v = 0;
      for(int id=0;id<1000;id++){
	max_v = Math.max(total[id],max_v);
      }
      System.out.println(max_v);
    }
  }
}

