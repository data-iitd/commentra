import java.util.PriorityQueue;
import java.util.Scanner;

public class JobScheduling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of jobs and the maximum number of days available
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize priority queues to store job days and salaries
        PriorityQueue<Job> x = new PriorityQueue<>((a, b) -> Integer.compare(b.day, a.day));
        PriorityQueue<Job> y = new PriorityQueue<>((a, b) -> Integer.compare(a.salary, b.salary));
        
        // Read each job's day and salary, and push them into the priority queue x
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            x.add(new Job(day, salary));
        }
        
        // Process the jobs in the order of their deadlines
        while (!x.isEmpty()) {
            // Pop the job with the largest deadline
            Job job = x.poll();
            
            // Calculate the remaining days available for new jobs
            int r = m - y.size();
            
            // If there are enough days to accommodate this job
            if (r >= job.day) {
                // Add the job to the list of chosen jobs
                y.add(job);
            } else {
                // If not enough days, check if we need to remove the smallest salary
                y.add(job);
                y.poll();
            }
        }
        
        // Output the sum of the chosen salaries
        int sum = 0;
        for (Job job : y) {
            sum += job.salary;
        }
        System.out.println(sum);
    }
    
    // Define a Job class to store job details
    static class Job {
        int day;
        int salary;
        
        Job(int day, int salary) {
            this.day = day;
            this.salary = salary;
        }
    }
}
