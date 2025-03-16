import java.util.*;

/**
 * A class that implements a job scheduling algorithm to maximize profit
 * while adhering to job deadlines and arrival times.
 *
 * This class provides functionality to schedule jobs based on their profit,
 * arrival time, and deadlines to ensure that the maximum number of jobs is completed
 * within the given timeframe. It sorts the jobs in decreasing order of profit
 * and attempts to assign them to the latest possible time slots.
 */
public class JobSchedulingWithDeadline {

    /**
     * Represents a job with an ID, arrival time, deadline, and profit.
     *
     * Each job has a unique identifier, an arrival time (when it becomes available for scheduling),
     * a deadline by which it must be completed, and a profit associated with completing the job.
     */
    static class Job {
        int jobId;
        int arrivalTime;
        int deadline;
        int profit;

        /**
         * Constructs a Job instance with the specified job ID, arrival time, deadline, and profit.
         *
         * @param jobId      Unique identifier for the job
         * @param arrivalTime Time when the job becomes available for scheduling
         * @param deadline   Deadline for completing the job
         * @param profit     Profit earned upon completing the job
         */
        Job(int jobId, int arrivalTime, int deadline, int profit) {
            this.jobId = jobId;
            this.arrivalTime = arrivalTime;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    /**
     * Main method to take input from the user, perform job scheduling, and print output.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read number of jobs
        int n = Integer.parseInt(sc.nextLine().trim());

        Job[] jobs = new Job[n];

        // Read job details without prompting
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split("\\s+");
            int jobId = Integer.parseInt(input[0]);
            int arrivalTime = Integer.parseInt(input[1]);
            int deadline = Integer.parseInt(input[2]);
            int profit = Integer.parseInt(input[3]);
            jobs[i] = new Job(jobId, arrivalTime, deadline, profit);
        }

        // Call the job scheduling function
        int[] result = jobSequencingWithDeadlines(jobs);

        // Print the results
        System.out.println(result[0]);
        System.out.println(result[1]);
    }

    /**
     * Schedules jobs to maximize profit while respecting their deadlines and arrival times.
     *
     * This method sorts the jobs in descending order of profit and attempts
     * to allocate them to time slots that are before or on their deadlines,
     * provided they have arrived. The function returns an array where the first element
     * is the total number of jobs scheduled and the second element is the total profit earned.
     *
     * @param jobs An array of Job objects, each representing a job with an ID, arrival time,
     *             deadline, and profit.
     * @return An array of two integers: the first element is the count of jobs
     *         that were successfully scheduled, and the second element is the
     *         total profit earned from those jobs.
     */
    public static int[] jobSequencingWithDeadlines(Job[] jobs) {
        Arrays.sort(jobs, Comparator.comparingInt(job -> -job.profit));

        int maxDeadline = Arrays.stream(jobs).mapToInt(job -> job.deadline).max().orElse(0);
        int[] timeSlots = new int[maxDeadline];
        Arrays.fill(timeSlots, -1);

        int count = 0;
        int maxProfit = 0;

        // Schedule the jobs
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
