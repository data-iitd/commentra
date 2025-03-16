import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Non-Preemptive Priority Scheduling Algorithm Implementation.
 * Processes are executed in the order of their priority, with lower priority values being executed first.
 */
public class NonPreemptivePriorityScheduling {

    /**
     * Represents a process with an ID, arrival time, burst time, priority, and start time.
     */
    static class Process implements Comparable<Process> {
        int id;
        int arrivalTime;
        int burstTime;
        int priority;
        int startTime;

        Process(int id, int arrivalTime, int burstTime, int priority) {
            this.id = id;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.priority = priority;
            this.startTime = -1; // Indicates the process has not started yet
        }

        @Override
        public int compareTo(Process other) {
            if (this.priority == other.priority) {
                return Integer.compare(this.arrivalTime, other.arrivalTime);
            }
            return Integer.compare(this.priority, other.priority);
        }
    }

    /**
     * Schedules the processes based on their priority in a non-preemptive manner.
     *
     * @param processes Array of processes to be scheduled.
     * @return Array of processes in the order they are executed.
     */
    public static Process[] scheduleProcesses(Process[] processes) {
        PriorityQueue<Process> pq = new PriorityQueue<Process>();
        Queue<Process> waitingQueue = new LinkedList<Process>();
        Collections.addAll(waitingQueue, processes);

        int currentTime = 0;
        int index = 0;
        Process[] executionOrder = new Process[processes.length];

        while (!waitingQueue.isEmpty() || !pq.isEmpty()) {
            // Add processes that have arrived to the priority queue
            while (!waitingQueue.isEmpty() && waitingQueue.peek().arrivalTime <= currentTime) {
                pq.add(waitingQueue.poll());
            }

            if (!pq.isEmpty()) {
                Process currentProcess = pq.poll();
                currentProcess.startTime = currentTime;
                executionOrder[index++] = currentProcess;
                currentTime += currentProcess.burstTime;
            } else {
                // If no process is ready, move to the next arrival time
                currentTime = waitingQueue.peek().arrivalTime;
            }
        }

        return executionOrder;
    }

    /**
     * Calculates the average waiting time of the processes.
     *
     * @param executionOrder Array of processes in execution order.
     * @return Average waiting time.
     */
    public static double calculateAverageWaitingTime(Process[] executionOrder) {
        int totalWaitingTime = 0;
        for (Process process : executionOrder) {
            int waitingTime = process.startTime - process.arrivalTime;
            totalWaitingTime += waitingTime;
        }
        return (double) totalWaitingTime / executionOrder.length;
    }

    /**
     * Calculates the average turnaround time of the processes.
     *
     * @param executionOrder Array of processes in execution order.
     * @return Average turnaround time.
     */
    public static double calculateAverageTurnaroundTime(Process[] executionOrder) {
        int totalTurnaroundTime = 0;
        for (Process process : executionOrder) {
            int turnaroundTime = process.startTime + process.burstTime - process.arrivalTime;
            totalTurnaroundTime += turnaroundTime;
        }
        return (double) totalTurnaroundTime / executionOrder.length;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Input number of processes
        int n = scanner.nextInt();
        Process[] processes = new Process[n];

        // Input process details
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            int priority = scanner.nextInt();
            processes[i] = new Process(id, arrivalTime, burstTime, priority);
        }

        // Schedule processes
        Process[] executionOrder = scheduleProcesses(processes);

        // Output execution order
        System.out.println("Execution Order:");
        for (Process process : executionOrder) {
            System.out.println("Process " + process.id + " started at time " + process.startTime);
        }

        double avgWaitingTime = calculateAverageWaitingTime(executionOrder);
        double avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder);

        System.out.printf("Average Waiting Time: %.2f%n", avgWaitingTime);
        System.out.printf("Average Turnaround Time: %.2f%n", avgTurnaroundTime);

        scanner.close();
    }
}
