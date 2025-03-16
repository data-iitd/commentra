
// Importing the java.util.Queue and java.util.LinkedList classes for implementing a First-In-First-Out (FIFO) queue
import java.util.Queue;
import java.util.LinkedList;

// Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
int b = scanner.nextInt();

// Defining a Task class to store the time, duration, and index of each task
class Task {
    int time;
    int duration;
    int index;

    public Task(int time, int duration, int index) {
        this.time = time;
        this.duration = duration;
        this.index = index;
    }
}

// Initializing an empty queue for storing the tasks to be executed
Queue<Task> remaining = new LinkedList<>();

// Initializing some variables for tracking the current finish time and whether any task is currently running
boolean running = false;
int finishTime = 0;

// Function to execute the next task in the queue and update the finish time and result accordingly
void runTask(Queue<Task> remaining, int finishTime) {
    // Getting the next task from the queue
    Task taskToRun = remaining.poll();
    // Updating the finish time based on the current task's time and duration
    finishTime = Math.max(finishTime, taskToRun.time) + taskToRun.duration;
    // Updating the result dictionary with the finish time for the current task
    result[taskToRun.index] = finishTime;
}

// Initializing an empty dictionary for storing the finish time for each task
Map<Integer, Integer> result = new HashMap<>();

// Iterating through each task and adding it to the queue or updating the result dictionary based on the current finish time and queue size
for (int i = 0; i < n; i++) {
    int time = scanner.nextInt();
    int duration = scanner.nextInt();
    // Creating a new Task instance and adding it to the result dictionary with an initial finish time of 0
    Task task = new Task(time, duration, i);
    result.put(i, 0);
    // If the current task can be executed immediately, update the finish time and result accordingly
    if (task.time > finishTime && remaining.isEmpty()) {
        running = true;
        finishTime = task.time + task.duration;
        result.put(i, finishTime);
    }
    // If the current task cannot be executed immediately, add it to the queue if the queue size is less than b, or update the result dictionary with -1 if the queue is full
    else if (task.time >= finishTime &&!remaining.isEmpty()) {
        runTask(remaining, finishTime);
        if (remaining.size() < b) {
            remaining.add(task);
        } else {
            result.put(i, -1);
        }
    }
}
// Executing the remaining tasks in the queue, if any
while (!remaining.isEmpty()) {
    runTask(remaining, finishTime);
}

// Printing the finish time for each task
for (int key : result.keySet()) {
    System.out.println(result.get(key));
}
