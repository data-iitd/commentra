import java.util.Scanner;

class Process {
    String name; // Name of the process
    int t;       // Remaining time for the process

    Process(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

public class RoundRobinScheduler {
    private static final int LEN = 100005;
    private static Process[] Q = new Process[LEN];
    private static int head = 0, tail = 0, n; // Queue pointers and number of processes

    // Function to add a process to the queue
    private static void enqueue(Process x) {
        Q[tail] = x; // Add the process to the tail of the queue
        tail = (tail + 1) % LEN; // Move the tail pointer forward, wrapping around if necessary
    }

    // Function to remove and return a process from the front of the queue
    private static Process dequeue() {
        Process x = Q[head]; // Get the process at the head of the queue
        head = (head + 1) % LEN; // Move the head pointer forward, wrapping around if necessary
        return x; // Return the dequeued process
    }

    // Function to return the minimum of two integers
    private static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elaps = 0, c; // elaps keeps track of elapsed time, c is the time slice
        int q; // The time quantum

        // Read the number of processes and the time quantum
        n = scanner.nextInt();
        q = scanner.nextInt();

        // Read the name and time for each process
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            Q[i] = new Process(name, time); // Create a new process and add it to the queue
        }

        // Initialize the tail pointer for the queue
        tail = n;

        // Process the queue until all processes are completed
        while (head != tail) {
            Process u = dequeue(); // Dequeue the next process
            c = min(q, u.t); // Determine the time slice to process (minimum of quantum and remaining time)
            u.t -= c; // Reduce the remaining time of the process
            elaps += c; // Increase the elapsed time by the time slice

            // If the process still has remaining time, enqueue it back
            if (u.t > 0) {
                enqueue(u);
            } else { // If the process is completed, print its name and the elapsed time
                System.out.println(u.name + " " + elaps);
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
