import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {
    // Class representing a process with its attributes
    public static class Process {
        private String processId; // Unique identifier for the process
        private int burstTime; // Time required for the process to complete
        private int tickets; // Number of tickets assigned to the process for scheduling
        private int waitingTime; // Time the process has been waiting in the queue
        private int turnAroundTime; // Total time taken from arrival to completion

        // Constructor to initialize a process with its ID, burst time, and tickets
        public Process(String processId, int burstTime, int tickets) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.tickets = tickets;
        }

        // Getter methods for process attributes
        public String getProcessId() {
            return processId;
        }
        public int getBurstTime() {
            return burstTime;
        }
        public int getTickets() {
            return tickets;
        }
        public int getWaitingTime() {
            return waitingTime;
        }
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

    // Method to schedule processes based on a lottery system
    public static List<Process> scheduleProcesses(List<Process> processes) {
        Random random = new Random(); // Random number generator for selecting winning tickets
        int totalTickets = processes.stream().mapToInt(Process::getTickets).sum(); // Calculate total tickets
        int currentTime = 0; // Initialize current time
        List<Process> executedProcesses = new ArrayList<>(); // List to store executed processes

        // Continue scheduling until all processes are executed
        while (!processes.isEmpty()) {
            // Select a winning ticket randomly
            int winningTicket = random.nextInt(totalTickets) + 1;
            // Select the process corresponding to the winning ticket
            Process selectedProcess = selectProcessByTicket(processes, winningTicket);
            // Set the waiting time for the selected process
            selectedProcess.setWaitingTime(currentTime);
            // Update current time by adding the burst time of the selected process
            currentTime += selectedProcess.getBurstTime();
            // Calculate turn around time for the selected process
            selectedProcess.setTurnAroundTime(selectedProcess.getWaitingTime() + selectedProcess.getBurstTime());
            // Add the executed process to the list
            executedProcesses.add(selectedProcess);
            // Remove the executed process from the original list
            processes.remove(selectedProcess);
            // Recalculate total tickets after removing the executed process
            totalTickets = processes.stream().mapToInt(Process::getTickets).sum();
        }
        return executedProcesses; // Return the list of executed processes
    }

    // Method to select a process based on the winning ticket
    private static Process selectProcessByTicket(List<Process> processes, int winningTicket) {
        int ticketSum = 0; // Initialize sum of tickets
        // Iterate through the processes to find the one corresponding to the winning ticket
        for (Process process : processes) {
            ticketSum += process.getTickets(); // Accumulate ticket sum
            if (ticketSum >= winningTicket) { // Check if the winning ticket falls within the current sum
                return process; // Return the selected process
            }
        }
        return null; // Return null if no process is found (should not happen)
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        int n = scanner.nextInt(); // Read the number of processes
        List<Process> processes = new ArrayList<>(); // List to store all processes

        // Loop to read process details from user input
        for (int i = 0; i < n; i++) {
            String processId = scanner.next(); // Read process ID
            int burstTime = scanner.nextInt(); // Read burst time
            int tickets = scanner.nextInt(); // Read number of tickets
            // Create a new process and add it to the list
            processes.add(new Process(processId, burstTime, tickets));
        }

        // Schedule the processes and get the executed order
        List<Process> scheduledProcesses = scheduleProcesses(processes);
        // Print the results: Process ID, Waiting Time, and Turn Around Time
        System.out.println("Process WaitingTime TurnAroundTime");
        for (Process process : scheduledProcesses) {
            System.out.println(process.getProcessId() + " " + process.getWaitingTime() + " " + process.getTurnAroundTime());
        }
        scanner.close(); // Close the scanner to free resources
    }
}
