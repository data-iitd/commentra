import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Process {
    String name; // Name of the process
    int remainingTime; // Remaining time for the process

    Process(String name, int remainingTime) {
        this.name = name;
        this.remainingTime = remainingTime;
    }
}

public class RoundRobinScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elapsedTime = 0; // Elapsed time
        int timeQuantum; // Time quantum
        int numberOfProcesses; // Number of processes

        // Read the number of processes and the time quantum
        numberOfProcesses = scanner.nextInt();
        timeQuantum = scanner.nextInt();

        // Queue to hold the processes
        Queue<Process> processQueue = new LinkedList<>();

        // Read the process names and their respective times
        for (int i = 0; i < numberOfProcesses; i++) {
            String name = scanner.next();
            int time = scanner.nextInt();
            processQueue.add(new Process(name, time)); // Add process to the queue
        }

        // Process the queue until all processes are completed
        while (!processQueue.isEmpty()) {
            Process currentProcess = processQueue.poll(); // Remove the next process from the queue
            int timeSlice = Math.min(timeQuantum, currentProcess.remainingTime); // Determine the time slice
            currentProcess.remainingTime -= timeSlice; // Decrease the remaining time of the process
            elapsedTime += timeSlice; // Increase the elapsed time by the time slice

            if (currentProcess.remainingTime > 0) {
                processQueue.add(currentProcess); // If the process is not finished, re-add it to the queue
            } else {
                // If the process is finished, print its name and the total elapsed time
                System.out.println(currentProcess.name + " " + elapsedTime);
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
