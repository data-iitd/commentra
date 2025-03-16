#include <iostream> // Include the iostream library for input/output functions
#include <string>   // Include the string library for string handling
#include <queue>    // Include the queue library for queue operations

#define MAX 100005 // Define the maximum number of processes
#define N 100      // Define the maximum length of the process name

struct P { // Define a structure for processes
    std::string name; // String to store the process name
    int t; // Integer to store the time required for the process
};

std::queue<P> Q; // Declare a queue of processes
int T = 0; // Initialize total time

int main() { // Main function to execute the process scheduling
    int n, q; // Declare variables for number of processes and quantum
    std::cin >> n >> q; // Read the number of processes and the quantum

    for (int i = 0; i < n; i++) { // Loop to read each process
        P a; // Declare a process variable
        std::cin >> a.name >> a.t; // Read the process name and time
        Q.push(a); // Enqueue the process
    }

    while (!Q.empty()) { // Loop to process each process
        P a = Q.front(); // Get the process at the front of the queue
        Q.pop(); // Remove the process from the queue

        if (a.t > q) { // If the process time is greater than the quantum
            a.t -= q; // Reduce the process time by the quantum
            T += q; // Increment the total time by the quantum
            Q.push(a); // Enqueue the process again
        } else { // If the process time is less than or equal to the quantum
            T += a.t; // Increment the total time by the process time
            std::cout << a.name << " " << T << std::endl; // Print the process name and total time
        }
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
