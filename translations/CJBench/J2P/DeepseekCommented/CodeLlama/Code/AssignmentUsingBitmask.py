import sys

# The Main class is defined as final, ensuring it cannot be extended by other classes.
class Main:
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
        self.task = [[] for i in range(totalTasks + 1)]
        for i in range(taskPerformed.size()):
            for j in taskPerformed.get(i):
                self.task.get(j).add(i)
        self.finalMask = (1 << taskPerformed.size()) - 1

    # Recursively counts the number of ways to assign tasks using dynamic programming.
    def countWaysUntil(self, mask, taskNo):
        if mask == self.finalMask:
            return 1
        if taskNo > self.totalTasks:
            return 0
        if self.dp[mask][taskNo] != -1:
            return self.dp[mask][taskNo]
        totalWays = self.countWaysUntil(mask, taskNo + 1)
        for p in self.task.get(taskNo):
            if (mask & (1 << p)) != 0:
                continue
            totalWays += self.countWaysUntil(mask | (1 << p), taskNo + 1)
        self.dp[mask][taskNo] = totalWays
        return self.dp[mask][taskNo]

    # Calls the recursive method to count the number of ways to assign tasks starting with an empty mask and task number 1.
    def countNoOfWays(self):
        return self.countWaysUntil(0, 1)

    # Main method to read input, create an instance of Main, and print the total number of ways to assign tasks.
    def main(self):
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
        assignment = Main(taskPerformed, tasks)
        result = assignment.countNoOfWays()
        print("Total number of ways to assign tasks: " + str(result))

if __name__ == "__main__":
    Main().main()
