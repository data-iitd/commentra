

import sys
def count_ways_until(mask, task_no, dp, task):
    if mask == final_mask:
        return 1
    if task_no > total_tasks:
        return 0
    if dp[mask][task_no]!= -1:
        return dp[mask][task_no]
    total_ways = count_ways_until(mask, task_no + 1, dp, task)
    for p in task[task_no]:
        if (mask & (1 << p))!= 0:
            continue
        total_ways += count_ways_until(mask | (1 << p), task_no + 1, dp, task)
    dp[mask][task_no] = total_ways
    return dp[mask][task_no]
def count_no_of_ways():
    return count_ways_until(0, 1, dp, task)
if __name__ == "__main__":
    persons, tasks = map(int, input().split())
    task_performed = []
    for _ in range(persons):
        task_list = []
        while True:
            task = int(input())
            if task == -1:
                break
            task_list.append(task)
        task_performed.append(task_list)
    dp = [[-1 for _ in range(tasks + 1)] for _ in range(1 << len(task_performed))]
    final_mask = (1 << len(task_performed)) - 1
    task = [[] for _ in range(tasks + 1)]
    for i in range(len(task_performed)):
        for j in task_performed[i]:
            task[j].append(i)
    total_tasks = tasks
    result = count_no_of_ways()
    print("Total number of ways to assign tasks:", result)