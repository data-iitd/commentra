import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Constant to indicate that a process was not found
    private static final int PROCESS_NOT_FOUND = -1;
    // Initial value for maximum response ratio
    private static final double INITIAL_MAX_RESPONSE_RATIO = -1.0;

    // Class representing a process with its attributes
    public static class Process {
        String name; // Name of the process
        int arrivalTime; // Arrival time of the process
        int burstTime; // Burst time of the process
        int turnAroundTime; // Turnaround time of the process
        boolean finished; // Flag to check if the process is finished

        // Constructor to initialize a process
        Process(String name, int arrivalTime, int burstTime) {
            this.name = name;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.turnAroundTime = 0;
            this.finished = false;
        }

        // Method to calculate the response ratio of the process
        double calculateResponseRatio(int currentTime) {
            return (double) (burstTime + currentTime - arrivalTime) / burstTime;
        }
    }

    public static void main(String[] args) {
        // Create a scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of processes
        int noOfProcesses = scanner.nextInt();
        String[] processNames = new String[noOfProcesses];
        int[] arrivalTimes = new int[noOfProcesses];
        int[] burstTimes = new int[noOfProcesses];

        // Read process details from user input
        for (int i = 0; i < noOfProcesses; i++) {
            processNames[i] = scanner.next();
            arrivalTimes[i] = scanner.nextInt();
            burstTimes[i] = scanner.nextInt();
        }

        // Calculate turnaround times for the processes
        int[] turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses);
        // Calculate waiting times based on turnaround times
        int[] waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes);

        // Print the waiting and turnaround times for each process
        System.out.println("Process WaitingTime TurnAroundTime");
        for (int i = 0; i < noOfProcesses; i++) {
            System.out.println(processNames[i] + " " + waitingTimes[i] + " " + turnAroundTimes[i]);
        }

        // Close the scanner
        scanner.close();
    }

    // Method to calculate turnaround times for all processes
    public static int[] calculateTurnAroundTime(String[] processNames, int[] arrivalTimes, int[] burstTimes, int noOfProcesses) {
        int currentTime = 0; // Initialize current time
        int[] turnAroundTime = new int[noOfProcesses]; // Array to store turnaround times
        Process[] processes = new Process[noOfProcesses]; // Array to hold process objects

        // Create process objects and initialize them
        for (int i = 0; i < noOfProcesses; i++) {
            processes[i] = new Process(processNames[i], arrivalTimes[i], burstTimes[i]);
        }

        // Sort processes based on their arrival times
        Arrays.sort(processes, Comparator.comparingInt(p -> p.arrivalTime));

        int finishedProcessCount = 0; // Counter for finished processes

        // Process scheduling loop
        while (finishedProcessCount < noOfProcesses) {
            // Find the next process to execute based on response ratio
            int nextProcessIndex = findNextProcess(processes, currentTime);
            if (nextProcessIndex == PROCESS_NOT_FOUND) {
                // If no process is found, increment current time
                currentTime++;
                continue;
            }

            // Get the current process to execute
            Process currentProcess = processes[nextProcessIndex];
            // Update current time to the arrival time of the current process if necessary
            currentTime = Math.max(currentTime, currentProcess.arrivalTime);
            // Calculate turnaround time for the current process
            currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime;
            // Update current time after executing the current process
            currentTime += currentProcess.burstTime;
            // Mark the current process as finished
            currentProcess.finished = true;
            finishedProcessCount++; // Increment the count of finished processes
        }

        // Store the calculated turnaround times in the array
        for (int i = 0; i < noOfProcesses; i++) {
            turnAroundTime[i] = processes[i].turnAroundTime;
        }
        return turnAroundTime; // Return the array of turnaround times
    }

    // Method to calculate waiting times based on turnaround times and burst times
    public static int[] calculateWaitingTime(int[] turnAroundTime, int[] burstTimes) {
        int[] waitingTime = new int[turnAroundTime.length]; // Array to store waiting times
        // Calculate waiting time for each process
        for (int i = 0; i < turnAroundTime.length; i++) {
            waitingTime[i] = turnAroundTime[i] - burstTimes[i];
        }
        return waitingTime; // Return the array of waiting times
    }

    // Method to find the next process to execute based on response ratio
    private static int findNextProcess(Process[] processes, int currentTime) {
        return findHighestResponseRatio(processes, currentTime); // Delegate to find highest response ratio
    }

    // Method to find the process with the highest response ratio
    private static int findHighestResponseRatio(Process[] processes, int currentTime) {
        double maxResponseRatio = INITIAL_MAX_RESPONSE_RATIO; // Initialize maximum response ratio
        int maxIndex = PROCESS_NOT_FOUND; // Index of the process with the highest response ratio

        // Iterate through processes to find the one with the highest response ratio
        for (int i = 0; i < processes.length; i++) {
            Process process = processes[i];
            // Check if the process is not finished and has arrived
            if (!process.finished && process.arrivalTime <= currentTime) {
                double responseRatio = process.calculateResponseRatio(currentTime);
                // Update maximum response ratio and index if a higher one is found
                if (responseRatio > maxResponseRatio) {
                    maxResponseRatio = responseRatio;
                    maxIndex = i;
                }
            }
        }
        return maxIndex; // Return the index of the process with the highest response ratio
    }
}
