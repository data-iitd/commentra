import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Process {
    String name;
    int time; // time taken by each process

    Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class ProcessScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, q; // Declare variables for input
        int totalTime = 0; // Initialize the total time to 0

        n = scanner.nextInt(); // Read the number of processes
        q = scanner.nextInt(); // Read the time limit

        Queue<Process> queue = new LinkedList<>(); // Create a queue to store the processes

        for (int i = 0; i < n; i++) { // Loop to read the details of each process and enqueue it
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Process(name, time)); // Enqueue the process
        }

        while (!queue.isEmpty()) { // While there are still processes in the queue
            Process currentProcess = queue.poll(); // Dequeue the current process
            if (currentProcess.time > q) { // If the process takes more time than the limit
                currentProcess.time -= q; // Subtract the excess time from the process time
                totalTime += q; // Add the time limit to the total time
                queue.add(currentProcess); // Re-enqueue the process
            } else { // If the process takes less time than the limit
                totalTime += currentProcess.time; // Add the process time to the total time
                System.out.println(currentProcess.name + " " + totalTime); // Print the name and total time taken for the process
            }
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
