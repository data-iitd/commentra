
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static class Process {
        private String processId;
        private int burstTime;
        private int tickets;
        private int waitingTime;
        private int turnAroundTime;

        // Constructor to initialize a process with its ID, burst time, and tickets
        public Process(String processId, int burstTime, int tickets) {
            this.processId = processId;
            this.burstTime = burstTime;
            this.tickets = tickets;
        }

        // Getter for process ID
        public String getProcessId() {
            return processId;
        }

        // Getter for burst time
        public int getBurstTime() {
            return burstTime;
        }

        // Getter for tickets
        public int getTickets() {
            return tickets;
        }

        // Getter for waiting time
        public int getWaitingTime() {
            return waitingTime;
        }

        // Setter for waiting time
        public void setWaitingTime(int waitingTime) {
            this.waitingTime = waitingTime;
        }

        // Getter for turn-around time
        public int getTurnAroundTime() {
            return turnAroundTime;
        }

        // Setter for turn-around time
        public void setTurnAroundTime(int turnAroundTime) {
            this.turnAroundTime = turnAroundTime;
        }
    }

    // Method to schedule processes using a lottery scheduling algorithm
    public static List<Process> scheduleProcesses(List<Process> processes) {
        Random random = new Random();
        int totalTickets = processes.stream().mapToInt(Process::getTickets).sum();
        int currentTime = 0;
        List<Process> executedProcesses = new ArrayList<>();

        // Continue scheduling processes until there are no processes left
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

    // Helper method to select a process based on the winning ticket
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

    // Main method to read process details, schedule them, and print their waiting and turn-around times
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Process> processes = new ArrayList<>();

        // Read process details from the user
        for (int i = 0; i < n; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int tickets = scanner.nextInt();
            processes.add(new Process(processId, burstTime, tickets));
        }

        // Schedule the processes and print their details
        List<Process> scheduledProcesses = scheduleProcesses(processes);
        System.out.println("Process WaitingTime TurnAroundTime");
        for (Process process : scheduledProcesses) {
            System.out.println(process.getProcessId() + " " + process.getWaitingTime() + " " + process.getTurnAroundTime());
        }
        scanner.close();
    }
}