import java.util.Collections; 
import java.util.PriorityQueue; 
import java.util.Queue; 
import java.util.Scanner; 

// Class representing a Job with two attributes 'a' and 'b'
class Job implements Comparable<Job> { 
    int a; // Represents the time or priority of the job
    int b; // Represents the value or weight of the job

    // Constructor to initialize Job attributes
    Job(int a, int b) { 
        this.a = a; 
        this.b = b; 
    } 

    // Override compareTo method to define the ordering of Jobs
    @Override 
    public int compareTo(Job otherJob) { 
        // Compare based on 'a' first, and if equal, then by 'b'
        if (otherJob.a == this.a) 
            return this.b - otherJob.b; 
        else 
            return this.a - otherJob.a; 
    } 
} 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input
        Scanner sc = new Scanner(System.in); 
        
        // Read the first line of input and split it to get N and M
        String[] line = sc.nextLine().split(" \u2581 "); 
        int N = Integer.parseInt(line[0]); // Number of jobs
        int M = Integer.parseInt(line[1]); // Maximum time or limit

        // Create a priority queue to hold the jobs
        Queue<Job> q = new PriorityQueue<>(); 
        
        // Read the job details and add them to the priority queue
        for (int i = 0; i < N; i++) { 
            line = sc.nextLine().split(" \u2581 "); 
            q.add(new Job(Integer.parseInt(line[0]), Integer.parseInt(line[1]))); 
        } 
        
        int cnt = 0; // Counter to accumulate the total value of jobs processed
        Queue<Integer> jobQ = new PriorityQueue<>(Collections.reverseOrder()); // Queue to hold job values in descending order
        
        // Process jobs for each time unit from 1 to M
        for (int i = 1; i <= M; i++) { 
            // While there are jobs that can be processed at time i
            while (!q.isEmpty()) { 
                Job job = q.peek(); // Peek at the job with the highest priority
                if (job.a <= i) { // If the job can be processed at time i
                    jobQ.add(q.poll().b); // Remove the job from the queue and add its value to jobQ
                } else 
                    break; // Break if the job cannot be processed yet
            } 
            // If there are jobs available to process, add the highest value job to the counter
            if (!jobQ.isEmpty()) 
                cnt += jobQ.poll(); // Poll the highest value job from jobQ and add to cnt
        } 
        
        // Output the total value of jobs processed
        System.out.println(cnt); 
    } 
}
