
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    // Define a Process class to store process details
    static class Process implements Comparable<Process> {
        int id;
        int arrivalTime;
        int burstTime;
        int priority;
        int startTime;
        Process(int id, int arrivalTime, int burstTime, int priority) {
            this.id = id;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.priority = priority;
            this.startTime = -1;  
        }

        // Implement Comparable interface for sorting based on priority and arrival time
        @Override
        public int compareTo(Process other) {
            if (this.priority == other.priority) {
                return Integer.compare(this.arrivalTime, other.arrivalTime);
            }
            return Integer.compare(this.priority, other.priority);
        }
    }

    // Function to schedule processes based on priority and arrival time
    public static Process[] scheduleProcesses(Process[] processes) {
        // Initialize a priority queue and a waiting queue
        PriorityQueue<Process> pq = new PriorityQueue<Process>();
        Queue<Process> waitingQueue = new LinkedList<Process>();

        // Add all processes to the waiting queue
        Collections.addAll(waitingQueue, processes);

        int currentTime = 0; // Initialize current time
        int index = 0; // Initialize index for execution order array
        Process[] executionOrder = new Process[processes.length]; // Initialize execution order array

        // Simulate the CPU scheduling algorithm
        while (!waitingQueue.isEmpty() || !pq.isEmpty()) {
            // While the waiting queue has processes that have arrived, add them to the priority queue
            while (!waitingQueue.isEmpty() && waitingQueue.peek().arrivalTime <= currentTime) {
                pq.add(waitingQueue.poll());
            }

            // If the priority queue is not empty, take the process with the highest priority and execute it
            if (!pq.isEmpty()) {
                Process currentProcess = pq.poll();
                currentProcess.startTime = currentTime; // Update start time
                executionOrder[index++] = currentProcess; // Add to execution order
                currentTime += currentProcess.burstTime; // Update current time
            } else { // If the priority queue is empty, wait for the next process to arrive
                currentTime = waitingQueue.peek().arrivalTime;
            }
        }

        // Return the execution order
        return executionOrder;
    }

    // Function to calculate average waiting time
    public static double calculateAverageWaitingTime(Process[] executionOrder) {
        int totalWaitingTime = 0; // Initialize total waiting time

        // Calculate waiting time for each process and add to total waiting time
        for (Process process : executionOrder) {
            int waitingTime = process.startTime - process.arrivalTime;
            totalWaitingTime += waitingTime;
        }

        // Calculate and return average waiting time
        return (double) totalWaitingTime / executionOrder.length;
    }

    // Function to calculate average turnaround time
    public static double calculateAverageTurnaroundTime(Process[] executionOrder) {
        int totalTurnaroundTime = 0; // Initialize total turnaround time

        // Calculate turnaround time for each process and add to total turnaround time
        for (Process process : executionOrder) {
            int turnaroundTime = process.startTime + process.burstTime - process.arrivalTime;
            totalTurnaroundTime += turnaroundTime;
        }

        // Calculate and return average turnaround time
        return (double) totalTurnaroundTime / executionOrder.length;
    }

    // Main function to read input and call scheduling functions
    public static void main(String[] args) {
        // Initialize scanner to read input from the console
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read number of processes from the console
        int n = scanner.nextInt();

        // Initialize an array of processes
        Process[] processes = new Process[n];

        // Read details of each process and initialize them
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            int priority = scanner.nextInt();
            processes[i] = new Process(id, arrivalTime, burstTime, priority);
        }

        // Call the scheduling function and store the execution order
        Process[] executionOrder = scheduleProcesses(processes);

        // Print the execution order
        System.out.println("Execution Order:");
        for (Process process : executionOrder) {
            System.out.println("Process " + process.id + " started at time " + process.startTime);
        }

        // Calculate and print average waiting time and turnaround time
        double avgWaitingTime = calculateAverageWaitingTime(executionOrder);
        double avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder);
        System.out.printf("Average Waiting Time: %.2f%n", avgWaitingTime);
        System.out.printf("Average Turnaround Time: %.2f%n", avgTurnaroundTime);

        // Close the scanner
        scanner.close();
    }
}