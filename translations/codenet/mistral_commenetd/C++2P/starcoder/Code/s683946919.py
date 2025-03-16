
#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
import sys
import math

# Function to convert date, hour and minute to total minutes
def time2min(month,day,hour,min):
  total_day_of_month = [31,28,31,30,31,30,31,31,30,31,30,31] # Total days in each month
  total = 0
  for i in range(1,month): # Calculate total minutes for each month before the current one
    total += total_day_of_month[i]*24*60
  for i in range(1,day): # Calculate total minutes for each day before the current one
    total += 24*60
  total += hour * 60 + min # Calculate total minutes for the current hour and minute

  return total

while True:
  N = int(input()) # Read the number of logs from the standard input
  if N == 0: break # If the number of logs is zero, break the loop

  log = {} # Create a map to store logs for each id
  for i in range(N): # Iterate through each log
    month,day,hour,min,action,id = map(int,input().split()) # Read the month, day, hour, minute, action and id from the standard input
    t = time2min(month,day,hour,min) # Calculate the total minutes for the log
    if id in log: # If the id is already in the map, add the total minutes to the vector of logs for the id
      log[id].append(t)
    else: # If the id is not in the map, add the id to the map and add the total minutes to the vector of logs for the id
      log[id] = [t]

  total = [0]*1000 # Create an array to store the total time spent for each id
  for i in range(0,len(log[0])-1,2): # Iterate through each pair of logs for the id 0
    god_start = log[0][i] # Get the start time of the first log
    god_end = log[0][i+1] # Get the end time of the first log

    for id in log: # Iterate through each id and its logs
      if id == 0: continue # If the id is 0, skip the iteration
      schedule = log[id] # Get the vector of logs for the id
      for j in range(0,len(schedule)-1,2): # Iterate through each pair of logs for the current id
	ppl_start = schedule[j] # Get the start time of the first log
	ppl_end = schedule[j+1] # Get the end time of the first log
	start = max(god_start,ppl_start) # Get the maximum start time between the logs of god and people
	end = min(god_end,ppl_end) # Get the minimum end time between the logs of god and people
	total[id] += max(0,end-start) # Calculate and add the total time spent for the current id

  max_v = 0 # Initialize the maximum total time spent to zero
  for id in range(1000): # Iterate through each id and find the maximum total time spent
    max_v = max(total[id],max_v)
  print(max_v) # Print the maximum total time spent

