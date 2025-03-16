
import sys

class Main:
    def __init__(self, taskPerformed, total):
        self.totalTasks = total
        self.dp = [[-1 for _ in range(total + 1)] for _ in range(1 << len(taskPerformed))]
        self.task = [[] for _ in range(total + 1)]
        self.finalMask = (1 << len(taskPerformed)) - 1

        for i in range(len(taskPerformed)):
            for j in taskPerformed[i]:
                self.task[j].append(i)

    def countWaysUntil(self, mask, taskNo):
        if mask == self.finalMask:
            return 1
        if taskNo > self.totalTasks:
            return 0
        if self.dp[mask][taskNo]!= -1:
            return self.dp[mask][taskNo]

        totalWays = self.countWaysUntil(mask, taskNo + 1)

        # Assign tasks to all possible persons
        for p in self.task[taskNo]:
            # If the person is already assigned a task
            if (mask & (1 << p))!= 0:
                continue
            totalWays += self.countWaysUntil(mask | (1 << p), taskNo + 1)

        self.dp[mask][taskNo] = totalWays
        return self.dp[mask][taskNo]

    def countNoOfWays(self):
        return self.countWaysUntil(0, 1)

if __name__ == "__main__":
    taskPerformed = []
    total = 0
    for i in range(int(input())):
        taskList = []
        while True:
            task = int(input())
            if task == -1:
                break
            taskList.append(task)
        taskPerformed.append(taskList)
    total = int(input())

    assignment = Main(taskPerformed, total)
    result = assignment.countNoOfWays()

    print("Total number of ways to assign tasks: " + str(result))

