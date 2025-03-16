
import sys

def main():
    # Read input
    persons, tasks = map(int, sys.stdin.readline().split())
    taskPerformed = []
    for i in range(persons):
        taskList = []
        while True:
            task = int(sys.stdin.readline())
            if task == -1:
                break
            taskList.append(task)
        taskPerformed.append(taskList)
    # Initialize instance variables
    totalTasks = tasks
    dp = [[-1 for i in range(totalTasks + 1)] for j in range(1 << persons)]
    task = [[] for i in range(totalTasks + 1)]
    for i in range(persons):
        for j in taskPerformed[i]:
            task[j].append(i)
    finalMask = (1 << persons) - 1
    # Recursive helper method to count ways to reach current state
    def countWaysUntil(mask, taskNo):
        # Base case: if mask represents all tasks performed, return 1
        if mask == finalMask:
            return 1
        # Base case: if taskNo exceeds total number of tasks, return 0
        if taskNo > totalTasks:
            return 0
        # Memoization: if dp[mask][taskNo] is already calculated, return it
        if dp[mask][taskNo] != -1:
            return dp[mask][taskNo]
        # Recursive call: count ways to reach next state
        totalWays = 0
        for p in task[taskNo]:
            if (mask & (1 << p)) != 0: # Skip if task p is already performed
                continue
            totalWays += countWaysUntil(mask | (1 << p), taskNo + 1) # Recursively call with next state
        # Memoization: store the result in dp[mask][taskNo] and return it
        dp[mask][taskNo] = totalWays
        return dp[mask][taskNo]
    # Method to count total number of ways to assign tasks
    def countNoOfWays():
        return countWaysUntil(0, 1)
    # Main method to read input and call countNoOfWays()
    result = countNoOfWays()
    print("Total number of ways to assign tasks: " + str(result))

if __name__ == "__main__":
    main()

