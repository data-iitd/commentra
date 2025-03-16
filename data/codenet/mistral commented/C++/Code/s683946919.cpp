
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

// Function to convert date, hour and minute to total minutes
int time2min(int month,int day,int hour,int min){
  const int total_day_of_month[]
    = {31,28,31,30,31,30,31,31,30,31,30,31}; // Total days in each month
  int total = 0;
  for(int i=1;i<month;i++){ // Calculate total minutes for each month before the current one
    total += total_day_of_month[i]*24*60;
  }
  for(int i=1;i<day;i++){ // Calculate total minutes for each day before the current one
    total += 24*60;
  }
  total += hour * 60 + min; // Calculate total minutes for the current hour and minute

  return total;
}

int main(){
  int N; // Number of logs
  while(~scanf("%d",&N)){ // Read the number of logs from the standard input
    if(N==0) break; // If the number of logs is zero, break the loop

    map<int,vector<int> > log; // Create a map to store logs for each id
    for(int i=0;i<N;i++){ // Iterate through each log
      int month,day,hour,min,id; // Read the month, day, hour, minute and id from the standard input
      char action[2]; // Read the action (add or remove) from the standard input

      scanf("%d/%d %d:%d %s %d", // Read the month, day, hour, minute, action and id from the standard input
	    &month,&day,&hour,&min,action,
	    &id);
      
      int t = time2min(month,day,hour,min); // Calculate the total minutes for the log
      log[id].push_back(t); // Add the total minutes to the vector of logs for the id
    }

    int total[1000]; // Create an array to store the total time spent for each id
    memset(total,0,sizeof(total)); // Initialize the array with zeros
    
    for(int i=0;i+1<log[0].size();i+=2){ // Iterate through each pair of logs for the id 0
      int god_start = log[0][i]; // Get the start time of the first log
      int god_end = log[0][i+1]; // Get the end time of the first log

      for(map<int,vector<int> >::iterator it = log.begin(); // Iterate through each id and its logs
	  it != log.end();
	  it++){
	int id = it->first; // Get the id
	if(id == 0) continue; // If the id is 0, skip the iteration
	vector<int>& schedule = it->second; // Get the vector of logs for the id
	for(int j=0;j<schedule.size();j+=2){ // Iterate through each pair of logs for the current id
	  int ppl_start = schedule[j]; // Get the start time of the first log
	  int ppl_end = schedule[j+1]; // Get the end time of the first log
	  int start = max(god_start,ppl_start); // Get the maximum start time between the logs of god and people
	  int end = min(god_end,ppl_end); // Get the minimum end time between the logs of god and people
	  total[id] += max(0,end-start); // Calculate and add the total time spent for the current id
	}
      }
    }

    int max_v = 0; // Initialize the maximum total time spent to zero
    for(int id=0;id<1000;id++){ // Iterate through each id and find the maximum total time spent
      max_v = max(total[id],max_v);
    }
    printf("%d\n",max_v); // Print the maximum total time spent
  }
}