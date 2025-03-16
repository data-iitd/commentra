import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

/**
 * The Multi-Level Feedback Queue (MLFQ) Scheduler class.
 * This class simulates scheduling using multiple queues, where processes move
 * between queues depending on their CPU burst behavior.
 */
public class MLFQScheduler {

    private List<Queue<Process>> queues; // Multi-level feedback queues
    private int[] timeQuantum; // Time quantum for each queue level
    private int currentTime; // Current time in the system

    /**
     * Constructor to initialize the MLFQ scheduler with the specified number of
     * levels and their corresponding time quantums.
     *
     * @param levels       Number of queues (priority levels)
     * @param timeQuantums Time quantum for each queue level
     */
    public MLFQScheduler(int levels, int[] timeQuantums) {
        queues = new ArrayList<>(levels);
        for (int i = 0; i < levels; i++) {
            queues.add(new LinkedList<>());
        }
        timeQuantum = timeQuantums;
        currentTime = 0;
    }

    /**
     * Adds a new process to the highest priority queue (queue 0).
     *
     * @param p The process to be added to the scheduler
     */
    public void addProcess(Process p) {
        queues.get(0).add(p);
    }

    /**
     * Executes the scheduling process by running the processes in all queues,
     * promoting or demoting them based on their completion status and behavior.
     * The process continues until all queues are empty.
     */
    public void run() {
        while (!allQueuesEmpty()) {
            for (int i = 0; i < queues.size(); i++) {
                Queue<Process> queue = queues.get(i);
                if (!queue.isEmpty()) {
                    Process p = queue.poll();
                    int quantum = timeQuantum[i];
                    int timeSlice = Math.min(quantum, p.remainingTime);
                    p.execute(timeSlice);
                    currentTime += timeSlice;

                    if (p.isFinished()) {
                        System.out.println("Process " + p.pid + " finished at time " + currentTime);
                    } else {
                        if (i < queues.size() - 1) {
                            p.priority++;
                            queues.get(i + 1).add(p);
                        } else {
                            queue.add(p);
                        }
                    }
                }
            }
        }
    }

    /**
     * Helper function to check if all the queues are empty (i.e., no process is
     * left to execute).
     *
     * @return true if all queues are empty, otherwise false
     */
    private boolean allQueuesEmpty() {
        for (Queue<Process> queue : queues) {
            if (!queue.isEmpty()) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input number of queues and their time quantums
        int levels = scanner.nextInt();
        int[] timeQuantums = new int[levels];
        for (int i = 0; i < levels; i++) {
            timeQuantums[i] = scanner.nextInt();
        }

        MLFQScheduler scheduler = new MLFQScheduler(levels, timeQuantums);

        // Input number of processes
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int pid = scanner.nextInt();
            int burstTime = scanner.nextInt();
            int arrivalTime = scanner.nextInt();
            scheduler.addProcess(new Process(pid, burstTime, arrivalTime));
        }

        scheduler.run();
        scanner.close();
    }
}

/**
 * Represents a process in the Multi-Level Feedback Queue (MLFQ) scheduling
 * algorithm.
 */
class Process {
    int pid;
    int burstTime;
    int remainingTime;
    int arrivalTime;
    int priority;

    /**
     * Constructor to initialize a new process.
     *
     * @param pid         Process ID
     * @param burstTime   CPU Burst Time (time required for the process)
     * @param arrivalTime Arrival time of the process
     */
    public Process(int pid, int burstTime, int arrivalTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        this.remainingTime = burstTime;
        this.arrivalTime = arrivalTime;
        this.priority = 0;
    }

    /**
     * Executes the process for a given time slice.
     *
     * @param timeSlice The amount of time the process is executed
     */
    public void execute(int timeSlice) {
        remainingTime -= timeSlice;
        if (remainingTime < 0) {
            remainingTime = 0;
        }
    }

    /**
     * Checks if the process has finished execution.
     *
     * @return true if the process is finished, otherwise false
     */
    public boolean isFinished() {
        return remainingTime == 0;
    }
}
