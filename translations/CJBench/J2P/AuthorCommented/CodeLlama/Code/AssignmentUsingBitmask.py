

import sys


def main():
    # Read input
    n_persons, n_tasks = map(int, sys.stdin.readline().split())
    task_performed = []
    for _ in range(n_persons):
        task_performed.append(list(map(int, sys.stdin.readline().split())))

    # Initialize dp
    dp = [[-1 for _ in range(n_tasks + 1)] for _ in range(1 << n_persons)]

    # Fill task list
    task = [[] for _ in range(n_tasks + 1)]
    for i in range(n_tasks):
        for j in task_performed[i]:
            task[i].append(j)

    # Final mask to check if all persons are included
    final_mask = (1 << n_persons) - 1

    # Count number of ways
    result = count_ways_until(0, 1, dp, task, final_mask)

    # Print result
    print("Total number of ways to assign tasks:", result)


def count_ways_until(mask, task_no, dp, task, final_mask):
    if mask == final_mask:
        return 1
    if task_no > n_tasks:
        return 0
    if dp[mask][task_no] != -1:
        return dp[mask][task_no]

    total_ways = count_ways_until(mask, task_no + 1, dp, task, final_mask)

    # Assign tasks to all possible persons
    for p in task[task_no]:
        # If the person is already assigned a task
        if mask & (1 << p):
            continue
        total_ways += count_ways_until(mask | (1 << p), task_no + 1, dp, task, final_mask)

    dp[mask][task_no] = total_ways
    return dp[mask][task_no]


if __name__ == "__main__":
    main()

