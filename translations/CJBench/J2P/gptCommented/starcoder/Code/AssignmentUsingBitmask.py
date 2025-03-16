import sys

# Total number of tasks to be assigned
total_tasks = 0
# Dynamic programming table to store results of subproblems
dp = []
# List to hold the tasks that can be performed by each person
task = []
# Final mask representing all tasks have been assigned
final_mask = 0

# Constructor to initialize the Main class with tasks performed by persons and total tasks
def __init__(self, task_performed, total):
    self.total_tasks = total
    # Initialize dp array with size based on number of persons and total tasks
    self.dp = [[-1 for i in range(total + 1)] for j in range(1 << task_performed.size())]
    # Fill dp array with -1 to indicate uncomputed states
    for row in self.dp:
        for i in range(len(row)):
            row[i] = -1
    # Initialize task list to hold tasks for each person
    self.task = [[] for i in range(total + 1)]
    # Calculate the final mask representing all tasks assigned
    self.final_mask = (1 << task_performed.size()) - 1
    # Populate the task list with tasks each person can perform
    for i in range(task_performed.size()):
        for j in task_performed.get(i):
            self.task[j].append(i)

# Recursive method to count the number of ways to assign tasks
def count_ways_until(self, mask, task_no):
    # Base case: if all tasks are assigned, return 1
    if mask == self.final_mask:
        return 1
    # Base case: if all tasks have been considered, return 0
    if task_no > self.total_tasks:
        return 0
    # Return the cached result if already computed
    if self.dp[mask][task_no]!= -1:
        return self.dp[mask][task_no]
    # Count ways without assigning the current task
    total_ways = self.count_ways_until(mask, task_no + 1)
    # Iterate through all persons who can perform the current task
    for p in self.task[task_no]:
        # Skip if the person has already been assigned a task
        if (mask & (1 << p))!= 0:
            continue
        # Count ways by assigning the current task to the person
        total_ways += self.count_ways_until(mask | (1 << p), task_no + 1)
    # Store the computed result in dp table
    self.dp[mask][task_no] = total_ways
    return self.dp[mask][task_no]

# Public method to initiate the counting of ways to assign tasks
def count_no_of_ways(self):
    return self.count_ways_until(0, 1)

# Main method to execute the program
def main():
    # Read the number of persons and tasks
    persons, tasks = map(int, sys.stdin.readline().split())
    # Initialize list to hold tasks performed by each person
    task_performed = []
    # Read tasks performed by each person
    for i in range(persons):
        task_list = []
        while True:
            task = int(sys.stdin.readline())
            # Break if the input task is -1
            if task == -1:
                break
            task_list.append(task)
        task_performed.append(task_list)
    # Create an instance of Main with the tasks performed and total tasks
    assignment = Main(task_performed, tasks)
    # Count the number of ways to assign tasks
    result = assignment.count_no_of_ways()
    # Output the result
    print("Total number of ways to assign tasks: " + str(result))

# Entry point of the program
if __name__ == "__main__":
    main()

