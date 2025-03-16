import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
public class LotteryScheduling {
    public static class Process {
        private String processId;
        private int burstTime;
        private int tickets;
        private int waitingTime;
        private int turnAroundTime;
        public Process(String processId, int burstTime, int tickets) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.tickets = tickets;
        }
        public String getProcessId() {
            return processId;
        }
        public int getBurstTime() {
            return burstTime;
        }
        public int getTickets() {
            return tickets;
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
    public static List<Process> scheduleProcesses(List<Process> processes) {
        Random random = new Random();
        int totalTickets = processes.stream().mapToInt(Process::getTickets).sum();
        int currentTime = 0;
        List<Process> executedProcesses = new ArrayList<>();
        while (!processes.isEmpty()) {
            int winningTicket = random.nextInt(totalTickets) + 1;
            Process selectedProcess = selectProcessByTicket(processes, winningTicket);
            selectedProcess.setWaitingTime(currentTime);
            currentTime += selectedProcess.getBurstTime();
            selectedProcess.setTurnAroundTime(selectedProcess.getWaitingTime() + selectedProcess.getBurstTime());
            executedProcesses.add(selectedProcess);
            processes.remove(selectedProcess);
            totalTickets = processes.stream().mapToInt(Process::getTickets).sum();
        }
        return executedProcesses;
    }
    private static Process selectProcessByTicket(List<Process> processes, int winningTicket) {
        int ticketSum = 0;
        for (Process process : processes) {
            ticketSum += process.getTickets();
            if (ticketSum >= winningTicket) {
                return process;
            }
        }
        return null;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Process> processes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int tickets = scanner.nextInt();
            processes.add(new Process(processId, burstTime, tickets));
        }
        List<Process> scheduledProcesses = scheduleProcesses(processes);
        System.out.println("Process WaitingTime TurnAroundTime");
        for (Process process : scheduledProcesses) {
            System.out.println(process.getProcessId() + " " + process.getWaitingTime() + " " + process.getTurnAroundTime());
        }
        scanner.close();
    }
}
