import sys

# Total number of tasks to be assigned
totalTasks = int(sys.stdin.readline())
# Dynamic programming table to store results of subproblems
dp = [[-1 for i in range(totalTasks + 1)] for j in range(1 << totalTasks)]
# List to hold the tasks that can be performed by each person
task = [[] for i in range(totalTasks + 1)]
# Final mask representing all tasks have been assigned
finalMask = (1 << totalTasks) - 1
# Populate the task list with tasks each person can perform
for i in range(totalTasks):
    for j in map(int, sys.stdin.readline().split()):
        task[j].append(i)

# Recursive method to count the number of ways to assign tasks
def countWaysUntil(mask, taskNo):
    # Base case: if all tasks are assigned, return 1
    if mask == finalMask:
        return 1
    # Base case: if all tasks have been considered, return 0
    if taskNo > totalTasks:
        return 0
    # Return the cached result if already computed
    if dp[mask][taskNo] != -1:
        return dp[mask][taskNo]
    # Count ways without assigning the current task
    totalWays = countWaysUntil(mask, taskNo + 1)
    # Iterate through all persons who can perform the current task
    for p in task[taskNo]:
        # Skip if the person has already been assigned a task
        if (mask & (1 << p)) != 0:
            continue
        # Count ways by assigning the current task to the person
        totalWays += countWaysUntil(mask | (1 << p), taskNo + 1)
    # Store the computed result in dp table
    dp[mask][taskNo] = totalWays
    return dp[mask][taskNo]

# Public method to initiate the counting of ways to assign tasks
def countNoOfWays():
    return countWaysUntil(0, 1)

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of persons and tasks
    persons = int(sys.stdin.readline())
    tasks = int(sys.stdin.readline())
    # Initialize list to hold tasks performed by each person
    taskPerformed = [[] for i in range(persons)]
    # Read tasks performed by each person
    for i in range(persons):
        while True:
            task = int(sys.stdin.readline())
            # Break if the input task is -1
            if task == -1:
                break
            taskPerformed[i].append(task)
    # Create an instance of Main with the tasks performed and total tasks
    assignment = Main(taskPerformed, tasks)
    # Count the number of ways to assign tasks
    result = assignment.countNoOfWays()
    # Output the result
    print("Total number of ways to assign tasks: " + str(result))

