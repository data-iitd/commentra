#include<iostream>
#include<string>
#include<queue>

using namespace std;

// Define a structure to hold a person's name and their time
struct Person{
  string name;  // Name of the person
  int t;        // Time associated with the person
};

// Declare a queue to hold Person structures
queue<Person> Q;

// Function to add an element to the queue
void Enqueue(Person x){
  Q.push(x);  // Add the element to the queue
}

// Function to remove and return an element from the queue
Person Dequeue(void){
  Person x = Q.front();  // Get the front element of the queue
  Q.pop();               // Remove the front element from the queue
  return x;              // Return the front element
}

int main(){
  int i, q, n, T = 0;  // Initialize variables for loop counters, query time, number of people, and total time
  Person a;  // Declare a variable of type Person to hold the current person

  // Read the number of people and the query time
  cin >> n >> q;

  // Read each person's name and time, and enqueue them
  for (i = 0; i < n; i++){
    cin >> a.name >> a.t;  // Read name and time
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
      cout << a.name << " " << T << endl;  // Print the person's name and total time
      n--;  // Decrease the count of people left to serve
    }
  }

  return 0;  // Return from main
}

