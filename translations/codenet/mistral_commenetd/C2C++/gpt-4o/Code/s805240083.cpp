#include <iostream>
#include <string>
#include <queue>

#define MAX 100005
#define N 100

struct P {
    char name[N];
    int t; // time taken by each process
};

std::queue<P> Q; // Queue to store the processes

int main() {
    int i, q, n; // Declare variables for input and loop counter
    P a; // Declare a variable to store the current process
    int T = 0; // Initialize the total time to 0

    std::cin >> n >> q; // Read the number of processes and the time limit from the input

    for (i = 0; i < n; i++) { // Loop to read the details of each process and enqueue it
        std::cin >> a.name >> a.t;
        Q.push(a); // Store the process in the queue
    }

    while (!Q.empty()) { // While there are still processes in the queue
        a = Q.front(); // Get the current process
        Q.pop(); // Remove the current process from the queue

        if (a.t > q) { // If the process takes more time than the limit
            a.t -= q; // Subtract the excess time from the process time
            T += q; // Add the time limit to the total time
            Q.push(a); // Re-enqueue the process
        } else { // If the process takes less time than the limit
            T += a.t; // Add the process time to the total time
            std::cout << a.name << " " << T << std::endl; // Print the name and total time taken for the process
            n--; // Decrement the number of processes left
        }
    }

    return 0; // Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
