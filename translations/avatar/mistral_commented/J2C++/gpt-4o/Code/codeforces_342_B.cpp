#include <iostream> // For input and output
#include <sstream> // For string stream
#include <vector> // For using vectors
#include <unordered_map> // For using unordered_map
#include <string> // For using strings

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr); // Untie cin from cout

    string line;
    getline(cin, line); // Read the first line of input
    stringstream ss(line);
    
    int m, s, f;
    ss >> m >> ws; // Read number of methods
    ss >> ws; // Skip whitespace
    ss >> s >> f; // Read start and finish positions

    int maxT = -1; // Initialize maximum thread ID
    unordered_map<int, vector<int>> map; // Create a map to store thread IDs and their arrival and departure times

    // Read the remaining lines of input and store the thread IDs and their arrival and departure times in the map
    while (m--) {
        getline(cin, line); // Read a line of input
        stringstream mth(line);
        int k, arrival, departure;
        mth >> k >> arrival >> departure; // Read thread ID, arrival and departure times
        map[k] = {arrival, departure}; // Store in the map
        maxT = max(maxT, k); // Update the maximum thread ID
    }

    string actions; // Initialize a string to store the output
    char M = (s < f) ? 'R' : 'L'; // Determine the direction of the simulation
    int d = (s < f) ? 1 : -1; // Determine the direction of the simulation as 1 for right and -1 for left
    int cur = s; // Initialize the current position
    int a = -1; // Initialize variables for storing the arrival and departure times of the current thread
    int b = -1;

    // Simulate the execution of threads and generate the output
    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) { // Check if there is a thread with the given ID
            a = map[t][0]; // Get the arrival time of the thread
            b = map[t][1]; // Get the departure time of the thread

            if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) { // Check if the current position is within the execution time of the thread
                actions += 'X'; // Append an 'X' to the output
            } else {
                actions += M; // Append the direction character to the output
                cur += d; // Move the current position in the direction of the simulation
            }

            if (cur == f) { // Break the loop if the finish position is reached
                break;
            }
        } else {
            actions += M; // Append the direction character if there is no thread at the current position
            cur += d; // Move the current position in the direction of the simulation
        }
    }

    // Print the output to the console
    while (cur != f) {
        actions += M;
        cur += d;
    }
    cout << actions << endl; // Output the result

    return 0;
}

// <END-OF-CODE>
