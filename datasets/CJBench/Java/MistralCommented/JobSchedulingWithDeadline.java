
import java.util.*;

public class Main {
    static class Job {
        int jobId;
        int arrivalTime;
        int deadline;
        int profit;

        // Constructor for Job class
        Job(int jobId, int arrivalTime, int deadline, int profit) {
            this.jobId = jobId;
            this.arrivalTime = arrivalTime;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize Scanner object for reading input

        int n = Integer.parseInt(sc.nextLine().trim()); // Read number of jobs from input

        Job[] jobs = new Job[n]; // Create an array of size n to store Job objects

        for (int i = 0; i < n; i++) { // Iterate through each line of input and create a new Job object
            String[] input = sc.nextLine().split("\\s+");
            int jobId = Integer.parseInt(input[0]);
            int arrivalTime = Integer.parseInt(input[1]);
            int deadline = Integer.parseInt(input[2]);
            int profit = Integer.parseInt(input[3]);

            jobs[i] = new Job(jobId, arrivalTime, deadline, profit); // Assign the new Job object to the jobs array
        }

        int[] result = jobSequencingWithDeadlines(jobs); // Call the jobSequencingWithDeadlines method to get the result

        System.out.println(result[0]); // Print the number of jobs processed
        System.out.println(result[1]); // Print the maximum profit earned
    }

    // Method to schedule jobs with deadlines
    public static int[] jobSequencingWithDeadlines(Job[] jobs) {
        Arrays.sort(jobs, Comparator.comparingInt(job -> -job.profit)); // Sort the jobs in descending order of profit

        int maxDeadline = Arrays.stream(jobs).mapToInt(job -> job.deadline).max().orElse(0); // Find the maximum deadline among all jobs

        int[] timeSlots = new int[maxDeadline]; // Create an array of size maxDeadline to store the jobId that can be scheduled in each time slot

        Arrays.fill(timeSlots, -1); // Initialize all time slots as empty

        int count = 0; // Initialize a counter to keep track of the number of jobs processed
        int maxProfit = 0; // Initialize a variable to keep track of the maximum profit earned

        for (Job job : jobs) { // Iterate through each job
            if (job.arrivalTime <= job.deadline) { // Check if the job can be processed before its deadline
                for (int i = Math.min(job.deadline - 1, maxDeadline - 1); i >= job.arrivalTime - 1; i--) { // Iterate through all possible time slots before the job's deadline
                    if (timeSlots[i] == -1) { // Check if the time slot is empty
                        timeSlots[i] = job.jobId; // Assign the jobId to the empty time slot
                        count++; // Increment the counter
                        maxProfit += job.profit; // Add the profit of the job to the maximum profit
                        break; // Exit the loop as soon as a suitable time slot is found
                    }
                }
            }
        }

        return new int[]{count, maxProfit}; // Return an array containing the number of jobs processed and the maximum profit earned
    }
}