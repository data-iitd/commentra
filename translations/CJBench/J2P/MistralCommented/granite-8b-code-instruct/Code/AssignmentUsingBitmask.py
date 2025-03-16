

import sys

def count_ways_until(mask, task_no):
    # Base case: if mask represents all tasks performed, return 1
    if mask == final_mask:
        return 1
    # Base case: if task_no exceeds total number of tasks, return 0
    if task_no > total_tasks:
        return 0
    # Memoization: if dp[mask][task_no] is already calculated, return it
    if dp[mask][task_no]!= -1:
        return dp[mask][task_no]
    # Recursive call: count ways to reach next state
    total_ways = 0
    for p in task[task_no]:
        if (mask & (1 << p))!= 0: # Skip if task p is already performed
            continue
        total_ways += count_ways_until(mask | (1 << p), task_no + 1) # Recursively call with next state
    # Memoization: store the result in dp[mask][task_no] and return it
    dp[mask][task_no] = total_ways
    return dp[mask][task_no]

def count_no_of_ways():
    return count_ways_until(0, 1)

# Main method to read input and call count_no_of_ways()
if __name__ == "__main__":
    persons, tasks = map(int, input().split()) # Read number of persons and tasks
    task_performed = [] # Initialize task_performed list
    for _ in range(persons): # Read tasks performed by each person
        task_list = []
        while True:
            task = int(input())
            if task == -1:
                break
            task_list.append(task)
        task_performed.append(task_list)
    total_tasks = tasks
    final_mask = (1 << len(task_performed[0])) - 1 # Calculate final_mask
    dp = [[-1 for _ in range(total_tasks + 1)] for _ in range(1 << len(task_performed[0]))] # Initialize dp matrix with -1
    task = [[] for _ in range(total_tasks + 1)] # Initialize task list with empty list
    for i in range(len(task_performed)):
        for j in task_performed[i]:
            task[j].append(i) # Add index of task i to the list of tasks that can be performed by person j
    result = count_no_of_ways() # Call count_no_of_ways() and store result in result
    print("Total number of ways to assign tasks:", result) # Print result
    sys.exit(0) # Exit program

Translate the above Python code to C++ and end with comment "