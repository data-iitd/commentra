import java.util.*;

public class Main {
    // Job class to represent a job with its attributes
    static class Job {
        int jobId;        // Unique identifier for the job
        int arrivalTime;  // Time at which the job arrives
        int deadline;     // Deadline by which the job must be completed
        int profit;       // Profit gained from completing the job

        // Constructor to initialize the job attributes
        Job(int jobId, int arrivalTime, int deadline, int profit) {
            this.jobId = jobId;
            this.arrivalTime = arrivalTime;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static void main(String[] args) {
        // Create a scanner object to read input
        Scanner sc = new Scanner(System.in);
        
        // Read the number of jobs
        int n = Integer.parseInt(sc.nextLine().trim());
        Job[] jobs = new Job[n]; // Array to hold the jobs

        // Read job details from input
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split("\\s+");
            int jobId = Integer.parseInt(input[0]);        // Job ID
            int arrivalTime = Integer.parseInt(input[1]);  // Arrival time
            int deadline = Integer.parseInt(input[2]);     // Deadline
            int profit = Integer.parseInt(input[3]);       // Profit
            jobs[i] = new Job(jobId, arrivalTime, deadline, profit); // Create and store job
        }

        // Call the job sequencing function and get the result
        int[] result = jobSequencingWithDeadlines(jobs);
        
        // Output the number of jobs done and the total profit
        System.out.println(result[0]); // Number of jobs completed
        System.out.println(result[1]); // Total profit earned
    }

    // Function to perform job sequencing with deadlines
    public static int[] jobSequencingWithDeadlines(Job[] jobs) {
        // Sort jobs in descending order of profit
        Arrays.sort(jobs, Comparator.comparingInt(job -> -job.profit));
        
        // Find the maximum deadline to determine the size of the time slots
        int maxDeadline = Arrays.stream(jobs).mapToInt(job -> job.deadline).max().orElse(0);
        int[] timeSlots = new int[maxDeadline]; // Array to keep track of time slots
        Arrays.fill(timeSlots, -1); // Initialize time slots as unoccupied (-1)
        
        int count = 0; // Count of jobs completed
        int maxProfit = 0; // Total profit from completed jobs
        
        // Iterate through each job to schedule it
        for (Job job : jobs) {
            // Check if the job can be scheduled within its deadline
            if (job.arrivalTime <= job.deadline) {
                // Try to find a free time slot for the job
                for (int i = Math.min(job.deadline - 1, maxDeadline - 1); i >= job.arrivalTime - 1; i--) {
                    // If the time slot is free, schedule the job
                    if (timeSlots[i] == -1) {
                        timeSlots[i] = job.jobId; // Assign job ID to the time slot
                        count++; // Increment the count of completed jobs
                        maxProfit += job.profit; // Add the profit of the job
                        break; // Exit the loop after scheduling the job
                    }
                }
            }
        }
        // Return the count of jobs completed and the total profit
        return new int[]{count, maxProfit};
    }
}
