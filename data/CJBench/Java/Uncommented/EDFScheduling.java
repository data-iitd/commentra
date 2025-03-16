import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
public final class EDFScheduling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numProcesses = scanner.nextInt();
        List<Process> processes = new ArrayList<>();
        for (int i = 0; i < numProcesses; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int deadline = scanner.nextInt();
            processes.add(new Process(processId, burstTime, deadline));
        }
        List<Process> executedProcesses = scheduleProcesses(processes);
        for (Process process : executedProcesses) {
            System.out.println(
                process.getProcessId() + " " +
                process.getWaitingTime() + " " +
                process.getTurnAroundTime()
            );
        }
        scanner.close();
    }
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
