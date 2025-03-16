import java.util.*;

public class TaskScheduler {
    // Defining a Task class to store the time, duration, and index of each task
    static class Task {
        int time;
        int duration;
        int index;

        Task(int time, int duration, int index) {
            this.time = time;
            this.duration = duration;
            this.index = index;
        }
    }

    public static void main(String[] args) {
        // Taking input for the number of tasks, n, and the maximum number of tasks that can be run in parallel, b
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);

        // Initializing a queue for storing the tasks to be executed
        Queue<Task> remaining = new LinkedList<>();

        // Initializing some variables for tracking the current finish time and whether any task is currently running
        boolean running = false;
        int finishTime = 0;

        // Initializing an array for storing the finish time for each task
        int[] result = new int[n];
        Arrays.fill(result, 0);

        // Iterating through each task and adding it to the queue or updating the result array based on the current finish time and queue size
        for (int i = 0; i < n; i++) {
            String[] taskInput = scanner.nextLine().split(" ");
            int time = Integer.parseInt(taskInput[0]);
            int duration = Integer.parseInt(taskInput[1]);
            Task task = new Task(time, duration, i);

            // If the current task can be executed immediately, update the finish time and result accordingly
            if (time > finishTime && remaining.isEmpty()) {
                running = true;
                finishTime = time + duration;
                result[i] = finishTime;
            } 
            // If the current task cannot be executed immediately
            else if (time >= finishTime && !remaining.isEmpty()) {
                finishTime = runTask(remaining, finishTime, result);
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result[i] = -1;
                }
            } else {
                if (remaining.size() < b) {
                    remaining.add(task);
                } else {
                    result[i] = -1;
                }
            }
        }

        // Executing the remaining tasks in the queue, if any
        while (!remaining.isEmpty()) {
            finishTime = runTask(remaining, finishTime, result);
        }

        // Printing the finish time for each task
        for (int finish : result) {
            System.out.println(finish);
        }

        scanner.close();
    }

    // Function to execute the next task in the queue and update the finish time and result accordingly
    private static int runTask(Queue<Task> remaining, int finishTime, int[] result) {
        Task taskToRun = remaining.poll();
        finishTime = Math.max(finishTime, taskToRun.time) + taskToRun.duration;
        result[taskToRun.index] = finishTime;
        return finishTime;
    }
}

// <END-OF-CODE>
