
import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n, q, T = 0;  // Initialize variables for loop counters, query time, and total time
    Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input
    Deque<P> Q = new ArrayDeque<P>();  // Create a queue to hold P structures
    P a;  // Declare a variable of type P to hold the current person

    // Read the number of people and the query time
    n = sc.nextInt();
    q = sc.nextInt();

    // Read each person's name and time, and enqueue them
    for (int i = 0; i < n; i++){
      a = new P();  // Create a new P structure
      a.name = sc.next();  // Read name
      a.t = sc.nextInt();  // Read time
      Q.add(a);  // Add the person to the queue
    }

    // Process the queue until all people have been served
    while(n!= 0){
      a = Q.remove();  // Remove the front person from the queue
      // Check if the person's time exceeds the query time
      if(a.t > q){
        a.t = a.t - q;  // Reduce their time by the query time
        T += q;         // Add query time to total time
        Q.add(a);       // Re-enqueue the person with the remaining time
      }
      else{
        T = T + a.t;    // Add the person's time to total time
        System.out.printf("%s %d\n", a.name, T);  // Print the person's name and total time
        n--;  // Decrease the count of people left to serve
      }
    }
  }
}

class P{
  String name;
  int t;
}

