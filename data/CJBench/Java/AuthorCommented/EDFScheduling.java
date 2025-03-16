import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * The Earliest Deadline First (EDF) Scheduling class implements a dynamic scheduling algorithm.
 * It assigns the CPU to processes with the earliest deadlines, ensuring that deadlines are met if possible.
 */
public final class EDFScheduling {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of processes
        int numProcesses = scanner.nextInt();

        // Input process details
        List<Process> processes = new ArrayList<>();
        for (int i = 0; i < numProcesses; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int deadline = scanner.nextInt();
            processes.add(new Process(processId, burstTime, deadline));
        }

        // Schedule processes
        List<Process> executedProcesses = scheduleProcesses(processes);

        // Output results
        for (Process process : executedProcesses) {
            System.out.println(
                process.getProcessId() + " " +
                process.getWaitingTime() + " " +
                process.getTurnAroundTime()
            );
        }

        scanner.close();
    }

    /**
     * Schedules the processes using Earliest Deadline First (EDF) scheduling.
     * Processes are sorted by their deadlines, and the method simulates their execution.
     * It calculates the waiting time and turnaround time for each process.
     *
     * @return List of processes after they have been executed in order of earliest deadline first.
     */
    public static List<Process> scheduleProcesses(List<Process> processes) {
        processes.sort(Comparator.comparingInt(Process::getDeadline));

        int currentTime = 0;
        List<Process> executedProcesses = new ArrayList<>();

        for (Process process : processes) {
            process.setWaitingTime(currentTime);
            currentTime += process.getBurstTime();
            process.setTurnAroundTime(process.getWaitingTime() + process.getBurstTime());

            if (currentTime > process.getDeadline()) {
                System.out.println("Warning: Process " + process.getProcessId() + " missed its deadline.");
            }

            executedProcesses.add(process);
        }

        return executedProcesses;
    }

    /**
     * The Process class represents a process with an ID, burst time, deadline, waiting time, and turnaround time.
     */
    public static class Process {
        private String processId;
        private int burstTime;
        private int deadline;
        private int waitingTime;
        private int turnAroundTime;

        public Process(String processId, int burstTime, int deadline) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.deadline = deadline;
        }

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
