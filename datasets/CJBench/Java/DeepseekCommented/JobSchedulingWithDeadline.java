import java.util.*;
public class Main {
    static class Job {
        int jobId;
        int arrivalTime;
        int deadline;
        int profit;
        Job(int jobId, int arrivalTime, int deadline, int profit) {
            this.jobId = jobId;
            this.arrivalTime = arrivalTime;
            this.deadline = deadline;
            this.profit = profit;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim()); // Read the number of jobs
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split("\\s+"); // Read each job's details
            int jobId = Integer.parseInt(input[0]);
            int arrivalTime = Integer.parseInt(input[1]);
            int deadline = Integer.parseInt(input[2]);
            int profit = Integer.parseInt(input[3]);
            jobs[i] = new Job(jobId, arrivalTime, deadline, profit);
        }
        int[] result = jobSequencingWithDeadlines(jobs); // Process the jobs
        System.out.println(result[0]); // Print the count of scheduled jobs
        System.out.println(result[1]); // Print the maximum profit
    }
    public static int[] jobSequencingWithDeadlines(Job[] jobs) {
        Arrays.sort(jobs, Comparator.comparingInt(job -> -job.profit)); // Sort jobs by profit in descending order
        int maxDeadline = Arrays.stream(jobs).mapToInt(job -> job.deadline).max().orElse(0); // Find the maximum deadline
        int[] timeSlots = new int[maxDeadline];
        Arrays.fill(timeSlots, -1); // Initialize time slots array with -1
        int count = 0; // To count the number of jobs scheduled
        int maxProfit = 0; // To calculate the maximum profit
        for (Job job : jobs) {
            if (job.arrivalTime <= job.deadline) { // Check if the job can be scheduled
                for (int i = Math.min(job.deadline - 1, maxDeadline - 1); i >= job.arrivalTime - 1; i--) {
                    if (timeSlots[i] == -1) { // Find a time slot available for the job
                        timeSlots[i] = job.jobId;
                        count++;
                        maxProfit += job.profit;
                        break;
                    }
                }
            }
        }
        return new int[]{count, maxProfit}; // Return the result
    }
}
