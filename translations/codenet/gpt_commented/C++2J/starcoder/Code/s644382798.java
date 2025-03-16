import java.util.*;

public class SJF
{
    public static void main(String[] args)
    {
        int elaps = 0, c; // elaps keeps track of elapsed time, c is the time slice
        int i, q; // Loop variables and the time quantum
        P u; // Variable to hold the current process

        // Read the number of processes and the time quantum
        Scanner sc = new Scanner(System.in);
        q = sc.nextInt();
        n = sc.nextInt();

        // Read the name and time for each process
        for (i = 1; i <= n; i++)
        {
            sc.next(); // Read the process name
            Q[i].t = sc.nextInt();    // Read the remaining time for the process
        }
        
        // Initialize the head and tail pointers for the queue
        head = 1;
        tail = n + 1;

        // Process the queue until all processes are completed
        while (head!= tail)
        {
            u = dequeue(); // Dequeue the next process
            c = min(q, u.t); // Determine the time slice to process (minimum of quantum and remaining time)
            u.t -= c; // Reduce the remaining time of the process
            elaps += c; // Increase the elapsed time by the time slice
            
            // If the process still has remaining time, enqueue it back
            if (u.t > 0)
                enqueue(u);
            else // If the process is completed, print its name and the elapsed time
                System.out.println(u.name + " " + elaps);
        }
    }
}

