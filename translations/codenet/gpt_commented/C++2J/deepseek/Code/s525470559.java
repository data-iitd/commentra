import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Task {
    String name;
    int time;

    Task(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // n: number of tasks
        int q = scanner.nextInt(); // q: time quantum
        int elaps = 0; // Variable to keep track of elapsed time
        Queue<Task> queue = new LinkedList<>(); // Queue to manage tasks in a FIFO manner

        // Read each task's name and time, and add it to the queue
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Task(name, time)); // Add task to the queue
        }

        // Process tasks until the queue is empty
        while (!queue.isEmpty()) {
            Task p = queue.poll(); // Get the task at the front of the queue

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
