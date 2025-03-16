import java.util.*;

public class JobScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of days (n) and the maximum number of jobs (m) from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize two priority queues: one for jobs (x) and one for selected salaries (y)
        PriorityQueue<Job> x = new PriorityQueue<>((a, b) -> {
            if (a.day != b.day) {
                return Integer.compare(b.day, a.day); // Max-heap based on day
            }
            return Integer.compare(b.salary, a.salary); // Max-heap based on salary
        });
        
        PriorityQueue<Integer> y = new PriorityQueue<>(); // Min-heap for selected salaries
        
        // Read the job details for n days
        for (int i = 0; i < n; i++) {
            int day = scanner.nextInt();
            int salary = scanner.nextInt();
            // Add the job to the heap
            x.offer(new Job(day, salary));
        }
        
        // Process the jobs in the heap until it's empty
        while (!x.isEmpty()) {
            Job job = x.poll();
            
            // Calculate the remaining capacity for jobs
            int r = m - y.size();
            
            // If there is enough capacity to take the job
            if (r >= job.day) {
                // Add the salary to the selected salaries heap
                y.offer(job.salary);
            } else {
                // If capacity is full, replace the lowest salary if the new salary is higher
                if (!y.isEmpty() && job.salary > y.peek()) {
                    y.poll(); // Remove the lowest salary from the heap
                    y.offer(job.salary); // Add the new salary
                }
            }
        }
        
        // Output the total sum of selected salaries
        int totalSum = 0;
        while (!y.isEmpty()) {
            totalSum += y.poll();
        }
        System.out.println(totalSum);
        
        scanner.close();
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

// <END-OF-CODE>
