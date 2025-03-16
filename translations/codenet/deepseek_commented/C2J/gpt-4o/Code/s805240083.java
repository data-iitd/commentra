import java.util.LinkedList; // Import LinkedList for queue implementation
import java.util.Scanner; // Import Scanner for input

class Process { // Define a class for processes
    String name; // Variable to store the process name
    int time; // Variable to store the time required for the process

    Process(String name, int time) { // Constructor to initialize process
        this.name = name;
        this.time = time;
    }
}

public class ProcessScheduler { // Main class for process scheduling
    private static final int MAX = 100005; // Define the maximum number of processes
    private static final int N = 100; // Define the maximum length of the process name

    public static void main(String[] args) { // Main method to execute the process scheduling
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the number of processes
        int q = scanner.nextInt(); // Read the quantum
        LinkedList<Process> queue = new LinkedList<>(); // Create a queue using LinkedList
        int totalTime = 0; // Variable to store total time

        for (int i = 0; i < n; i++) { // Loop to read each process
            String name = scanner.next(); // Read the process name
            int time = scanner.nextInt(); // Read the process time
            queue.add(new Process(name, time)); // Enqueue the process
        }

        while (!queue.isEmpty()) { // Loop to process each process
            Process currentProcess = queue.poll(); // Dequeue a process
            if (currentProcess.time > q) { // If the process time is greater than the quantum
                currentProcess.time -= q; // Reduce the process time by the quantum
                totalTime += q; // Increment the total time by the quantum
                queue.add(currentProcess); // Enqueue the process again
            } else { // If the process time is less than or equal to the quantum
                totalTime += currentProcess.time; // Increment the total time by the process time
                System.out.println(currentProcess.name + " " + totalTime); // Print the process name and total time
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
