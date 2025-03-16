
import sys

class Main:
    # Declare instance variables
    def __init__(self, taskPerformed, total):
        # Initialize instance variables
        self.totalTasks = total
        self.dp = [[-1 for _ in range(total + 1)] for _ in range(1 << len(taskPerformed))]
        self.task = [[] for _ in range(total + 1)]
        self.finalMask = (1 << len(taskPerformed)) - 1
        for i in range(len(taskPerformed)):
            for j in taskPerformed[i]:
                self.task[j].append(i)

    # Recursive helper method to count ways to reach current state
    def countWaysUntil(self, mask, taskNo):
        # Base case: if mask represents all tasks performed, return 1
        if mask == self.finalMask:
            return 1
        # Base case: if taskNo exceeds total number of tasks, return 0
        if taskNo > self.totalTasks:
            return 0
        # Memoization: if dp[mask][taskNo] is already calculated, return it
        if self.dp[mask][taskNo]!= -1:
            return self.dp[mask][taskNo]
        # Recursive call: count ways to reach next state
        totalWays = 0
        for p in self.task[taskNo]:
            if (mask & (1 << p))!= 0: # Skip if task p is already performed
                continue
            totalWays += self.countWaysUntil(mask | (1 << p), taskNo + 1) # Recursively call with next state
        # Memoization: store the result in dp[mask][taskNo] and return it
        self.dp[mask][taskNo] = totalWays
        return self.dp[mask][taskNo]

    # Method to count total number of ways to assign tasks
    def countNoOfWays(self):
        return self.countWaysUntil(0, 1)

if __name__ == '__main__':
    # Read input
    persons = int(sys.stdin.readline())
    tasks = int(sys.stdin.readline())
    taskPerformed = []
    for i in range(persons):
        taskList = []
        while True:
            task = int(sys.stdin.readline())
            if task == -1:
                break
            taskList.append(task)
        taskPerformed.append(taskList)
    # Create Main object with given input
    assignment = Main(taskPerformed, tasks)
    # Call countNoOfWays() and store result in result
    result = assignment.countNoOfWays()
    # Print result
    print("Total number of ways to assign tasks: " + str(result))

