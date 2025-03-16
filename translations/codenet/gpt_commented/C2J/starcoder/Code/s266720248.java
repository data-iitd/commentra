
import java.util.*;

public class Main {
  public static void main(String[] args) {
    int elaps = 0, c; // elaps keeps track of elapsed time, c for current time slice
    int i, q; // Loop variables and the time quantum
    P u; // Variable to hold the current process

    // Read the number of processes and the time quantum
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    q = sc.nextInt();

    // Read the process names and their respective times
    for(i = 1 ; i <= n ; i++){
      sc.next(); // Read process name
      Q[i].t = sc.nextInt();    // Read remaining time for the process
    }
    
    // Initialize head and tail pointers for the queue
    head = 1;
    tail = n + 1;

    // Process the queue until all processes are completed
    while(head!= tail){
      u = dequeue(); // Remove the next process from the queue
      c = min(q, u.t); // Determine the time slice to process (minimum of quantum and remaining time)
      u.t -= c; // Decrease the remaining time of the process
      elaps += c; // Increase the elapsed time by the time slice
      if(u.t > 0) enqueue(u); // If the process is not finished, re-add it to the queue
      else{
        // If the process is finished, print its name and the total elapsed time
        System.out.println(u.name + " " + elaps);
      }
    }
  }
}

