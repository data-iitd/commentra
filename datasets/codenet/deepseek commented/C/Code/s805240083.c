#include<stdio.h> // Include the standard input/output library for input/output functions

#define MAX 100005 // Define the maximum number of processes
#define N 100 // Define the maximum length of the process name

typedef struct{ // Define a structure for processes
  char name[N]; // Array to store the process name
  int t; // Integer to store the time required for the process
}P;

P Q[MAX+1]; // Declare a queue of processes
int head, tail; // Initialize pointers for the queue

void Enqueue(P x){ // Function to add a process to the queue
  if(MAX==tail) tail=0; // Wrap around if tail reaches the maximum size
  Q[tail]=x; // Assign the process to the queue
  tail++; // Increment the tail pointer
}

P Dequeue(void){ // Function to remove and return the process at the front of the queue
  if(head==MAX) head=0; // Wrap around if head reaches the maximum size
  return Q[head++]; // Return the process and increment the head pointer
}

int main(){ // Main function to execute the process scheduling
  int i,q,n,T=0; // Declare variables for iteration, quantum, number of processes, and total time
  P a; // Declare a process variable
  scanf("%d %d", &n, &q); // Read the number of processes and the quantum

  for (i=0;i<n;i++){ // Loop to read each process
    scanf("%s%d",a.name,&a.t); // Read the process name and time
    Enqueue(a); // Enqueue the process
  }

  while(n!=0){ // Loop to process each process
    a=Dequeue(); // Dequeue a process
    if(a.t>q){ // If the process time is greater than the quantum
      a.t=a.t-q; // Reduce the process time by the quantum
      T+=q; // Increment the total time by the quantum
      Enqueue(a); // Enqueue the process again
    }
    else{ // If the process time is less than or equal to the quantum
      T=T+a.t; // Increment the total time by the process time
      printf("%s %d\n",a.name,T); // Print the process name and total time
      n--; // Decrement the number of processes
    }
  }

  return 0; // Return 0 to indicate successful execution
}
