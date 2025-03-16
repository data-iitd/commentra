#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define LEN 100005 // Maximum size of the queue

// Define a structure 'pp' to store name and time of each process
struct P {
    std::string name; // Name of the process
    int t; // Time taken by the process
};

// Initialize head and tail pointers and size of the queue
std::vector<P> Q(LEN);
int head = 1, tail = 1, n;

// Function to add an element to the queue
void enqueue(const P& x) {
    Q[tail] = x; // Add the process to the queue
    tail = (tail + 1) % LEN; // Increment tail pointer
}

// Function to remove an element from the queue
P dequeue() {
    P x = Q[head]; // Store the process to be removed
    head = (head + 1) % LEN; // Increment head pointer
    return x; // Return the removed process
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b; // Return the smaller integer
}

int main() {
    int elaps = 0, c; // Initialize elapsed time and control variable c
    int q; // Number of processes to be served

    // Read number of processes and number of queries
    std::cin >> n >> q;

    // Allocate memory for each process and read its name and time
    for (int i = 1; i <= n; i++) {
        P process;
        std::cin >> process.name; // Read name of the process
        std::cin >> process.t; // Read time taken by the process
        enqueue(process); // Add the process to the queue
    }
    
    // Simulate the queue and serve processes based on their arrival time and time taken
    while (head != tail) {
        P u = dequeue(); // Dequeue a process
        c = min(q, u.t); // Find the minimum of remaining queries and time taken by the process
        u.t -= c; // Subtract the time taken to serve the queries
        elaps += c; // Add the time taken to serve the queries to elapsed time
        if (u.t > 0) enqueue(u); // If the process still has time left, add it back to the queue
        else {
            std::cout << u.name << " " << elaps << std::endl; // Print the name of the process and elapsed time when it is finished
        }
    }

    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
