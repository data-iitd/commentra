// Define a structure to hold the name and time of each process
class P {
    String name; // Name of the process
    int t;       // Remaining time for the process

    // Constructor to initialize the name and time
    P(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

// Declare a queue to hold processes
P[] Q = new P[100005];
int head, tail, n; // Queue pointers and number of processes

// Function to add a process to the queue
void enqueue(P x) {
    Q[tail] = x; // Add the process to the tail of the queue
    tail = (tail + 1) % 100005; // Move the tail pointer forward, wrapping around if necessary
}

// Function to remove and return a process from the front of the queue
P dequeue() {
    P x = Q[head]; // Get the process at the head of the queue
    head = (head + 1) % 100005; // Move the head pointer forward, wrapping around if necessary
    return x; // Return the dequeued process
}

// Function to return the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

public class Main {
    public static void main(String[] args) {
        int elaps = 0, c; // elaps keeps track of elapsed time, c is the time slice
        int i, q; // Loop variables and the time quantum
        P u; // Variable to hold the current process

        // Read the number of processes and the time quantum
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        q = sc.nextInt();

        // Read the name and time for each process
        for (i = 1; i <= n; i++) {
            Q[i] = new P(sc.next(), sc.nextInt()); // Read the process name and time
        }

        // Initialize the head and tail pointers for the queue
        head = 1;
        tail = n + 1;

        // Process the queue until all processes are completed
        while (head != tail) {
            u = dequeue(); // Dequeue the next process
            c = min(q, u.t); // Determine the time slice to process (minimum of quantum and remaining time)
            u.t -= c; // Reduce the remaining time of the process
            elaps += c; // Increase the elapsed time by the time slice

            // If the process still has remaining time, enqueue it back
            if (u.t > 0)
                enqueue(u);
            else // If the process is completed, print its name and the elapsed time
                System.out.println(u.name + " " + elaps);
        }
    }
}

