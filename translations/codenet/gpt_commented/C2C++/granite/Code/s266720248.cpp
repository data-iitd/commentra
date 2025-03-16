
#include<iostream>
#include<string>

#define LEN 100005

// Define a structure to hold the name and time of each process
struct pp{
  std::string name; // Name of the process
  int t;            // Remaining time for the process
};

// Declare a queue to hold the processes
pp Q[LEN];
int head, tail, n; // Variables for queue management and number of processes

// Function to add a process to the queue
void enqueue(pp x){
  Q[tail] = x; // Add the process to the queue at the tail
  tail = (tail + 1) % LEN; // Move the tail pointer in a circular manner
}

// Function to remove a process from the queue
pp dequeue(){
  pp x = Q[head]; // Get the process at the head of the queue
  head = (head + 1) % LEN; // Move the head pointer in a circular manner
  return x; // Return the removed process
}

// Function to find the minimum of two integers
int min(int a, int b){
  return a < b? a : b; // Return the smaller of the two values
}

int main(){
  int elaps = 0, c; // elaps keeps track of elapsed time, c for current time slice
  int i, q; // Loop variables and the time quantum
  pp u; // Variable to hold the current process

  // Read the number of processes and the time quantum
  std::cin >> n >> q;

  // Read the process names and their respective times
  for(i = 1 ; i <= n ; i++){
    std::cin >> Q[i].name; // Read process name
    std::cin >> Q[i].t;    // Read remaining time for the process
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
      std::cout << u.name << " " << elaps << std::endl;
    }
  }

  return 0; // End of the program
}


