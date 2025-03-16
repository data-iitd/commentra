import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
public class NonPreemptivePriorityScheduling {
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
            this.startTime = -1; 
        }
        @Override
        public int compareTo(Process other) {
            if (this.priority == other.priority) {
                return Integer.compare(this.arrivalTime, other.arrivalTime);
            }
            return Integer.compare(this.priority, other.priority);
        }
    }
    public static Process[] scheduleProcesses(Process[] processes) {
        PriorityQueue<Process> pq = new PriorityQueue<Process>();
        Queue<Process> waitingQueue = new LinkedList<Process>();
        Collections.addAll(waitingQueue, processes);
        int currentTime = 0;
        int index = 0;
        Process[] executionOrder = new Process[processes.length];
        while (!waitingQueue.isEmpty() || !pq.isEmpty()) {
            while (!waitingQueue.isEmpty() && waitingQueue.peek().arrivalTime <= currentTime) {
                pq.add(waitingQueue.poll());
            }
            if (!pq.isEmpty()) {
                Process currentProcess = pq.poll();
                currentProcess.startTime = currentTime;
                executionOrder[index++] = currentProcess;
                currentTime += currentProcess.burstTime;
            } else {
                currentTime = waitingQueue.peek().arrivalTime;
            }
        }
        return executionOrder;
    }
    public static double calculateAverageWaitingTime(Process[] executionOrder) {
        int totalWaitingTime = 0;
        for (Process process : executionOrder) {
            int waitingTime = process.startTime - process.arrivalTime;
            totalWaitingTime += waitingTime;
        }
        return (double) totalWaitingTime / executionOrder.length;
    }
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
        int n = scanner.nextInt();
        Process[] processes = new Process[n];
        for (int i = 0; i < n; i++) {
            int id = scanner.nextInt();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            int priority = scanner.nextInt();
            processes[i] = new Process(id, arrivalTime, burstTime, priority);
        }
        Process[] executionOrder = scheduleProcesses(processes);
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
