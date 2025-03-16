import java.util.*;

public class Main{
  public static void main(String[] args){
    int n,q,T=0; // Declare variables for iteration, quantum, and total time
    Scanner sc=new Scanner(System.in); // Create a Scanner object
    n=sc.nextInt(); // Read the number of processes
    q=sc.nextInt(); // Read the quantum
    Queue<P> Q=new LinkedList<P>(); // Create a queue of processes
    for (int i=0;i<n;i++){ // Loop to read each process
      P a=new P(); // Create a process variable
      a.name=sc.next(); // Read the process name
      a.t=sc.nextInt(); // Read the time required for the process
      Q.add(a); // Enqueue the process
    }

    while(n!=0){ // Loop to process each process
      P a=Q.remove(); // Dequeue a process
      if(a.t>q){ // If the process time is greater than the quantum
        a.t=a.t-q; // Reduce the process time by the quantum
        T+=q; // Increment the total time by the quantum
        Q.add(a); // Enqueue the process again
      }
      else{ // If the process time is less than or equal to the quantum
        T=T+a.t; // Increment the total time by the process time
        System.out.println(a.name+" "+T); // Print the process name and total time
        n--; // Decrement the number of processes
      }
    }
  }
}

class P{ // Define a structure for processes
  String name; // String to store the process name
  int t; // Integer to store the time required for the process
}

