import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public final class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of processes to be scheduled
        int numProcesses = scanner.nextInt();
        
        // Initialize a list to hold the processes
        List<Process> processes = new ArrayList<>();
        
        // Loop to read each process's details
        for (int i = 0; i < numProcesses; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int deadline = scanner.nextInt();
            // Add the new process to the list
            processes.add(new Process(processId, burstTime, deadline));
        }
        
        // Schedule the processes and get the list of executed processes
        List<Process> executedProcesses = scheduleProcesses(processes);
        
        // Output the results for each executed process
        for (Process process : executedProcesses) {
            System.out.println(
                process.getProcessId() + " " +
                process.getWaitingTime() + " " +
                process.getTurnAroundTime()
            );
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    public static List<Process> scheduleProcesses(List<Process> processes) {
        // Sort the processes based on their deadlines
        processes.sort(Comparator.comparingInt(Process::getDeadline));
        
        // Initialize the current time to track the scheduling
        int currentTime = 0;
        
        // List to hold the processes that have been executed
        List<Process> executedProcesses = new ArrayList<>();
        
        // Loop through each process to calculate waiting and turnaround times
        for (Process process : processes) {
            // Set the waiting time for the current process
            process.setWaitingTime(currentTime);
            
            // Update the current time by adding the burst time of the current process
            currentTime += process.getBurstTime();
            
            // Calculate the turnaround time for the current process
            process.setTurnAroundTime(process.getWaitingTime() + process.getBurstTime());
            
            // Check if the process has missed its deadline and print a warning if so
            if (currentTime > process.getDeadline()) {
                System.out.println("Warning: Process " + process.getProcessId() + " missed its deadline.");
            }
            
            // Add the current process to the list of executed processes
            executedProcesses.add(process);
        }
        
        // Return the list of executed processes
        return executedProcesses;
    }

    // Inner class to represent a process with its attributes
    public static class Process {
        private String processId; // Unique identifier for the process
        private int burstTime;    // Time required for the process to complete
        private int deadline;     // Deadline by which the process should be completed
        private int waitingTime;  // Time the process has to wait before execution
        private int turnAroundTime; // Total time taken from arrival to completion

        // Constructor to initialize a process with its ID, burst time, and deadline
        public Process(String processId, int burstTime, int deadline) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.deadline = deadline;
        }

        // Getter methods for process attributes
        public String getProcessId() {
            return processId;
        }
        public int getBurstTime() {
            return burstTime;
        }
        public int getDeadline() {
            return deadline;
        }
        public int getWaitingTime() {
            return waitingTime;
        }
        
        // Setter methods for waiting and turnaround times
        public void setWaitingTime(int waitingTime) {
            this.waitingTime = waitingTime;
        }
        public int getTurnAroundTime() {
            return turnAroundTime;
        }
        public void setTurnAroundTime(int turnAroundTime) {
            this.turnAroundTime = turnAroundTime;
        }
    }
}
