def count_ways_until(mask, task_no, dp, final_mask, task, total_tasks):
    if mask == final_mask:
        return 1
    if task_no > total_tasks:
        return 0
    if dp[mask][task_no] != -1:
        return dp[mask][task_no]
    total_ways = count_ways_until(mask, task_no + 1, dp, final_mask, task, total_tasks)
    for p in task[task_no]:
        if (mask & (1 << p)) != 0:
            continue
        total_ways += count_ways_until(mask | (1 << p), task_no + 1, dp, final_mask, task, total_tasks)
    dp[mask][task_no] = total_ways
    return dp[mask][task_no]

def count_no_of_ways(task_performed, total_tasks):
    persons = len(task_performed)
    final_mask = (1 << persons) - 1
    dp = [[-1 for _ in range(total_tasks + 1)] for _ in range(1 << persons)]
    task = [[] for _ in range(total_tasks + 1)]
    for i in range(persons):
        for j in task_performed[i]:
            task[j].append(i)
    return count_ways_until(0, 1, dp, final_mask, task, total_tasks)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    persons = int(data[index])
    tasks = int(data[index + 1])
    index += 2
    task_performed = [[] for _ in range(persons)]
    for i in range(persons):
        while True:
            task = int(data[index])
            index += 1
            if task == -1:
                break
            task_performed[i].append(task)
    result = count_no_of_ways(task_performed, tasks)
    print("Total number of ways to assign tasks:", result)
