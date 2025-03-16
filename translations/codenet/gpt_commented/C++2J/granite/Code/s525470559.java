
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class s525470559{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Number of tasks
        int q = sc.nextInt(); // Time quantum
        int elaps = 0; // Elapsed time
        Queue<String> Q = new LinkedList<>(); // Queue to manage tasks

        // Read each task's name and add it to the queue
        for(int i = 0; i < n; i++) {
            String name = sc.next(); // Task name
            int time = sc.nextInt(); // Task time
            Q.add(name + " " + time); // Add task name and time to the queue
        }

        // Process tasks until the queue is empty
        while(!Q.isEmpty()) {
            String p = Q.peek(); // Get the task at the front of the queue
            String[] tmp = p.split(" "); // Split the task name and time
            int time = Integer.parseInt(tmp[1]); // Get the task time

            // Check if the task can be completed within the time quantum
            if(time <= q) {
                elaps += time; // Update elapsed time
                System.out.println(p + " " + elaps); // Output task name and total elapsed time
                Q.remove(); // Remove the task from the queue
            }
            else {
                // If the task cannot be completed, reduce its time and re-add it to the queue
                time -= q; // Decrease the remaining time of the task
                elaps += q; // Update elapsed time by the time quantum
                Q.remove(); // Remove the task from the queue
                Q.add(tmp[0] + " " + time); // Re-add the task to the queue for further processing
            }
        }
    }
}
