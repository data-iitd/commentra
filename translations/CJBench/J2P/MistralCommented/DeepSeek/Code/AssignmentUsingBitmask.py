import sys

class Main:
    def __init__(self, task_performed, total_tasks):
        self.total_tasks = total_tasks
        self.dp = [[-1 for _ in range(total_tasks + 1)] for _ in range(2 ** len(task_performed))]
        self.task = [[] for _ in range(total_tasks + 1)]
        self.final_mask = (1 << len(task_performed)) - 1
        for i, tasks in enumerate(task_performed):
            for task_id in tasks:
                self.task[task_id].append(i)

    def count_ways_until(self, mask, task_no):
        if mask == self.final_mask:
            return 1
        if task_no > self.total_tasks:
            return 0
        if self.dp[mask][task_no] != -1:
            return self.dp[mask][task_no]
        total_ways = 0
        for person in self.task[task_no]:
            if mask & (1 << person) == 0:
                total_ways += self.count_ways_until(mask | (1 << person), task_no + 1)
        self.dp[mask][task_no] = total_ways
        return self.dp[mask][task_no]

    def count_no_of_ways(self):
        return self.count_ways_until(0, 1)

if __name__ == "__main__":
    input_data = sys.stdin.readline
    persons = int(input_data().strip())
    tasks = int(input_data().strip())
    task_performed = [[] for _ in range(persons)]
    for i in range(persons):
        while True:
            task = int(input_data().strip())
            if task == -1:
                break
            task_performed[i].append(task)
    assignment = Main(task_performed, tasks)
    result = assignment.count_no_of_ways()
    print("Total number of ways to assign tasks:", result)
