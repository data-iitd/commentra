
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {

    // Define a Process class with its properties and methods
    public static class Process {
        private String processId;
        private int burstTime;
        private int tickets;
        private int waitingTime;
        private int turnAroundTime;

        public Process(String processId, int burstTime, int tickets) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.tickets = tickets;
        }

        // Getters for process properties
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

        // Setters for process properties
        public void setWaitingTime(int waitingTime) {
            this.waitingTime = waitingTime;
        }

        public void setTurnAroundTime(int turnAroundTime) {
            this.turnAroundTime = turnAroundTime;
        }
    }

    // Schedule processes using the Round-Robin Scheduling Algorithm
    public static List<Process> scheduleProcesses(List<Process> processes) {
        Random random = new Random(); // Initialize a random number generator
        int totalTickets = processes.stream().mapToInt(Process::getTickets).sum(); // Calculate the total number of tickets
        int currentTime = 0; // Initialize the current time to zero
        List<Process> executedProcesses = new ArrayList<>(); // Initialize an empty list to store the executed processes

        while (!processes.isEmpty()) { // While there are still processes to be executed
            int winningTicket = random.nextInt(totalTickets) + 1; // Generate a random number between 1 and the total number of tickets
            Process selectedProcess = selectProcessByTicket(processes, winningTicket); // Select the process with the corresponding ticket

            // Update the process properties
            selectedProcess.setWaitingTime(currentTime);
            currentTime += selectedProcess.getBurstTime();
            selectedProcess.setTurnAroundTime(selectedProcess.getWaitingTime() + selectedProcess.getBurstTime());
            executedProcesses.add(selectedProcess); // Add the executed process to the list
            processes.remove(selectedProcess); // Remove the executed process from the list

            totalTickets = processes.stream().mapToInt(Process::getTickets).sum(); // Update the total number of tickets
        }

        return executedProcesses; // Return the list of executed processes
    }

    // Helper method to select a process by its ticket number
    private static Process selectProcessByTicket(List<Process> processes, int winningTicket) {
        int ticketSum = 0; // Initialize a variable to keep track of the total number of tickets of the previous processes

        for (Process process : processes) { // Iterate through the list of processes
            ticketSum += process.getTickets(); // Add the number of tickets of the current process to the total

            if (ticketSum >= winningTicket) { // If the total number of tickets is greater than or equal to the winning ticket number
                return process; // Return the process with the corresponding tickets
            }
        }

        return null; // If no process is found with the winning ticket number, return null
    }

    // Main method to read input and call the scheduling algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a scanner to read input from the console

        int n = scanner.nextInt(); // Read the number of processes
        List<Process> processes = new ArrayList<>(); // Initialize an empty list to store the processes

        for (int i = 0; i < n; i++) { // Iterate through the list of processes and read their properties
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int tickets = scanner.nextInt();
            processes.add(new Process(processId, burstTime, tickets));
        }

        List<Process> scheduledProcesses = scheduleProcesses(processes); // Call the scheduling algorithm and store the result

        System.out.println("Process WaitingTime TurnAroundTime"); // Print the header of the output table

        for (Process process : scheduledProcesses) { // Iterate through the list of executed processes and print their properties
            System.out.println(process.getProcessId() + " " + process.getWaitingTime() + " " + process.getTurnAroundTime());
        }

        scanner.close(); // Close the scanner to release system resources
    }
}

