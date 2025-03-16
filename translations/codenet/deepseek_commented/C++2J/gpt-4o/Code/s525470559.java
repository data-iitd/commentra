import java.util.LinkedList; // Import LinkedList for queue implementation.
import java.util.Queue;      // Import Queue interface.

class Task {                // Define a class named 'Task' to hold the name and time for each task.
    String name;           // The name of the task.
    int time;              // The time required to complete the task.

    Task(String name, int time) { // Constructor to initialize the task.
        this.name = name;
        this.time = time;
    }
}

public class Main {         // Define the main class.
    public static void main(String[] args) { // The main method where execution begins.
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a scanner for input.
        
        int n = scanner.nextInt(); // Read the number of tasks.
        int q = scanner.nextInt(); // Read the time quantum.
        int elaps = 0;              // Initialize the elapsed time to 0.
        
        Queue<Task> queue = new LinkedList<>(); // Create a queue of tasks.

        for (int i = 0; i < n; i++) { // Loop to read each task's name and time.
            String name = scanner.next(); // Read the task's name.
            int time = scanner.nextInt(); // Read the task's time.
            queue.add(new Task(name, time)); // Add the task to the queue.
        }

        while (!queue.isEmpty()) { // Process each task in the queue until it is empty.
            Task p = queue.poll(); // Get and remove the front task from the queue.
            if (p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
                elaps += p.time; // Update the elapsed time by adding the task's remaining time.
                System.out.println(p.name + " " + elaps); // Print the task's name and the current elapsed time.
            } else { // If the task's remaining time is greater than the time quantum.
                p.time -= q; // Reduce the task's remaining time by the time quantum.
                elaps += q;   // Update the elapsed time by adding the time quantum.
                queue.add(p); // Push the task back into the queue with the remaining time.
            }
        }
        scanner.close(); // Close the scanner.
    }
}
// <END-OF-CODE>
