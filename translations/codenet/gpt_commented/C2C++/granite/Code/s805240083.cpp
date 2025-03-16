
#include<iostream>
#include<string>

#define MAX 100005  // Maximum size of the queue
#define N 100       // Maximum size of the name string

// Define a structure to hold a person's name and their time
struct P{
  std::string name;  // Name of the person
  int t;              // Time associated with the person
};

// Declare a queue to hold P structures
P Q[MAX+1];
int head, tail;  // Head and tail pointers for the queue

// Function to add an element to the queue
void Enqueue(P x){
  // Wrap around the tail if it reaches the maximum size
  if(MAX==tail) tail=0;
  Q[tail] = x;  // Add the element to the queue
  tail++;       // Move the tail pointer forward
}

// Function to remove and return an element from the queue
P Dequeue(void){
  // Wrap around the head if it reaches the maximum size
  if(head==MAX) head=0;
  return Q[head++];  // Return the element at the head and move the head pointer forward
}

int main(){
  int i, q, n, T = 0;  // Initialize variables for loop counters, query time, number of people, and total time
  P a;  // Declare a variable of type P to hold the current person

  // Read the number of people and the query time
  std::cin >> n >> q;

  // Read each person's name and time, and enqueue them
  for (i = 0; i < n; i++){
    std::cin >> a.name >> a.t;  // Read name and time
    Enqueue(a);  // Add the person to the queue
  }

  // Process the queue until all people have been served
  while(n!= 0){
    a = Dequeue();  // Remove the front person from the queue
    // Check if the person's time exceeds the query time
    if(a.t > q){
      a.t = a.t - q;  // Reduce their time by the query time
      T += q;         // Add query time to total time
      Enqueue(a);     // Re-enqueue the person with the remaining time
    }
    else{
      T = T + a.t;    // Add the person's time to total time
      std::cout << a.name << " " << T << std::endl;  // Print the person's name and total time
      n--;  // Decrease the count of people left to serve
    }
  }

  return 0;  // Return from main
}

