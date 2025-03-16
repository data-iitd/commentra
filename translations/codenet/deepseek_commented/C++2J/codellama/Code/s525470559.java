import java.util.Scanner; // Import the Scanner class for input and output operations.
import java.util.LinkedList; // Import the LinkedList class for using the queue data structure.

public class Main { // Define a class named 'Main' to hold the program execution.
    public static void main(String[] args) { // Define a main function to start the program execution.
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the standard input.
        int n, q, elaps = 0; // Declare variables for the number of tasks, the time quantum, and the elapsed time.
        LinkedList<task> Q = new LinkedList<task>(); // Declare a queue of tasks.

        n = sc.nextInt(); // Read the number of tasks from the standard input.
        q = sc.nextInt(); // Read the time quantum from the standard input.

        for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
            task tmp = new task(); // Create a temporary task object.
            tmp.name = sc.next(); // Read the task's name from the standard input.
            tmp.time = sc.nextInt(); // Read the task's time from the standard input.
            Q.add(tmp); // Push the task into the queue.
        }

        while(!Q.isEmpty()) { // Process each task in the queue until it is empty.
            task p = Q.remove(); // Get the front task from the queue and remove it from the queue.
            if(p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
                elaps += p.time; // Update the elapsed time by adding the task's remaining time.
                System.out.println(p.name + " " + elaps); // Print the task's name and the current elapsed time.
            }
            else { // If the task's remaining time is greater than the time quantum.
                p.time -= q; // Reduce the task's remaining time by the time quantum.
                elaps += q;  // Update the elapsed time by adding the time quantum.
                Q.add(p); // Push the task back into the queue with the remaining time.
            }
        }
    }
}

class task { // Define a class named 'task' to hold the name and time for each task.
    String name; // The name of the task.
    int time; // The time required to complete the task.
}

