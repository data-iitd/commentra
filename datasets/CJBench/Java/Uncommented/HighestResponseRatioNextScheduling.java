import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
public class HighestResponseRatioNextScheduling {
    private static final int PROCESS_NOT_FOUND = -1;
    private static final double INITIAL_MAX_RESPONSE_RATIO = -1.0;
    public static class Process {
        String name;
        int arrivalTime;
        int burstTime;
        int turnAroundTime;
        boolean finished;
        Process(String name, int arrivalTime, int burstTime) {
            this.name = name;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.turnAroundTime = 0;
            this.finished = false;
        }
        double calculateResponseRatio(int currentTime) {
            return (double) (burstTime + currentTime - arrivalTime) / burstTime;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int noOfProcesses = scanner.nextInt();
        String[] processNames = new String[noOfProcesses];
        int[] arrivalTimes = new int[noOfProcesses];
        int[] burstTimes = new int[noOfProcesses];
        for (int i = 0; i < noOfProcesses; i++) {
            processNames[i] = scanner.next();
            arrivalTimes[i] = scanner.nextInt();
            burstTimes[i] = scanner.nextInt();
        }
        int[] turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses);
        int[] waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes);
        System.out.println("Process WaitingTime TurnAroundTime");
        for (int i = 0; i < noOfProcesses; i++) {
            System.out.println(processNames[i] + " " + waitingTimes[i] + " " + turnAroundTimes[i]);
        }
        scanner.close();
    }
    public static int[] calculateTurnAroundTime(String[] processNames, int[] arrivalTimes, int[] burstTimes, int noOfProcesses) {
        int currentTime = 0;
        int[] turnAroundTime = new int[noOfProcesses];
        Process[] processes = new Process[noOfProcesses];
        for (int i = 0; i < noOfProcesses; i++) {
            processes[i] = new Process(processNames[i], arrivalTimes[i], burstTimes[i]);
        }
        Arrays.sort(processes, Comparator.comparingInt(p -> p.arrivalTime));
        int finishedProcessCount = 0;
        while (finishedProcessCount < noOfProcesses) {
            int nextProcessIndex = findNextProcess(processes, currentTime);
            if (nextProcessIndex == PROCESS_NOT_FOUND) {
                currentTime++;
                continue;
            }
            Process currentProcess = processes[nextProcessIndex];
            currentTime = Math.max(currentTime, currentProcess.arrivalTime);
            currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime;
            currentTime += currentProcess.burstTime;
            currentProcess.finished = true;
            finishedProcessCount++;
        }
        for (int i = 0; i < noOfProcesses; i++) {
            turnAroundTime[i] = processes[i].turnAroundTime;
        }
        return turnAroundTime;
    }
    public static int[] calculateWaitingTime(int[] turnAroundTime, int[] burstTimes) {
        int[] waitingTime = new int[turnAroundTime.length];
        for (int i = 0; i < turnAroundTime.length; i++) {
            waitingTime[i] = turnAroundTime[i] - burstTimes[i];
        }
        return waitingTime;
    }
    private static int findNextProcess(Process[] processes, int currentTime) {
        return findHighestResponseRatio(processes, currentTime);
    }
    private static int findHighestResponseRatio(Process[] processes, int currentTime) {
        double maxResponseRatio = INITIAL_MAX_RESPONSE_RATIO;
        int maxIndex = PROCESS_NOT_FOUND;
        for (int i = 0; i < processes.length; i++) {
            Process process = processes[i];
            if (!process.finished && process.arrivalTime <= currentTime) {
                double responseRatio = process.calculateResponseRatio(currentTime);
                if (responseRatio > maxResponseRatio) {
                    maxResponseRatio = responseRatio;
                    maxIndex = i;
                }
            }
        }
        return maxIndex;
    }
}
