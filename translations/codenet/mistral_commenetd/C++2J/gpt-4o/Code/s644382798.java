import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Process {
    String name;
    int time; // time taken by each process

    Process(String name, int time) {
        this.name = name;
        this.time = time;
    }
}

public class ProcessScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int elapsed = 0, c; // elapsed time and the number of units processed in each iteration
        int n, q; // number of processes and the number of queries

        n = scanner.nextInt();
        q = scanner.nextInt();
        Queue<Process> queue = new LinkedList<>(); // queue to store process information

        for (int i = 0; i < n; i++) { // initialize the queue with process information
            String name = scanner.next();
            int time = scanner.nextInt();
            queue.add(new Process(name, time)); // enqueue each process
        }

        while (!queue.isEmpty()) { // processing loop
            Process u = queue.poll(); // dequeue a process
            c = Math.min(q, u.time); // calculate the number of units to be processed in this iteration
            u.time -= c; // update the remaining time for the process
            elapsed += c; // update the elapsed time
            if (u.time > 0) { // if the process still has remaining time, enqueue it again
                queue.add(u);
            } else { // if the process has been fully processed, print the result
                System.out.println(u.name + " " + elapsed);
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
