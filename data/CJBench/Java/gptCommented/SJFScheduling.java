import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // List to hold the process details
    protected ArrayList<ProcessDetails> processes;
    // List to hold the scheduled order of process execution
    protected ArrayList<String> schedule;

    // Constructor to initialize the process list and sort them by arrival time
    public Main(final ArrayList<ProcessDetails> processes) {
        this.processes = processes;
        this.schedule = new ArrayList<>();
        sortProcessesByArrivalTime(this.processes);
    }

    // Method to sort processes based on their arrival time
    private static void sortProcessesByArrivalTime(List<ProcessDetails> processes) {
        processes.sort((p1, p2) -> Integer.compare(p1.getArrivalTime(), p2.getArrivalTime()));
    }

    // Method to schedule processes using Shortest Job First (SJF) algorithm
    public void scheduleProcesses() {
        ArrayList<ProcessDetails> ready = new ArrayList<>(); // List of processes that are ready to execute
        int size = processes.size(); // Total number of processes
        int time = 0; // Current time in the scheduling
        int executed = 0; // Count of executed processes
        int k = 0; // Index for traversing the processes

        // If there are no processes, exit the method
        if (size == 0) {
            return;
        }

        // Loop until all processes are executed
        while (executed < size) {
            // Add processes that have arrived by the current time to the ready list
            while (k < size && processes.get(k).getArrivalTime() <= time) {
                ready.add(processes.get(k));
                k++;
            }

            // Find the shortest job from the ready processes
            ProcessDetails running = findShortestJob(ready);
            if (running == null) {
                // If no process is ready, increment time
                time++;
            } else {
                // Execute the shortest job
                time += running.getBurstTime(); // Increment time by the burst time of the running process
                schedule.add(running.getProcessId()); // Add the process ID to the schedule
                ready.remove(running); // Remove the running process from the ready list
                executed++; // Increment the count of executed processes
            }
        }
    }

    // Method to find the process with the shortest burst time from the ready list
    private ProcessDetails findShortestJob(List<ProcessDetails> readyProcesses) {
        if (readyProcesses.isEmpty()) {
            return null; // Return null if there are no ready processes
        }
        // Return the process with the minimum burst time
        return readyProcesses.stream()
                .min((p1, p2) -> Integer.compare(p1.getBurstTime(), p2.getBurstTime()))
                .orElse(null);
    }

    // Method to get the scheduled order of processes
    public ArrayList<String> getSchedule() {
        return schedule;
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of processes
        ArrayList<ProcessDetails> processes = new ArrayList<>();

        // Read process details from input
        for (int i = 0; i < n; i++) {
            String processId = scanner.next();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            processes.add(new ProcessDetails(processId, arrivalTime, burstTime));
        }

        // Create an instance of Main with the list of processes
        Main sjfScheduling = new Main(processes);
        // Schedule the processes
        sjfScheduling.scheduleProcesses();

        // Print the execution order of processes
        System.out.println("Execution Order:");
        for (String processId : sjfScheduling.getSchedule()) {
            System.out.println(processId);
        }
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// Class to hold the details of each process
class ProcessDetails {
    private final String processId; // Unique identifier for the process
    private final int arrivalTime; // Time at which the process arrives
    private final int burstTime; // Time required for the process to execute

    // Constructor to initialize process details
    public ProcessDetails(String processId, int arrivalTime, int burstTime) {
        this.processId = processId;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
    }

    // Getter for process ID
    public String getProcessId() {
        return processId;
    }

    // Getter for arrival time
    public int getArrivalTime() {
        return arrivalTime;
    }

    // Getter for burst time
    public int getBurstTime() {
        return burstTime;
    }
}
