import java.util.Scanner;

class Process {
    String name;
    int time;

    Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class RoundRobinScheduler {
    private static final int LEN = 100005;
    private static Process[] queue = new Process[LEN];
    private static int head = 0, tail = 0, n;

    // Enqueue function to add a process to the queue
    private static void enqueue(Process process) {
        queue[tail] = process; // Assign the process to the current tail position
        tail = (tail + 1) % LEN; // Update tail to the next position, wrapping around if necessary
    }

    // Dequeue function to remove and return the next process from the queue
    private static Process dequeue() {
        Process process = queue[head]; // Get the process at the head
        head = (head + 1) % LEN; // Update head to the next position, wrapping around if necessary
        return process; // Return the dequeued process
    }

    // Min function to return the smaller of two integers
    private static int min(int a, int b) {
        return Math.min(a, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elapsedTime = 0, timeQuantum; // Initialize elapsed time and a variable to hold the time quantum

        n = scanner.nextInt(); // Read the number of processes
        timeQuantum = scanner.nextInt(); // Read the time quantum

        // Read each process's name and time
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            enqueue(new Process(name, time)); // Enqueue the new process
        }

        // Process each process in the queue
        while (head != tail) {
            Process currentProcess = dequeue(); // Dequeue the next process
            int timeSlice = min(timeQuantum, currentProcess.time); // Determine the time slice to process the process
            currentProcess.time -= timeSlice; // Reduce the process time by the time slice
            elapsedTime += timeSlice; // Add the time slice to the elapsed time

            if (currentProcess.time > 0) {
                enqueue(currentProcess); // If there is more time left for the process, enqueue it again
            } else {
                System.out.println(currentProcess.name + " " + elapsedTime); // Otherwise, print the process name and elapsed time
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
