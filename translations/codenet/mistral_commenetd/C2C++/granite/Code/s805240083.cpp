
#include<iostream>
#define MAX 100005
#define N 100

using namespace std;

struct P{
  char name[N];
  int t; // time taken by each process
};

P Q[MAX+1]; // Circular queue to store the processes
int head, tail; // pointers for head and tail of the queue

void Enqueue(P x){
  // Function to add a process to the queue
  if(MAX==tail) { // Check if the queue is full
    tail=0;
  }
  Q[tail]=x; // Store the process in the queue
  tail++; // Increment the tail pointer
}

P Dequeue(void){
  // Function to remove a process from the queue
  P temp; // Temporary variable to store the process to be removed
  if(head==MAX) { // Check if the queue is empty
    head=0;
  }
  temp=Q[head]; // Store the process to be removed
  head++; // Increment the head pointer
  return temp; // Return the process
}

int main(){
  int i,q,n; // Declare variables for input and loop counter
  P a; // Declare a variable to store the current process
  int T=0; // Initialize the total time to 0

  cin>>n>>q; // Read the number of processes and the time limit from the input

  for (i=0;i<n;i++){ // Loop to read the details of each process and enqueue it
    cin>>a.name>>a.t;
    Enqueue(a);
  }

  while(n!=0){ // While there are still processes in the queue
    a=Dequeue(); // Dequeue the current process
    if(a.t>q){ // If the process takes more time than the limit
      a.t=a.t-q; // Subtract the excess time from the process time
      T+=q; // Add the time limit to the total time
      Enqueue(a); // Re-enqueue the process
    }
    else{ // If the process takes less time than the limit
      T=T+a.t; // Add the process time to the total time
      cout<<a.name<<" "<<T<<endl; // Print the name and total time taken for the process
      n--; // Decrement the number of processes left
    }
  }

  return 0; // Return 0 to indicate successful execution of the program
}

