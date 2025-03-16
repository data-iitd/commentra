import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        int elaps = 0, c; // Initialize elapsed time and a variable to hold the time quantum
        int n, q;
        String name;
        int t;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); // Read the number of processes and the time quantum
        q = sc.nextInt();

        // Read each process's name and time
        for (int i = 1; i <= n; i++)
        {
            name = sc.next(); // Read the process name
            t = sc.nextInt(); // Read the process time
            P u = new P(name, t); // Create a new process
            Q.add(u); // Add the process to the queue
        }

        // Process each process in the queue
        while (!Q.isEmpty())
        {
            u = Q.remove(); // Dequeue the next process
            c = Math.min(q, u.t); // Determine the time slice to process the process
            u.t -= c; // Reduce the process time by the time slice
            elaps += c; // Add the time slice to the elapsed time
            if (u.t > 0)
                Q.add(u); // If there is more time left for the process, enqueue it again
            else
                System.out.printf("%s %d\n", u.name, elaps); // Otherwise, print the process name and elapsed time
        }
    }
}

class P
{
    String name;
    int t;
    P(String name, int t)
    {
        this.name = name;
        this.t = t;
    }
}

