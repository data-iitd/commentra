import queue

# Read the number of tasks (n) and the maximum number of concurrent tasks (b)
n, b = list(map(int, input().split()))

# Define a class to represent a Task with its start time, duration, and index
class Task:
    def __init__(self, time: int, duration: int, index: int) -> None:
        super().__init__()
        self.time = time      # The time at which the task is available to run
        self.duration = duration  # The duration for which the task will run
        self.index = index    # The index of the task for result tracking

# Initialize a queue to hold remaining tasks and variables to track the running state and finish time
remaining = queue.Queue()
running = False
finish_time = 0

# Function to run a task from the queue and update the finish time
def run_task(remaining: queue.Queue, finish_time: int):
    task_to_run = remaining.get()  # Get the next task to run from the queue
    finish_time = max(finish_time, task_to_run.time) + task_to_run.duration  # Update finish time
    result[task_to_run.index] = finish_time  # Store the finish time for the task
    return finish_time, result  # Return updated finish time and results

# Dictionary to store the finish time of each task
result = {}

# Loop through each task input
for i in range(n):
    time, duration = list(map(int, input().split()))  # Read task's start time and duration
    task = Task(time, duration, index=i)  # Create a Task object
    result.update({i: 0})  # Initialize the result for this task

    # Check if the task can run immediately
    if task.time > finish_time and remaining.empty():
        running = True  # Mark that we are running a task
        finish_time = task.time + task.duration  # Update finish time for this task
        result[i] = finish_time  # Store the finish time for this task
    else:
        # If the task starts after the last finished task and there are tasks in the queue
        if task.time >= finish_time and not remaining.empty():
            finish_time, result = run_task(remaining=remaining, finish_time=finish_time)  # Run the next task

        # Check if we can add the task to the queue
        if remaining.qsize() < b:
            remaining.put(task)  # Add the task to the queue if there's capacity
        else:
            result[i] = -1  # If the queue is full, mark this task as not runnable

# Process any remaining tasks in the queue
while not remaining.empty():
    finish_time, result = run_task(remaining=remaining, finish_time=finish_time)

# Print the finish times for all tasks
for key in result:
    print(result.get(key))
