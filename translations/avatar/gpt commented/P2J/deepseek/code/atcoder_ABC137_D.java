import java.util.PriorityQueue;
import java.util.Scanner;

public class JobSelection {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of days (n) and the maximum number of jobs (m) from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize two heaps: one for jobs (x) and one for selected salaries (y)
        PriorityQueue<Job> x = new PriorityQueue<>((a, b) -> (b.day != a.day) ? b.day - a.day : b.salary - a.salary);
        PriorityQueue<Job> y = new PriorityQueue<>((a, b) -> b.salary - a.salary);
        
        // Read the job details for n days
        for (int i = 0; i < n; i++) {
            // For each day, read the day number and salary
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            // Push the job onto the heap
            x.add(new Job(-day, -salary));
        }
        
        // Process the jobs in the heap until it's empty
        while (!x.isEmpty()) {
            // Pop the job with the highest day and salary (due to negation)
            Job job = x.poll();
            int d = job.day;
            int s = job.salary;
            
            // Calculate the remaining capacity for jobs
            int r = m - y.size();
            
            // If there is enough capacity to take the job
            if (r >= -d) {
                // Add the job to the selected salaries heap
                y.add(new Job(-d, -s));
            } else {
                // If capacity is full, replace the lowest salary if the new salary is higher
                y.add(new Job(-d, -s));
                y.poll();  // Remove the lowest salary from the heap
            }
        }
        
        // Output the total sum of selected salaries
        int totalSalary = 0;
        for (Job job : y) {
            totalSalary += job.salary;
        }
        System.out.println(totalSalary);
    }
    
    static class Job {
        int day;
        int salary;
        
        Job(int day, int salary) {
            this.day = day;
            this.salary = salary;
        }
    }
}
