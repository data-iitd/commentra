import java.util.*;
public class JobSchedulingWithDeadline {
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
        int n = Integer.parseInt(sc.nextLine().trim());
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split("\\s+");
            int jobId = Integer.parseInt(input[0]);
            int arrivalTime = Integer.parseInt(input[1]);
            int deadline = Integer.parseInt(input[2]);
            int profit = Integer.parseInt(input[3]);
            jobs[i] = new Job(jobId, arrivalTime, deadline, profit);
        }
        int[] result = jobSequencingWithDeadlines(jobs);
        System.out.println(result[0]);
        System.out.println(result[1]);
    }
    public static int[] jobSequencingWithDeadlines(Job[] jobs) {
        Arrays.sort(jobs, Comparator.comparingInt(job -> -job.profit));
        int maxDeadline = Arrays.stream(jobs).mapToInt(job -> job.deadline).max().orElse(0);
        int[] timeSlots = new int[maxDeadline];
        Arrays.fill(timeSlots, -1);
        int count = 0;
        int maxProfit = 0;
        for (Job job : jobs) {
            if (job.arrivalTime <= job.deadline) {
                for (int i = Math.min(job.deadline - 1, maxDeadline - 1); i >= job.arrivalTime - 1; i--) {
                    if (timeSlots[i] == -1) {
                        timeSlots[i] = job.jobId;
                        count++;
                        maxProfit += job.profit;
                        break;
                    }
                }
            }
        }
        return new int[]{count, maxProfit};
    }
}
