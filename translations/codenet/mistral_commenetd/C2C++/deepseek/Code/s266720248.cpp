#include<iostream>
#include<string>
#include<queue>

using namespace std;

#define LEN 100005 // Maximum size of the queue

// Define a structure 'pp' to store name and time of each process
typedef struct pp{
  string name; // Name of the process
  int t; // Time taken by the process
}P;

// Initialize head and tail pointers and size of the queue
P Q[LEN];
int head, tail, n;

// Function to add an element to the queue
void enqueue(P x){
  Q[tail] = x; // Add the process to the queue
  tail = (tail + 1) % LEN; // Increment tail pointer
}

// Function to remove an element from the queue
P dequeue(){
  P x = Q[head]; // Store the process to be removed
  head = (head + 1) % LEN; // Increment head pointer
  return x; // Return the removed process
}

// Function to find the minimum of two integers
int min(int a, int b){
  return a < b ? a : b; // Return the smaller integer
}

int main(){
  int elaps = 0, c; // Initialize elapsed time and control variable c
  int i, q; // Loop counter and number of processes to be served

  // Read number of processes and number of queries
  cin >> n >> q;

  // Allocate memory for each process and read its name and time
  for(i = 1 ; i <= n ; i++){
    cin >> Q[i].name >> Q[i].t; // Read name of the process and time taken by the process
    enqueue(Q[i]); // Add the process to the queue
  }
  head = 1;
  tail = n + 1; // Initialize head and tail pointers

  // Simulate the queue and serve processes based on their arrival time and time taken
  while(head != tail){
    P u = dequeue(); // Dequeue a process
    c = min(q,u.t); // Find the minimum of remaining queries and time taken by the process
    u.t -= c; // Subtract the time taken to serve the queries
    elaps += c; // Add the time taken to serve the queries to elapsed time
    if(u.t > 0) enqueue(u); // If the process still has time left, add it back to the queue
    else{
      cout << u.name << " " << elaps << endl; // Print the name of the process and elapsed time when it is finished
    }
  }

  return 0; // Indicate successful termination of the program
}

