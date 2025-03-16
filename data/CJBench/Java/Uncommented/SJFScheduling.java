import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class SJFScheduling {
    protected ArrayList<ProcessDetails> processes;
    protected ArrayList<String> schedule;
    public SJFScheduling(final ArrayList<ProcessDetails> processes) {
        this.processes = processes;
        this.schedule = new ArrayList<>();
        sortProcessesByArrivalTime(this.processes);
    }
    private static void sortProcessesByArrivalTime(List<ProcessDetails> processes) {
        processes.sort((p1, p2) -> Integer.compare(p1.getArrivalTime(), p2.getArrivalTime()));
    }
    public void scheduleProcesses() {
        ArrayList<ProcessDetails> ready = new ArrayList<>();
        int size = processes.size();
        int time = 0;
        int executed = 0;
        int k = 0;
        if (size == 0) {
            return;
        }
        while (executed < size) {
            while (k < size && processes.get(k).getArrivalTime() <= time) {
                ready.add(processes.get(k));
                k++;
            }
            ProcessDetails running = findShortestJob(ready);
            if (running == null) {
                time++;
            } else {
                time += running.getBurstTime();
                schedule.add(running.getProcessId());
                ready.remove(running);
                executed++;
            }
        }
    }
    private ProcessDetails findShortestJob(List<ProcessDetails> readyProcesses) {
        if (readyProcesses.isEmpty()) {
            return null;
        }
        return readyProcesses.stream()
                .min((p1, p2) -> Integer.compare(p1.getBurstTime(), p2.getBurstTime()))
                .orElse(null);
    }
    public ArrayList<String> getSchedule() {
        return schedule;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<ProcessDetails> processes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String processId = scanner.next();
            int arrivalTime = scanner.nextInt();
            int burstTime = scanner.nextInt();
            processes.add(new ProcessDetails(processId, arrivalTime, burstTime));
        }
        SJFScheduling sjfScheduling = new SJFScheduling(processes);
        sjfScheduling.scheduleProcesses();
        System.out.println("Execution Order:");
        for (String processId : sjfScheduling.getSchedule()) {
            System.out.println(processId);
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
