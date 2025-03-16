
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Constants for special values
    private static final int PROCESS_NOT_FOUND = -1;
    private static final double INITIAL_MAX_RESPONSE_RATIO = -1.0;
    
    // Class for process information
    public static class Process {
        String name;
        int arrivalTime;
        int burstTime;
        int turnAroundTime;
        boolean finished;
        
        // Constructor for process object
        public Process(String name, int arrivalTime, int burstTime) {
            this.name = name;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.turnAroundTime = 0;
            this.finished = false;
        }
        
        // Method to calculate response ratio
        public double calculateResponseRatio(int currentTime) {
            return (double) (burstTime + currentTime - arrivalTime) / burstTime;
        }
    }
    
    public static void main(String[] args) {
        // Initialize scanner for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read number of processes from user input
        int noOfProcesses = scanner.nextInt();
        
        // Initialize arrays for process names, arrival times, and burst times
        String[] processNames = new String[noOfProcesses];
        int[] arrivalTimes = new int[noOfProcesses];
        int[] burstTimes = new int[noOfProcesses];
        
        // Read process information from user input
        for (int i = 0; i < noOfProcesses; i++) {
            processNames[i] = scanner.next();
            arrivalTimes[i] = scanner.nextInt();
            burstTimes[i] = scanner.nextInt();
        }
        
        // Calculate turnaround times
        int[] turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses);
        
        // Calculate waiting times
        int[] waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes);
        
        // Print process information with waiting and turnaround times
        System.out.println("Process WaitingTime TurnAroundTime");
        for (int i = 0; i < noOfProcesses; i++) {
            System.out.println(processNames[i] + " " + waitingTimes[i] + " " + turnAroundTimes[i]);
        }
        
        // Close scanner
        scanner.close();
    }
    
    // Method to calculate turnaround times
    public static int[] calculateTurnAroundTime(String[] processNames, int[] arrivalTimes, int[] burstTimes, int noOfProcesses) {
        int currentTime = 0; // Current time
        
        int[] turnAroundTime = new int[noOfProcesses]; // Array to store turnaround times
        Process[] processes = new Process[noOfProcesses]; // Array to store process objects
        
        // Initialize process objects
        for (int i = 0; i < noOfProcesses; i++) {
            processes[i] = new Process(processNames[i], arrivalTimes[i], burstTimes[i]);
        }
        
        // Sort processes based on arrival times
        Arrays.sort(processes, Comparator.comparingInt(p -> p.arrivalTime));
        
        int finishedProcessCount = 0; // Number of finished processes
        
        // Simulate CPU scheduling
        while (finishedProcessCount < noOfProcesses) {
            int nextProcessIndex = findNextProcess(processes, currentTime);
            
            if (nextProcessIndex == PROCESS_NOT_FOUND) {
                currentTime++; // Increment current time if no process is ready
                continue;
            }
            
            Process currentProcess = processes[nextProcessIndex]; // Get the next process
            currentTime = Math.max(currentTime, currentProcess.arrivalTime); // Set current time to the arrival time of the next process
            
            currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime; // Calculate turnaround time
            currentTime += currentProcess.burstTime; // Increment current time by burst time of the current process
            currentProcess.finished = true; // Mark the current process as finished
            finishedProcessCount++; // Increment finished process count
        }
        
        // Copy turnaround times from process objects to the output array
        for (int i = 0; i < noOfProcesses; i++) {
            turnAroundTime[i] = processes[i].turnAroundTime;
        }
        
        return turnAroundTime;
    }
    
    // Method to calculate waiting times
    public static int[] calculateWaitingTime(int[] turnAroundTime, int[] burstTimes) {
        int[] waitingTime = new int[turnAroundTime.length]; // Array to store waiting times
        
        for (int i = 0; i < turnAroundTime.length; i++) {
            waitingTime[i] = turnAroundTime[i] - burstTimes[i]; // Calculate waiting time for each process
        }
        
        return waitingTime;
    }
    
    // Method to find the next process based on the highest response ratio
    private static int findNextProcess(Process[] processes, int currentTime) {
        double maxResponseRatio = INITIAL_MAX_RESPONSE_RATIO; // Initialize maximum response ratio
        int maxIndex = PROCESS_NOT_FOUND; // Initialize index of the process with the maximum response ratio
        
        for (int i = 0; i < processes.length; i++) {
            Process process = processes[i]; // Get the current process
            
            if (!process.finished && process.arrivalTime <= currentTime) { // Check if the process is ready and not finished
                double responseRatio = process.calculateResponseRatio(currentTime); // Calculate response ratio
                
                if (responseRatio > maxResponseRatio) { // If the response ratio is higher than the current maximum
                    maxResponseRatio = responseRatio; // Update maximum response ratio
                    maxIndex = i; // Update index of the process with the maximum response ratio
                }
            }
        }
        
        return maxIndex; // Return the index of the process with the maximum response ratio
    }
}