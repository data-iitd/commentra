

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int** log = (int**)malloc(sizeof(int*)*1000); // Create a 2D array to store logs for each id
    for(int i=0;i<1000;i++){ // Initialize the 2D array with NULL
      log[i] = NULL;
    }

    for(int i=0;i<N;i++){ // Iterate through each log
      int month,day,hour,min,id; // Read the month, day, hour, minute and id from the standard input
      char action[2]; // Read the action (add or remove) from the standard input

      scanf("%d/%d %d:%d %s %d", // Read the month, day, hour, minute, action and id from the standard input
	    &month,&day,&hour,&min,action,
	    &id);
      
      int t = time2min(month,day,hour,min); // Calculate the total minutes for the log
      if(log[id] == NULL){ // If the 2D array for the current id is NULL, allocate memory for it
	log[id] = (int*)malloc(sizeof(int)*2); // Allocate memory for two integers
      }
      else{ // If the 2D array for the current id is not NULL, reallocate memory for it
	log[id] = (int*)realloc(log[id],sizeof(int)*(2*i+2)); // Reallocate memory for two more integers
      }
      log[id][2*i] = t; // Store the total minutes for the current log in the 2D array
      log[id][2*i+1] = t; // Store the total minutes for the current log in the 2D array
    }

    int total[1000]; // Create an array to store the total time spent for each id
    memset(total,0,sizeof(total)); // Initialize the array with zeros
    
    for(int i=0;i+1<log[0][0];i+=2){ // Iterate through each pair of logs for the id 0
      int god_start = log[0][i]; // Get the start time of the first log
      int god_end = log[0][i+1]; // Get the end time of the first log

      for(int id=0;id<1000;id++){ // Iterate through each id and its logs
	if(log[id] == NULL) continue; // If the 2D array for the current id is NULL, skip the iteration
	for(int j=0;j<log[id][0];j+=2){ // Iterate through each pair of logs for the current id
	  int ppl_start = log[id][j]; // Get the start time of the first log
	  int ppl_end = log[id][j+1]; // Get the end time of the first log
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

    for(int id=0;id<1000;id++){ // Free the memory allocated for the 2D array for each id
      if(log[id]!= NULL){
	free(log[id]);
      }
    }
    free(log); // Free the memory allocated for the 2D array
  }
}

