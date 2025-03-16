import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    // Class representing a process with its attributes and comparison logic
    static class Process implements Comparable<Process> {
        int id; // Unique identifier for the process
        int arrivalTime; // Time at which the process arrives
        int burstTime; // Time required for the process to complete
        int priority; // Priority of the process
        int startTime; // Time at which the process starts execution

        // Constructor to initialize process attributes
        Process(int id, int arrivalTime, int burstTime, int priority) {
            this.id = id;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.priority = priority;
            this.startTime = -1; // Initialize start time to -1 (not started)
        }

        // Comparison logic for priority queue based on priority and arrival time
        @Override
        public int compareTo(Process other) {
            if (this.priority == other.priority) {
                return Integer.compare(this.arrivalTime, other.arrivalTime);
            }
            return Integer.compare(this.priority, other.priority);
        }
    }

    // Method to schedule processes based on their arrival time and priority
    public static Process[] scheduleProcesses(Process[] processes) {
        // Priority queue to manage processes based on priority
        PriorityQueue<Process> pq = new PriorityQueue<Process>();
        // Queue to hold processes that are waiting to be scheduled
        Queue<Process> waitingQueue = new LinkedList<Process>();
        // Add all processes to the waiting queue
        Collections.addAll(waitingQueue, processes);
        
        int currentTime = 0; // Tracks the current time in the scheduling
        int index = 0; // Index to track the execution order
        Process[] executionOrder = new Process[processes.length]; // Array to store execution order

        // Loop until all processes are executed
        while (!waitingQueue.isEmpty() || !pq.isEmpty()) {
            // Add processes that have arrived to the priority queue
            while (!waitingQueue.isEmpty() && waitingQueue.peek().arrivalTime <= currentTime) {
                pq.add(waitingQueue.poll());
            }
            // If there are processes in the priority queue, execute the highest priority one
            if (!pq.isEmpty()) {
                Process currentProcess = pq.poll(); // Get the process with the highest priority
                currentProcess.startTime = currentTime; // Set the start time for the current process
                executionOrder[index++] = currentProcess; // Record the execution order
                currentTime += currentProcess.burstTime; // Update current time after execution
            } else {
                // If no process is ready, jump to the next arriving process
                currentTime = waitingQueue.peek().arrivalTime;
            }
        }
        return executionOrder; // Return the order in which processes were executed
    }

    // Method to calculate the average waiting time of the executed processes
    public static double calculateAverageWaitingTime(Process[] executionOrder) {
        int totalWaitingTime = 0; // Variable to accumulate total waiting time
        // Calculate waiting time for each process
        for (Process process : executionOrder) {
            int waitingTime = process.startTime - process.arrivalTime; // Calculate waiting time
            totalWaitingTime += waitingTime; // Add to total waiting time
        }
        // Return average waiting time
        return (double) totalWaitingTime / executionOrder.length;
    }

    // Method to calculate the average turnaround time of the executed processes
    public static double calculateAverageTurnaroundTime(Process[] executionOrder) {
        int totalTurnaroundTime = 0; // Variable to accumulate total turnaround time
        // Calculate turnaround time for each process
        for (Process process : executionOrder) {
            int turnaroundTime = process.startTime + process.burstTime - process.arrivalTime; // Calculate turnaround time
            totalTurnaroundTime += turnaroundTime; // Add to total turnaround time
        }
        // Return average turnaround time
        return (double) totalTurnaroundTime / executionOrder.length;
    }

    // Main method to execute the scheduling program
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of processes
        Process[] processes = new Process[n]; // Array to hold the processes

        // Read process details from input
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt(); // Read process ID
            int arrivalTime = scanner.nextInt(); // Read arrival time
            int burstTime = scanner.nextInt(); // Read burst time
            int priority = scanner.nextInt(); // Read priority
            processes[i] = new Process(id, arrivalTime, burstTime, priority); // Create process object
        }

        // Schedule the processes and get the execution order
        Process[] executionOrder = scheduleProcesses(processes);
        System.out.println("Execution Order:");
        // Print the execution order of processes
        for (Process process : executionOrder) {
            System.out.println("Process " + process.id + " started at time " + process.startTime);
        }

        // Calculate and print average waiting time
        double avgWaitingTime = calculateAverageWaitingTime(executionOrder);
        // Calculate and print average turnaround time
        double avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder);
        System.out.printf("Average Waiting Time: %.2f%n", avgWaitingTime);
        System.out.printf("Average Turnaround Time: %.2f%n", avgTurnaroundTime);
        
        scanner.close(); // Close the scanner resource
    }
}
