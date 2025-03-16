import sys

class Main:
    def __init__(self, taskPerformed, total):
        self.totalTasks = total
        self.dp = [[-1 for _ in range(total + 1)] for _ in range(2 ** len(taskPerformed))]
        self.task = [[] for _ in range(total + 1)]
        self.finalMask = (1 << len(taskPerformed)) - 1

        for i, tasks in enumerate(taskPerformed):
            for task in tasks:
                self.task[task].append(i)

    def countWaysUntil(self, mask, taskNo):
        if mask == self.finalMask:
            return 1
        if taskNo > self.totalTasks:
            return 0
        if self.dp[mask][taskNo] != -1:
            return self.dp[mask][taskNo]

        totalWays = self.countWaysUntil(mask, taskNo + 1)

        for p in self.task[taskNo]:
            if mask & (1 << p) != 0:
                continue
            totalWays += self.countWaysUntil(mask | (1 << p), taskNo + 1)

        self.dp[mask][taskNo] = totalWays
        return self.dp[mask][taskNo]

    def countNoOfWays(self):
        return self.countWaysUntil(0, 1)

if __name__ == "__main__":
    input_data = sys.stdin.readline
    persons = int(input_data().split()[0])
    tasks = int(input_data().split()[1])

    taskPerformed = []
    for _ in range(persons):
        taskList = list(map(int, input_data().split()))
        taskPerformed.append(taskList[:-1])

    assignment = Main(taskPerformed, tasks)
    result = assignment.countNoOfWays()

    print("Total number of ways to assign tasks:", result)
