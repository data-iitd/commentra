import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

// Step 2: Define Job class
class Job implements Comparable<Job> {
    int a;
    int b;

    Job(int a, int b) {
        this.a = a;
        this.b = b;
    }

    // Step 2: Implement compareTo method to compare jobs based on parameters a and b
    @Override
    public int compareTo(Job otherJob) {
        if (otherJob.a == this.a)
            return this.b - otherJob.b;
        else
            return this.a - otherJob.a;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Step 4: Read input and initialize variables
        String[] line = sc.nextLine().split(" \u2581 ");
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);
        
        // Step 5: Create a priority queue to store jobs
        Queue<Job> q = new PriorityQueue<>();
        
        // Step 6: Read job details and add to the priority queue
        for (int i = 0; i < N; i++) {
            line = sc.nextLine().split(" \u2581 ");
            q.add(new Job(Integer.parseInt(line[0]), Integer.parseInt(line[1])));
        }
        
        // Step 7: Initialize counters and another priority queue
        int cnt = 0;
        Queue<Integer> jobQ = new PriorityQueue<>(Collections.reverseOrder());
        
        // Step 8: Process each day from 1 to M
        for (int i = 1; i <= M; i++) {
            while (!q.isEmpty()) {
                Job job = q.peek();
                if (job.a <= i) {
                    jobQ.add(q.poll().b);
                } else {
                    break;
                }
            }
            if (!jobQ.isEmpty())
                cnt += jobQ.poll();
        }
        
        // Step 10: Print the total reward
        System.out.println(cnt);
    }
}
