
import sys

# Function to count the number of ways to assign tasks
def count_ways(task_performed, total_tasks):
    # Initialize dp array with size based on number of persons and total tasks
    dp = [[-1 for _ in range(total_tasks + 1)] for _ in range(1 << len(task_performed))]
    # List to hold the tasks that can be performed by each person
    task = [[] for _ in range(total_tasks + 1)]
    # Calculate the final mask representing all tasks assigned
    final_mask = (1 << len(task_performed)) - 1
    # Populate the task list with tasks each person can perform
    for i, tasks in enumerate(task_performed):
        for j in tasks:
            task[j].append(i)
    # Recursive method to count the number of ways to assign tasks
    def count_ways_until(mask, task_no):
        # Base case: if all tasks are assigned, return 1
        if mask == final_mask:
            return 1
        # Base case: if all tasks have been considered, return 0
        if task_no > total_tasks:
            return 0
        # Return the cached result if already computed
        if dp[mask][task_no]!= -1:
            return dp[mask][task_no]
        # Count ways without assigning the current task
        total_ways = count_ways_until(mask, task_no + 1)
        # Iterate through all persons who can perform the current task
        for p in task[task_no]:
            # Skip if the person has already been assigned a task
            if mask & (1 << p):
                continue
            # Count ways by assigning the current task to the person
            total_ways += count_ways_until(mask | (1 << p), task_no + 1)
        # Store the computed result in dp table
        dp[mask][task_no] = total_ways
        return dp[mask][task_no]
    # Count the number of ways to assign tasks
    result = count_ways_until(0, 1)
    # Output the result
    print("Total number of ways to assign tasks:", result)

# Main method to execute the program
def main():
    # Read the number of persons and tasks
    persons, tasks = map(int, input().split())
    # Initialize list to hold tasks performed by each person
    task_performed = [[] for _ in range(persons)]
    # Read tasks performed by each person
    for i in range(persons):
        tasks_list = []
        while True:
            task = int(input())
            # Break if the input task is -1
            if task == -1:
                break
            tasks_list.append(task)
        task_performed[i] = tasks_list
    # Call the count_ways function with the tasks performed and total tasks
    count_ways(task_performed, tasks)

# Execute the main method
if __name__ == "__main__":
    main()

