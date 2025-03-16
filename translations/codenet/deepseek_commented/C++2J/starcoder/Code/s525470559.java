import java.util.*; // Import the Scanner and Queue classes from the Java standard library.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from stdin.
        int n = sc.nextInt(); // Read the number of tasks.
        int q = sc.nextInt(); // Read the time quantum.
        Queue<task> Q = new LinkedList<task>(); // Create a queue of tasks.
        int elaps = 0; // Initialize the elapsed time to 0.

        for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
            task tmp = new task(); // Create a temporary task object.
            tmp.name = sc.next(); // Read the task's name.
            tmp.time = sc.nextInt(); // Read the task's time.
            Q.add(tmp); // Push the task into the queue.
        }

        while(!Q.isEmpty()) { // Process each task in the queue until it is empty.
            task p = Q.peek(); Q.remove(); // Get the front task from the queue and remove it from the queue.
            if(p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
                elaps += p.time; // Update the elapsed time by adding the task's remaining time.
                System.out.println(p.name + " " + elaps); // Print the task's name and the current elapsed time.
            }
            else { // If the task's remaining time is greater than the time quantum.
                p.time -= q; // Reduce the task's remaining time by the time quantum.
                elaps += q;  // Update the elapsed time by adding the time quantum.
                Q.add(p);   // Push the task back into the queue with the remaining time.
            }
        }
    }
}

