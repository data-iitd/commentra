import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// Define a class to represent a task with a name and time
class Task {
    String name; // Name of the task
    int time;    // Time required to complete the task

    // Constructor to initialize a task
    Task(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class TaskScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n, q; // n: number of tasks, q: time quantum
        int elaps = 0; // Variable to keep track of elapsed time
        Queue<Task> queue = new LinkedList<>(); // Queue to manage tasks in a FIFO manner

        // Read the number of tasks and the time quantum from input
        n = scanner.nextInt();
        q = scanner.nextInt();
        
        // Read each task's name and time, and add it to the queue
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Task(name, time)); // Add the task to the queue
        }

        // Process tasks until the queue is empty
        while (!queue.isEmpty()) {
            Task p = queue.poll(); // Get and remove the task at the front of the queue
            
            // Check if the task can be completed within the time quantum
            if (p.time <= q) {
                elaps += p.time; // Update elapsed time
                System.out.println(p.name + " " + elaps); // Output task name and total elapsed time
            } else {
                // If the task cannot be completed, reduce its time and re-add it to the queue
                p.time -= q; // Decrease the remaining time of the task
                elaps += q; // Update elapsed time by the time quantum
                queue.add(p); // Re-add the task to the queue for further processing
            }
        }
        
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
