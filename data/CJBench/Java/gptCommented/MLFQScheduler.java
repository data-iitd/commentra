import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    // List of queues to hold processes at different priority levels
    private List<Queue<Process>> queues; 
    // Array to hold time quantums for each priority level
    private int[] timeQuantum; 
    // Variable to track the current time in the scheduling process
    private int currentTime; 

    // Constructor to initialize the scheduler with the number of levels and their respective time quantums
    public Main(int levels, int[] timeQuantums) {
        queues = new ArrayList<>(levels);
        // Initialize each queue for the different priority levels
        for (int i = 0; i < levels; i++) {
            queues.add(new LinkedList<>());
        }
        timeQuantum = timeQuantums;
        currentTime = 0; // Start time at 0
    }

    // Method to add a new process to the highest priority queue (queue 0)
    public void addProcess(Process p) {
        queues.get(0).add(p);
    }

    // Method to run the scheduling algorithm
    public void run() {
        // Continue running until all queues are empty
        while (!allQueuesEmpty()) {
            // Iterate through each priority level's queue
            for (int i = 0; i < queues.size(); i++) {
                Queue<Process> queue = queues.get(i);
                // If the current queue is not empty, process the next process
                if (!queue.isEmpty()) {
                    Process p = queue.poll(); // Get the next process from the queue
                    int quantum = timeQuantum[i]; // Get the time quantum for the current level
                    int timeSlice = Math.min(quantum, p.remainingTime); // Determine the time slice to execute

                    // Execute the process for the determined time slice
                    p.execute(timeSlice);
                    currentTime += timeSlice; // Update the current time

                    // Check if the process has finished executing
                    if (p.isFinished()) {
                        System.out.println("Process " + p.pid + " finished at time " + currentTime);
                    } else {
                        // If not finished and not at the last queue, increase priority and move to the next queue
                        if (i < queues.size() - 1) {
                            p.priority++;
                            queues.get(i + 1).add(p); // Add to the next priority queue
                        } else {
                            queue.add(p); // If at the last queue, re-add to the same queue
                        }
                    }
                }
            }
        }
    }

    // Helper method to check if all queues are empty
    private boolean allQueuesEmpty() {
        for (Queue<Process> queue : queues) {
            if (!queue.isEmpty()) {
                return false; // If any queue is not empty, return false
            }
        }
        return true; // All queues are empty
    }

    // Main method to run the scheduler
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of priority levels
        int levels = scanner.nextInt();
        int[] timeQuantums = new int[levels];
        // Read the time quantums for each level
        for (int i = 0; i < levels; i++) {
            timeQuantums[i] = scanner.nextInt();
        }
        // Initialize the scheduler with levels and time quantums
        Main scheduler = new Main(levels, timeQuantums);
        // Read the number of processes to schedule
        int n = scanner.nextInt();
        // Read each process's details and add to the scheduler
        for (int i = 0; i < n; i++) {
            int pid = scanner.nextInt(); // Process ID
            int burstTime = scanner.nextInt(); // Burst time of the process
            int arrivalTime = scanner.nextInt(); // Arrival time of the process
            scheduler.addProcess(new Process(pid, burstTime, arrivalTime));
        }
        // Start the scheduling process
        scheduler.run();
        scanner.close(); // Close the scanner
    }
}

// Class representing a process with its attributes and methods
class Process {
    int pid; // Process ID
    int burstTime; // Total burst time required for the process
    int remainingTime; // Remaining time for the process to finish
    int arrivalTime; // Arrival time of the process
    int priority; // Priority level of the process

    // Constructor to initialize a process with its attributes
    public Process(int pid, int burstTime, int arrivalTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        this.remainingTime = burstTime; // Initially, remaining time is equal to burst time
        this.arrivalTime = arrivalTime;
        this.priority = 0; // Initial priority is set to 0
    }

    // Method to execute the process for a given time slice
    public void execute(int timeSlice) {
        remainingTime -= timeSlice; // Decrease the remaining time by the time slice
        if (remainingTime < 0) {
            remainingTime = 0; // Ensure remaining time does not go negative
        }
    }

    // Method to check if the process has finished executing
    public boolean isFinished() {
        return remainingTime == 0; // Process is finished if remaining time is 0
    }
}
