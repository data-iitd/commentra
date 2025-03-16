
import java.util.Scanner; // Import the Scanner class for reading input from the standard input.
import java.util.Queue;    // Import the Queue interface and the LinkedList class for using the queue data structure.

public class s525470559{         // Define a class named 's525470559' to contain the main function.
    public static void main(String[] args) { // The main function is where the program execution begins.
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
        Queue<String> Q = new LinkedList<>(); // Create a queue of tasks using the LinkedList class.

        int n = sc.nextInt(); // Read the number of tasks from the standard input.
        int q = sc.nextInt(); // Read the time quantum from the standard input.

        for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
            String name = sc.next(); // Read the task's name from the standard input.
            int time = sc.nextInt(); // Read the task's time from the standard input.
            Q.add(name + " " + time); // Add the task's name and time to the queue as a single string.
        }

        int elaps = 0; // Initialize the elapsed time to 0.

        while(!Q.isEmpty()) { // Process each task in the queue until it is empty.
            String p = Q.poll(); // Get the front task from the queue and remove it from the queue.
            String[] tmp = p.split(" "); // Split the task string into a name and time array.
            int time = Integer.parseInt(tmp[1]); // Convert the task's time from a string to an integer.
            if(time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
                elaps += time; // Update the elapsed time by adding the task's remaining time.
                System.out.println(p + " " + elaps); // Print the task's name, remaining time, and the current elapsed time.
            }
            else { // If the task's remaining time is greater than the time quantum.
                time -= q; // Reduce the task's remaining time by the time quantum.
                elaps += q; // Update the elapsed time by adding the time quantum.
                Q.add(tmp[0] + " " + time); // Push the task back into the queue with the remaining time.
            }
        }
    }
}
