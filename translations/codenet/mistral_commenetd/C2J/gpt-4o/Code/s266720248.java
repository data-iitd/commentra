import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Process {
    String name; // Name of the process
    int time; // Time taken by the process

    Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class ProcessQueue {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elapsed = 0; // Initialize elapsed time
        int c; // Control variable
        int n, q; // Number of processes and number of queries

        // Read number of processes and number of queries
        n = scanner.nextInt();
        q = scanner.nextInt();
        Queue<Process> queue = new LinkedList<>();

        // Allocate memory for each process and read its name and time
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Process(name, time)); // Add the process to the queue
        }

        // Simulate the queue and serve processes based on their arrival time and time taken
        while (!queue.isEmpty()) {
            Process current = queue.poll(); // Dequeue a process
            c = Math.min(q, current.time); // Find the minimum of remaining queries and time taken by the process
            current.time -= c; // Subtract the time taken to serve the queries
            elapsed += c; // Add the time taken to serve the queries to elapsed time

            if (current.time > 0) {
                queue.add(current); // If the process still has time left, add it back to the queue
            } else {
                System.out.println(current.name + " " + elapsed); // Print the name of the process and elapsed time when it is finished
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
