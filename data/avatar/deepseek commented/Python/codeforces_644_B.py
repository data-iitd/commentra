import queue
n , b = list ( map ( int , input ( ).split ( ) ) )
# Read the number of tasks (n) and the buffer size (b) from the input.

class Task :
    def __init__ ( self , time : int , duration : int , index : int ) -> None :
        super ( ).__init__ ( )
        self.time = time
        self.duration = duration
        self.index = index
# Define the Task class to represent a task with its starting time, duration, and index.

remaining = queue.Queue ( )
running = False
finish_time = 0
# Initialize a queue to store tasks waiting to be processed, a boolean flag to check if a task is running, and a variable to keep track of the finish time.

def run_task ( remaining : queue.Queue , finish_time : int ) :
    task_to_run = remaining.get ( )
    finish_time = max ( finish_time , task_to_run.time ) + task_to_run.duration
    result [ task_to_run.index ] = finish_time
    return finish_time , result
# Define the run_task function to process a task from the queue and update the finish time.

result = { }
# Initialize a dictionary to store the finish time of each task.

for i in range ( n ) :
    time , duration = list ( map ( int , input ( ).split ( ) ) )
    task = Task ( time , duration , index = i )
    result.update ( { i : 0 } )
    if task.time > finish_time and remaining.empty ( ) :
        running = True
        finish_time = task.time + task.duration
        result [ i ] = finish_time
    else :
        if task.time >= finish_time and not remaining.empty ( ) :
            finish_time , result = run_task ( remaining = remaining , finish_time = finish_time )
        if remaining.qsize ( ) < b :
            remaining.put ( task )
        else :
            result [ i ] = - 1
# Read each task, create a Task object, and process it according to the specified rules:
# - If the task's start time is greater than the current finish time and the queue is empty, start the task.
# - If the task's start time is greater than or equal to the current finish time and the queue is not empty, finish the current task and start the new one.
# - If the buffer is full, mark the task as unable to run.

while not remaining.empty ( ) :
    finish_time , result = run_task ( remaining = remaining , finish_time = finish_time )
# Continue processing tasks in the queue until it is empty.

for key in result :
    print ( result.get ( key ) )
# Print the finish time of each task stored in the result dictionary.
