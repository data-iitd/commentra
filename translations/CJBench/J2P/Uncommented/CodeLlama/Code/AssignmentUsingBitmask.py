
import sys
import itertools

def main():
    persons = int(sys.stdin.readline().strip())
    tasks = int(sys.stdin.readline().strip())
    taskPerformed = []
    for i in range(persons):
        taskList = []
        while True:
            task = int(sys.stdin.readline().strip())
            if task == -1:
                break
            taskList.append(task)
        taskPerformed.append(taskList)
    finalMask = (1 << persons) - 1
    dp = [[-1 for i in range(tasks + 1)] for j in range(finalMask + 1)]
    task = [[] for i in range(tasks + 1)]
    for i in range(persons):
        for j in taskPerformed[i]:
            task[j].append(i)
    def countWaysUntil(mask, taskNo):
        if mask == finalMask:
            return 1
        if taskNo > tasks:
            return 0
        if dp[mask][taskNo] != -1:
            return dp[mask][taskNo]
        totalWays = countWaysUntil(mask, taskNo + 1)
        for p in task[taskNo]:
            if (mask & (1 << p)) != 0:
                continue
            totalWays += countWaysUntil(mask | (1 << p), taskNo + 1)
        dp[mask][taskNo] = totalWays
        return dp[mask][taskNo]
    result = countWaysUntil(0, 1)
    print("Total number of ways to assign tasks: " + str(result))

if __name__ == "__main__":
    main()
    # 