
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    // Initialize BufferedReader to read input from the console
    string line;
    getline(cin, line);
    stringstream ss(line);
    int m, s, f;
    ss >> m >> s >> f;

    // Initialize maxT to keep track of the maximum time step
    int maxT = -1;

    // Create a map to store the movements at each time step
    map<int, vector<int>> map;

    // Read the movements for each time step
    while (m > 0) {
        // Read the movement data for the current time step
        string line;
        getline(cin, line);
        stringstream ss(line);
        int k;
        ss >> k;
        int a, b;
        ss >> a >> b;

        // Update maxT to the highest time step encountered
        maxT = max(maxT, k);

        // Add the movement range to the map
        map[k] = {a, b};

        m--;
    }

    // Prepare a string to store the actions taken
    string actions;

    // Determine the direction of movement based on start and final positions
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? +1 : -1;

    // Initialize current position to start position
    int cur = s;

    // Iterate through each time step from 1 to maxT
    for (int t = 1; t <= maxT; t++) {
        // Check if there are movements defined for the current time step
        if (map.count(t)) {
            a = map[t][0]; // Get the start of the movement range
            b = map[t][1]; // Get the end of the movement range
        }

        // Check if the current position or the next position is within the movement range
        if (map.count(t) && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions += 'X'; // Append 'X' if within the range
        } else {
            actions += M; // Append the movement direction
            cur += d; // Update the current position
        }

        // Break the loop if the current position reaches the final position
        if (cur == f) break;
    }

    // Continue moving until the current position reaches the final position
    while (cur!= f) {
        actions += M; // Append the movement direction
        cur += d; // Update the current position
    }

    // Output the sequence of actions taken
    cout << actions << endl;

    return 0;
}
