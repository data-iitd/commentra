import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
public class Main {
    private List<Queue<Process>> queues; // List to hold queues for different priority levels
    private int[] timeQuantum; // Array to hold time quantums for each priority level
    private int currentTime; // Variable to keep track of the current time
    
    // Constructor to initialize the scheduler with given number of levels and time quantums
    public Main(int levels, int[] timeQuantums) {
        queues = new ArrayList<>(levels);
        for (int i = 0; i < levels; i++) {
            queues.add(new LinkedList<>()); // Initialize each queue
        }
        timeQuantum = timeQuantums;
        currentTime = 0; // Initialize current time to 0
    }
    
    // Method to add a process to the highest priority queue
    public void addProcess(Process p) {
        queues.get(0).add(p);
    }
    
    // Main method to run the scheduler
    public void run() {
        while (!allQueuesEmpty()) { // Continue until all queues are empty
            for (int i = 0; i < queues.size(); i++) { // Iterate through each queue
                Queue<Process> queue = queues.get(i);
                if (!queue.isEmpty()) { // Check if the queue is not empty
                    Process p = queue.poll(); // Get the process at the front of the queue
                    int quantum = timeQuantum[i]; // Get the time quantum for the current priority level
                    int timeSlice = Math.min(quantum, p.remainingTime); // Calculate the time slice
                    p.execute(timeSlice); // Execute the process for the time slice
                    currentTime += timeSlice; // Update the current time
                    if (p.isFinished()) { // Check if the process is finished
                        System.out.println("Process " + p.pid + " finished at time " + currentTime); // Print the finished process message
                    } else {
                        if (i < queues.size() - 1) { // Check if there is a higher priority queue
                            p.priority++; // Increase the priority of the process
                            queues.get(i + 1).add(p); // Move the process to the next higher priority queue
                        } else {
                            queue.add(p); // Add the process back to the current queue if no higher priority queue exists
                        }
                    }
                }
            }
        }
    }
    
    // Method to check if all queues are empty
    private boolean allQueuesEmpty() {
        for (Queue<Process> queue : queues) {
            if (!queue.isEmpty()) {
                return false;
            }
        }
        return true;
    }
    
    // Main method to read input and run the scheduler
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int levels = scanner.nextInt(); // Read the number of priority levels
        int[] timeQuantums = new int[levels]; // Initialize the time quantums array
        for (int i = 0; i < levels; i++) {
            timeQuantums[i] = scanner.nextInt(); // Read the time quantums for each priority level
        }
        Main scheduler = new Main(levels, timeQuantums); // Initialize the scheduler
        int n = scanner.nextInt(); // Read the number of processes
        for (int i = 0; i < n; i++) {
            int pid = scanner.nextInt(); // Read the process ID
            int burstTime = scanner.nextInt(); // Read the burst time
            int arrivalTime = scanner.nextInt(); // Read the arrival time
            scheduler.addProcess(new Process(pid, burstTime, arrivalTime)); // Add the process to the scheduler
        }
        scheduler.run(); // Run the scheduler
        scanner.close(); // Close the scanner
    }
}

// Class to represent a process
class Process {
    int pid; // Process ID
    int burstTime; // Burst time of the process
    int remainingTime; // Remaining time to complete the process
    int arrivalTime; // Arrival time of the process
    int priority; // Priority of the process
    
    // Constructor to initialize the process with given parameters
    public Process(int pid, int burstTime, int arrivalTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        this.remainingTime = burstTime; // Initialize remaining time to burst time
        this.arrivalTime = arrivalTime;
        this.priority = 0; // Initialize priority to 0
    }
    
    // Method to execute the process for a given time slice
    public void execute(int timeSlice) {
        remainingTime -= timeSlice; // Decrease the remaining time by the time slice
        if (remainingTime < 0) {
            remainingTime = 0; // Ensure remaining time is not negative
        }
    }
    
    // Method to check if the process is finished
    public boolean isFinished() {
        return remainingTime == 0; // Return true if remaining time is 0
    }
}
