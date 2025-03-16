from typing import List

class Main:
    def __init__(self, task_performed: List[List[int]], total: int):
        self.total_tasks = total
        self.dp = [[-1] * (total + 1) for _ in range(1 << len(task_performed))]
        self.task = [[] for _ in range(total + 1)]
        self.final_mask = (1 << len(task_performed)) - 1
        
        for i in range(len(task_performed)):
            for j in task_performed[i]:
                self.task[j].append(i)

    def count_ways_until(self, mask: int, task_no: int) -> int:
        if mask == self.final_mask:
            return 1
        if task_no > self.total_tasks:
            return 0
        if self.dp[mask][task_no] != -1:
            return self.dp[mask][task_no]
        
        total_ways = 0
        for p in self.task[task_no]:
            if (mask & (1 << p)) != 0:
                continue
            total_ways += self.count_ways_until(mask | (1 << p), task_no + 1)
        
        self.dp[mask][task_no] = total_ways
        return self.dp[mask][task_no]

    def count_no_of_ways(self) -> int:
        return self.count_ways_until(0, 1)

if __name__ == "__main__":
    persons = int(input("Enter number of persons: "))  # Read number of persons
    tasks = int(input("Enter number of tasks: "))      # Read number of tasks
    task_performed = []                                  # Initialize task_performed list
    
    for _ in range(persons):                            # Read tasks performed by each person
        task_list = []
        while True:
            task = int(input("Enter task (or -1 to stop): "))
            if task == -1:
                break
            task_list.append(task)
        task_performed.append(task_list)
    
    assignment = Main(task_performed, tasks)           # Create Main object with given input
    result = assignment.count_no_of_ways()             # Call count_no_of_ways() and store result
    print("Total number of ways to assign tasks:", result)  # Print result
