import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

/**
 * The LotteryScheduling class implements the Lottery Scheduling algorithm, which is
 * a probabilistic CPU scheduling algorithm. Processes are assigned tickets, and
 * the CPU is allocated to a randomly selected process based on ticket count.
 * Processes with more tickets have a higher chance of being selected.
 */
public class LotteryScheduling {

    /**
     * The Process class represents a process in the scheduling system. Each process has
     * an ID, burst time (CPU time required for execution), number of tickets (used in
     * lottery selection), waiting time, and turnaround time.
     */
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

    /**
     * Schedules the processes using the Lottery Scheduling algorithm.
     * Each process is assigned a certain number of tickets, and the algorithm randomly
     * selects a process to execute based on ticket count. The method calculates the
     * waiting time and turnaround time for each process and simulates their execution.
     */
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

    /**
     * Selects a process based on a winning ticket. The method iterates over the
     * list of processes, and as the ticket sum accumulates, it checks if the
     * current process holds the winning ticket.
     *
     * @param winningTicket The randomly generated ticket number that determines the selected process.
     * @return The process associated with the winning ticket.
     */
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

        // Input number of processes
        int n = scanner.nextInt();
        List<Process> processes = new ArrayList<>();

        // Input process details
        for (int i = 0; i < n; i++) {
            String processId = scanner.next();
            int burstTime = scanner.nextInt();
            int tickets = scanner.nextInt();
            processes.add(new Process(processId, burstTime, tickets));
        }

        // Schedule processes and calculate results
        List<Process> scheduledProcesses = scheduleProcesses(processes);

        // Output the results
        System.out.println("Process WaitingTime TurnAroundTime");
        for (Process process : scheduledProcesses) {
            System.out.println(process.getProcessId() + " " + process.getWaitingTime() + " " + process.getTurnAroundTime());
        }

        scanner.close();
    }
}
