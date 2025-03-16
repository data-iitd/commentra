import sys

# The Main class is defined as final, ensuring it cannot be extended by other classes.
class Main(object):
    # Variable to store the total number of tasks.
    totalTasks = 0
    # 2D array used for dynamic programming to store the number of ways to assign tasks.
    dp = []
    # List of lists to store the tasks each person can perform.
    task = []
    # Integer representing the final mask used to check if all tasks are assigned.
    finalMask = 0

    # Constructor to initialize the class variables.
    def __init__(self, taskPerformed, total):
        self.totalTasks = total
        self.dp = [[-1 for i in range(total + 1)] for j in range(1 << taskPerformed.size())]
        for row in self.dp:
            for i in range(len(row)):
                row[i] = -1 # Initialize the dp array with -1 to indicate unvisited states.
        self.task = [[] for i in range(total + 1)]
        for i in range(total + 1):
            self.task[i] = [] # Initialize the task list with empty lists for each task.
        self.finalMask = (1 << taskPerformed.size()) - 1 # Calculate the final mask.
        for i in range(taskPerformed.size()):
            for j in taskPerformed.get(i):
                self.task[j].append(i) # Populate the task list with the tasks each person can perform.

    # Recursively counts the number of ways to assign tasks using dynamic programming.
    def countWaysUntil(self, mask, taskNo):
        if mask == self.finalMask: # If all tasks are assigned, return 1.
            return 1
        if taskNo > self.totalTasks: # If all tasks are considered, return 0.
            return 0
        if self.dp[mask][taskNo]!= -1: # If the state is already computed, return the stored value.
            return self.dp[mask][taskNo]
        totalWays = self.countWaysUntil(mask, taskNo + 1) # Skip the current task.
        for p in self.task[taskNo]:
            if (mask & (1 << p))!= 0: # If the task is already assigned, skip it.
                continue
            totalWays += self.countWaysUntil(mask | (1 << p), taskNo + 1) # Assign the task to someone.
        self.dp[mask][taskNo] = totalWays # Store the computed value in dp array.
        return self.dp[mask][taskNo]

    # Calls the recursive method to count the number of ways to assign tasks starting with an empty mask and task number 1.
    def countNoOfWays(self):
        return self.countWaysUntil(0, 1)

# Main method to read input, create an instance of Main, and print the total number of ways to assign tasks.
if __name__ == "__main__":
    taskPerformed = []
    total = 0
    for i in range(int(raw_input())):
        taskList = []
        while True:
            task = int(raw_input())
            if task == -1:
                break
            taskList.append(task)
        taskPerformed.append(taskList)
    total = int(raw_input())
    assignment = Main(taskPerformed, total)
    result = assignment.countNoOfWays()
    print "Total number of ways to assign tasks: " + str(result)

