
import sys

# The Main class is defined as final, ensuring it cannot be extended by other classes.
class Main:
    # Variable to store the total number of tasks.
    total_tasks = 0
    # 2D array used for dynamic programming to store the number of ways to assign tasks.
    dp = []
    # List of lists to store the tasks each person can perform.
    task = []
    # Integer representing the final mask used to check if all tasks are assigned.
    final_mask = 0

    # Constructor to initialize the class variables.
    def __init__(self, task_performed, total):
        self.total_tasks = total
        self.dp = [[-1 for _ in range(total + 1)] for _ in range(1 << len(task_performed))]
        self.task = [[] for _ in range(total + 1)]
        self.final_mask = (1 << len(task_performed)) - 1
        for i in range(len(task_performed)):
            for j in task_performed[i]:
                self.task[j].append(i)

    # Recursively counts the number of ways to assign tasks using dynamic programming.
    def count_ways_until(self, mask, task_no):
        if mask == self.final_mask:
            return 1
        if task_no > self.total_tasks:
            return 0
        if self.dp[mask][task_no]!= -1:
            return self.dp[mask][task_no]
        total_ways = self.count_ways_until(mask, task_no + 1)
        for p in self.task[task_no]:
            if (mask & (1 << p))!= 0:
                continue
            total_ways += self.count_ways_until(mask | (1 << p), task_no + 1)
        self.dp[mask][task_no] = total_ways
        return self.dp[mask][task_no]

    # Calls the recursive method to count the number of ways to assign tasks starting with an empty mask and task number 1.
    def count_no_of_ways(self):
        return self.count_ways_until(0, 1)

# Main method to read input, create an instance of Main, and print the total number of ways to assign tasks.
def main():
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
    assignment = Main(task_performed, tasks)
    result = assignment.count_no_of_ways()
    print("Total number of ways to assign tasks:", result)

if __name__ == "__main__":
    sys.exit(main())

