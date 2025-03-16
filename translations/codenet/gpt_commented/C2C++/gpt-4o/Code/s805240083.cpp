#include <iostream>
#include <string>
#include <queue>

#define N 100       // Maximum size of the name string

// Define a structure to hold a person's name and their time
struct P {
    std::string name;  // Name of the person
    int t;             // Time associated with the person
};

// Declare a queue to hold P structures
std::queue<P> Q;  // Using STL queue for simplicity
int T = 0;        // Total time

int main() {
    int i, q, n;  // Initialize variables for loop counters, query time, and number of people
    P a;          // Declare a variable of type P to hold the current person

    // Read the number of people and the query time
    std::cin >> n >> q;

    // Read each person's name and time, and enqueue them
    for (i = 0; i < n; i++) {
        std::cin >> a.name >> a.t;  // Read name and time
        Q.push(a);                  // Add the person to the queue
    }

    // Process the queue until all people have been served
    while (!Q.empty()) {
        a = Q.front();  // Get the front person from the queue
        Q.pop();        // Remove the front person from the queue

        // Check if the person's time exceeds the query time
        if (a.t > q) {
            a.t -= q;   // Reduce their time by the query time
            T += q;     // Add query time to total time
            Q.push(a);  // Re-enqueue the person with the remaining time
        } else {
            T += a.t;   // Add the person's time to total time
            std::cout << a.name << " " << T << std::endl;  // Print the person's name and total time
        }
    }

    return 0;  // Return from main
}

// <END-OF-CODE>
