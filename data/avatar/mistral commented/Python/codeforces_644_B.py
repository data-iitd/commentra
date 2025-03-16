# Importing the queue module for implementing a First-In-First-Out (FIFO) queue
import queue

# Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
n, b = list(map(int, input().split()))

# Defining a Task class to store the time, duration, and index of each task
class Task:
    def __init__(self, time: int, duration: int, index: int) -> None:
        # Initializing the parent class (object)
        super().__init__()
        # Initializing the instance variables for time, duration, and index
        self.time = time
        self.duration = duration
        self.index = index

# Initializing an empty queue for storing the tasks to be executed
remaining = queue.Queue()

# Initializing some variables for tracking the current finish time and whether any task is currently running
running = False
finish_time = 0

# Function to execute the next task in the queue and update the finish time and result accordingly
def run_task(remaining: queue.Queue, finish_time: int) -> tuple:
    # Getting the next task from the queue
    task_to_run = remaining.get()
    # Updating the finish time based on the current task's time and duration
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration
    # Updating the result dictionary with the finish time for the current task
    result[task_to_run.index] = finish_time
    # Returning the updated finish time and result dictionary
    return finish_time, result

# Initializing an empty dictionary for storing the finish time for each task
result = {}

# Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
for i in range(n):
    time, duration = list(map(int, input().split()))
    # Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
    task = Task(time, duration, index=i)
    result.update({i: 0})
    # If the current task can be executed immediately, update the finish time and result accordingly
    if task.time > finish_time and remaining.empty():
        running = True
        finish_time = task.time + task.duration
        result[i] = finish_time
    # If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
    elif task.time >= finish_time and not remaining.empty():
        finish_time, result = run_task(remaining=remaining, finish_time=finish_time)
        if remaining.qsize() < b:
            remaining.put(task)
        else:
            result[i] = -1
# Executing the remaining tasks in the queue, if any
while not remaining.empty():
    finish_time, result = run_task(remaining=remaining, finish_time=finish_time)

# Printing the finish time for each task
for key in result:
    print(result.get(key))
