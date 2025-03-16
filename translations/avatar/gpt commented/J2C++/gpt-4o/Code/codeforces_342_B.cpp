#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    // Initialize variables
    int m, s, f;
    
    // Read the first line of input
    string input;
    getline(cin, input);
    sscanf(input.c_str(), "%*s %d %d %d", &m, &s, &f);
    
    // Initialize maxT to keep track of the maximum time step
    int maxT = -1;
    
    // Create a map to store the movements at each time step
    map<int, vector<int>> movements;
    
    // Read the movements for each time step
    while (m > 0) {
        string mth;
        getline(cin, mth);
        int k, a, b;
        sscanf(mth.c_str(), "%d %d %d", &k, &a, &b);
        
        // Store the movement range in the map
        movements[k] = {a, b};
        
        // Update maxT to the highest time step encountered
        maxT = max(maxT, k);
        m--;
    }
    
    // Prepare a string to store the actions taken
    string actions;
    
    // Determine the direction of movement based on start and final positions
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    
    // Initialize current position to start position
    int cur = s;
    int a = -1;
    int b = -1;
    
    // Iterate through each time step from 1 to maxT
    for (int t = 1; t <= maxT; t++) {
        // Check if there are movements defined for the current time step
        if (movements.find(t) != movements.end()) {
            a = movements[t][0]; // Get the start of the movement range
            b = movements[t][1]; // Get the end of the movement range
        }
        
        // Check if the current position or the next position is within the movement range
        if (movements.find(t) != movements.end() && 
            ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions += 'X'; // Append 'X' if within the range
        } else {
            actions += M; // Append the movement direction
            cur += d; // Update the current position
        }
        
        // Break the loop if the current position reaches the final position
        if (cur == f) break;
    }
    
    // Continue moving until the current position reaches the final position
    while (cur != f) {
        actions += M; // Append the movement direction
        cur += d; // Update the current position
    }
    
    // Output the sequence of actions taken
    cout << actions << endl;
    
    return 0;
}

// <END-OF-CODE>
