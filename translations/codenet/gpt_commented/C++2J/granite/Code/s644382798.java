
import java.util.Scanner;

public class s644382798{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elaps = 0, c; // elaps keeps track of elapsed time, c is the time slice
        int i, q; // Loop variables and the time quantum
        P u; // Variable to hold the current process

        // Read the number of processes and the time quantum
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        // Read the name and time for each process
        P[] Q = new P[n + 1];
        for (i = 1; i <= n; i++) {
            Q[i] = new P(); // Create a new process object
            Q[i].name = scanner.next(); // Read the process name
            Q[i].t = scanner.nextInt(); // Read the remaining time for the process
        }

        // Initialize the head and tail pointers for the queue
        int head = 1;
        int tail = n + 1;

        // Process the queue until all processes are completed
        while (head!= tail) {
            u = dequeue(Q, head, tail); // Dequeue the next process
            c = Math.min(q, u.t); // Determine the time slice to process (minimum of quantum and remaining time)
            u.t -= c; // Reduce the remaining time of the process
            elaps += c; // Increase the elapsed time by the time slice

            // If the process still has remaining time, enqueue it back
            if (u.t > 0)
                enqueue(Q, head, tail, u);
            else // If the process is completed, print its name and the elapsed time
                System.out.println(u.name + " " + elaps);
        }
    }

    // Define a structure to hold the name and time of each process
    static class P {
        String name; // Name of the process
        int t; // Remaining time for the process
    }

    // Function to add a process to the queue
    static void enqueue(P[] Q, int head, int tail, P x) {
        Q[tail] = x; // Add the process to the tail of the queue
        tail = (tail + 1) % (Q.length); // Move the tail pointer forward, wrapping around if necessary
    }

    // Function to remove and return a process from the front of the queue
    static P dequeue(P[] Q, int head, int tail) {
        P x = Q[head]; // Get the process at the head of the queue
        head = (head + 1) % (Q.length); // Move the head pointer forward, wrapping around if necessary
        return x; // Return the dequeued process
    }
}

