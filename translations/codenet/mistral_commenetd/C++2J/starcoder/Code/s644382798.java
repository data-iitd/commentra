
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        int elaps = 0, c; // elapsed time and the number of units processed in each iteration
        int n, q; // number of processes and queries
        int i, q; // loop variables
        P u; // variable to store the process dequeued from the queue

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        q = sc.nextInt();

        for (i = 1; i <= n; i++) // initialize the queue with process information
        {
            u = new P();
            u.name = sc.next();
            u.t = sc.nextInt();
            Q[i] = u; // enqueue each process
        }
        head = 1;
        tail = n + 1;

        while (head!= tail) // processing loop
        {
            u = Q[head]; // dequeue a process
            c = Math.min(q, u.t); // calculate the number of units to be processed in this iteration
            u.t -= c; // update the remaining time for the process
            elaps += c; // update the elapsed time
            if (u.t > 0) // if the process still has remaining time, enqueue it again
                Q[tail] = u;
            else // if the process has been fully processed, print the result
                System.out.printf("%s %d\n", u.name, elaps);
        }
    }
}

