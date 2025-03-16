
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    // Initialize an empty list to store queues for each level
    private List<Queue<Process>> queues;
    
    // Initialize an array to store time quantum for each level
    private int[] timeQuantum;
    
    // Initialize current time to zero
    private int currentTime;
    
    // Constructor to initialize the number of levels and time quanta for each level
    public Main(int levels, int[] timeQuantums) {
        queues = new ArrayList<>(levels); // Initialize an empty list with the specified size
        for (int i = 0; i < levels; i++) {
            queues.add(new LinkedList<>()); // Add an empty queue for each level
        }
        timeQuantum = timeQuantums;
        currentTime = 0;
    }
    
    // Method to add a process to the first queue
    public void addProcess(Process p) {
        queues.get(0).add(p);
    }
    
    // Method to run the scheduler
    public void run() {
        // Loop until all queues are empty
        while (!allQueuesEmpty()) {
            for (int i = 0; i < queues.size(); i++) {
                Queue<Process> queue = queues.get(i); // Get the queue for the current level
                if (!queue.isEmpty()) { // If the queue is not empty
                    Process p = queue.poll(); // Dequeue the process
                    int quantum = timeQuantum[i]; // Get the time quantum for the current level
                    int timeSlice = Math.min(quantum, p.remainingTime); // Calculate the time slice
                    p.execute(timeSlice); // Execute the process for the calculated time slice
                    currentTime += timeSlice; // Increment the current time
                    
                    // Check if the process is finished
                    if (p.isFinished()) {
                        System.out.println("Process " + p.pid + " finished at time " + currentTime);
                    } else {
                        // If there is a next level, increment the priority and add the process to the next queue
                        if (i < queues.size() - 1) {
                            p.priority++;
                            queues.get(i + 1).add(p);
                        } else { // Otherwise, add the process back to the current queue
                            queue.add(p);
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
    
    // Main method to read input and start the scheduler
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a scanner to read input
        
        // Read the number of levels and time quanta for each level
        int levels = scanner.nextInt();
        int[] timeQuantums = new int[levels];
        for (int i = 0; i < levels; i++) {
            timeQuantums[i] = scanner.nextInt();
        }
        
        // Create a scheduler instance with the given levels and time quanta
        Main scheduler = new Main(levels, timeQuantums);
        
        // Read the number of processes and their details
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int pid = scanner.nextInt();
            int burstTime = scanner.nextInt();
            int arrivalTime = scanner.nextInt();
            scheduler.addProcess(new Process(pid, burstTime, arrivalTime));
        }
        
        // Start the scheduler
        scheduler.run();
        
        // Close the scanner
        scanner.close();
    }
}

class Process {
    int pid; // Process ID
    int burstTime; // Burst time of the process
    int remainingTime; // Remaining time of the process
    int arrivalTime; // Arrival time of the process
    int priority; // Priority of the process
    
    // Constructor to initialize a process with the given details
    public Process(int pid, int burstTime, int arrivalTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        this.remainingTime = burstTime;
        this.arrivalTime = arrivalTime;
        this.priority = 0;
    }
    
    // Method to execute the process for a given time slice
    public void execute(int timeSlice) {
        remainingTime -= timeSlice; // Decrement the remaining time by the given time slice
        if (remainingTime < 0) {
            remainingTime = 0; // Set the remaining time to zero if it becomes negative
        }
    }
    
    // Method to check if the process is finished
    public boolean isFinished() {
        return remainingTime == 0;
    }
}