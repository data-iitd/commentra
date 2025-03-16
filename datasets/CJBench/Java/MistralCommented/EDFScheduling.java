
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Initialize a Scanner to read input from the console
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of processes from the input
        int numProcesses = scanner.nextInt();

        // Initialize an ArrayList to store the Process objects
        List<Process> processes = new ArrayList<>();

        // Read the details of each process and add it to the list
        for (int i = 0; i < numProcesses; i++) {
            String processId = scanner.next(); // Read the process ID
            int burstTime = scanner.nextInt(); // Read the burst time
            int deadline = scanner.nextInt(); // Read the deadline
            processes.add(new Process(processId, burstTime, deadline));
        }

        // Schedule the processes and print the results
        List<Process> executedProcesses = scheduleProcesses(processes);
        for (Process process : executedProcesses) {
            System.out.println(
                process.getProcessId() + " " +
                process.getWaitingTime() + " " +
                process.getTurnAroundTime()
            );
        }

        // Close the Scanner to free system resources
        scanner.close();
    }

    // Sort the list of processes based on their deadlines
    public static List<Process> scheduleProcesses(List<Process> processes) {
        // Sort the list using a Comparator that compares the deadlines
        processes.sort(Comparator.comparingInt(Process::getDeadline));

        // Initialize variables for current time and executed processes
        int currentTime = 0;
        List<Process> executedProcesses = new ArrayList<>();

        // Iterate through the sorted list of processes and execute them
        for (Process process : processes) {
            // Calculate the waiting time and turnaround time for the current process
            process.setWaitingTime(currentTime);
            currentTime += process.getBurstTime();
            process.setTurnAroundTime(process.getWaitingTime() + process.getBurstTime());

            // Check if the current process missed its deadline
            if (currentTime > process.getDeadline()) {
                System.out.println("Warning: Process " + process.getProcessId() + " missed its deadline.");
            }

            // Add the executed process to the list of executed processes
            executedProcesses.add(process);
        }

        // Return the list of executed processes
        return executedProcesses;
    }

    // Define a static inner class Process to represent a process
    public static class Process {
        private String processId;
        private int burstTime;
        private int deadline;
        private int waitingTime;
        private int turnAroundTime;

        // Initialize the Process object with the given process ID, burst time, and deadline
        public Process(String processId, int burstTime, int deadline) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.deadline = deadline;
        }

        // Getters for the process ID, burst time, deadline, waiting time, and turnaround time
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