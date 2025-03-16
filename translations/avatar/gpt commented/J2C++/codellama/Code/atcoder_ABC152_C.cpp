#include <iostream> 
#include <queue> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    Scanner sc(cin); 
    
    // Read the number of elements in the array
    int N = sc.nextInt(); 
    
    // Initialize an array to hold the input values
    int arr[N]; 
    
    // Populate the array with user input
    for (int i = 0; i < N; i++) { 
        arr[i] = sc.nextInt(); 
    } 
    
    // Initialize a variable to keep track of the count of elements
    int sum = 0; 
    
    // Create a priority queue to manage the elements
    priority_queue<int> q; 
    
    // Iterate through the array to process each element
    for (int i = 0; i < N; i++) { 
        // Add the current element to the priority queue
        q.push(arr[i]); 
        
        // Check if the current element is less than or equal to the smallest element in the queue
        if (arr[i] <= q.top()) { 
            // Increment the count if the condition is met
            sum++; 
        } 
    } 
    
    // Return the final count of elements that met the condition
    return sum; 
} 

