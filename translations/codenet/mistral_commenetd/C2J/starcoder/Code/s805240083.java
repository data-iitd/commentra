import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n,q,i; // Declare variables for input and loop counter
    int T=0; // Initialize the total time to 0
    Scanner sc=new Scanner(System.in); // Create a Scanner object to read input
    n=sc.nextInt(); // Read the number of processes and the time limit from the input
    q=sc.nextInt();
    P[] Q=new P[n]; // Create an array to store the processes
    for (i=0;i<n;i++){ // Loop to read the details of each process and enqueue it
      Q[i]=new P();
      Q[i].name=sc.next();
      Q[i].t=sc.nextInt();
      Enqueue(Q[i]);
    }

    while(n!=0){ // While there are still processes in the queue
      P a=Dequeue(); // Dequeue the current process
      if(a.t>q){ // If the process takes more time than the limit
        a.t=a.t-q; // Subtract the excess time from the process time
        T+=q; // Add the time limit to the total time
        Enqueue(a); // Re-enqueue the process
      }
      else{ // If the process takes less time than the limit
        T=T+a.t; // Add the process time to the total time
        System.out.println(a.name+" "+T); // Print the name and total time taken for the process
        n--; // Decrement the number of processes left
      }
    }
  }

  static class P{ // Class to store the details of each process
    String name;
    int t;
  }

  static void Enqueue(P x){
    // Function to add a process to the queue
    if(MAX==tail) { // Check if the queue is full
      tail=0;
    }
    Q[tail]=x; // Store the process in the queue
    tail++; // Increment the tail pointer
  }

  static P Dequeue(void){
    // Function to remove a process from the queue
    P temp; // Temporary variable to store the process to be removed
    if(head==MAX) { // Check if the queue is empty
      head=0;
    }
    temp=Q[head]; // Store the process to be removed
    head++; // Increment the head pointer
    return temp; // Return the process
  }

  static int head=0,tail=0; // Declare variables for head and tail of the queue
  static int MAX=100005; // Maximum number of processes that can be stored in the queue
}

