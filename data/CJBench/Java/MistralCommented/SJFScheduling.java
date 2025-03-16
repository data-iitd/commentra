
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Initialize instance variables
    protected ArrayList<ProcessDetails> processes;
    protected ArrayList<String> schedule;

    // Constructor
    public Main(final ArrayList<ProcessDetails> processes) {
        this.processes = processes; // Assign input processes to the instance variable
        this.schedule = new ArrayList<>(); // Initialize an empty list to store the execution order
        sortProcessesByArrivalTime(this.processes); // Sort the processes based on their arrival time
    }

    // Static method to sort the processes based on their arrival time
    private static void sortProcessesByArrivalTime(List<ProcessDetails> processes) {
        processes.sort((p1, p2) -> Integer.compare(p1.getArrivalTime(), p2.getArrivalTime())); // Use Collections.sort() method with a custom Comparator
    }

    // Method to schedule the processes based on Shortest Job First (SJF) algorithm
    public void scheduleProcesses() {
        ArrayList<ProcessDetails> ready = new ArrayList<>(); // Initialize an empty list to store the ready processes
        int size = processes.size(); // Get the number of processes
        int time = 0; // Initialize the current time to zero
        int executed = 0; // Initialize the number of executed processes to zero
        int k = 0; // Initialize an index variable to traverse the processes list

        if (size == 0) { // Check if there are any processes to schedule
            return;
        }

        while (executed < size) { // Iterate while all processes are not executed
            while (k < size && processes.get(k).getArrivalTime() <= time) { // Iterate while there are ready processes or processes that have arrived
                ready.add(processes.get(k)); // Add the process to the ready list
                k++; // Increment the index
            }
            ProcessDetails running = findShortestJob(ready); // Find the process with the shortest burst time from the ready list
            if (running == null) { // If the ready list is empty, increment the time and continue the loop
                time++;
            } else { // Else, execute the shortest process and update the schedule and ready list
                time += running.getBurstTime();
                schedule.add(running.getProcessId());
                ready.remove(running);
                executed++;
            }
        }
    }

    // Method to find the process with the shortest burst time from the ready list
    private ProcessDetails findShortestJob(List<ProcessDetails> readyProcesses) {
        if (readyProcesses.isEmpty()) { // If the ready list is empty, return null
            return null;
        }
        return readyProcesses.stream()
                .min((p1, p2) -> Integer.compare(p1.getBurstTime(), p2.getBurstTime())) // Use Java Stream API to find the process with the shortest burst time
                .orElse(null); // If the stream is empty, return null
    }

    // Method to get the execution order of the processes
    public ArrayList<String> getSchedule() {
        return schedule; // Return the execution order list
    }

    // Main method to read input and call the scheduling algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input
        int n = scanner.nextInt(); // Read the number of processes
        ArrayList<ProcessDetails> processes = new ArrayList<>(); // Initialize an empty list to store the processes

        for (int i = 0; i < n; i++) { // Iterate through each process and add it to the processes list
            String processId = scanner.next();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            processes.add(new ProcessDetails(processId, arrivalTime, burstTime));
        }

        Main sjfScheduling = new Main(processes); // Create an instance of the Main class and pass the processes list as an argument to the constructor
        sjfScheduling.scheduleProcesses(); // Call the scheduleProcesses() method to schedule the processes

        System.out.println("Execution Order:"); // Print the execution order header
        for (String processId : sjfScheduling.getSchedule()) { // Iterate through the execution order list and print each process ID
            System.out.println(processId);
        }

        scanner.close(); // Close the Scanner object
    }
}

class ProcessDetails {
    // Initialize instance variables and constructor
    private final String processId;
    private final int arrivalTime;
    private final int burstTime;

    public ProcessDetails(String processId, int arrivalTime, int burstTime) {
        this.processId = processId;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
    }

    // Getter methods for the instance variables
    public String getProcessId() {
        return processId;
    }

    public int getArrivalTime() {
        return arrivalTime;
    }

    public int getBurstTime() {
        return burstTime;
    }
}