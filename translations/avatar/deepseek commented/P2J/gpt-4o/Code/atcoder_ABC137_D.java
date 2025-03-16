import java.util.*;

public class JobScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of jobs and the maximum number of days available
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize a priority queue to store jobs based on their deadlines
        PriorityQueue<Job> jobQueue = new PriorityQueue<>(Comparator.comparingInt(job -> job.day));
        
        // Read each job's day and salary, and add them to the priority queue
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            jobQueue.offer(new Job(day, salary));
        }
        
        // Initialize a priority queue to store the salaries of chosen jobs
        PriorityQueue<Integer> salaryQueue = new PriorityQueue<>();
        
        // Process the jobs in the order of their deadlines
        while (!jobQueue.isEmpty()) {
            Job job = jobQueue.poll();
            
            // Calculate the remaining days available for new jobs
            int remainingDays = m - salaryQueue.size();
            
            // If there are enough days to accommodate this job
            if (remainingDays >= job.day) {
                // Add the salary to the list of chosen salaries
                salaryQueue.offer(job.salary);
            } else {
                // If not enough days, check if we need to remove the smallest salary
                salaryQueue.offer(job.salary);
                salaryQueue.poll();
            }
        }
        
        // Output the sum of the chosen salaries
        int totalSalary = 0;
        while (!salaryQueue.isEmpty()) {
            totalSalary += salaryQueue.poll();
        }
        
        System.out.println(totalSalary);
        scanner.close();
    }
    
    // Job class to hold the day and salary
    static class Job {
        int day;
        int salary;
        
        Job(int day, int salary) {
            this.day = day;
            this.salary = salary;
        }
    }
}

// <END-OF-CODE>
