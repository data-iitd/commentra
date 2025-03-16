import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Define a custom class for tasks
class Task {
    // Name of the task
    String name;
    // Time taken by the task
    int time;

    // Constructor to initialize task
    Task(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class TaskScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n, q; // Number of tasks and queries
        int elaps = 0; // Elapsed time
        Queue<Task> queue = new LinkedList<>(); // Queue to store tasks

        // Read number of tasks and queries from standard input
        n = scanner.nextInt();
        q = scanner.nextInt();

        // Read tasks details and add them to the queue
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Task(name, time)); // Add the task to the queue
        }

        // Process tasks in the queue until it is empty
        while (!queue.isEmpty()) {
            Task task = queue.poll(); // Get the task at the front of the queue

            // Check if the current task can be completed within the given query time
            if (task.time <= q) {
                elaps += task.time; // Add the time taken by the task to the elapsed time
                System.out.println(task.name + " " + elaps); // Print the name and elapsed time of the task
            } else { // If the current task cannot be completed within the given query time
                // Subtract the query time from the time taken by the task
                task.time -= q;
                // Add the task back to the queue with updated time
                queue.add(task);
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
