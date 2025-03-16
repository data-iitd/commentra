import java.util.*;

public class TaskScheduler {
    // Define a class to represent a Task with its start time, duration, and index
    static class Task {
        int time;      // The time at which the task is available to run
        int duration;  // The duration for which the task will run
        int index;     // The index of the task for result tracking

        Task(int time, int duration, int index) {
            this.time = time;
            this.duration = duration;
            this.index = index;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of tasks (n) and the maximum number of concurrent tasks (b)
        int n = scanner.nextInt();
        int b = scanner.nextInt();

        // Initialize a queue to hold remaining tasks and variables to track the running state and finish time
        Queue<Task> remaining = new LinkedList<>();
        boolean running = false;
        int finishTime = 0;

        // Dictionary to store the finish time of each task
        int[] result = new int[n];
        Arrays.fill(result, 0); // Initialize the result for all tasks

        // Loop through each task input
        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int duration = scanner.nextInt();
            Task task = new Task(time, duration, i); // Create a Task object

            // Check if the task can run immediately
            if (task.time > finishTime && remaining.isEmpty()) {
                running = true; // Mark that we are running a task
                finishTime = task.time + task.duration; // Update finish time for this task
                result[i] = finishTime; // Store the finish time for this task
            } else {
                // If the task starts after the last finished task and there are tasks in the queue
                if (task.time >= finishTime && !remaining.isEmpty()) {
                    finishTime = runTask(remaining, finishTime, result); // Run the next task
                }

                // Check if we can add the task to the queue
                if (remaining.size() < b) {
                    remaining.add(task); // Add the task to the queue if there's capacity
                } else {
                    result[i] = -1; // If the queue is full, mark this task as not runnable
                }
            }
        }

        // Process any remaining tasks in the queue
        while (!remaining.isEmpty()) {
            finishTime = runTask(remaining, finishTime, result);
        }

        // Print the finish times for all tasks
        for (int finish : result) {
            System.out.println(finish);
        }

        scanner.close();
    }

    // Function to run a task from the queue and update the finish time
    private static int runTask(Queue<Task> remaining, int finishTime, int[] result) {
        Task taskToRun = remaining.poll(); // Get the next task to run from the queue
        finishTime = Math.max(finishTime, taskToRun.time) + taskToRun.duration; // Update finish time
        result[taskToRun.index] = finishTime; // Store the finish time for the task
        return finishTime; // Return updated finish time
    }
}

// <END-OF-CODE>
