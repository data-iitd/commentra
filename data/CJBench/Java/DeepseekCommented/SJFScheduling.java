import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    protected ArrayList<ProcessDetails> processes; // List to hold process details
    protected ArrayList<String> schedule; // List to hold the schedule of process execution
    public Main(final ArrayList<ProcessDetails> processes) {
        this.processes = processes;
        this.schedule = new ArrayList<>();
        sortProcessesByArrivalTime(this.processes); // Sort processes by arrival time
    }
    private static void sortProcessesByArrivalTime(List<ProcessDetails> processes) {
        processes.sort((p1, p2) -> Integer.compare(p1.getArrivalTime(), p2.getArrivalTime())); // Sort processes by arrival time
    }
    public void scheduleProcesses() {
        ArrayList<ProcessDetails> ready = new ArrayList<>(); // List to hold ready processes
        int size = processes.size();
        int time = 0; // Current time
        int executed = 0; // Number of processes executed
        int k = 0; // Index for iterating through processes
        if (size == 0) {
            return;
        }
        while (executed < size) { // Continue until all processes are executed
            while (k < size && processes.get(k).getArrivalTime() <= time) {
                ready.add(processes.get(k));
                k++;
            }
            ProcessDetails running = findShortestJob(ready); // Find the shortest job in the ready list
            if (running == null) {
                time++; // If no process is ready, increment time
            } else {
                time += running.getBurstTime(); // Increment time by the burst time of the running process
                schedule.add(running.getProcessId()); // Add the process ID to the schedule
                ready.remove(running); // Remove the process from the ready list
                executed++; // Increment the number of executed processes
            }
        }
    }
    private ProcessDetails findShortestJob(List<ProcessDetails> readyProcesses) {
        if (readyProcesses.isEmpty()) {
            return null;
        }
        return readyProcesses.stream()
                .min((p1, p2) -> Integer.compare(p1.getBurstTime(), p2.getBurstTime()))
                .orElse(null); // Find the process with the shortest burst time
    }
    public ArrayList<String> getSchedule() {
        return schedule;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of processes
        ArrayList<ProcessDetails> processes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String processId = scanner.next();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            processes.add(new ProcessDetails(processId, arrivalTime, burstTime)); // Create process details and add to list
        }
        Main sjfScheduling = new Main(processes);
        sjfScheduling.scheduleProcesses();
        System.out.println("Execution Order:");
        for (String processId : sjfScheduling.getSchedule()) {
            System.out.println(processId); // Print the execution order of processes
        }
        scanner.close();
    }
}
class ProcessDetails {
    private final String processId;
    private final int arrivalTime;
    private final int burstTime;
    public ProcessDetails(String processId, int arrivalTime, int burstTime) {
        this.processId = processId;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
    }
    public String getProcessId() {
        return processId;
    }
    public int getArrivalTime() {
        return arrivalTime;
    }
    public int getBurstTime() {
        return burstTime;
    }
}
