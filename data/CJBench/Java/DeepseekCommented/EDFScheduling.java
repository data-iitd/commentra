import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
public final class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read the number of processes
        int numProcesses = scanner.nextInt();
        // Create a list to store the processes
        List<Process> processes = new ArrayList<>();
        // Loop to read each process's details and add to the list
        for (int i = 0; i < numProcesses; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int deadline = scanner.nextInt();
            processes.add(new Process(processId, burstTime, deadline));
        }
        // Schedule the processes and get the list of executed processes
        List<Process> executedProcesses = scheduleProcesses(processes);
        // Loop to print the details of each executed process
        for (Process process : executedProcesses) {
            System.out.println(
                process.getProcessId() + " " +
                process.getWaitingTime() + " " +
                process.getTurnAroundTime()
            );
        }
        // Close the scanner to free up resources
        scanner.close();
    }
    // Method to schedule processes based on their deadlines
    public static List<Process> scheduleProcesses(List<Process> processes) {
        // Sort the processes by their deadlines
        processes.sort(Comparator.comparingInt(Process::getDeadline));
        // Initialize the current time to 0
        int currentTime = 0;
        // Create a list to store the executed processes
        List<Process> executedProcesses = new ArrayList<>();
        // Loop through each process to calculate waiting and turnaround times
        for (Process process : processes) {
            // Set the waiting time for the current process
            process.setWaitingTime(currentTime);
            // Update the current time by adding the burst time of the current process
            currentTime += process.getBurstTime();
            // Set the turnaround time for the current process
            process.setTurnAroundTime(process.getWaitingTime() + process.getBurstTime());
            // Check if the process missed its deadline and print a warning if it did
            if (currentTime > process.getDeadline()) {
                System.out.println("Warning: Process " + process.getProcessId() + " missed its deadline.");
            }
            // Add the current process to the list of executed processes
            executedProcesses.add(process);
        }
        // Return the list of executed processes
        return executedProcesses;
    }
    // Inner class representing a process
    public static class Process {
        private String processId;
        private int burstTime;
        private int deadline;
        private int waitingTime;
        private int turnAroundTime;
        // Constructor for the Process class
        public Process(String processId, int burstTime, int deadline) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.deadline = deadline;
        }
        // Getter for process ID
        public String getProcessId() {
            return processId;
        }
        // Getter for burst time
        public int getBurstTime() {
            return burstTime;
        }
        // Getter for deadline
        public int getDeadline() {
            return deadline;
        }
        // Getter for waiting time
        public int getWaitingTime() {
            return waitingTime;
        }
        // Setter for waiting time
        public void setWaitingTime(int waitingTime) {
            this.waitingTime = waitingTime;
        }
        // Getter for turnaround time
        public int getTurnAroundTime() {
            return turnAroundTime;
        }
        // Setter for turnaround time
        public void setTurnAroundTime(int turnAroundTime) {
            this.turnAroundTime = turnAroundTime;
        }
    }
}
