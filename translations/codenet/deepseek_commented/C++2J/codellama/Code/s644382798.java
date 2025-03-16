// Define a class to hold process name and time
class PP {
    String name;
    int t;

    // Constructor to initialize the process name and time
    PP(String name, int t) {
        this.name = name;
        this.t = t;
    }
}

// Define a class to hold the queue, head, tail, and number of processes
class ProcessQueue {
    PP[] Q;
    int head, tail, n;

    // Constructor to initialize the queue, head, tail, and number of processes
    ProcessQueue(int n) {
        Q = new PP[n + 1];
        head = 1;
        tail = n + 1;
        this.n = n;
    }

    // Enqueue function to add a process to the queue
    void enqueue(PP x) {
        Q[tail] = x; // Assign the process to the current tail position
        tail = (tail + 1) % (n + 1); // Update tail to the next position, wrapping around if necessary
    }

    // Dequeue function to remove and return the next process from the queue
    PP dequeue() {
        PP x = Q[head]; // Get the process at the head
        head = (head + 1) % (n + 1); // Update head to the next position, wrapping around if necessary
        return x; // Return the dequeued process
    }

    // Min function to return the smaller of two integers
    int min(int a, int b) {
        return a < b ? a : b;
    }

    // Main function to process the processes
    void main() {
        int elaps = 0, c; // Initialize elapsed time and a variable to hold the time quantum
        int i, q;
        PP u;
        scanf("%d %d", n, q); // Read the number of processes and the time quantum

        // Read each process's name and time
        for (i = 1; i <= n; i++) {
            scanf("%s", Q[i].name); // Read the process name
            scanf("%d", &Q[i].t); // Read the process time
        }
        head = 1; // Initialize head to the first position in the queue
        tail = n + 1; // Initialize tail to the position after the last process

        // Process each process in the queue
        while (head != tail) {
            u = dequeue(); // Dequeue the next process
            c = min(q, u.t); // Determine the time slice to process the process
            u.t -= c; // Reduce the process time by the time slice
            elaps += c; // Add the time slice to the elapsed time
            if (u.t > 0)
                enqueue(u); // If there is more time left for the process, enqueue it again
            else
                printf("%s %d\n", u.name, elaps); // Otherwise, print the process name and elapsed time
        }
    }
}

// Main function to run the program
public static void main(String[] args) {
    ProcessQueue pq = new ProcessQueue(100005); // Create a new process queue with 100005 processes
    pq.main(); // Run the main function
}

